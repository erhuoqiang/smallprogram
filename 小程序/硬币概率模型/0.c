#include<stdio.h>
#include<stdlib.h>
#define times 32
#define lun 2000

int judge()
{
	return rand() < RAND_MAX / 2;
}
int main(int argc, int *argv[])
{

	int p[times + 1] = {0};
	int i = 0, j = 0, count = 0;
	for( i = 0; i < lun; i++)
	{
		count = 0;
		for( j = 0; j < times; j++)
		{
			if( judge() ) count++;
		}
		p[count]++;
	}
	for(j = 0 ; j <= times; j++)
	{
		printf(" %d", j);
		for( i = 0; i < p[j]; i+=10)
			printf("*");
		printf("\n");
	}
}
	

			
			