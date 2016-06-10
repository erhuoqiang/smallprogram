#include<stdio.h>
#include<stdlib.h>

#define NULL ((void *)0)
typedef struct  list
{
	int data;
	struct list * next;
} list;

/*list * creat_list(void)
{
	list * head, * tail, * p;
	int e = 0;
	head = tail = (list *)malloc(sizeof(list));
	
	printf("please input:");
	scanf("%d", &e);
	while(e)
	{
		p = (list *)malloc(sizeof(list));
		p->data = e;
		tail->next = p;
		tail = p;
		scanf("%d", &e);
	}
	tail->next = NULL;
		return head->next;
}
void Creat_list()
{
	Student p1, p2;
	int num = 0;
	p1 = p2 = head = (Student)malloc(sizeof(struct student));
	while(scanf("%d",&p1->data) == 1)
	{
			p2->next = p1;
			p2 = p1;
			p1 = (Student)malloc(sizeof(struct student));
	}
	p1 = NULL;
	p2->next = p1;
}*/

list * creat_list(void)
{
	list * p1, * p2, * head;
	int n = 0;
	head = p1 = p2 = (list *)malloc(sizeof(list));
	printf("please input:\n");
	scanf("%d", &p1->data);
	while(p1->data != 0 )
	{
		n++;
		if(n == 1)
			head = p1;
		else
		    p2->next = p1;
			p2 = p1;
			p1 = (list *)malloc(sizeof(list));
			scanf("%d", &p1->data );
	}
	p2->next = NULL;
	return head;
		
}

void output_list( list * head )
{
	while( head != NULL )
	{
		printf("%d ", head->data);
		head = head -> next;
	}
	printf("\n");
}

list * list_reverse(list * head)
{
	if (head != NULL && head->next != NULL)
	{
	  list * r, * p, * q;
	  p = head;
	  q = p->next;
	  
	  while( q != NULL )
	  {
		  r = q->next; 
		  q->next = p;
		  p = q;
		  q = r;
		}
	  head->next = NULL;
	  head = p;
	}
	
	return head;
}

void main()
{
    list * head;
	head = creat_list();
	output_list( head );
	head = list_reverse(head);
	output_list( head );
}
	