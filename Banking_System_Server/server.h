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
#include <QThreadPool>

class Server : public QTcpServer

{
    Q_OBJECT
public:
    Server(QObject *parent);
    ~Server();
protected:
    void incomingConnection(qintptr handle) override;

    QThreadPool* pool;
    QMutex *mutex;

};

#endif // SERVER_H
