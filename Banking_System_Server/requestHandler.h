#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <QObject>
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
#include <QThreadPool>
#include "databasehandler.h"
class Handler : public QObject

{
    Q_OBJECT
public:
    Handler(QMutex *mutex);
    ~Handler();


private slots:
    bool isLoggedIn(QTcpSocket *socket);
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
    void handleLogin(QTcpSocket *socket, const QString &username, const QString &password);
    void handleGetRequest(QTcpSocket *socket, const QByteArray &requestData);
    void handlePostRequest(QTcpSocket *socket, const QByteArray &requestData);
    void sendJsonResponse(QTcpSocket *clientSocket, const QJsonObject &jsonObject);
    void sendResponse(QTcpSocket *clientSocket, const QByteArray &data);
public:
    void handleLogout(QTcpSocket *socket);
    void handleRequest(QTcpSocket *socket, const QByteArray &requestData);
private:
    QMap<QTcpSocket*, QString> loggedInClients_Roles; // Map of logged-in clients with their roles
    QMap<QTcpSocket*, QString> loggedInClients_Names; // Map of logged-in clients with their usernames
    databaseHandler *dbHandler;
    QMutex *mutex;

};

#endif // REQUESTHANDLER_H
