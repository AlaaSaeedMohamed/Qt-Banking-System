#include "requestHandler.h"

Handler::Handler(QMutex *mutex) {

    this->mutex = mutex;
    dbHandler = new databaseHandler();
}

Handler::~Handler()
{
    delete dbHandler;
}


void Handler::sendJsonResponse(QTcpSocket *clientSocket, const QJsonObject &jsonObject)
{
    QJsonDocument jsonResponse(jsonObject);
    sendResponse(clientSocket, jsonResponse.toJson());
}

void Handler::sendResponse(QTcpSocket *clientSocket, const QByteArray &data) {
    clientSocket->write(data);
    clientSocket->flush();
    clientSocket->waitForBytesWritten();
    //clientSocket->disconnectFromHost();
}

void Handler::handleRequest(QTcpSocket *socket, const QByteArray &requestData) {

    mutex->lock();

    // Parse the request
    QString requestString(requestData);
    if (requestString.startsWith("POST")) {
        handlePostRequest(socket, requestData);
    }
    else if(requestString.startsWith("GET"))
    {
        handleGetRequest(socket,requestData);
    }
    else if(requestString.startsWith("PUT"))
    {
        if(requestString.contains("updateUser"))
        {
            if(loggedInClients_Roles.find(socket).value() == "admin")
            {
                handleUpdateUser(socket,requestData);
            }
            else{
                QByteArray responseData = "Not Authorized";
                sendResponse(socket, responseData);
            }
        }
    }
    else if(requestString.startsWith("DELETE"))
    {
        if(requestString.contains("deleteUser"))
        {
            if(loggedInClients_Roles.find(socket).value() == "admin")
            {
                handleDeleteUser(socket,requestData);
            }
            else{
                QByteArray responseData = "Not Authorized";
                sendResponse(socket, responseData);
            }
        }
    }
    else {
        qDebug() << "Unsupported request";
        // Respond with an error message or HTTP 400 Bad Request
    }
    mutex->unlock();

}

void Handler::handlePostRequest(QTcpSocket *socket, const QByteArray &requestData) {
    QJsonObject jsonObject;
    parseJSONFromRequest(requestData, jsonObject);

    if (jsonObject.isEmpty()) {
        // Handle empty or invalid JSON
        return;
    }

    if (requestData.contains("login")) {
        // Handle login request
        QString username = jsonObject["username"].toString();
        QString password = jsonObject["password"].toString();
        handleLogin(socket, username, password);
    } else {
        if(isLoggedIn(socket))
        {
            if ((requestData.contains("createUser")) && (loggedInClients_Roles.find(socket).value() == "admin")) {

                createUser(socket,requestData);

            } else if ((requestData.contains("accountNumberAdmin")) && (loggedInClients_Roles.find(socket).value() == "admin")) {

                handleGetAccountNumberAdmin(socket,jsonObject["username"].toString());

            }
            else if ((requestData.contains("accountBalanceAdmin")) && (loggedInClients_Roles.find(socket).value() == "admin")) {

                handleGetBalanceAdmin(socket,jsonObject["accountnumber"].toString());

            }
            else if (requestData.contains("TransactionHistory") && (loggedInClients_Roles.find(socket).value() == "user")) {

                handleGetTransactionHisory(socket,jsonObject["count"].toInt());

            }
            else if ((requestData.contains("THAdmin")) && (loggedInClients_Roles.find(socket).value() == "admin")) {

                handleGetTransactionHisoryAdmin(socket, jsonObject["accountnumber"].toString() ,jsonObject["count"].toInt());

            }
            else if ((requestData.contains("makeT")) && (loggedInClients_Roles.find(socket).value() == "user")) {

                handleMakeTransaction(socket, jsonObject["amount"].toInt());

            }
            else if ((requestData.contains("Transfer")) && (loggedInClients_Roles.find(socket).value() == "user")) {

                handleTransfer(socket,jsonObject["toaccountnumber"].toString(), jsonObject["amount"].toInt());

            }
            else{
                QByteArray responseData = "Not Authorized";
                sendResponse(socket, responseData);
            }
        }
        else{
            QByteArray responseData = "You have to be loggedd in!";
            sendResponse(socket, responseData);
        }
    }
}

