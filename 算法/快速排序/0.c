#include<stdio.h>

void QuickSort( int R[], int s, int t )
{
	int i = s, j = t;
	int temp =0;
	if( s < t )
	{
		temp = R[s];
		while ( i != j)
		{
			while( j > i && R[j] >= temp )
				j--;
			R[i] = R[j];
			while( j > i && R[i] <= temp )
				i++;
			R[j] = R[i];
		}
	R[i] = temp;
	QuickSort( R, s, i - 1 );
	QuickSort( R, i + 1, t );
	}
}

int main()
{
#if 1
	int i, R[6] = {1,1,0,3,6,12};
	QuickSort( R, 0, 5 );
	for( i = 0; i < 6; i++)
		printf("%d\t", R[i]);
#endif
	/*
	const int I = 1000;
	int * b = &I;
	*b = 100;
	printf("%d", I);*/
}
