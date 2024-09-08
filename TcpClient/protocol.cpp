#include "protocol.h"
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <cstring>

PDU *mkPDU(uint uiMsgLen)
{
    uint uiPDULen = sizeof(PDU)-sizeof(char[1])+uiMsgLen;
    PDU* pdu=(PDU*)malloc(uiPDULen);
    if(pdu==NULL)
    {
     exit(EXIT_SUCCESS);
    }
    memset(pdu,0,uiPDULen);   //会用指针操作（初始化，赋值等）大块内存才会使得程序的效率更高
    pdu->uiPDULen=uiPDULen;         //初始化的数据，分为外部（给client）和内部
    pdu->uiMsgLen=uiMsgLen;
    return pdu;     //返回的是函数中你想传出去的变量，而不是类型
}
