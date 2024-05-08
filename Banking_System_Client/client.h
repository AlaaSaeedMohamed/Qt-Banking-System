#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonDocument>
#include <QEventLoop>
class Client : public QObject
{
    Q_OBJECT
public:
    Client();
    ~Client();

signals:

public slots:
    void connectToHost(QString hostname, quint16 port);
    void get(QString path);
    void post(QString path, QByteArray data);
    void put(QString path, QByteArray data);
    void deleteReq(QString path, QByteArray data);
    void login(QString username, QString password);
    void getAccountNumber();
    void getAccountBalance();
    void getTransactionHistory(int count);
    void getAccountNumber_Admin(QString username);
    void getAccountBalance_Admin(QString accountNumber);
    void getTransactionHistory_Admin(QString accountNum, int count);
    void makeTransaction(int amount);
    void transferAmount(QString toAccNum, int amount);
    void viewBankDatabase();
    void createUser(QString userData);
    void updateUser(QString accountNumber, QString userData);
    void deleteUser(QString accountNumber);
private slots:
    void Connected();
    void disconnected();
    void errorOccurred(QAbstractSocket::SocketError socketError);
    void hostFound();
    void stateChanged(QAbstractSocket::SocketState socketState);
    void disconnect();
    void readyRead();

private:
    QTcpSocket *socket;
};

#endif // CLIENT_H
