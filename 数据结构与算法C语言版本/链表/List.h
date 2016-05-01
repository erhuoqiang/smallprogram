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

List CreatHeader(void); //����һ���ձ�ͷ
int IsEmpty( List L );  //�ж��Ƿ�Ϊ��
int IsLast( Position P, List L ); //�ж�P�Ƿ�ΪL��ĩβԪ��
Position Find( ElementType X, List L ); //����L�б���XԪ��
Position FindPrevious( ElementType X, List L ); //����L�б���XԪ�ص�ǰһ��Ԫ��
void Delete( ElementType X, List L );//ɾ���б�L�е�XԪ��
void Insert( ElementType X, List L, Position P ); //����Ԫ��X ��L�����Pλ�ú���
void DeleteList( List L ); //ɾ��
List List_Reverse(List L);//������
struct Node
{
	ElementType Element;
	Position	Next;
};
#endif