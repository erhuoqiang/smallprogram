#include<stdio.h>

int N;
void foo( int a[])
{
	int i, j; 
	char flag = 1;
	for(i=0;i<4 && flag ;i++)
	{
		flag = 0;
		for(j=0;j<4-i;j++)
		{	
			if(a[j]>a[j+1])
			{
				N++;
				flag = 1;
				a[j] = a[j+1] + a[j];
				a[j+1] = a[j] - a[j+1];
				a[j] = a[j] - a[j+1];
	/*t=a[j];
	a[j]=a[j+1];
	a[j+1]=t;*/
			}
		}
	}
}

int main()
{
		int a[5],i,j,t;
		for(i=0;i<5;i++)
			scanf("%d",a+i);
		foo(a);
		for(i=0;i<5;i++)
			printf("%d\t",a[i]);
		printf("¸´ÔÓ¶È:%d", N);
		return 0;
}

/*void main()
{
	int value[5], temp , i, j;
	for(i=0;i<5;i++)
		scanf("%d",value+i);
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4 - i; j++)
		{
			if(*(value + j) > *(value + j + 1))
			{
				temp = *(value + j);
				*(value + j) = *( value + j + 1 );
				*(value + j + 1) = temp;
			}
		}
		for(i=0;i<5;i++)
		printf("%d\t",value[i]);
}*/