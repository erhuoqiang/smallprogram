#include<stdio.h>

void one(int a)
{
	printf("one %d\n",a);
}
void two(int a)
{
	printf("two %d\n",a);
}

void main()
{	
	void (*p[2])(int);
	p[0] = &one;
	p[1] = one;
	(*p[1])(5);;

}