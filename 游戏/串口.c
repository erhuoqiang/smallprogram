#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <winnt.h>

#define BAUD_RATE 9600
#define p printf

int main()
{
    HANDLE hCom;
    //unsigned char buf[128];
    char inputData[1024]="  ";
    char outputData[1024];
    int sizeBuffer = 1;
    int length;
    COMMTIMEOUTS TimeOuts; /*定义超时变量*/
    DCB dcb;/*串口DCB设置*/

    /*打开串口文件*/
    hCom = CreateFile("COM1",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);  //倒数第二个0的话是同步，FILE_FLAG_OVERLAPPED异步
   

    /*强制类型转换-1为HANDLE类型*/
    if(hCom == (HANDLE)-1)
    {
        printf("open COM failed\n");
        exit(1);
    }

    /* 超时设置 */
    TimeOuts.ReadIntervalTimeout=1000;
    TimeOuts.ReadTotalTimeoutMultiplier=500;
    TimeOuts.ReadTotalTimeoutConstant=5000;
    TimeOuts.WriteTotalTimeoutMultiplier=500;
    TimeOuts.WriteTotalTimeoutConstant=2000;

    /* 写入串口超时参数,出错返回0*/
    if(!SetCommTimeouts(hCom,&TimeOuts))
    {
        printf("写入超时参数错误");
        exit(1);
    }

    /* 设置输入输出缓冲区参数，返回非0表示成功 */
    if(!SetupComm(hCom,1024,1024))
    {
        printf("设置串口读写缓冲区失败\n");
        exit(1);
    }

    /* 获取当前串口状态信息(只需要修改部分串口信息),调用失败返回0*/
    if(!GetCommState(hCom,&dcb))
    {
        printf("获取串口属性失败\n");
        exit(1);
    }
   

    /*具体情况，具体对待*/
    dcb.BaudRate = BAUD_RATE;
    dcb.ByteSize = 8;
    dcb.Parity = NOPARITY;    /*无校验*/
    dcb.StopBits=ONESTOPBIT; /*1位停止位*/

    if(!SetCommState(hCom,&dcb))
    {
        printf("设置串口参数出错\n");
        exit(1);
    }


    if(WriteFile(hCom,outputData,sizeBuffer,&length,NULL)==0)
    {
        printf("写入串口数据失败\n");
        exit(1);
    }
while(1)
{
    if(ReadFile(hCom,inputData,sizeBuffer,&length,NULL)==0)
    {
        printf("读取串口数据失败\n");
        exit(1);
    }
   printf("%s",inputData);
}
    /*关闭串口*/
    CloseHandle(hCom);
   

    return 0;
}