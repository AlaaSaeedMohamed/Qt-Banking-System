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

    Client client;

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

    return a.exec();
}