void Handler::handleGetRequest(QTcpSocket *socket, const QByteArray &requestData) {

    if(isLoggedIn(socket))
    {

        if((requestData.contains("accountNumber")) && (loggedInClients_Roles.find(socket).value() == "user"))
        {

            handleGetAccountNumber(socket);

        }
        else if((requestData.contains("BankDB")) && (loggedInClients_Roles.find(socket).value() == "admin"))
        {
            dbHandler->DB();
            sendResponse(socket, dbHandler->JsonDoc.toJson());

        }
        else if((requestData.contains("accountBalance")) && (loggedInClients_Roles.find(socket).value() == "user"))
        {
            handleGetBalance(socket);
        }
        else if(requestData.contains("Logout"))
        {
            handleLogout(socket);
        }
        else{
            QByteArray responseData = "Not Authorized";
            sendResponse(socket, responseData);
        }
    }
    else {
        QByteArray responseData = "you have to llogin first";
        sendResponse(socket, responseData);

    }
}


void Handler::createUser(QTcpSocket *socket,const QByteArray &requestData)
{
    QJsonObject jsonObject;
    parseJSONFromRequest(requestData, jsonObject);

    if (jsonObject.isEmpty()) {
        // Handle empty or invalid JSON
        return;
    }
    QJsonArray Userstable = dbHandler->userDatabase.value("users").toArray();
    QJsonArray Accountstable = dbHandler->userDatabase.value("accounts").toArray();
    foreach (const QJsonValue &value, Userstable) {

        if (value.toObject().value("username") == jsonObject["username"] ||
            value.toObject().value("accountnumber") == jsonObject["accountnumber"]) {

            QByteArray responseData = "Incoming data already exists in the document.";
            sendResponse(socket, responseData);
            return;
        }
    }

    // If the incoming data does not already exist, add it to the specific table
    QJsonObject  account;
    account.insert("accountnumber",jsonObject.value("accountnumber"));
    account.insert("balance",0);
    Userstable.append(jsonObject);
    dbHandler->userDatabase["users"] = Userstable;
    Accountstable.append(account);
    dbHandler->userDatabase["accounts"] = Accountstable;

    // Save the updated JSON document back to the file
    dbHandler->saveUserDatabaseToFile();

    QByteArray responseData = "User Added!";
    sendResponse(socket, responseData);
}

void Handler::handleDeleteUser(QTcpSocket *socket, const QByteArray &requestData) {
    QJsonObject jsonObject;
    int userDeleted = 0;
    parseJSONFromRequest(requestData, jsonObject);

    if (jsonObject.isEmpty()) {
        // Handle empty or invalid JSON
        return;
    }

    // Extract necessary information from the request
    QString accountnumber = jsonObject["accountnumber"].toString();

    // Find the user record in the JSON document
    QJsonArray users = dbHandler->userDatabase.value("users").toArray();
    QJsonArray accounts = dbHandler->userDatabase.value("accounts").toArray();
    QJsonArray transactions = dbHandler->userDatabase.value("transactions").toArray();

    for (int i = 0; i < users.size(); ++i) {
        QJsonObject userObject = users[i].toObject();
        if (userObject.value("accountnumber").toString() == accountnumber) {
            // Remove the user record from the JSON array
            users.removeAt(i);
            dbHandler->userDatabase["users"] = users;

            userDeleted = 1;
            break;
        }
    }
    if(userDeleted ==  0)
    {
        QByteArray responseData = "User not found";
        sendResponse(socket, responseData);
        return;
    }
    for (int i = 0; i < accounts.size(); ++i) {
        QJsonObject accountObject = accounts[i].toObject();
        if (accountObject.value("accountnumber").toString() == accountnumber) {
            // Remove the user record from the JSON array
            accounts.removeAt(i);
            dbHandler->userDatabase["accounts"] = accounts;

            break;
        }
    }
    for (int i = 0; i < transactions.size(); ++i) {
        QJsonObject transactionObject = transactions[i].toObject();
        if (transactionObject.value("accountnumber").toString() == accountnumber) {
            // Remove the user record from the JSON array
            transactions.removeAt(i);

            --i; //adjusting the iterator ater removing the item
        }
    }
    dbHandler->userDatabase["transactions"] = transactions;

    dbHandler->saveUserDatabaseToFile();
    // Respond to the client with success message or handle as needed
    QByteArray responseData = "User record deleted successfully.";
    sendResponse(socket, responseData);
}

