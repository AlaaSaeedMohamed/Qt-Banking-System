#include "databasehandler.h"

databaseHandler::databaseHandler() {
    DB();
}

void databaseHandler::saveUserDatabaseToFile()
{
    QFile outFile("/home/alaasaeed/test/users.json");
    if (!outFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qDebug() << "Failed to open output file.";
        return;
    }
    QJsonDocument updatedDoc(userDatabase);
    outFile.write(updatedDoc.toJson());
    outFile.close();
}

void databaseHandler::DB()
{
    QFile file("/home/alaasaeed/test/users.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open user database file";
        return;
    }
    QByteArray data = file.readAll();
    file.close();

    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &jsonError);
    if (jsonError.error != QJsonParseError::NoError) {
        qDebug() << "Error parsing JSON:" << jsonError.errorString();
        return;
    }

    userDatabase = jsonDoc.object();
    JsonDoc = jsonDoc;
}
