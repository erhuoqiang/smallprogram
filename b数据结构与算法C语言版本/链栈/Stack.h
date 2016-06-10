#ifndef _Stack_h
#define _Stack_h

#define ElementType int
#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )

struct StackRecord;
typedef struct StackRecord * Stack;

int IsEmpty( Stack S );
int IsFull( Stack S );
Stack CreatStack( void );
void DisposeStack( Stack S );
void MakeEmpty( Stack S );
void Push( ElementType X, Stack S);
ElementType Top( Stack S );
void Pop( Stack S );
ElementType TopAndPop( Stack S );

#endif


struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};
