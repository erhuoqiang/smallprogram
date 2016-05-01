#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(struct student)
struct student
{	
	char a[20];	
	int num;
	int score;
	struct student *front;
	struct student *next;
};
struct student *head = NULL, *end = NULL;
void  creat()
{
	struct student *p2,*p1;
	int n=0;
	p1=p2=(struct student *)malloc(LEN);
	head=NULL;
	p1->front = NULL;
	scanf("%s%d%d",p1->a,&p1->num,&p1->score);
	while(p1->num!=0)
	{
		n++;
		if(n==1)
			head=p1;
		else
		{
			p2->next=p1;
			p1->front=p2;
		}
			p2=p1;
			p1=(struct student *)malloc(LEN);
		scanf("%s%d%d",p1->a,&p1->num,&p1->score);
		
	}
	p2->next=NULL;
	end = p2;
	//return head;

	
	}
void printh(struct student * head)
{
	printf("output:\n");
		while(head != NULL)
		{
			printf("%s %d %d \n",head->a,head->num,head->score);
			head=head->next;
		}
}
void printe(struct student * end)
{
	printf("output:\n");
		while(end != NULL)
		{
			printf("%s %d %d \n",end->a,end->num,end->score);
			end=end->front;
		}
}


		
void main()
{
		//	freopen("input.txt","r", stdin);
		//	freopen("output.txt","w", stdout);
		struct student *head_m = NULL, *end_m = NULL;
		creat();
		head_m = head;
		end_m = end;
		printh(head_m);
		printf("\n");
		printe(end_m);
		
}
