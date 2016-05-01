#include<stdio.h>
#include "List.h"

/* CreatHeader */
List CreatHeader(void)
{
	List L = ( List )malloc( sizeof(Node) );
	if( L == NULL )
		printf("Creat error !Out of space!!");  //这里使用的是STDIO里面的函数 如果换平台需要注意
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

	if( !IsLast(P, L) ) //不是最后一个 则删除
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
		printf(" Insert error ! Out of space!!");  //这里使用的是STDIO里面的函数 如果换平台需要注意
	
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

/*****链表倒叙*******/
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

/*** 输入和输出的顺序一样*************/
int main()
{
	List L = CreatHeader();
	Position P = L;
	int temp = 0;

	while( scanf("%d", &temp) == 1 )
	{
		Insert( temp, L, P ); //从末尾插入
		P = P->Next;
	}
	P = L->Next;
	while( P != NULL )
	{
		printf("%d ",P->Element);
			P = P->Next;
	}
	/******将L倒叙****/
	L = List_Reverse(L);
	P = L->Next;
	while( P != NULL )
	{
		printf("%d ",P->Element);
			P = P->Next;
	}
	while(1);
}



/*** 输入和输出的顺序相反*************/
/*
int main()
{
	List L = CreatHeader();
	Position P = L;
	int temp = 0;

	while( scanf("%d", &temp) == 1 )
	{
		Insert( temp, L, L );	//从开头插入
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