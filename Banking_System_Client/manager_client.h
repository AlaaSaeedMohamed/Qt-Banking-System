#ifndef MANAGER_CLIENT_H
#define MANAGER_CLIENT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonDocument>
class Manager_Client : public QObject
{
    Q_OBJECT
public:
    Manager_Client();

public slots:
    void get(QString path);
    void post(QString path, QByteArray data);
    void put(QString path, QByteArray data);
    void login(QString username, QString password);
private slots:
    void readyRead();
    void encrypted(QNetworkReply *reply);
    void finished(QNetworkReply *reply);
    void handleNetworkData(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
};


#endif // MANAGER_CLIENT_H
