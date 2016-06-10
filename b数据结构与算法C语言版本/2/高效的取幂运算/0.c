#include<stdio.h>

long int pow(long int X, int N)
{
	if( 0 == N )
		return 1;
	else if( 1 == N )
		return X;
	else if( N % 2 == 0 )
		return pow( X * X, N / 2 );
	else 
		return pow ( X * X, N / 2 ) * X;
}

int main()
{
    long unsigned int temp = pow(2, 29);
	printf("%lld\n", temp);
}