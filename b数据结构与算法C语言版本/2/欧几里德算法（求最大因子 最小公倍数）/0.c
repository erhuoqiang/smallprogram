#include<stdio.h>

int Gcd(int M, int N)
{
	int Rem = 0;
	while(N > 0)
	{
		Rem = M % N;
		M = N;
		N = Rem;
	}
	return M;
}
int main()
{
	int m = 0, n = 0;
	scanf("%d%d",&m, &n);
	printf("������ӣ�%d\n��С��������%d \n",Gcd(m,n), m * n/Gcd(m,n));
}

	
