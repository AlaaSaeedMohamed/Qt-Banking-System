#include "client.h"
#include <QObject>
Client::Client() {

    socket = new QTcpSocket;
    connect(socket,&QAbstractSocket::connected,this,&Client::Connected);
    connect(socket,&QAbstractSocket::disconnected,this,&Client::disconnected);
    connect(socket,&QAbstractSocket::hostFound,this,&Client::hostFound);
    connect(socket,&QAbstractSocket::errorOccurred,this,&Client::errorOccurred);
    connect(socket,&QAbstractSocket::stateChanged,this,&Client::stateChanged);
    connect(socket, &QTcpSocket::readyRead, this, &Client::readyRead);

}

Client:: ~Client()
{
    delete socket;
}
void Client::connectToHost(QString hostname, quint16 port)
{
    if(socket->isOpen())    disconnect();
    qInfo() << "Trying to connect to " << hostname << " on port " << port;
    socket->connectToHost(hostname, port);
}

void Client::Connected()
{
    qInfo() << "Connected to Host";
}

void Client::disconnected()
{
    qInfo() << "Connection Closed...";
}

void Client::errorOccurred(QAbstractSocket::SocketError socketError)
{
    qInfo() << "Error: " << socketError << " " << socket->errorString();
}

void Client::hostFound()
{
    qInfo() << "Server Host is Found";

}

void Client::stateChanged(QAbstractSocket::SocketState socketState)
{
    qInfo() << "State: " << socketState;
}

void Client::disconnect()
{
    socket->close();
    socket->waitForDisconnected();   //to make it synchronous
}

void Client::readyRead()
{
    QByteArray data = socket->readAll();
    QTextStream in(&data);
    while (!in.atEnd())
    {
        QString line = in.readLine();

        // Remove newline and carriage return characters
        line.remove("\n");
        line.remove("\r");

        // Display the line
        qDebug().noquote() << line;
    }
    // qInfo() << "Data: " << socket->readAll();
}


void Client::get(QString path)
{
    QString getRequest = "GET " + path + " HTTP/1.1\r\nHost: 192.168.1.14:22\r\n\r\n";
    socket->write(getRequest.toUtf8());
    socket->waitForReadyRead();

}

void Client::getAccountNumber_Admin(QString username)
{
    QJsonObject obj;
    obj["username"] = username;
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();
    post("http://192.168.1.14:22/accountNumberAdmin", data);
}

void Client::getAccountBalance_Admin(QString accountNumber)
{
    QJsonObject obj;
    obj["accountnumber"] = accountNumber;
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();
    post("http://192.168.1.14:22/accountBalanceAdmin", data);
}

void Client::getTransactionHistory_Admin(QString accountnumber, int count)
{
    QJsonObject obj;
    obj["accountnumber"] = accountnumber;
    obj["count"] = count;
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();
    post("http://192.168.1.14:22/THAdmin", data);
}

void Client::makeTransaction(int amount)
{
    QJsonObject obj;
    obj["amount"] = amount;
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();
    post("http://192.168.1.14:22/makeT", data);
}

void Client::getAccountNumber()
{
    get("http://192.168.1.14:22/accountNumber");
}

void Client::getAccountBalance()
{
    get("http://192.168.1.14:22/accountBalance");
}

void Client::getTransactionHistory(int count)
{
    QJsonObject obj;
    obj["count"] = count;
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();
    post("http://192.168.1.14:22/TransactionHistory", data);
}
void Client::viewBankDatabase()
{
    get("http://192.168.1.14:22/BankDB");
}

void Client::transferAmount(QString toAccNum, int amount)
{
    QJsonObject obj;
    obj["amount"] = amount;
    obj["toaccountnumber"] = toAccNum;
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();
    post("http://192.168.1.14:22/Transfer", data);
}



void Client::createUser(QString userData)
{
    QString path = "http://192.168.1.14:22/createUser";

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(userData.toUtf8(), &error);

    if (doc.isNull()) {
        qDebug() << "Failed to parse JSON:" << error.errorString();
        return;
    }

    post(path, doc.toJson());

}


void Client::updateUser(QString accountNumber, QString userData)
{
    QString path = "http://192.168.1.14:22/updateUser";

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(userData.toUtf8(), &error);
    if (doc.isNull()) {
        qDebug() << "Failed to parse JSON:" << error.errorString();
        return;
    }

    QJsonObject jsonObject = doc.object();

    // Merge the QJsonObjects
    QJsonObject mergedObject = jsonObject;
    mergedObject.insert("accountnumber", accountNumber);


    // Convert the merged QJsonObject back to a JSON string
    QJsonDocument mergedDoc(mergedObject);
    qDebug() << mergedDoc;

    put(path, mergedDoc.toJson());

}


void Client::deleteUser(QString accountNumber)
{
    QString path = "http://192.168.1.14:22/deleteUser";

    QJsonObject jsonObject;
    jsonObject.insert("accountnumber", accountNumber);

    QJsonDocument doc(jsonObject);

    deleteReq(path, doc.toJson());

}


void Client::post(QString path, QByteArray data)
{
    QString request = "POST "+ path + "HTTP/1.1\r\n";
    request += "Host: 192.168.1.14:22\r\n";
    request += "Content-Type: application/application/json\r\n";
    request += "Content-Length: " + std::to_string(strlen(data)) + "\r\n";
    request += "\r\n";
    request += data;

    socket->write(request.toUtf8());

    socket->waitForReadyRead();
}

void Client::login(QString username, QString password)
{
    QString path = "http://192.168.1.14:22/login";

    QJsonObject obj;
    obj["username"] = username;
    obj["password"] = password;
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();

    post(path, data);

}

void Client::put(QString path, QByteArray data)
{
    QString request = "PUT "+ path + "HTTP/1.1\r\n";
    request += "Host: 192.168.1.14:22\r\n";
    request += "Content-Type: application/application/json\r\n";
    request += "Content-Length: " + std::to_string(strlen(data)) + "\r\n";
    request += "\r\n";
    request += data;

    socket->write(request.toUtf8());

    socket->waitForReadyRead();
}

void Client::deleteReq(QString path, QByteArray data)
{
    QString request = "DELETE "+ path + "HTTP/1.1\r\n";
    request += "Host: 192.168.1.14:22\r\n";
    request += "Content-Type: application/application/json\r\n";
    request += "Content-Length: " + std::to_string(strlen(data)) + "\r\n";
    request += "\r\n";
    request += data;

    socket->write(request.toUtf8());
    socket->waitForReadyRead();
}
