#include<stdio.h>
#include<stdlib.h>
#define DUMBCOPY for(i = 0; i < 65536; i ++) \
    destination[i] = source[i]          //用时1.7s

#define smartcopy memcpy(destination,source,65536) //用时1s     预处理不一定任何时候都比调用函数快   原因在专家编程的P149页     
int main()
{
    char source[65536], destination[65536];
    int i, j;
    for(j = 0; j < 100; j++)
       try ;
}
