#include<stdio.h>
#include "List.h"

/* CreatHeader */
List CreatHeader(void)
{
	List L = ( List )malloc( sizeof(Node) );
	if( L == NULL )
		printf("Creat error !Out of space!!");  //����ʹ�õ���STDIO����ĺ��� �����ƽ̨��Ҫע��
	L->Next = NULL;
//	L->Element = 0;
	return L;
}
/* Return ture if L is empty */
int IsEmpty( List L )
{
	return L->Next == NULL;
}

/* Return ture if P is the last position in List L*/
/* Parameter L is unused in this implementation */
int IsLast( Position P, List L )
{
	return P->Next == NULL;
}

/* Return Position of X in L; if not found return NULL */
Position Find( ElementType X, List L )
{
	Position P;

	P = L->Next;
	while( P != NULL && P->Element != X )
		P = P->Next;
	return P;
}

/* If X is not found, then Next field of returned */
/* Position is NULL */
/* Assume a header */
Position FindPrevious( ElementType X, List L )
{
	Position P;

	P = L;
	while( P != NULL && P->Next->Element != X )
		P = P->Next;
	return P;
}
/* Delete first occurrence of X from a list */
/* Assume use of a header node */
void Delete( ElementType X, List L )
{
	Position P, TempCell;

	P = FindPrevious( X, L );

	if( !IsLast(P, L) ) //�������һ�� ��ɾ��
	{
		TempCell = P->Next;
		P->Next = TempCell->Next;
		free( TempCell );
	}
}

/* Insert (after legal position p) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void Insert( ElementType X, List L, Position P )
{
	Position TempCell;

	TempCell = malloc( sizeof(Node) );
	if(TempCell == NULL )
		printf(" Insert error ! Out of space!!");  //����ʹ�õ���STDIO����ĺ��� �����ƽ̨��Ҫע��
	
	TempCell->Element = X;
	TempCell->Next = P->Next;
	P->Next = TempCell;
}

/*  DeleteList */
void DeleteList( List L )
{
	Position P, TempCell;

	P = L->Next;
	L->Next = NULL;
	while( P != NULL )
	{
		TempCell = P->Next;
		free(P);
		P = TempCell;
	}
}

List First( List L )
{
	if( L->Next != NULL )
		return L->Next;
	else
		return NULL;
}

ElementType Retrieve( Position P )
{
		return P->Element;
}

/*****������*******/
List List_Reverse(List L)
{
	if (L != NULL && L->Next != NULL)
	{
	  List Fir, Sec, Thi;
	  Fir = L->Next;
	  Sec = Fir->Next;
		
	  while(Sec != NULL)
	  {
		  Thi = Sec->Next;
		  Sec->Next = Fir;
		  Fir = Sec;
		  Sec = Thi;
	  }
	  L->Next->Next = NULL;
	  L->Next = Fir;
	
      return L;
	}
	
	perror("List is NULL\n");
	return L;
}

/*** ����������˳��һ��*************/
int main()
{
	List L = CreatHeader();
	Position P = L;
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
	/******��L����****/
	L = List_Reverse(L);
	P = L->Next;
	while( P != NULL )
	{
		printf("%d ",P->Element);
			P = P->Next;
	}
	while(1);
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