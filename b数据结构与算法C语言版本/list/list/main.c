#include <stdio.h>
#include <stdlib.h>
#include "List.h"
/*** ����������˳��һ��*************/

int main()
{
	List L = CreatHeader();
	Position P = L;
	Position middle = NULL;
	int temp = 0;

	while( scanf("%d", &temp) == 1 )
	{
		Insert( temp, L, P ); //��ĩβ����
		P = P->Next;
	}
	P = L->Next;
	while( P != NULL )
	{
		printf("%d ",P->Element);
			P = P->Next;
	}

    middle = Search_Moddle(L);
    printf("middle element is %d\n", middle->Element);

	/******��L����****/
	L = List_Reverse(L);
	P = L->Next;
	while( P != NULL )
	{
		printf("%d ",P->Element);
			P = P->Next;
	}
	L->Next->Next->Next->Next = L->Next;
    printf("IsLoop ? %s\n", IsLoop(L, &P)? "yes": "no");
    printf("%d", P->Element);
    getchar();
    return 0;
}



/*** ����������˳���෴*************/
/*
int main()
{
	List L = CreatHeader();
	Position P = L;
	int temp = 0;

	while( scanf("%d", &temp) == 1 )
	{
		Insert( temp, L, L );	//�ӿ�ͷ����
	//	P = P->Next;
	}
	P = L->Next;
	while( P != NULL )
	{
		printf("%d",P->Element);
			P = P->Next;
	}

	while(1);
}
*/