void Handler::handleUpdateUser(QTcpSocket *socket,const QByteArray &requestData) {
    QJsonObject jsonObject;
    parseJSONFromRequest(requestData, jsonObject);

    if (jsonObject.isEmpty()) {
        // Handle empty or invalid JSON
        return;
    }

    if (!jsonObject.contains("accountnumber")) {
        qDebug() << "account number not provided in the request.";
        return;
    }

    QString accountnumber = jsonObject["accountnumber"].toString();
    bool nameExists = false;

    // Find the user record in the JSON document
    QJsonArray users = dbHandler->userDatabase.value("users").toArray();
    for (int i = 0; i < users.size(); ++i) {
        QJsonObject userObject = users[i].toObject();
        if (userObject.value("accountnumber").toString() == accountnumber) {
            // Update the fields of the identified user record
            QString UsernameUpdatedUser= userObject.value("username").toString();
            qDebug()  << UsernameUpdatedUser;
            if (jsonObject.contains("username")) {
                QJsonArray table = dbHandler->userDatabase.value("users").toArray();
                foreach (const QJsonValue &value, table) {

                    if ((value.toObject().value("username") == jsonObject["username"]) && (value.toObject().value("username") != UsernameUpdatedUser)) {
                        nameExists = true;
                        break;
                    }
                }
                if(nameExists == false)
                {
                    userObject["username"] = jsonObject["username"];
                }
                else{
                    QByteArray responseData = "Incoming data already exists in the document.";
                    sendResponse(socket, responseData);
                    return;
                }
            }
            if (jsonObject.contains("password")) {
                userObject["password"] = jsonObject["password"];
            }
            if (jsonObject.contains("role")) {
                userObject["role"] = jsonObject["role"];
            }

            // Update the user record in the JSON array
            users[i] = userObject;
            dbHandler->userDatabase["users"] = users;

            // Save the updated JSON document back to the file
            dbHandler->saveUserDatabaseToFile();

            qDebug() << "User record updated successfully.";
            QByteArray responseData = "User record updated successfully.";
            sendResponse(socket, responseData);
            return;
        }
    }

    qDebug() << "User not found in the database.";
    QByteArray responseData = "User not found in the database.";
    sendResponse(socket, responseData);
}


void Handler::handleLogin(QTcpSocket *socket, const QString &username, const QString &password) {
    // Check if the provided username and password match any user in the database
    QJsonArray users = dbHandler->userDatabase.value("users").toArray();
    for (const QJsonValue &userValue : users) {
        QJsonObject userObject = userValue.toObject();
        if (userObject.value("username").toString() == username &&
            userObject.value("password").toString() == password) {
            // Successful login
            loggedInClients_Roles.insert(socket, userObject.value("role").toString());
            loggedInClients_Names.insert(socket, userObject.value("username").toString());
            if(userObject.value("role").toString() == "admin")
            {
                QByteArray responseData = "Hello Admin!";
                sendResponse(socket, responseData);
                return;
            }
            QByteArray responseData = "Login successfulll.";
            sendResponse(socket, responseData);
            qDebug() << "Login successfulll. User:" << username;
            return;
        }
    }

    // Failed login
    QByteArray responseData = "Login failed. Invalid username or password.";
    sendResponse(socket, responseData);
    qDebug() << "Login failed. Invalid username or password.";
}

void Handler::handleGetAccountNumber(QTcpSocket *socket) {

    QString username = loggedInClients_Names.find(socket).value();
    QJsonArray users = dbHandler->userDatabase.value("users").toArray();
    for (const QJsonValue &userValue : users) {

        QJsonObject userObject = userValue.toObject();

        if (userObject.value("username").toString() == username) {

            QString accountNum = userObject.value("accountnumber").toString();
            QByteArray responseData = "Number: " ;
            responseData += accountNum.toUtf8() ;
            sendResponse(socket, responseData);
            return;

        }

    }

    QByteArray responseData = "Username Not found";
    sendResponse(socket, responseData);

}

void Handler::handleGetBalance(QTcpSocket *socket) {

    QString username = loggedInClients_Names.find(socket).value();
    QJsonArray users = dbHandler->userDatabase.value("users").toArray();
    QString accountNum;
    for (const QJsonValue &userValue : users) {

        QJsonObject userObject = userValue.toObject();

        if (userObject.value("username").toString() == username) {

            accountNum = userObject.value("accountnumber").toString();
            qDebug() << accountNum;
            break;

        }

    }

    QJsonArray accounts = dbHandler->userDatabase.value("accounts").toArray();
    for (const QJsonValue &accountValue : accounts) {

        QJsonObject accountObject = accountValue.toObject();

        if (accountObject.value("accountnumber").toString() == accountNum) {

            int Balance = accountObject.value("balance").toInt();
            qDebug() << QString::number(Balance);
            QByteArray responseData = "Balance: " ;
            responseData += QByteArray::number(Balance) ;
            sendResponse(socket, responseData);
            return;

        }

    }

    QByteArray responseData = "account number Not found";
    sendResponse(socket, responseData);

}

