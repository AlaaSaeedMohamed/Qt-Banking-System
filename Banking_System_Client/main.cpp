// #include <QtNetwork>
#include <QCoreApplication>
#include <QDebug>
#include "client.h"
#include <QThread>
#include <iostream>
#include <QTextStream>
#include <QFile>
using namespace std;



int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QFile file("D:/ITIDA/C++/ITIDA_PRO/manual.txt");

    QTextStream in(stdin);

    // QThread thread;

    Client client;

    // client.moveToThread(&thread);
    // thread.start();

    client.connectToHost("192.168.1.14",22);

    qDebug() << "welcome to banking app, type 'help' to print the manual. ";

    while(true)
    {
        qDebug() << "bank>> ";

        QString command = in.readLine();

        QStringList words = command.split(" ");

        int numberOfArguments = words.size() - 1;

        if(command.contains("login") && numberOfArguments == 2)
        {
            client.login(words.at(1),words.at(2));
        }
        else if(command.contains("help") && numberOfArguments == 0)
        {

                if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                {
                    qDebug() << "Failed to open the file.";
                    return 1;
                }

                // Read the file line by line
                QTextStream in(&file);
                while (!in.atEnd())
                {
                    QString line = in.readLine();

                    // Remove newline and carriage return characters
                    line.remove("\n");
                    line.remove("\r");

                    // Display the line
                    qDebug().noquote() << line;
                }

                // Close the file
                file.close();

        }
        else if(command.contains("accountnumber") && numberOfArguments == 1)
        {
            qDebug() << "hhh";
            client.getAccountNumber_Admin(words.at(1));
        }
        else if(command.contains("accountnumber") && numberOfArguments == 0)
        {
            client.getAccountNumber();
        }
        else if(command.contains("accountbalance") && numberOfArguments == 1)
        {

            client.getAccountBalance_Admin(words.at(1));
        }
        else if(command.contains("accountbalance") && numberOfArguments == 0)
        {
            client.getAccountBalance();
        }
        else if(command.contains("bankDB") && numberOfArguments == 0)
        {
            client.viewBankDatabase();
        }
        else if(command.contains("createUser") && numberOfArguments == 3)
        {
            QJsonObject obj;
            obj["username"] = words.at(1);
            obj["password"] = words.at(2);
            obj["accountnumber"] = words.at(3);
            obj["role"] = "user";
            QJsonDocument doc(obj);
            QByteArray data = doc.toJson();
            client.createUser(data);
        }
        else if(command.contains("updateUser") && numberOfArguments != 0 && numberOfArguments != 1 && numberOfArguments != 4)
        {
            QJsonObject obj;
            if(numberOfArguments == 2)
            {
                obj["username"] = words.at(2);
            }
            else if(numberOfArguments == 3)
            {
                obj["username"] = words.at(2);
                obj["password"] = words.at(3);
            }
            QJsonDocument doc(obj);
            QByteArray data = doc.toJson();
            client.updateUser(words.at(1), data);
        }
        else if(command.contains("deleteUser") && numberOfArguments == 1)
        {
            client.deleteUser(words.at(1));
        }
        else if(command.contains("transactions") && numberOfArguments == 2)
        {
            client.getTransactionHistory_Admin(words.at(1), words.at(2).toInt());
        }
        else if(command.contains("transactions") && numberOfArguments == 1)
        {
            client.getTransactionHistory(words.at(1).toInt());
        }
        else if(command.contains("makeTransaction") && numberOfArguments == 1)
        {
            client.makeTransaction(words.at(1).toInt());
        }
        else if(command.contains("transfer") && numberOfArguments == 2)
        {
            client.transferAmount(words.at(1), words.at(2).toInt());
        }
        else{
            qDebug() << "invalid command, type 'help' to print the manual";
        }
    }

    // thread.wait();

    // Split the line into words
    // QStringList words = line.split(" ");

    // out << "Words in the line: " << "\n";
    // for (const QString &word : words) {
    //     // Skip empty strings
    //     if (!word.isEmpty())
    //         out << word << "\n";
    // }
    // out.flush();
    // Client client;
    // Client client2;

    // QThread thread1;
    // QThread thread2;

    // client.moveToThread(&thread1);
    // client2.moveToThread(&thread2);


    // // client2.connectToHost("192.168.1.14",22);

    // QObject::connect(&thread1, &QThread::started, [&]() {
    //     client.connectToHost("192.168.1.14",22);
    //     client.login("user2", "password12");
    //     // client.transferAmount("A005", 100);
    // });

    // QObject::connect(&thread2, &QThread::started, [&]() {
    //     client2.connectToHost("192.168.1.14",22);
    //     client2.login("user1", "password123");
    //     // client2.getTransactionHistory(10);
    // });


    // // Start the thread
    // thread1.start();
    // // Start the thread
    // thread2.start();

    // // Wait for the thread to finish
    // thread1.wait();
    // thread2.wait();
    // client.login("user2", "password12");
    // client.transferAmount("A005", 100);
    // client2.login("user2", "password12");

    // client2.getTransactionHistory(10);
    // client.getTransactionHistory_Admin("A005", 4);

    //client.getAccountNumber("http://192.168.1.14:22/accountNumber");
    //client.getAccountNumber_Admin("http://192.168.1.14:22/accountNumberAdmin", "user2");

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


    //client.getAccountNumber_Admin("user1");

    // QString Data = "{\n";
    // Data.append("\t\"username\": \"user4\",\n");
    // Data.append("\t\"password\": \"password12\",\n");
    // Data.append("\t\"role\": \"user\",\n");
    // Data.append("\t\"accountnumber\": \"A005\"\n");
    // Data.append("}");

    // client.updateUser("A002", Data);
    // client.deleteUser("A004");

    // // client.viewBankDatabase();

    // client.makeTransaction(-200);


    //  client.createUser(Data);
    // client.getAccountBalance();
    // client.getAccountBalance_Admin("A003");
    return a.exec();
}
