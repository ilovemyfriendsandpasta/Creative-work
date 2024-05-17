#ifndef SERVER_H
#define SERVER_H

#include<QTcpServer>
#include<QTcpSocket>
#include<QVector>
#include<QDataStream>
#include<QTime>


class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server();
    QTcpSocket* socket;
    QString nickname;

private:
    QVector<QTcpSocket*>Sockets;
    QByteArray Data;
    void SendToClient(QString str, QString str2);
    quint16 nextBlockSize;

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
    void slotSetNickname(QString a);

};

#endif // SERVER_H
