#include  <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create an instance of the server
    Server serverr(&a);

    return a.exec();
}
