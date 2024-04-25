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
    void loginCompleted(); // Signal emitted when login is completed
public slots:
    void connectToHost(QString hostname, quint16 port);
    void get(QString path);
    void post(QString path, QByteArray data);
    void put(QString path, QByteArray data);
    void login(QString username, QString password);
private slots:
    void Connected();
    void disconnected();
    void errorOccurred(QAbstractSocket::SocketError socketError);
    void hostFound();
    void stateChanged(QAbstractSocket::SocketState socketState);
    void disconnect();
    void readyRead();
    void handleLoginResponse();
    void handleGetResponse();



private:
    QTcpSocket *socket;
};

#endif // CLIENT_H
