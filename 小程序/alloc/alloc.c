#include<stdio.h>
#include"alloc.h"
#undef malloc
void * alloc( unsigned int size )
{
	void * new_mem;
	new_mem = (void * )malloc(size);
	if(new_mem == NULL)
	{
		printf(" Out of memory!\n");
		exit(1);
	}
	return new_mem;
}
