#include <QtNetwork>
#include <QCoreApplication>
#include <QDebug>
#include "client.h"
#include "manager_client.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    //Client client;
    Manager_Client m_client;
    Manager_Client m_client2;

    // Send GET request
    // m_client.get("http://192.168.1.14:22/get");


    // Send POST request
    //m_client.post("http://192.168.1.14:22", data);
    m_client.login("user3", "abc123");
    //m_client2.login("user3", "abc123");

    m_client.get("http://192.168.1.14:22/gett");

    return a.exec();
}
