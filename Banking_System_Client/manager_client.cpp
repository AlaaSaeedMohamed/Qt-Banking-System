#include "manager_client.h"

Manager_Client::Manager_Client() {

    manager = new QNetworkAccessManager;
    connect(manager, &QNetworkAccessManager::encrypted, this, &Manager_Client::encrypted);
    connect(manager, &QNetworkAccessManager::finished, this, &Manager_Client::finished);

}

void Manager_Client::get(QString path)
{

    //manager->get(QNetworkRequest(QUrl(path)));

    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(path)));

    connect(reply, &QNetworkReply::readyRead, this, &Manager_Client::readyRead);

}

void Manager_Client::handleNetworkData(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        qDebug() << "Response from server:" << responseData;
    } else {
        qDebug() << "Error:" << reply->errorString();
    }
    //qApp->quit();
}

void Manager_Client::post(QString path, QByteArray data)
{
    QUrl url = QUrl(path);
    QNetworkRequest request(path);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = manager->post(request, data);

    connect(reply, &QNetworkReply::readyRead, this, &Manager_Client::readyRead);

}

void Manager_Client::login(QString username, QString password)
{
    QString path = "http://192.168.1.14:22/login";

    QNetworkRequest request(path);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject obj;
    obj["username"] = username;
    obj["password"] = password;
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();

    QNetworkReply *reply = manager->post(request, data);

    connect(reply, &QNetworkReply::readyRead, this, &Manager_Client::readyRead);

}

void Manager_Client::put(QString path, QByteArray data)
{
    QNetworkRequest request(path);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    manager->put(request, data);
}

void Manager_Client::readyRead()
{
    qInfo() << "Reading Data from server";
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        qDebug() << "Response from server:" << responseData;
    } else {
        qDebug() << "Error:" << reply->errorString();
    }
    //qApp
}

void Manager_Client::encrypted(QNetworkReply *reply)
{
    qInfo() << "Connection is encrypted";
}

void Manager_Client::finished(QNetworkReply *reply)
{
    qInfo() << "Reply finished";
}
