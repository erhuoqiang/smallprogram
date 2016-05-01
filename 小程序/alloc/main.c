#include"alloc.h"
#include<stdio.h>
int main()
{
	int *p = MALLOC(4,int);
	printf("%p",p);
}