#include<stdio.h>
int main()
{
	char i,n,j;
	printf("input a char:");
		scanf("%c",&n);
			for(j='A';j<=n;j++)
			{
				for(i='A';i<j;i++)
					printf(" ");
				for(i='A';i<=n+65-j;i++)
					printf("%c",i);
				for(i=n-j+64;i>=65;i--)
					printf("%c",i);
				printf("\n");
			}
		return 0;
}