#include "mytcpsocket.h"
#include <QDebug>
#include "protocol.h"
MyTcpsocket::MyTcpsocket()
{
    connect(this,SIGNAL(readyRead()),this,SLOT(recvMsg()));  //为什么信号和槽函数都是this呢，
    //因为这是对象本身内部自己通信的，不需要和外部的对象进行通信
    //readRead是QtcpSocket中用于读取socket的输入数据流，当有数据流从
    //socket发送的时候，readRead信号就会触发
}

void MyTcpsocket::recvMsg()
{
    qDebug()<<this->bytesAvailable(); //因为继承了QTcpSocket这个类，所以包含这个方法
    qDebug() << "Bytes available: " << this->bytesAvailable();                                //可以在类的内部直接调用继承类的方法
    uint uiPDULen =0;
    this->read((char*)&uiPDULen,sizeof(int));
    qDebug() << "PDULen: " << uiPDULen;
    uint uiMsgLen = uiPDULen-sizeof(PDU);
    PDU *pdu = mkPDU(uiMsgLen);
    this->read((char*)pdu+sizeof(uint),uiPDULen-sizeof(uint));
    qDebug()<<pdu->uiMsgType<<(char*)pdu->caMsg;
    qDebug() << "Actual length of message in bytes: " << strlen((char*)pdu->caMsg);
    free(pdu); // 释放内存
    pdu = nullptr; // 避免悬挂指针

}
