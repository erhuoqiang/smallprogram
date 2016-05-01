#include<stdio.h>

int main()
{
	int max , min, s = 0, n = 0, x;
	scanf("%d",&x);
	max = min = s = x;
	n++;
	while(scanf("%d",&x))
	{
		s += x;
		n++;
		if(x > max) max = x;
		if(x < min) min = x;
	}
	printf("%d,%d,%.3f",max, min, (float)s/n);

	return 0;
}