#include<stdio.h>

void print( int num )
{
	if(num < 0)
	{
		putchar('-');
		num *= -1;
	}
	if(num >= 10)
		print(num/10);
	printf("%d",num%10);
}

int main()
{
	int value = 0;
	while(1)
	{
		printf("Please input num:\n");
		if(scanf("%d", &value) == -1)
			perror("Input error:\n");
		print(value);
		printf("\n");
	}
	return 0;
		
}
