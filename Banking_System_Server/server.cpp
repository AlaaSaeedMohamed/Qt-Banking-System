#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    connect(&server, &QTcpServer::newConnection, this, &Server::newConnection);
    if (!server.listen(QHostAddress::Any, 22)) {
        qDebug() << "Error:" << server.errorString();
        qApp->quit();
    } else {
        qDebug() << "Server started. Listening on port 22...";
    }
}

void Server::readRequest()
{
    {
        // Read the incoming request from the client
        QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
        if (!socket)
            return;

        QByteArray requestData = socket->readAll();
        //qDebug() << "Received request:" << requestData;

        // Parse the request
        QString requestString(requestData);
        if (requestString.startsWith("GET")) {
            if(isLoggedIn(socket))
            {
                if(requestString.contains("gett"))
                {

                    QByteArray responseData = "HTTP/1.0 200 OK\r\n\r\n";
                    responseData += "gett";
                    socket->write(responseData);
                    //socket->disconnectFromHost();
                    qDebug() << "Received a GET request";
                }



                }

                else {
                    QByteArray responseData = "HTTP/1.0 200 OK\r\n\r\n";
                    responseData += "you have to llogin first";
                    socket->write(responseData);
                    //socket->disconnectFromHost();

                }



        } else if (requestString.startsWith("POST")) {
            qDebug() << "Received a POST request";

            if(requestString.contains("login"))
            {
                QFile file("/home/alaasaeed/test/users.json");
                if (!file.open(QIODevice::ReadOnly)) {
                    qDebug() << "Failed to open JSON file.";
                    return;
                }

                QByteArray jsonData = file.readAll();
                file.close();

                // Parse the JSON document
                QJsonParseError error;
                QJsonDocument doc = QJsonDocument::fromJson(jsonData, &error);
                if (doc.isNull()) {
                    qDebug() << "Failed to parse JSON:" << error.errorString();
                    return;
                }

                // Get the root object (containing the "users" array)
                QJsonObject root = doc.object();

                // Get the "users" array
                QJsonArray usersArray = root.value("users").toArray();

                // Extract JSON data from the request body
                int jsonDataStart = requestData.indexOf("{");
                int jsonDataEnd = requestData.lastIndexOf("}");
                if (jsonDataStart != -1 && jsonDataEnd != -1 && jsonDataEnd > jsonDataStart) {
                    QByteArray jsonData = requestData.mid(jsonDataStart, jsonDataEnd - jsonDataStart + 1);
                    qDebug() << "JSON data:" << jsonData;

                    // Parse JSON data
                    QJsonParseError jsonError;
                    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &jsonError);
                    if (jsonError.error == QJsonParseError::NoError) {
                        if (jsonDoc.isObject()) {
                            QJsonObject jsonObject = jsonDoc.object();
                            qDebug() << "Parsed JSON object:" << jsonObject;
                            handleLogin(socket,jsonObject["username"].toString(), jsonObject["password"].toString(), usersArray);
                            // Handle the parsed JSON object as needed
                        } else {
                            qDebug() << "Invalid JSON object";
                        }
                    } else {
                        qDebug() << "JSON parsing error:" << jsonError.errorString();
                    }
                } else {
                    qDebug() << "No JSON data found in the request body";
                }
            }

            //socket->disconnectFromHost();
            //handlePostRequest(socket);
        } else {
            qDebug() << "Unsupported request";
            // Respond with an error message or HTTP 400 Bad Request
        }
    }
}


bool Server::handleLogin(QTcpSocket *socket, const QString username, const QString password, QJsonArray usersArray) {
    // Simulated login logic - replace this with your actual authentication logic
    foreach (const QJsonValue &userValue, usersArray) {
        QJsonObject userObject = userValue.toObject();
        qDebug() << userObject;
        QString user = userObject.value("username").toString();
        QString pass = userObject.value("password").toString();
        qDebug()  <<  user;
        qDebug()  <<  pass;
        if (user == username && pass == password && !isLoggedIn(socket)) {
            // Generate a session ID
            QString sessionId = QUuid::createUuid().toString();
            loggedInClients.insert(socket, sessionId);
            QByteArray responseData = "HTTP/1.0 200 OK\r\n\r\n";
            responseData += "Login successful.";
            socket->write(responseData);
            qDebug() << "Login successful.";
            //socket->disconnectFromHost();
            return true;
        }

    }
    if(isLoggedIn(socket))
    {
        QByteArray responseData = "HTTP/1.0 200 OK\r\n\r\n";
        responseData += "already logged in";
        socket->write(responseData);
        return false;
    }
    else{
        QByteArray responseData = "HTTP/1.0 200 OK\r\n\r\n";
        responseData += "Login failed. Invalid username or password.";
        socket->write(responseData);
        //socket->disconnectFromHost();
    }
    return  false;

}

void Server::handleLogout(QTcpSocket *socket) {
    // Remove the client from the list of logged-in clients upon logout
    if (loggedInClients.contains(socket)) {
        loggedInClients.remove(socket);
        qDebug() << "Logout successful.";
    }
}

bool Server::isLoggedIn(QTcpSocket *socket) {
    // Check if the given socket is logged in
    return loggedInClients.contains(socket);
}
