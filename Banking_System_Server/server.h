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
#include <QCoreApplication>
#include <QThread>
#include <QMutex>
class Server : public QTcpServer

{
    Q_OBJECT
public:
    Server(QObject *parent);

protected:
    void incomingConnection(qintptr handle) override;


private slots:
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
    void createUser(QTcpSocket *socket,const QByteArray &requestData);
    void handleUpdateUser(QTcpSocket *socket,const QByteArray &requestData);
    void handleDeleteUser(QTcpSocket *socket,const QByteArray &requestData);
    void parseJSONFromRequest(const QByteArray &requestData, QJsonObject &jsonObject);
    void saveUserDatabaseToFile();
    void handleLogin(QTcpSocket *socket, const QString &username, const QString &password);

private:
    void handleGetRequest(QTcpSocket *socket, const QByteArray &requestData);
    void handlePostRequest(QTcpSocket *socket, const QByteArray &requestData);
    void sendJsonResponse(QTcpSocket *clientSocket, const QJsonObject &jsonObject);
    void sendResponse(QTcpSocket *clientSocket, const QByteArray &data);
    void handleRequest(QTcpSocket *socket, const QByteArray &requestData);

    QTcpServer server;
    QMap<QTcpSocket*, QString> loggedInClients_Roles; // Map of logged-in clients with their roles
    QMap<QTcpSocket*, QString> loggedInClients_Names; // Map of logged-in clients with their usernames
    QJsonObject userDatabase; // JSON object representing the user database
    QJsonDocument JsonDoc;
    QMutex mutex;

};

#endif // SERVER_H
