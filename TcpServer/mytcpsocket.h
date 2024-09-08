#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H
#include <QTcpSocket>

class MyTcpsocket : public QTcpSocket
{
    Q_OBJECT
public:
    MyTcpsocket();
public slots:
    void recvMsg();
};

#endif // MYTCPSOCKET_H
