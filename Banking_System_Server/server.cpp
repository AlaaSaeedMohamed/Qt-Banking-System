#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    connect(&server, &QTcpServer::newConnection, this, &Server::newConnection);
    if (!server.listen(QHostAddress::Any, 22)) {
        qDebug() << "Error:" << server.errorString();
        qApp->quit();
    } else {
        qDebug() << "Server started. Listening on port 22.00..";
    }

    QFile file("/home/alaasaeed/test/users.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open user database file";
        return;
    }
    QByteArray data = file.readAll();
    file.close();

    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &jsonError);
    if (jsonError.error != QJsonParseError::NoError) {
        qDebug() << "Error parsing JSON:" << jsonError.errorString();
        return;
    }

    userDatabase = jsonDoc.object();
}

void Server::readRequest()
{

        // Read the incoming request from the client
        QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
        qDebug() << socket;
        if (!socket)
            return;

        QByteArray requestData = socket->readAll();
        qDebug() << "Received request:" << requestData;

        // Parse the request
        QString requestString(requestData);
        if (requestString.startsWith("POST")) {
            qDebug() << "Received a POST request";

            if(requestString.contains("login"))
            {
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
                            handleLogin(socket,jsonObject["username"].toString(), jsonObject["password"].toString());
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

        }
        else if(requestString.startsWith("GET"))
        {
            //qDebug() << "Received a GET request";
            if(isLoggedIn(socket))
            {
                if(requestString.contains("accountNumber"))
                {

                        handleGetAccountNumber(socket);

                    //socket->waitForBytesWritten();
                    qDebug() << "Received a GET requestttt";
                }

            }
            else {
                QByteArray responseData = "";
                responseData += "you have to llogin first";
                socket->write(responseData);

            }
        }
        else {
            qDebug() << "Unsupported request";
            // Respond with an error message or HTTP 400 Bad Request
        }

}


void Server::handleLogin(QTcpSocket *socket, const QString &username, const QString &password) {
    // Check if the provided username and password match any user in the database
    QJsonArray users = userDatabase.value("users").toArray();
    for (const QJsonValue &userValue : users) {
        QJsonObject userObject = userValue.toObject();
        if (userObject.value("username").toString() == username &&
            userObject.value("password").toString() == password) {
            // Successful login
            loggedInClients_Roles.insert(socket, userObject.value("role").toString());
            loggedInClients_Names.insert(socket, userObject.value("username").toString());
            QByteArray responseData = "";
            responseData += "Login successful.";
            socket->write(responseData);
            qDebug() << "Login successful. User:" << username;
            return;
        }
    }

    // Failed login
    qDebug() << "Login failed. Invalid username or password.";
}

void Server::handleGetAccountNumber(QTcpSocket *socket) {



        QString username = loggedInClients_Names.find(socket).value();
        QJsonArray users = userDatabase.value("users").toArray();
        for (const QJsonValue &userValue : users) {

            QJsonObject userObject = userValue.toObject();

            if (userObject.value("username").toString() == username) {

                QString accountNum = userObject.value("account_number").toString();
                QByteArray responseData = "Number: " ;
                responseData += accountNum.toUtf8() ;
                socket->write(responseData);
                return;

            }

        }

        QByteArray responseData = "Username Not found";
        socket->write(responseData);

}


void Server::handleLogout(QTcpSocket *socket) {
    // Remove the client from the list of logged-in clients upon logout
    if (loggedInClients_Roles.contains(socket)) {
        loggedInClients_Roles.remove(socket);
        loggedInClients_Names.remove(socket);
        qDebug() << "Logout successful.";
    }
}

bool Server::isLoggedIn(QTcpSocket *socket) {
    // Check if the given socket is logged in
    return loggedInClients_Roles.contains(socket);
}
