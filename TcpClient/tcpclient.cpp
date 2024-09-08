#include "tcpclient.h"
#include "ui_tcpclient.h"
#include <QByteArray>
#include <QDebug>
#include<QMessageBox>
#include<QHostAddress>
#include "protocol.h"
TcpClient::TcpClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    loadConfig();

    //信号连接函数
    connect(&my_tcpSocket,SIGNAL(connected()),this,SLOT(showConnect()));    //两个对象之间的通信


    //连接服务器
    my_tcpSocket.connectToHost(QHostAddress(my_strIP),my_intPort);

}

TcpClient::~TcpClient()
{
    delete ui;
}

void TcpClient::loadConfig()
{
    QFile file(":/client.config");
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

void TcpClient::showConnect()
{
    QMessageBox::information(this,"连接服务器","连接服务器成功");
}



void TcpClient::on_send_clicked()
{

     QString strMsg = ui->lineEdit->text();
//     PDU *pdu =mkPDU(strMsg.size());
//     pdu->uiMsgType = 8888;
//     pdu->uiMsgLen=strMsg.size();        //当你使用QT中的一些数据结构
//     //想和别的环境交互（C++）先把QT中的定义的数据类型转化成，C++的或者C的数据类型
//     memcpy(pdu->caMsg,strMsg.toStdString().c_str(),strMsg.size());
//     free(pdu);
//     pdu =nullptr;

     if(not strMsg.isEmpty())
     {
        PDU *pdu =mkPDU(strMsg.size());
        pdu->uiMsgType = 8888;
        memcpy(pdu->caMsg,strMsg.toStdString().c_str(),strMsg.size());
        qDebug() << "Sending PDULen: " << pdu->uiPDULen;
        my_tcpSocket.write((char*)pdu,pdu->uiPDULen);
        free(pdu);
        pdu =nullptr;
     }
     else
     {
        QMessageBox::warning(this,"信息发送","发送的信息不能为空！！");//传递this指针，表示构造的对象本身，而在Qmessage这对话框，是子窗口，依赖TCP这个父窗口

     }





}
