#ifndef LIST_H
#define LIST_H

#ifndef STDLIB_H
#define STDLIB_H
#include<stdlib.h>
#endif

#define ElementType int  
struct Node;
typedef struct Node * PtrToNode;
typedef struct Node	  Node;
typedef PtrToNode List;
typedef PtrToNode Position;

List CreatHeader(void); //创建一个空表头
int IsEmpty( List L );  //判断是否为空
int IsLast( Position P, List L ); //判断P是否为L的末尾元素
Position Find( ElementType X, List L ); //查找L列表中X元素
Position FindPrevious( ElementType X, List L ); //查找L列表中X元素的前一个元素
void Delete( ElementType X, List L );//删除列表L中的X元素
void Insert( ElementType X, List L, Position P ); //插入元素X 在L链表的P位置后面
void DeleteList( List L ); //删除
List List_Reverse(List L);//链表倒叙
struct Node
{
	ElementType Element;
	Position	Next;
};
#endif