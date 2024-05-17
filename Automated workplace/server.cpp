#include"server.h"

Server::Server(){
    if (this->listen(QHostAddress::Any, 2323)){
        qDebug() << "start";
    }
    else{
        qDebug() << "error";
    }
    nextBlockSize = 0;
}

void Server:: incomingConnection(qintptr socketDescriptor){
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket);
    qDebug() << "Client connected" << socketDescriptor;
}

void Server::slotReadyRead(){
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_12);
    if (in.status() == QDataStream::Ok){
        qDebug() << "read";
        /*QString str;
        in >> str;
        qDebug() << str;
        SendToClient(str);*/
        for (;;){
            if (nextBlockSize == 0){
                if (socket->bytesAvailable() < 2){
                    break;
                }
                in >> nextBlockSize;
            }
            if (socket->bytesAvailable() < nextBlockSize){
                break;
            }
            QString str;
            QString str2;
            QTime time;
            in >> time >> str >> str2;
            nextBlockSize = 0;
            SendToClient(str, str2);
            break;
        }
    }
    else{
        qDebug() << "DataStream error";
    }
}

void Server::slotSetNickname(QString a)
{
    this->nickname = a;
}

void Server::SendToClient(QString str, QString str2){
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_12);
    out << qint16(0) << QTime::currentTime() << str2 << str;
    out.device()->seek(0);
    out << quint16(Data.size() - sizeof(quint16));
    //socket->write(Data);
    for (int i = 0; i < Sockets.size(); ++i){
        Sockets[i]->write(Data);
    }
}
