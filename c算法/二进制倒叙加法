#include<stdio.h>

unsigned char  BackAdd(unsigned char num, unsigned char add_num)
{
	unsigned char temp = 1<<sizeof(num)*8 - 1;
	unsigned char k = temp;
	int i = 0;
	for(; i < add_num; i++)
	{
		k  = temp;
		while(k <= num)
		{
			num -= k;
			k /= 2;
		}
		num += k;
	}
	return num;
}

int main(int argc, char ** argv)
{
	printf("%d\n",BackAdd(0xf8,3));
}
		
