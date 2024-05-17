#include "thread.h"

Thread::Thread(QMutex *mutex, qintptr socketDescriptor, QObject *parent)
    : QObject(parent), socketDescriptor(socketDescriptor) {
    handler  = new Handler(mutex);
}

Thread::~Thread()
{
    delete socket;;
    delete handler;
}

void Thread::run()
{
    socket = new QTcpSocket();
    QEventLoop loop;

    // to tell the socket which client it needs to communicate with
    //the socket descriptor comes from the os and is uniqe for each connection
    if(!socket->setSocketDescriptor(socketDescriptor))
    {
        qDebug() << "Failed to connect to the client ";
        qDebug() << socket->errorString();

        delete socket;
        return;
    }

    /*we use Qt::DirectConnection when we connect signals and slots to
    ensure that slots will be invoked in the singling thread.*/

    /* when the clients disconnects the event loop will quit and the run method will treminate
        and since the setAutoDelete is enabled in the incomingConnection method of the  server
        ,the QThreadPool will delete the Clienthandler object automatically   */
    connect(socket, &QTcpSocket::disconnected, &loop, &QEventLoop::quit, Qt::DirectConnection);

    connect(socket, &QTcpSocket::disconnected, handler, [=](){
        handler->handleLogout(socket);
    });

    // to read the data from the socket buffer when it's ready
    connect(socket, &QTcpSocket::readyRead, this, &Thread::readyRead, Qt::DirectConnection);



    loop.exec();


}

void Thread::readyRead()
{

    qDebug() << "new incoming connection3";

    QByteArray data = socket->readAll();

    qDebug() << data;
    //syncronus call that reaches the DataBase
    handler->handleRequest(socket,data);

}
