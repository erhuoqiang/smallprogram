#include<stdio.h>

int main()
{
	int data[400] = {1,1,0};
	int N = 0;
	int i = 0, j = 1, k = 0;
	scanf("%d", &N );
	for( i = 1; i <= N; i++ )
	{
		for( k = 1; k <= j; k++)
		{
			data[k] *= 2; //N的N次方 
		//	data[k] *= i; //N的阶乘
		}
		for( k = 1; k <= j; k++)
		{
			
			if(data[k] >= 10)
			{
				data[k + 1] += data[k] / 10;
				data[k] = data[k] % 10;
				if( k == j )
				j++;
			}
			
		}
		
	}
	for(i = j; i > 0; i--)
	{
		
		printf("%d", data[i] );
	}
	printf("\n");
}