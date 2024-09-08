#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QTcpServer>
#include "mytcpsocket.h"

class MyTcpServer : public QTcpServer
{
    Q_OBJECT//使用这个宏才能用到QT中的signal和slot机制
public:
    MyTcpServer();//构造函数
    static MyTcpServer &getInstance();//单例模式
    void incomingConnection(qintptr handle);
public:

    QList<MyTcpsocket*> myTcpSocketList;


};

#endif // MYTCPSERVER_H