void Handler::handleGetTransactionHisory(QTcpSocket *socket, int count)
{
    int c = 0;
    QString username = loggedInClients_Names.find(socket).value();
    QJsonArray users = dbHandler->userDatabase.value("users").toArray();
    QString accountNum;
    for (const QJsonValue &userValue : users) {

        QJsonObject userObject = userValue.toObject();

        if (userObject.value("username").toString() == username) {
            accountNum = userObject.value("accountnumber").toString();
        }

    }

    QJsonArray transactions = dbHandler->userDatabase.value("transactions").toArray();
    QJsonArray arr ;
    for (int i = transactions.size() - 1; i >= 0; --i) {
        if(c < count)
        {
            QJsonObject transactionObject = transactions.at(i).toObject();

            if (transactionObject.value("accountnumber").toString() == accountNum) {


                arr.append(transactionObject);
                c++;

            }
        }

    }
    if(c == 0)
    {
        QByteArray responseData = "No Transactions";
        sendResponse(socket, responseData);
        return;
    }

    QJsonDocument doc(arr);
    QByteArray responseData = "Transaction History: " ;
    responseData += doc.toJson() ;
    sendResponse(socket, responseData);

}


void Handler::handleMakeTransaction(QTcpSocket *socket, int amount)
{
    QString username = loggedInClients_Names.find(socket).value();
    QJsonArray users = dbHandler->userDatabase.value("users").toArray();
    QJsonArray accounts = dbHandler->userDatabase.value("accounts").toArray();
    QString accountNum;
    for (const QJsonValue &userValue : users) {

        QJsonObject userObject = userValue.toObject();

        if (userObject.value("username").toString() == username) {
            accountNum = userObject.value("accountnumber").toString();
            qDebug() << accountNum;
        }

    }

    for (int i = 0; i < accounts.size(); ++i) {
        QJsonObject accountObject = accounts[i].toObject();
        if (accountObject.value("accountnumber").toString() == accountNum) {

            if((accountObject["balance"].toInt() + amount) < 0)
            {
                QByteArray responseData = "NNot enough Balance";
                sendResponse(socket, responseData);
                return;
            }

            int balance = accountObject["balance"].toInt();
            balance += amount;
            accountObject["balance"] = balance;

            qDebug() << balance;

            // Update the user record in the JSON array
            accounts[i] = accountObject;
            dbHandler->userDatabase["accounts"] = accounts;



        }
    }

    QDate currentDate = QDate::currentDate();

    QJsonArray transactions = dbHandler->userDatabase.value("transactions").toArray();

    QJsonObject  transaction;
    transaction.insert("accountnumber",accountNum);
    transaction.insert("amount",amount);
    transaction.insert("date",currentDate.toString(Qt::ISODate));
    transactions.append(transaction);
    dbHandler->userDatabase["transactions"] = transactions;

    dbHandler->saveUserDatabaseToFile();

    QByteArray responseData = "Transaction Made Successfully";
    sendResponse(socket, responseData);

}

void Handler::handleTransfer(QTcpSocket *socket, QString toAcc, int amount)
{

    if(amount < 0)
    {
        QByteArray responseData = "Amount must be positive";
        sendResponse(socket, responseData);
        return;
    }

    QString username = loggedInClients_Names.find(socket).value();
    QJsonArray users = dbHandler->userDatabase.value("users").toArray();
    QJsonArray accounts = dbHandler->userDatabase.value("accounts").toArray();
    QString accountNum;
    for (const QJsonValue &userValue : users) {

        QJsonObject userObject = userValue.toObject();

        if (userObject.value("username").toString() == username) {
            accountNum = userObject.value("accountnumber").toString();
        }

    }

    if(accountNum == toAcc)
    {
        QByteArray responseData = "you cannott transfer to yourself";
        sendResponse(socket, responseData);
        return;
    }

    for (int i = 0; i < accounts.size(); ++i) {
        QJsonObject accountObject = accounts[i].toObject();
        if (accountObject.value("accountnumber").toString() == accountNum) {

            if((accountObject["balance"].toInt() - amount) < 0)
            {
                QByteArray responseData = "NNot enough Balance";
                sendResponse(socket, responseData);
                return;
            }

            int fromBalance = accountObject["balance"].toInt();
            fromBalance -= amount;
            accountObject["balance"] = fromBalance;

            // Update the user record in the JSON array
            accounts[i] = accountObject;
            dbHandler->userDatabase["accounts"] = accounts;

        }
        if (accountObject.value("accountnumber").toString() == toAcc) {

            int toBalance = accountObject["balance"].toInt();
            toBalance += amount;
            accountObject["balance"] = toBalance;

            // Update the user record in the JSON array
            accounts[i] = accountObject;
            dbHandler->userDatabase["accounts"] = accounts;

        }
    }

    dbHandler->saveUserDatabaseToFile();

    QByteArray responseData = "Transferred Successfully";
    sendResponse(socket, responseData);
}


