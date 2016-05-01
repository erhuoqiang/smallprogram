#include<stdio.h>
#include<stdlib.h>

typedef struct position
{
	int x;
	int y;
	struct position * next;
} * Position;
int i = 0;
void sort(Position  previous)
{
	int j = 0, k = 0;
	int temp = 0;
	Position  max, p1;
	max = p1 = previous;
	for( j = 0; j < i -1; j++)
	{
		max = p1 = previous;
		for( k = 0; k < i - 1 - j; k++)
		{
			max = p1;
			p1 = p1->next;
			if(p1->y > max->y)
			{
				temp = p1->y;
				p1->y = max->y;
				max->y = temp;
				
				temp = p1->x;
				p1->x = max->x;
				max->x = temp;
			}
		}
	}
}

int main()
{
	Position head, previous = (Position)malloc(sizeof(struct position)),temp;
	int num = 0;
	while(1)
	{
		while( scanf("%d ", &previous->y) == 1 )
		{
			if( i == 0 ) 
			{
				
				previous->next = NULL;
				i++;
				previous->x = i;
			}
			else
			{
				i++;
				previous->x = i;
				previous->next = head;

			}
			head = previous;
			sort(previous);
			previous = (Position)malloc(sizeof(struct position));
		}
		free(previous);
		previous = head;
		while(previous != NULL)
			{
				previous->x = i + 1 - previous->x;
				previous = previous->next;
			}
		previous = head;
			while(previous != NULL)
			{
				for(num = 0; num < previous->x;num++)
					printf("   ");
				printf("*");
				for(num = 0; previous->next != NULL && num < previous->y - previous->next->y ; num++)
					printf("\n|");
				temp = previous;
					previous = previous->next;
			}
			for(num = 0; num < temp->y;num++)
			{
				printf("\n|");
			}
			printf(" ");
			for( num = 1; num <= 10; num ++)
			{
				printf("--%d",num);
			}
			previous = head;
			while(previous != NULL)
			{
				previous->x = i + 1 - previous->x;
				previous = previous->next;
			}
			previous = (Position)malloc(sizeof(struct position));
	}
	
		
}
