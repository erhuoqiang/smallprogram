#include<stdio.h>
#include<math.h>

char prime( int i )
{
	int j;
	for( j = 2; j <= (int)sqrt(i); j++)
		{
			if( i % j == 0 )
			{	
				return 0;
			}
		}
	return 1;
}
int main()
{
	int i, j = 2;
	
	for( i = 3; i < 100; i+=2 )
	{
		if( prime(i) )
			printf("%d\t", i);

	}
}
