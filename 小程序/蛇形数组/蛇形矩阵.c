#include<stdio.h>
#include<string.h>

#define MAXN 100
int a[MAXN][MAXN];

int main()
{
	int n, x, y, tot = 0;
	memset(a, 0, sizeof(a));
	scanf("%d", &n);
	tot = a[x = 0][y = n-1] = 1;
	while(tot < n*n)
	{
		while( x < n - 1 && !a[x + 1][y] ) a[++x][y] = ++tot; 
		while( y > 0  && !a[x][y - 1] ) a[x][--y] = ++tot;
		while( x > 0 && !a[x - 1][y] ) a[--x][y] = ++tot;
		while ( y < n-1 && !a[x][y + 1] ) a[x][++y] = ++tot;
	}
	for(x = 0; x < n; x++)
	{
		for(y = 0; y < n; y++)
			printf("%4d",a[x][y]);
		printf("\n");
	}
	return 0;
}