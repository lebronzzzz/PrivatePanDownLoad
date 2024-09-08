#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    int a ;
    int b;
    int c;
    int d[];    //数组名是数组的首地址

}PDU;
//实际上struct中的数组成员在实际内存中不分配，等待外部指定去分配

int main()
{
    printf("Hello World!\n");
    PDU *pdu =(PDU*)malloc(sizeof(PDU)+100*sizeof(int));    //动态数组的好处，就是根据外面的接受数据进行自动申请内存
    pdu->a=10;
    pdu->b=20;
    pdu->c=30;
    char str[]="you jump i will jump";

    memcpy(pdu->d,str,strlen(str)+1);
    printf("a :%d,b:%d,c:%d,d=%s\n",pdu->a,pdu->b,pdu->c,(char*)pdu->d);
    //pdu->d 指向的是数组的首地址，你要打印格式是字符，所以指针的类型要转换
    free(pdu);
    return 0;
}
