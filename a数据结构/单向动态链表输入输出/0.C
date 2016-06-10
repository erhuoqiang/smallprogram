#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(struct student)
struct student
{	
	char a[20];	
	int num;
	int score;

	struct student *next;
};
struct student * creat()
{
	struct student *head,*p2,*p1;
	int n=0;
	p1=p2=(struct student *)malloc(LEN);
	head=NULL;
	scanf("%s%d%d",p1->a,&p1->num,&p1->score);
	while(p1->num!=0)
	{
		n++;
		if(n==1)
			head=p1;
		else
			p2->next=p1;
			p2=p1;
			p1=(struct student *)malloc(LEN);
		scanf("%s%d%d",p1->a,&p1->num,&p1->score);
		
	}
	p2->next=NULL;
	return head;

	
	}
void print(struct student * head)
{
	printf("output:\n");
		while(head != NULL)
		{
			printf("%s %d %d \n",head->a,head->num,head->score);
			head=head->next;
		}
}


		
		
		void main()
		{
		//	freopen("input.txt","r", stdin);
		//	freopen("output.txt","w", stdout);
	print(creat());
		
}
