#include "server.h"
#include "thread.h"

Server::Server(QObject *parent = nullptr) : QTcpServer(parent){

    pool = new QThreadPool(this);
    pool->setMaxThreadCount(100);

    mutex = new QMutex;

    QString add = "192.168.1.14";
    QHostAddress host(add);
    if(this->listen(host, 22))
    {
        qDebug() << "listening";
    }

}

Server::~Server()
{
    delete mutex;
    delete pool;
}


void Server::incomingConnection(qintptr socketDescriptor) {

    qDebug() << "new incoming connection";
    Thread *thread = new Thread(mutex,socketDescriptor,this);
    thread->setAutoDelete(true);
    pool->start(thread);
}

