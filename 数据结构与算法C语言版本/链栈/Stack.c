#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>


Stack CreateStack( int MaxElements )
{
	Stack S;
	if( MaxElements < MinStackSize )
		perror("Stack size is too small\n");
	S = ( Stack )malloc( sizeof( struct StackRecord) );
	if( S = NULL )
		perror("Out if Space !\n");
	S->Array =( ElementType * )malloc( sizeof( ElementType ) * MaxElements );
	if( S->Array == NULL )
		perror("Out if Space !\n");
	S->Capacity = MaxElements;
	S->TopOfStack = EmptyTOS;

	return S;
}

void main()
{
}