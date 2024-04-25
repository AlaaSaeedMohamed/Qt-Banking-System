#include "client.h"
#include <QObject>
Client::Client() {

    socket = new QTcpSocket;
    connect(socket,&QAbstractSocket::connected,this,&Client::Connected);
    connect(socket,&QAbstractSocket::disconnected,this,&Client::disconnected);
    connect(socket,&QAbstractSocket::hostFound,this,&Client::hostFound);
    connect(socket,&QAbstractSocket::errorOccurred,this,&Client::errorOccurred);
    connect(socket,&QAbstractSocket::stateChanged,this,&Client::stateChanged);
    //connect(socket,&QAbstractSocket::readyRead,this,&Client::readyRead);

}

Client:: ~Client()
{
    delete socket;
}
void Client::connectToHost(QString hostname, quint16 port)
{
    if(socket->isOpen())    disconnect();
    qInfo() << "Trying to connect to " << hostname << " on port " << port;
    socket->connectToHost(hostname, port);
}

void Client::Connected()
{
    qInfo() << "Connected to Host";

    QByteArray data;

    data.append("GET / HTTP/1.1\r\n");
    data.append("Host: mshmae.pythonanywhere.com\r\n");
    // data.append("Connection: Close \r\n");
    data.append("\r\n");

    // socket->write(data);
}

void Client::disconnected()
{
    qInfo() << "Connection Closed...";
}

void Client::errorOccurred(QAbstractSocket::SocketError socketError)
{
    qInfo() << "Error: " << socketError << " " << socket->errorString();
}

void Client::hostFound()
{
    qInfo() << "Server Host is Found";

}

void Client::stateChanged(QAbstractSocket::SocketState socketState)
{
    qInfo() << "State: " << socketState;
}

void Client::disconnect()
{
    socket->close();
    socket->waitForDisconnected();   //to make it synchronous
}

void Client::readyRead()
{
    qInfo() << "Reading Data from Server";
    qInfo() << "Data: " << socket->readAll();
}


void Client::get(QString path)
{

    //manager->get(QNetworkRequest(QUrl(path)));

    QString getRequest = "GET " + path + " HTTP/1.1\r\nHost: 192.168.1.14:22\r\n\r\n";
    socket->write(getRequest.toUtf8());

    connect(socket, &QTcpSocket::readyRead, this, &Client::handleGetResponse);

}

void Client::handleGetResponse() {
    // Read GET response
    QByteArray responseData = socket->readAll();
    qDebug() << "GET response:" << responseData;

    // Disconnect from readyRead signal to avoid processing GET response again
    QObject::disconnect(socket, &QTcpSocket::readyRead, this, &Client::handleGetResponse);
}


void Client::post(QString path, QByteArray data)
{
    QUrl url = QUrl(path);
    QNetworkRequest request(path);

    // request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // QNetworkReply *reply = manager->post(request, data);

    // connect(reply, &QNetworkReply::readyRead, this, &Client::readyRead);

}

void Client::login(QString username, QString password)
{
    QString path = "http://192.168.1.14:22/login";

    //socket->connectToHost("192.168.1.14", 22);
    // QNetworkRequest request(path);

    // request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject obj;
    obj["username"] = username;
    obj["password"] = password;
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();

    // QNetworkReply *reply = manager->post(request, data);

    //const char* postData = "key1=value1&key2=value2";
    QString request = "POST "+ path + "HTTP/1.1\r\n";
    request += "Host: 192.168.1.14:22\r\n";
    request += "Content-Type: application/application/json\r\n";
    request += "Content-Length: " + std::to_string(strlen(data)) + "\r\n";
    request += "\r\n";
    request += data;

    qDebug() << request;

    socket->write(request.toUtf8());
    connect(socket, &QTcpSocket::readyRead, this, &Client::handleLoginResponse);
    // connect(reply, &QNetworkReply::readyRead, this, &Manager_Client::handleLoginResponse);
    // connect(reply, &QNetworkReply::readyRead, this, &Manager_Client::readyRead);

}

void Client::handleLoginResponse() {
    // QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    // if (reply->error() == QNetworkReply::NoError) {
    //     qDebug() << "bla";
    //     emit loginCompleted(); // Emit signal indicating login is completed
    // } else {
    //     // Login failed
    //     qDebug() << "Login failed:" << reply->errorString();
    // }

    QByteArray responseData = socket->readAll();
    qDebug() << "Login response:" << responseData;

    emit loginCompleted();
    // Disconnect from readyRead signal to avoid processing login response again
    QObject::disconnect(socket, &QTcpSocket::readyRead, this, &Client::handleLoginResponse);
    //reply->deleteLater();
}

void Client::put(QString path, QByteArray data)
{
    QNetworkRequest request(path);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //manager->put(request, data);
}
