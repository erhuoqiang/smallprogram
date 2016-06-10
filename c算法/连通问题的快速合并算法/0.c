#include<stdio.h>

#define N 10

int main()
{
	int i = 0, j = 0, p = 0, q = 0;
	int id[N], sz[N];
	for(i = 0; i < N; i++)
	{
		id[i] = i;
		sz[i] = 1;
	}
	while( scanf("%d.%d", &p, &q) == 2 )
	{
		for(i = p; id[i] != i; i = id[i])	;
		for(j = q; id[j] != j; j = id[j])	;
		if( i == j ) continue;
		if(sz[i] < sz[j])
		{
			id[i] = j;
			sz[j] += sz[i];
		}
		else
		{
			id[j] = i;
			sz[i] += sz[j];
		}
	}
	for( i = 0; i < N ; i++ )
		printf("%d ", id[i]);
	printf("\n");

		

}
