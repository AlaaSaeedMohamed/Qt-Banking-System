#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>
#include <QJsonArray>
#include  <QCoreApplication>

class Server : public QObject
{
    //Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

protected:


private slots:
    void newConnection() {
        QTcpSocket *socket = server.nextPendingConnection();
        //QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
        connect(socket, &QTcpSocket::readyRead, this, &Server::readRequest);
        connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
        connect(socket, &QTcpSocket::disconnected, this, [=]() { handleLogout(socket); });
    }
    bool handleLogin(QTcpSocket *socket, const QString username, const QString password, QJsonArray usersArray);
    void handleLogout(QTcpSocket *socket);
    bool isLoggedIn(QTcpSocket *socket);
    void readRequest();
    void handleGetAccountNumber(QTcpSocket *socket);

private:
    void handleGetRequest(QTcpSocket *clientSocket) {
        // Define your endpoint logic for GET requests here
        // For example, you can send back a JSON response
        QJsonObject jsonResponse;
        jsonResponse["message"] = "Hello from GET endpoint!";
        sendJsonResponse(clientSocket, jsonResponse);
    }

    void handlePostRequest(QTcpSocket *clientSocket) {
        // Define your endpoint logic for POST requests here
        // For example, you can parse the POST data and send back a response
        // For simplicity, let's echo back the POST data
        QByteArray postData = clientSocket->readAll();
        sendResponse(clientSocket, postData);
    }

    void sendJsonResponse(QTcpSocket *clientSocket, const QJsonObject &jsonObject) {
        QJsonDocument jsonResponse(jsonObject);
        sendResponse(clientSocket, jsonResponse.toJson());
    }

    void sendResponse(QTcpSocket *clientSocket, const QByteArray &data) {
        clientSocket->write(data);
        clientSocket->flush();
        //clientSocket->waitForBytesWritten();
        clientSocket->disconnectFromHost();
    }

private:
    QTcpServer server;
    QMap<QTcpSocket*, QString> loggedInClients_Roles; // Map of logged-in clients with their roles
    QMap<QTcpSocket*, QString> loggedInClients_Names; // Map of logged-in clients with their usernames
    QJsonObject userDatabase; // JSON object representing the user database

    void handleLogin(QTcpSocket *socket, const QString &username, const QString &password);
};

#endif // SERVER_H
