#include "mytcpserver.h"
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <mytcpsocket.h>
#include    <QList>

MyTcpServer::MyTcpServer()  //默认构造函数
{

}

MyTcpServer &MyTcpServer::getInstance()     //实现单例模式
{
    static MyTcpServer instance; // 静态的，无论调用多少次，只有这一个对象
    return instance;


}

void MyTcpServer::incomingConnection(qintptr handle)    //一旦客户端连接服务器，服务器会自动执行socket函数
{
    qDebug()<<tr("new client connected!")<<tr("连接成功")<<endl;
//    QWidget tmpQWidget;
    //为什么不能用临时对象，因为在函数调用时，会销毁，然而父窗口还在，调用QWidget tmpQWidget会调用失败
    //QMessageBox::information(QWidget tmpQWidget ,"连接服务器","连接服务器成功");
//    QMessageBox::information(&tmpQWidget ,tr("连接服务器"),tr("连接服务器成功")); //QMessageBox::information(this)这个指针的传递给父窗口
    MyTcpsocket* pTcpSocket = new MyTcpsocket;
    pTcpSocket->setSocketDescriptor(handle);
    myTcpSocketList.append(pTcpSocket);

}
