#include<stdio.h>

int GET_SET_BIT(unsigned int x)
{
    int Counter = 0;
    while(x)
    {
        Counter++;
        x = x & (x - 1);
    }
     return Counter;
}

int GET_DOWN_BIT(unsigned int x)
{
    int Counter = 0;
    while(x + 1)
    {
        Counter++;
        x = x | (x + 1);
    }
    return Counter;
}


int main()
{
    int x = 0;
    scanf("%d",&x);
    printf("1:%d \n0:%d \n",GET_SET_BIT(x),GET_DOWN_BIT(x));
}
