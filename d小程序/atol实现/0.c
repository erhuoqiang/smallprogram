#include<stdio.h>

int atol(char * a)
{
	int i = 0;
	int sum = 0;
	while( a[i] != '\0' )
	{
		if(a[i] < 48 || a[i] > 57)
		{
			i++;
			
		}
		else
		{
			while(a[i] >= 48 && a[i] <= 57)
			{
				sum = sum * 10 + a[i] - 48;
				i++;
			}
			return sum;
		}
	}
	return -1;
}
int main()
{
	char a[50] = "xaf454";
	int temp = 0;
	temp = atol(a);
	printf("%d",temp);
}