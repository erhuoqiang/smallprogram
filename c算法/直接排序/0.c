#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

typedef struct
{
	int r[MAX_SIZE + 1];
	int length;
} SqList;



void InsertSort(SqList * L)
{
	int i,j;
	for(i = 2; i <= L->length; i++)
	{
		if( L->r[i] < L->r[i-1] )
		{
			L->r[0] = L->r[i];
			for( j = i - 1; L->r[j] > L->r[0]; j--)
				L->r[j + 1] = L->r[j];
			L->r[j + 1] = L->r[0];
		}
	}
}

void main()
{
	int i = 0;
	SqList *L = (SqList *)malloc(sizeof(SqList));
	L->length = 0;
	for(i = 1; i <= 3; i++)
	{
		scanf("%d", &L->r[i]);
		L->length++;
	}

	InsertSort(L);

	for(i = 1; i <= 3; i++)
	{
		printf("%d ", L->r[i]);
	}
}
