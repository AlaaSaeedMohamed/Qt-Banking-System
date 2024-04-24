#include "client.h"
#include <QObject>
Client::Client() {

    socket = new QTcpSocket;
    connect(socket,&QAbstractSocket::connected,this,&Client::Connected);
    connect(socket,&QAbstractSocket::disconnected,this,&Client::disconnected);
    connect(socket,&QAbstractSocket::hostFound,this,&Client::hostFound);
    connect(socket,&QAbstractSocket::errorOccurred,this,&Client::errorOccurred);
    connect(socket,&QAbstractSocket::stateChanged,this,&Client::stateChanged);
    connect(socket,&QAbstractSocket::readyRead,this,&Client::readyRead);

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
