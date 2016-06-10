/*
#include<stdio.h>
#include<string.h>

int main()
{
	char cs[5][20];
	char st[20];
	int i,j;
	for( i = 0; i < 5; i++)
		gets(cs[i]);
	for(i = 0; i < 4; i++)
	{
		for( j = 0; j < 4-i; j++)
		{
			if( strcmp(cs[j], cs[j+1]) >= 0)
			{
				strcpy(st, cs[j]);
				strcpy(cs[j], cs[j+1]);
				strcpy(cs[j+1], st);
			}
		}
	}
	for( i = 0; i < 5; i++)
		printf("%s\n",cs[i]);
}
	
*/
//选择 或者叫简单排序
#include<stdio.h>
#include<string.h>

int main()
{
	char cs[5][20];
	char st[20];
	int i,j;
	int min;
	for( i = 0; i < 5; i++)
		scanf("%s",cs[i]);
	for(i = 0; i < 5; i++)
	{
		min = i;
		//strcpy(st, cs[i]);
		for( j = i + 1; j < 5; j++)
		{
			if( strcmp(cs[j], cs[min]) < 0)
			{
				min = j;
			//	strcpy(st, cs[j]);
			}
		}
		if(min != i)
		{
			strcpy(st, cs[i]);
				strcpy(cs[i], cs[min]);
				strcpy(cs[min], st);
		}
	}
	for( i = 0; i < 5; i++)
		printf("%s\n",cs[i]);
}