#include<stdio.h>
int main()
{
	int i,n,j,k,num[50];
	printf("输入总人数:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		num[i]=1;
		j=0;k=0;i=0;
	while(j<n-1)
	{
	if(num[i]!=0)	
		k++;
		if(k==3)
		{
			num[i]=0;
			k=0;
			j++;
		}
		i++;
		if(i==n) i=0;
	}
	for(i=0;num[i]==0;i++)
		;
	printf("留到最后的是第%d位\n",i+1);
	return 0;
}
