#include<stdio.h>

void fun( int * m1, int * m2, int *result, int row, int com, int cow )
{
	register int i, j, k;
	int sum  = 0;
	for( i = 0; i < row; i++ )
	{
		for ( j = 0; j < cow; j++ )
		{
			sum = 0;
			for( k = 0; k < com; k++ )
			{
				sum = sum + *(m1 + i * com + k) * *(m2 + cow * k + j);
			}
			*(result + 4 * i + j ) = sum;
		}
	}
}



int main()
{
	int a[100] = {2,-6,3,5,1,-1};
	int b[100] = {4,-2,-4,-5,-7,-3,6,7};
	int r[100] = {0};
	int i , j;
	fun(a, b, r, 3, 2, 4);
	for( i = 0; i < 3; i++ )
	{
		for( j = 0; j < 4; j++ )
		{
			printf("%d ", r[ i * 4 + j]);
		}
		printf("\n");
	}
}
			
