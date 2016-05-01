#include<stdio.h>
#define Element int
int Max_sum( const Element temp[], int N)
{
	Element Thissum = 0, Maxsum = 0;
	int i =0;
	for( i = 0; i < N; i++)
	{
		Thissum += temp[i];
		if(Thissum < 0)
				Thissum = 0;
		else if(Thissum > Maxsum)
			Maxsum = Thissum;
	}
	if( Maxsum == 0)
		printf("NO number >0\n");
	return Maxsum;
}

int main()
{
	Element temp[10]={-1,-2,-1,-4,-8,-5,-8,-7,-1,-8};
	printf("%d\n",Max_sum(temp,10));
}