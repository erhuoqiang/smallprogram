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
    COMMTIMEOUTS TimeOuts; /*���峬ʱ����*/
    DCB dcb;/*����DCB����*/

    /*�򿪴����ļ�*/
    hCom = CreateFile("COM1",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);  //�����ڶ���0�Ļ���ͬ����FILE_FLAG_OVERLAPPED�첽
   

    /*ǿ������ת��-1ΪHANDLE����*/
    if(hCom == (HANDLE)-1)
    {
        printf("open COM failed\n");
        exit(1);
    }

    /* ��ʱ���� */
    TimeOuts.ReadIntervalTimeout=1000;
    TimeOuts.ReadTotalTimeoutMultiplier=500;
    TimeOuts.ReadTotalTimeoutConstant=5000;
    TimeOuts.WriteTotalTimeoutMultiplier=500;
    TimeOuts.WriteTotalTimeoutConstant=2000;

    /* д�봮�ڳ�ʱ����,������0*/
    if(!SetCommTimeouts(hCom,&TimeOuts))
    {
        printf("д�볬ʱ��������");
        exit(1);
    }

    /* ��������������������������ط�0��ʾ�ɹ� */
    if(!SetupComm(hCom,1024,1024))
    {
        printf("���ô��ڶ�д������ʧ��\n");
        exit(1);
    }

    /* ��ȡ��ǰ����״̬��Ϣ(ֻ��Ҫ�޸Ĳ��ִ�����Ϣ),����ʧ�ܷ���0*/
    if(!GetCommState(hCom,&dcb))
    {
        printf("��ȡ��������ʧ��\n");
        exit(1);
    }
   

    /*�������������Դ�*/
    dcb.BaudRate = BAUD_RATE;
    dcb.ByteSize = 8;
    dcb.Parity = NOPARITY;    /*��У��*/
    dcb.StopBits=ONESTOPBIT; /*1λֹͣλ*/

    if(!SetCommState(hCom,&dcb))
    {
        printf("���ô��ڲ�������\n");
        exit(1);
    }


    if(WriteFile(hCom,outputData,sizeBuffer,&length,NULL)==0)
    {
        printf("д�봮������ʧ��\n");
        exit(1);
    }
while(1)
{
    if(ReadFile(hCom,inputData,sizeBuffer,&length,NULL)==0)
    {
        printf("��ȡ��������ʧ��\n");
        exit(1);
    }
   printf("%s",inputData);
}
    /*�رմ���*/
    CloseHandle(hCom);
   

    return 0;
}