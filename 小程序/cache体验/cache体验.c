#include<stdio.h>
#include<stdlib.h>
#define DUMBCOPY for(i = 0; i < 65536; i ++) \
    destination[i] = source[i]          //��ʱ1.7s

#define smartcopy memcpy(destination,source,65536) //��ʱ1s     Ԥ����һ���κ�ʱ�򶼱ȵ��ú�����   ԭ����ר�ұ�̵�P149ҳ     
int main()
{
    char source[65536], destination[65536];
    int i, j;
    for(j = 0; j < 100; j++)
       try ;
}
