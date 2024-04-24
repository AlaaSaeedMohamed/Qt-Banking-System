#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
class Client : public QObject
{
    Q_OBJECT
public:
    Client();
    ~Client();

signals:

public slots:
    void connectToHost(QString hostname, quint16 port);
private slots:
    void Connected();
    void disconnected();
    void errorOccurred(QAbstractSocket::SocketError socketError);
    void hostFound();
    void stateChanged(QAbstractSocket::SocketState socketState);
    void disconnect();
    void readyRead();

private:
    QTcpSocket *socket;
};

#endif // CLIENT_H
