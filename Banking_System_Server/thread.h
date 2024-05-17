#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QTcpSocket>

#include  <QRunnable>
#include <QEventLoop>
#include  "requestHandler.h"

class Thread : public QObject, public QRunnable {
    Q_OBJECT

public:
    explicit Thread(QMutex *mutex, qintptr socketDescriptor, QObject *parent = nullptr);
    ~Thread();

    void run() override;

    void readyRead();


private:
    qintptr socketDescriptor;
    QTcpSocket *socket;
    Handler *handler;
};



#endif // THREAD_H
