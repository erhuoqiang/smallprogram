#include<stdio.h>
#include<stdlib.h>

struct stack_node
{
	int data;
	struct stack_node * next;
};

typedef struct stack_node   list ;

list * stack = NULL;

void stack_print(void)
{
	list * temp = stack;
	if(temp == NULL)
		printf(" ¿ÕÕ» ");
	else
		while(temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
}
	
void push( int value )
{
	list * temp;
	temp = (list *)malloc(sizeof(list));
	temp->data = value;
	temp->next = stack;
	stack = temp;
}

int pop( void )
{
	list * top = stack;
	int temp = 0;
	if(top == NULL)
		printf(" ¿ÕÕ» ");
	else
	{
		stack = top->next;
		temp = top->data;
		free(top);
		return temp;
		
	}
	return -1;
}

void main()
{
	int temp = 0;
	list * temp1;
	temp1 = (list *)malloc(sizeof(list));
	scanf("%d", &temp);
	while(temp != 0)
	{
		push(temp);
		scanf("%d", &temp);
	}
	while(stack != 0)
	{
		temp =pop();
		printf("%d ", temp);
		
	}
	
}


