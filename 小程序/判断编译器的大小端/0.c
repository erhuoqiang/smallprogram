#include<stdio.h>
//union��ʼ��ַһ��
// С��ģʽ ���ֽ����ݷ��ڵ͵�ַ
//���ģʽ  ���ֽھݷ��ڸߵ�ַ
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
		printf("С��");
	}
	else 
	{
			printf("���");
	}
}

void main()
{
	Endian();
}