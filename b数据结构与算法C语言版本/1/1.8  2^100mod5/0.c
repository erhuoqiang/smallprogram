#include<stdio.h>
#include<time.h>

int main()
{
	int i = 0, reg = 1;
	for(i = 0; i < 100; i++)
	{
		reg *= 2;
		if(reg >= 10)
		reg %= 10;    //把10去掉 因为10可以整除5； 2的N次方尾数也是有规律的 2 4 8 6 
	}
	printf("%d\n",reg%5);
}
