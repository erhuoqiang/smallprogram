#include<iostream>
#include<cassert>

using namespace std;


void get_num(const char * str,int * max1, int *max0)
{
    assert(str != NULL && max1 != NULL && max0 != NULL);
    int temp1 = 0;
    int temp0 = 0;
    *max0 = 0;
    *max1 = 0;
    while(*str)
    {
        if(*str == '1')
        {
            temp1++;
            temp0 = 0;
            if(temp1 > *max1)
                *max1 = temp1;
        }
        if(*str == '0')
        {
            temp1 = 0;
            temp0++;
            if(temp0 > *max0)
                *max0 = temp0;
        }
        str++;
    }
}
int main()
{
    char num[]= "011110000000000000000";
    int a,b;
   get_num(num,&a,&b);
   cout<<"1:"<<a<<endl<<"0:"<<b<<endl;
}