void Handler::handleGetAccountNumberAdmin(QTcpSocket *socket, QString username)
{
    QJsonArray users = dbHandler->userDatabase.value("users").toArray();
    for (const QJsonValue &userValue : users) {

        QJsonObject userObject = userValue.toObject();

        if (userObject.value("username").toString() == username) {

            QString accountNum = userObject.value("accountnumber").toString();
            QByteArray responseData = "Number: " ;
            responseData += accountNum.toUtf8() ;
            sendResponse(socket, responseData);
            return;

        }

    }

    QByteArray responseData = "Username Not found";
    sendResponse(socket, responseData);
}


void Handler::handleGetBalanceAdmin(QTcpSocket *socket, QString accountNum)
{
    QJsonArray accounts = dbHandler->userDatabase.value("accounts").toArray();
    for (const QJsonValue &accountValue : accounts) {

        QJsonObject accountObject = accountValue.toObject();

        if (accountObject.value("accountnumber").toString() == accountNum) {

            int Balance = accountObject.value("balance").toInt();
            qDebug() << QString::number(Balance);
            QByteArray responseData = "Balance: " ;
            responseData += QByteArray::number(Balance) ;
            sendResponse(socket, responseData);
            return;

        }

    }

    QByteArray responseData = "account number Not found";
    sendResponse(socket, responseData);
}

void Handler::handleGetTransactionHisoryAdmin(QTcpSocket *socket, QString accountNum, int count)
{
    int c = 0;
    QJsonArray arr ;
    QJsonArray transactions = dbHandler->userDatabase.value("transactions").toArray();
    for (int i = transactions.size() - 1; i >= 0; --i) {
        if(c < count)
        {
            QJsonObject transactionObject = transactions.at(i).toObject();

            if (transactionObject.value("accountnumber").toString() == accountNum) {


                arr.append(transactionObject);
                c++;

            }
        }

    }
    if(c == 0)
    {
        QByteArray responseData = "No Transactions";
        sendResponse(socket, responseData);
        return;
    }

    QJsonDocument doc(arr);
    QByteArray responseData = "Transaction History: " ;
    responseData += doc.toJson() ;
    sendResponse(socket, responseData);
}


void Handler::handleLogout(QTcpSocket *socket) {
    // Remove the client from the list of logged-in clients upon logout
    if (loggedInClients_Roles.contains(socket)) {
        loggedInClients_Roles.remove(socket);
        loggedInClients_Names.remove(socket);
        qDebug() << "Logout successful.";

        QByteArray responseData = "Logout successful." ;
        sendResponse(socket, responseData);
    }
    else{
        QByteArray responseData = "you are not logged in" ;
        sendResponse(socket, responseData);
    }

}

bool Handler::isLoggedIn(QTcpSocket *socket) {
    // Check if the given socket is logged in
    return loggedInClients_Roles.contains(socket);
}


void Handler::parseJSONFromRequest(const QByteArray &requestData, QJsonObject &jsonObject) {
    int jsonDataStart = requestData.indexOf("{");
    int jsonDataEnd = requestData.lastIndexOf("}");
    if (jsonDataStart != -1 && jsonDataEnd != -1 && jsonDataEnd > jsonDataStart) {
        QByteArray jsonData = requestData.mid(jsonDataStart, jsonDataEnd - jsonDataStart + 1);
        QJsonParseError jsonError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &jsonError);
        if (jsonError.error == QJsonParseError::NoError && jsonDoc.isObject()) {
            jsonObject = jsonDoc.object();
        } else {
            qDebug() << "JSON parsing error:" << jsonError.errorString();
        }
    } else {
        qDebug() << "No JSON data found in the request body";
    }
}

