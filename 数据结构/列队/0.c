#include<stdio.h>

#define MAX_SIZE 40

typedef struct
{
	int head;
	int tail;
	char temp[MAX_SIZE];
}queue;

queue x = {0,0,0};

void push(char temp)
{
	int pos = (x.tail + 1) % MAX_SIZE;
//	printf("%d", pos);
	if( pos != x.head )
	{
		x.temp[x.tail] = temp;
		x.tail = pos;
	}
}

void pop(char * temp)
{
	if( x.head != x.tail )
	{
		*temp = x.temp[x.head];
			x.head++;
	}
}

int get_size()
{
	return ((x.tail - x.head + MAX_SIZE) % MAX_SIZE);
}

void queue_init()
{
	x.head = x.tail = 0;
}


int main()
{
	char i, size;
	char ch;
	queue_init();
	for( i = 1+48; i < 9 +48; i++)
	{
		
		push(i);
	}
	
	for( i = 0; i < 8; i++)
	{
		size = get_size();
		printf("leng:%d    ", size);
		pop(&ch);
		printf("%c ", ch);
	}
}