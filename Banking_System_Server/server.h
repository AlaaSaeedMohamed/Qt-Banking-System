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
        qDebug() << socket;
        connect(socket, &QTcpSocket::readyRead, this, &Server::readRequest);
        connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
        connect(socket, &QTcpSocket::disconnected, this, [=]() { handleLogout(socket); });
    }
    bool handleLogin(QTcpSocket *socket, const QString username, const QString password, QJsonArray usersArray);
    void handleLogout(QTcpSocket *socket);
    bool isLoggedIn(QTcpSocket *socket);
    void readRequest();
    void handleGetAccountNumber(QTcpSocket *socket);
    void handleGetAccountNumberAdmin(QTcpSocket *socket, QString username);
    void handleGetBalance(QTcpSocket *socket);
    void handleGetBalanceAdmin(QTcpSocket *socket, QString accountNum);
    void handleGetTransactionHisory(QTcpSocket *socket, int count);
    void handleMakeTransaction(QTcpSocket *socket, int amount);
    void handleGetTransactionHisoryAdmin(QTcpSocket *socket, QString accountNum, int count);
    void handleTransfer(QTcpSocket *socket, QString toAcc, int amount);
    void getBankDB();
    void createUser();
    void handleUpdateUser(QTcpSocket *socket,const QByteArray &requestData);
    void handleDeleteUser(QTcpSocket *socket,const QByteArray &requestData);
    void parseJSONFromRequest(const QByteArray &requestData, QJsonObject &jsonObject);
    void saveUserDatabaseToFile();
private:
    void handleGetRequest(QTcpSocket *socket, const QByteArray &requestData);
    void handlePostRequest(QTcpSocket *socket, const QByteArray &requestData);

    void sendJsonResponse(QTcpSocket *clientSocket, const QJsonObject &jsonObject) {
        QJsonDocument jsonResponse(jsonObject);
        sendResponse(clientSocket, jsonResponse.toJson());
    }

    void sendResponse(QTcpSocket *clientSocket, const QByteArray &data) {
        clientSocket->write(data);
        clientSocket->flush();
        clientSocket->waitForBytesWritten();
        //clientSocket->disconnectFromHost();
    }

private:
    QTcpServer server;
    QMap<QTcpSocket*, QString> loggedInClients_Roles; // Map of logged-in clients with their roles
    QMap<QTcpSocket*, QString> loggedInClients_Names; // Map of logged-in clients with their usernames
    QJsonObject userDatabase; // JSON object representing the user database
    QJsonDocument JsonDoc;

    void handleLogin(QTcpSocket *socket, const QString &username, const QString &password);
};

#endif // SERVER_H
