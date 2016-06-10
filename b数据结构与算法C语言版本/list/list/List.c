#include "List.h"
#include <stdio.h>
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

/******���������м�Ԫ��*******/
Position Search_Moddle(List L)
{
    Position cur = NULL, middle = NULL;
    int i = 0, j = 0;
    if(L == NULL)
    {
        printf("List is NULL");
        return NULL;
    }
    cur = middle = L->Next;
    while(cur != NULL)
    {
        if( i / 2 > j )
        {
            j++;
            middle = middle->Next;
        }
        cur = cur->Next;
        i++;
    }
    return middle;
}

/*******�ػ�������**********/
int IsLoop(List L, List *start)
{
    Position stepone = L, steptwo = L;
    if( L == NULL || start == NULL || L->Next == NULL )
    {
        return 0;
    }
    do
    {
        stepone = stepone->Next;
        steptwo = steptwo->Next->Next;
    }
    while( steptwo != NULL && steptwo->Next && stepone != steptwo );

    if( stepone != steptwo )
    {
        return 0;
    }
    *start = stepone;
    return 1;
}

