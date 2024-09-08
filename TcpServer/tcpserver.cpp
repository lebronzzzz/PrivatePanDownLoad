#include "tcpserver.h"
#include "ui_tcpserver.h"
#include "mytcpserver.h"
#include <QFile>
#include <QByteArray>
#include <QMessageBox>
#include <QDebug>
#include <QList>
#include "mytcpsocket.h"

TcpServer::TcpServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TcpServer)
{
    ui->setupUi(this);
    loadConfig();

    //单例模式调用成员函数
    MyTcpServer::getInstance().listen(QHostAddress(my_strIP),my_intPort);

}

TcpServer::~TcpServer()
{
    delete ui;
}

void TcpServer::loadConfig()
{
    QFile file(":/server.config");
    if(file.open(QIODevice::ReadOnly))
    {

        QByteArray baData =file.readAll();
        QString strData = baData.toStdString().c_str();
        file.close();
        strData.replace("\r\n"," ");
        QStringList strList= strData.split(" ");

        my_strIP=strList.at(0);
        my_intPort=strList.at(1).toUShort();
        qDebug()<<"ip--->"<<my_strIP<<endl<<"port---->"<<my_intPort;
    }
    else
    {
        QMessageBox::critical(this,"open config","open error");


    }
}

