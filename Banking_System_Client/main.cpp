#include <QtNetwork>
#include <QCoreApplication>
#include <QDebug>
#include "client.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    Client client;
    //Manager_Client m_client;
    //Manager_Client m_client2;

    // Send GET request
    // m_client.get("http://192.168.1.14:22/get");


    // Send POST request
    //m_client.post("http://192.168.1.14:22", data);
    //Client client;
    client.connectToHost("192.168.1.14",22);
    //client.getAccountNumber("http://192.168.1.14:22/accountNumber");
    //client.getAccountNumber_Admin("http://192.168.1.14:22/accountNumberAdmin", "user2");

    client.login("user4", "password12");
    //client.getAccountNumber_Admin("user1");

    QString Data = "{\n";
    Data.append("\t\"username\": \"user4\",\n");
    Data.append("\t\"password\": \"password12\",\n");
    Data.append("\t\"role\": \"user\",\n");
    Data.append("\t\"accountnumber\": \"A005\"\n");
    Data.append("}");

    // client.updateUser("A002", Data);
    // client.deleteUser("A004");

    // // client.viewBankDatabase();


    //  client.createUser(Data);
    client.getAccountBalance();

    // QObject::connect(&client, &Client::loginCompleted, [&client]() {
    //     // After the POST request is completed, send the GET request
    //     // client.getAccountNumber();
    //     // client.getAccountNumber_Admin("user2");
    //     client.viewBankDatabase();
    // });

    // QString str = R"({"ID":"001","account_number":"A001","password":"password123","role":"admin","username":"user1"})";

    // QJsonParseError error;
    // QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8(), &error);
    // if (doc.isNull()) {
    //     qDebug() << "Failed to parse JSON:" << error.errorString();
    //     return -1;
    // }

    // QJsonObject jsonObject = doc.object();

    // qDebug() << jsonObject;

    return a.exec();
}
