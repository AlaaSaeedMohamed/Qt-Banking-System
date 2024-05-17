#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

class databaseHandler :  public QObject
{
    Q_OBJECT
public:
    databaseHandler();
    void saveUserDatabaseToFile();
    void DB();

    QJsonObject userDatabase; // JSON object representing the user database
    QJsonDocument JsonDoc;
};

#endif // DATABASEHANDLER_H
