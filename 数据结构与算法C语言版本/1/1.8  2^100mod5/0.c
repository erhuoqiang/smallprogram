#include<stdio.h>
#include<time.h>

int main()
{
	int i = 0, reg = 1;
	for(i = 0; i < 100; i++)
	{
		reg *= 2;
		if(reg >= 10)
		reg %= 10;    //��10ȥ�� ��Ϊ10��������5�� 2��N�η�β��Ҳ���й��ɵ� 2 4 8 6 
	}
	printf("%d\n",reg%5);
}
