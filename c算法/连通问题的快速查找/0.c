#include<stdio.h>

#define N 10

int main()
{
	int x = 0, y = 0, num = 0;
	int i = 0, t = 0, j = 0;
	int temp[N];
	for(i = 0; i < N; i++)
	{
		temp[i] = i;
	}
	while(scanf("%d %d",&x,&y))
	{
		if(temp[x] == temp[y]) continue;
		for(t = temp[x], i = 0; i < N; i++)
			if(temp[i] == t) 
				temp[i] = temp[y];
	}
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(i == temp[j])
			{
				num++;
				printf("%d->",j);
			}
		}
		if( num != 0)
		{
			num = 0;
			printf("NULL\n");
		}
	}
	
}