#ifndef PROTOCOL_H
#define PROTOCOL_H

#endif // PROTOCOL_H

typedef unsigned int uint;


typedef struct{
    uint uiPDULen;
    uint uiMsgType;
    uint caData[64];
    uint uiMsgLen;
    int caMsg[];
} PDU;

PDU *mkPDU(uint uiMsgLen);
