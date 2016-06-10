#include<stdio.h>
//union起始地址一致
// 小端模式 低字节数据放在低地址
//大端模式  低字节据放在高地址
union Check_Endian
{
	int i;
	char ch;
}x;

int Endian()
{
	x.i = 1;

	if( x.ch )
	{
		printf("小端");
	}
	else 
	{
			printf("大端");
	}
}

void main()
{
	Endian();
}