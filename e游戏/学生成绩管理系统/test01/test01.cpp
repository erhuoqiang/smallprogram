#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct scorenode)
#define DEBUG

/*===========���ݽṹ==========*/
struct scorenode
{
	int number;				//ѧ��ѧ��
	char name[10];			//ѧ������
	float chinese;			//���ĳɼ�
	float mathmatic;		//��ѧ�ɼ�
	float english;			//Ӣ��ɼ� 
	struct scorenode *next;
};
typedef struct scorenode score;		//����ṹ�����
int n,k; 
/*n,kΪȫ�ֱ������������еĺ���������ʹ����,�ֱ����ڼ����ͱ��*/

/*==========��������==========*/
/*����creatlink,���ܣ����������˺�������һ��ָ������ͷ��ָ��*/
score *creatlink()
{
	score*head;
	score *p1,*p2,*p3,*max;
	int i,j;
	float fen;
	char t[10];
	n=0;
	p1=p2=p3=(score *)malloc(LEN);head=p3;					//����һ���µ�Ԫ
	printf("������ѧ�����ϣ���0�˳�!\n");
	repeat1: printf("������ѧ��ѧ��(ѧ��Ӧ����0)��");		//����ѧ�ţ�ѧ��Ӧ����0
	scanf("%d",&p1->number);
	while(p1->number<0)
	{
		getchar();
		printf("�����������������ѧ��ѧ��:");
		scanf("%d",&p1->number);}							//����ѧ��Ϊ�ַ���С��0ʱ�����򱨴���ʾ��������ѧ�� 
		if(p1->number==0)
		goto end;											//�������ѧ��Ϊ0ʱ��ת��ĩβ��������������
		else  
		{ 
			p3=head;
			if(n>0)
			{
				for(i=0;i<n;i++)
				{
					if(p1->number!=p3->number)
						p3=p3->next;
					else 
					{
						printf("ѧ���ظ�,������!\n");
						 goto repeat1;
						/*�������ѧ���Ѿ����ڣ����򱨴�����ǰ����������*/
					}
				}     
			}          
		}
	printf("������ѧ��������");
	scanf("%s",&p1->name);                                          /*����ѧ������*/
	printf("���������ĳɼ�(0~100)��");            /*�������ĳɼ����ɼ�Ӧ��0-100*/
	scanf("%f",&p1->chinese);
	while(p1->chinese<0||p1->chinese>100)
	{
		getchar();
		printf("��������������������ĳɼ�");           /*������������������ĳɼ�ֱ����ȷΪֹ*/
       scanf("%f",&p1->chinese);}
       printf("��������ѧ�ɼ�(0~100)��");            /*������ѧ�ɼ����ɼ�Ӧ��0-100*/
       scanf("%f",&p1->mathmatic);
    while(p1->mathmatic<0||p1->mathmatic>100)
   {getchar();
    printf("�������������������ѧ�ɼ�");           /*�����������������ѧ�ɼ�ֱ����ȷΪֹ*/
    scanf("%f",&p1->mathmatic);}
    printf("������Ӣ��ɼ�(0~100)��");                       /*����Ӣ��ɼ����ɼ�Ӧ��0-100*/
    scanf("%f",&p1->english);
    while(p1->english<0||p1->english>100)
    {getchar();
     printf("�����������������Ӣ��ɼ�");
     scanf("%f",&p1->english);}                     /*���������������Ӣ��ɼ�ֱ����ȷΪֹ*/
     head=NULL;
 while(p1->number!=0)
  {
    n=n+1;
 if(n==1)  
    head=p1;
 else
    p2->next=p1;
    p2=p1;
    p1=(score *)malloc(LEN);
    printf("������ѧ�����ϣ���0�˳�!\n");
repeat2:printf("������ѧ��ѧ��(ѧ��Ӧ����0)��");
    scanf("%d",&p1->number);                            /*����ѧ�ţ�ѧ��Ӧ����0*/
    while(p1->number<0)
   {getchar();
    printf("�������,����������ѧ��ѧ��:");
       scanf("%d",&p1->number);}          /*����ѧ��Ϊ�ַ���С��0ʱ�����򱨴���ʾ��������ѧ��*/
  if(p1->number==0)
   goto end;                             /*�������ѧ��Ϊ0ʱ��ת��ĩβ��������������*/
  else
  {
  p3=head;
  if(n>0)
   {for(i=0;i<n;i++)
      {if(p1->number!=p3->number)
    p3=p3->next;
    else 
    {printf("ѧ���ظ�,������!\n");
     goto repeat2;                       /*�������ѧ���Ѿ����ڣ����򱨴�����ǰ����������*/
        }
    }     
   }          
  }
  printf("������ѧ��������");
  scanf("%s",&p1->name);                             /*����ѧ������*/
  printf("���������ĳɼ�(0~100)��");
   scanf("%f",&p1->chinese);           /*�������ĳɼ����ɼ�Ӧ��0-100*/
  while(p1->chinese<0||p1->chinese>100)
{
getchar();
   printf("��������������������ĳɼ�");
   scanf("%f",&p1->chinese);}             /*������������������ĳɼ�ֱ����ȷΪֹ*/
   printf("��������ѧ�ɼ�(0~100)��");
   scanf("%f",&p1->mathmatic);        /*������ѧ�ɼ����ɼ�Ӧ��0-100*/
  while(p1->mathmatic<0||p1->mathmatic>100)
{
getchar();
   printf("�������������������ѧ�ɼ�");
   scanf("%f",&p1->mathmatic);}              /*�����������������ѧ�ɼ�ֱ����ȷΪֹ*/
   printf("������Ӣ��ɼ�(0~100)��");
   scanf("%f",&p1->english);                 /*����Ӣ��ɼ����ɼ�Ӧ��0-100*/
   while(p1->english<0||p1->english>100)
   {getchar();
   printf("�����������������Ӣ��ɼ�");
   scanf("%f",&p1->english);}               /*���������������Ӣ��ɼ�ֱ����ȷΪֹ*/
}
end:
     p3=p1;
  for(i=1;i<n;i++)
  {max=head;p1=head;
for(j=i+1;j<=n;j++)
    {
       max=p1;
       p1=p1->next;
       if(max->number>p1->number)
        {
          k=max->number;
          max->number=p1->number;
          p1->number=k;                    /*����ǰ�����е�ѧ��ֵ��ʹ��ѧ�Ŵ����Ƶ�����Ľ����*/
         strcpy(t,max->name);
         strcpy(max->name,p1->name);
         strcpy(p1->name,t);                /*����ǰ�����е�������ʹ֮��ѧ����ƥ��*/
         fen=max->chinese;
         max->chinese=p1->chinese;
         p1->chinese=fen;                     /*����ǰ�����е����ĳɼ���ʹ֮��ѧ����ƥ��*/
         fen=max->mathmatic;
         max->mathmatic=p1->mathmatic;
         p1->mathmatic=fen;                   /*����ǰ�����е���ѧ�ɼ���ʹ֮��ѧ����ƥ��*/
         fen=max->english;
         max->english=p1->english;
         p1->english=fen;                     /*����ǰ�����е�Ӣ��ɼ���ʹ֮��ѧ����ƥ��*/
         }
    }
                           /*����ʹmax,pָ������ͷ*/
  } 
p2->next=NULL;                                       /*�����β*/
  printf("�����ѧ����Ϊ:%d��!\n",n);
 return(head);
}



/*==========��ʾ����==========*/
/*����print,���ܣ���ʾѧ���ɼ�*/
void print(score *head)
{
 score *p;
 if(head==NULL)      
     {printf("\nû���κ�ѧ������!\n");}
 else
  { printf("%d\n",n);
   printf("-----------------------------------------\n");
printf("|ѧ��\t|����\t|����\t|��ѧ\t|Ӣ��\t|\n");
   printf("-----------------------------------------\n");                       /*��ӡ�����*/
 p=head;
   do
    {printf("|%d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|\n",p->number,p->name,p->chinese,p->mathmatic,p->english);
     printf("-----------------------------------------\n");               /*��ӡ�����*/
     p=p->next;}while (p!=NULL);                            /*��ӡ�����*/
  }
}

/*==========���ѧ������==========*/
/*����add,���ܣ�׷��ѧ������,���ҽ�����ѧ�����ϰ�ѧ������*/
score *add(score *head,score *stu)
{
 score *p0,*p1,*p2,*p3,*max;
 int i,j;
 float fen;
 char t[10];  
 p3=stu=(score *)malloc(LEN);                           /*����һ���µ�Ԫ*/
  printf("\n����Ҫ���ӵ�ѧ��������!");
  repeat4: printf("������ѧ��ѧ��(ѧ��Ӧ����0)��");
  scanf("%d",&stu->number);                              /*����ѧ�ţ�ѧ��Ӧ����0*/
  while(stu->number<0)
   { getchar();
    printf("�����������������ѧ��ѧ��:");
    scanf("%d",&stu->number);}               /*���������������ѧ��*/         
    if(stu->number==0)                  
   goto end2;                              /*�������ѧ��Ϊ0ʱ��ת��ĩβ������׷��*/
  else 
  { 
   p3=head;
   if(n>0)
   {   for(i=0;i<n;i++)
      {   if(stu->number!=p3->number)
            p3=p3->next;
          else 
          {printf("ѧ���ظ�,������!\n");
           goto repeat4;       /*�������ѧ���Ѿ����ڣ����򱨴�����ǰ����������*/
          }
      }     
   }          
 }
 printf("����ѧ��������");
 scanf("%s",stu->name);                         /*����ѧ������*/
 printf("���������ĳɼ�(0~100)��");
 scanf("%f",&stu->chinese);                     /*�������ĳɼ����ɼ�Ӧ��0-100*/
 while(stu->chinese<0||stu->chinese>100)
  {  getchar();
     printf("��������������������ĳɼ�");
     scanf("%f",&stu->chinese);}                /*������������������ĳɼ�ֱ����ȷΪֹ*/
      printf("��������ѧ�ɼ�(0~100)��");
      scanf("%f",&stu->mathmatic);                  /*������ѧ�ɼ����ɼ�Ӧ��0-100*/
     while(stu->mathmatic<0||stu->mathmatic>100)
     {  getchar();
        printf("�������������������ѧ�ɼ�");
        scanf("%f",&stu->mathmatic);}            /*�����������������ѧ�ɼ�ֱ����ȷΪֹ*/
        printf("������Ӣ��ɼ�(0~100)��");
        scanf("%f",&stu->english);                /*����Ӣ��ɼ����ɼ�Ӧ��0-100*/
       while(stu->english<0||stu->english>100)
       {   getchar();
           printf("�����������������Ӣ��ɼ�");
           scanf("%f",&stu->english);
}                                  /*���������������Ӣ��ɼ�ֱ����ȷΪֹ*/
p1=head;
p0=stu;
if(head==NULL)
  {  head=p0;p0->next=NULL;}              /*��ԭ������Ϊ��ʱ�����׽�㿪ʼ�������*/
 else                                   /*����Ϊ��*/
 {
  if(p1->next==NULL)                    /*�ҵ�ԭ�������ĩβ*/
  {
   p1->next=p0;
   p0->next=NULL;                    /*�������¿���Ԫ������*/
  }
   else
  {
    while(p1->next!=NULL)                /*��û�ҵ�ĩβ��������*/
    {
     p2=p1;p1=p1->next;
    }
   p1->next=p0;
   p0->next=NULL;
  }
 }
 n=n+1;
p1=head;
p0=stu;
  for(i=1;i<n;i++)
  {
    for(j=i+1;j<=n;j++)
     {
       max=p1;
       p1=p1->next;
       if(max->number>p1->number)
        {
         k=max->number;
         max->number=p1->number;
         p1->number=k;                /*����ǰ�����е�ѧ��ֵ��ʹ��ѧ�Ŵ����Ƶ�����Ľ����*/
        strcpy(t,max->name);
        strcpy(max->name,p1->name);
        strcpy(p1->name,t);                   /*����ǰ�����е�������ʹ֮��ѧ����ƥ��*/
        fen=max->chinese;
        max->chinese=p1->chinese;
        p1->chinese=fen;                /*����ǰ�����е����ĳɼ���ʹ֮��ѧ����ƥ��*/
        fen=max->mathmatic;
        max->mathmatic=p1->mathmatic;
        p1->mathmatic=fen;                 /*����ǰ�����е���ѧ�ɼ���ʹ֮��ѧ����ƥ��*/
        fen=max->english;
        max->english=p1->english;
        p1->english=fen;                   /*����ǰ�����е�Ӣ��ɼ���ʹ֮��ѧ����ƥ��*/
       }
  }
    max=head;p1=head ;                    /*����ʹmax,pָ������ͷ*/
  } end2:
 printf("���ڵ�ѧ����Ϊ:%d��!\n",n);
 return(head);
}

/*==========��ѯ����==========*/
/*����search,���ܣ���ѯѧ���ɼ�*/
score *search(score *head)
{
 int number;
 score *p1,*p2;
 printf("����Ҫ��ѯ��ѧ����ѧ�ţ�");
 scanf("%d",&number);
while(number!=0)
{
  if(head==NULL)
  { printf("\nû���κ�ѧ������!\n");return(head);}
   printf("-----------------------------------------\n");
   printf("|ѧ��\t|����\t|����\t|��ѧ\t|Ӣ��\t|\n");
   printf("-----------------------------------------\n");/*��ӡ�����*/
   p1=head;
   while(number!=p1->number&&p1->next!=NULL)
    {p2=p1;p1=p1->next;} 
   if(number==p1->number)  
   {   printf("|%d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|\n",p1->number,p1->name,p1->chinese,p1->mathmatic,p1->english);
       printf("-----------------------------------------\n");
}                    /*��ӡ�����*/
   else 
      printf("%d�����ڴ�ѧ��!\n",number);
   printf("����Ҫ��ѯ��ѧ����ѧ��,");
  scanf("%d",&number);
}
printf("�Ѿ��˳���!\n");
return(head);
}

/*==========ɾ������==========*/
/*����dele�����ܣ�ɾ��ѧ������*/
score *dele(score *head) 
{
 score *p1,*p2;
 int number;
 printf("����Ҫɾ����ѧ����ѧ��(����0ʱ�˳�):");
 scanf("%d",&number);
 getchar();
 while(number!=0)                                  /*����ѧ��Ϊ0ʱ�˳�*/
 {
  if(head==NULL)
  {
   printf("\nû���κ�ѧ������!\n");
   return(head);
  }
  
  p1=head;
   while(number!=p1->number&&p1->next!=NULL)  /*p1ָ��Ĳ�����Ҫ�ҵ��׽�㣬���Һ��滹�н��*/
   {
   p2=p1;p1=p1->next;
   }                                            /*p1����һ�����*/
   if(number==p1->number)                                 /*�ҵ���*/
  {
   if(p1==head)
    head=p1->next;                          /*��p1ָ������׽�㣬�ѵض�������ַ����head*/
   else 
    p2->next=p1->next;                    /*������һ������ַ ����ǰһ����ַ*/
   printf("ɾ��:%d\n",number);n=n-1;
   }
  else
   printf("%d�����ڴ�ѧ��!\n",number);          /*�Ҳ����ý��*/
   printf("����Ҫɾ����ѧ����ѧ��:");
   scanf("%d",&number);
   getchar();
 }
#ifdef DEBUG 
 printf("�Ѿ��˳���!\n");
#endif
printf("���ڵ�ѧ����Ϊ:%d��!\n",n);
 return(head);
}

/*==========����==========*/
/*�������������˺�������һ��ָ������ͷ��ָ��*/
score *sortdata(score *head) 
 { 
  score *p,*max;
  int  i,j,x;
  float fen;
  char t[10];
  if(head==NULL)
  {printf("\nû���κ�ѧ�����ϣ����Ƚ�������!\n");return(head);}           /*����Ϊ��*/
  max=p=head;
  
  for(i=0;i<80;i++)
  printf("*");
    printf("1��ѧ��ѧ������\t2��ѧ����������\t3�����ĳɼ�����\n");
    printf("4����ѧ�ɼ�����\t5��Ӣ��ɼ�����\t\n");
  for(i=0;i<80;i++)
  printf("*");
  printf("��ѡ�����:");
  scanf("%d",&x);                                 /*ѡ�����*/
  getchar();
  switch(x)                                         /*��switch���ʵ�ֹ���ѡ��*/
  {case 1 :  
           for(i=1;i<n;i++)
          {
             for(j=i+1;j<=n;j++)
              {
                 max=p;
                 p=p->next;
                 if(max->number>p->number)
                {
        k=max->number;
        max->number=p->number;
        p->number=k;               /*����ǰ�����е�ѧ��ֵ��ʹ��ѧ�Ŵ����Ƶ�����Ľ����*/
        strcpy(t,max->name);
        strcpy(max->name,p->name);
        strcpy(p->name,t);          /*����ǰ�����е�������ʹ֮��ѧ����ƥ��*/
        fen=max->chinese;
        max->chinese=p->chinese;
        p->chinese=fen;            /*����ǰ�����е����ĳɼ���ʹ֮��ѧ����ƥ��*/
        fen=max->mathmatic;
        max->mathmatic=p->mathmatic;
        p->mathmatic=fen;            /*����ǰ�����е���ѧ�ɼ���ʹ֮��ѧ����ƥ��*/
        fen=max->english;
        max->english=p->english;
        p->english=fen;               /*����ǰ�����е�Ӣ��ɼ���ʹ֮��ѧ����ƥ��*/
          }
 }
      max=head;p=head;/*����ʹmax,pָ������ͷ*/
     }
       print(head);break;/*��ӡֵ��������������*/
   case 2 :   for(i=1;i<n;i++)
        {
    for(j=i+1;j<=n;j++)
    {
     max=p;
     p=p->next;
      if(strcmp(max->name,p->name)>0)/*strcmp=>�ַ����ȽϺ���*/
      {
       strcpy(t,max->name);/*strcpy=>�ַ������ƺ���*/
       strcpy(max->name,p->name);
       strcpy(p->name,t);          /*����ǰ�����е�������ʹ�������ַ�����ֵ�����Ƶ�����Ľ����*/
       k=max->number;
       max->number=p->number;
       p->number=k;                 /*����ǰ�����е�ѧ��ֵ��ʹ֮��������ƥ��*/
     fen=max->chinese;
       max->chinese=p->chinese;
       p->chinese=fen;                        /*����ǰ�����е����ĳɼ���ʹ֮��������ƥ��*/
       fen=max->mathmatic;
       max->mathmatic=p->mathmatic;
       p->mathmatic=fen;               /*����ǰ�����е���ѧ�ɼ���ʹ֮��������ƥ��*/
       fen=max->english;
       max->english=p->english;
       p->english=fen;                 /*����ǰ�����е�Ӣ��ɼ���ʹ֮��������ƥ��*/
      }
    }
       p=head;
       max=head;
     }
 print(head);
    break;
   case 3 :     for(i=1;i<n;i++)
                {for(j=i+1;j<=n;j++)
                 {max=p;
      p=p->next;
      if(max->chinese>p->chinese)
      {
        fen=max->chinese;
        max->chinese=p->chinese;
        p->chinese=fen;          /*����ǰ�����е����ĳɼ���ʹ�����ĳɼ������Ƶ�����Ľ����*/
       k=max->number;
       max->number=p->number;
       p->number=k;             /*����ǰ�����е�ѧ�ţ�ʹ֮�����ĳɼ���ƥ��*/
      strcpy(t,max->name);
      strcpy(max->name,p->name);
      strcpy(p->name,t);           /*����ǰ�����е�������ʹ֮�����ĳɼ���ƥ��*/
      fen=max->mathmatic;
      max->mathmatic=p->mathmatic;
      p->mathmatic=fen;              /*����ǰ�����е���ѧ�ɼ���ʹ֮�����ĳɼ���ƥ��*/
      fen=max->english;
      max->english=p->english;
      p->english=fen;                 /*����ǰ�����е�Ӣ��ɼ���ʹ֮�����ĳɼ���ƥ��*/
       }
    }
       p=head;
        max=head;
    }
    print(head);
    break;
   case 4 :      for(i=1;i<n;i++)
    {for(j=i+1;j<=n;j++)
     {max=p;
      p=p->next;
      if(max->mathmatic>p->mathmatic)
       {
         fen=max->mathmatic;
         max->mathmatic=p->mathmatic;
         p->mathmatic=fen;      /*����ǰ�����е���ѧ�ɼ���ʹ����ѧ�ɼ������Ƶ�����Ľ����*/
         k=max->number;
        max->number=p->number;
        p->number=k;                  /*����ǰ�����е�ѧ�ţ�ʹ֮����ѧ�ɼ���ƥ��*/
       strcpy(t,max->name);
       strcpy(max->name,p->name);
       strcpy(p->name,t);               /*����ǰ�����е�������ʹ֮����ѧ�ɼ���ƥ��*/
      fen=max->chinese;
      max->chinese=p->chinese;
      p->chinese=fen;                    /*����ǰ�����е����ĳɼ���ʹ֮����ѧ�ɼ���ƥ��*/
      fen=max->english;
      max->english=p->english;
      p->english=fen;                    /*����ǰ�����е�Ӣ��ɼ���ʹ֮����ѧ�ɼ���ƥ��*/
       }
    }
       p=head;
       max=head;
   }
    print(head);
    break;
   case 5 :      for(i=1;i<n;i++)
     {for(j=i+1;j<=n;j++)
       {max=p;
        p=p->next;
        if(max->english>p->english)
        {
         fen=max->english;
         max->english=p->english;
         p->english=fen;      /*����ǰ�����е�Ӣ��ɼ���ʹ��Ӣ��ɼ������Ƶ�����Ľ����*/
        k=max->number;
        max->number=p->number;
        p->number=k;              /*����ǰ�����е�ѧ�ţ�ʹ֮��Ӣ��ɼ���ƥ��*/
       strcpy(t,max->name);
      strcpy(max->name,p->name);
      strcpy(p->name,t);             /*����ǰ�����е�������ʹ֮��Ӣ��ɼ���ƥ��*/
      fen=max->chinese;
      max->chinese=p->chinese;
      p->chinese=fen;               /*����ǰ�����е����ĳɼ���ʹ֮��Ӣ��ɼ���ƥ��*/
      fen=max->mathmatic;
      max->mathmatic=p->mathmatic;
      p->mathmatic=fen;             /*����ǰ�����е���ѧ�ɼ���ʹ֮��Ӣ��ɼ���ƥ��*/
      }
     }
      p=head;
      max=head;
   }
    print(head);
    break;
   default :printf("�������,������! \n");
  }
   return (0);
}

/*==========��������==========*/
/*����save,���ܣ�����ѧ��������*/
save(score *p1) 
{ 
  FILE *fp;
  char filepn[20];/*��������ļ�����·���Լ��ļ���*/
  printf("�������ļ�·�����ļ���:");
 scanf("%s",filepn);
 if((fp=fopen(filepn,"w+"))==NULL)
 {
  printf("���ܴ��ļ�!\n");
  return 0;
 }
    fprintf(fp,"            ѧ���ɼ�����ϵͳ             \n");
   fprintf(fp,"\n");
    fprintf(fp,"-----------------------------------------\n");
 fprintf(fp,"|ѧ��\t|����\t|����\t|��ѧ\t|Ӣ��\t|\n");
    fprintf(fp,"-----------------------------------------\n");             /*��ӡ�����*/
 while(p1!=NULL)
 {
 fprintf(fp,"%d\t%s\t%.1f\t%.1f\t%.1f\t\n",p1->number,p1->name,p1->chinese,p1->mathmatic,p1->english);
 p1=p1->next;                                          /*����һ�����*/
}
 fclose(fp);
 printf("�ļ��Ѿ�����!\n");
 return 0;
}

/*==========�����ļ�==========*/
/*����loadfile������:���ļ�����ѧ����¼*/
score *loadfile(score *head)
{
   score *p1,*p2;
   int m=0;
   char filename[10];
  FILE *fp;
  printf("�������ļ�·�����ļ���:");
  scanf("%s",filename);/*�����ļ�·��������*/
  if((fp=fopen(filename,"r+"))==NULL)
 {
  printf("���ܴ��ļ�!\n");
  return 0;
 }
     fscanf(fp,"            ѧ���ɼ�����ϵͳ             \n");
     fscanf(fp,"\n");
        fscanf(fp,"-----------------------------------------\n");
  fscanf(fp,"|ѧ��\t|����\t|����\t|��ѧ\t|Ӣ��\t|\n");
        fscanf(fp,"-----------------------------------------\n");                        /*��������*/
  printf("            ѧ���ɼ�����ϵͳ             \n");
     printf("\n");
        printf("-----------------------------------------\n");
  printf("|ѧ��\t|����\t|����\t|��ѧ\t|Ӣ��\t|\n");
        printf("-----------------------------------------\n");                         /*��ӡ�����*/
  m=m+1;  
  if(m==1)
  {
  
  p1=(score *)malloc(LEN);                                            /*����һ���µ�Ԫ*/
  fscanf(fp,"%d%s%f%f%f",&p1->number,p1->name,&p1->chinese,&p1->mathmatic,&p1->english);
         printf("|%d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|\n",p1->number,p1->name,p1->chinese,p1->mathmatic,p1->english);
    /*�ļ���������ʾ*/
  head=NULL;
  do
  {
   n=n+1;
   if(n==1) head=p1;
   else p2->next=p1;
   p2=p1;
   p1=(score *)malloc(LEN);                        /*����һ���µ�Ԫ*/
      fscanf(fp,"%d%s%f%f%f\n",&p1->number,p1->name,&p1->chinese,&p1->mathmatic,&p1->english);
            printf("|%d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|\n",p1->number,p1->name,p1->chinese,p1->mathmatic,p1->english);
           /*�ļ���������ʾ*/
  }while(!feof(fp));
  p2->next=p1;
  p1->next=NULL;
  n=n+1; 
 }
printf("-----------------------------------------\n");                   /*�������*/
  fclose(fp);                                               /*�������룬�ر��ļ�*/
      
 return (head);
}

/*==========ͳ��==========*/
/*����statistics,���ܣ�ͳ��ѧ���ɼ�*/
score *statistics(score *head)
{
float sum1=0,sum2=0,sum3=0,ave1=0,ave2=0,ave3=0,max=0,min=0;
  char maxname[10],minname[10];
  score *p;
  int x,y=0,i=0;
  p=head;
  printf("1�����ֺܷ�ƽ����\t2����ƽ����\t3�ܷ���߷ֺ���ͷ�\n");
  scanf("%d",&x);
  getchar();
switch(x)                /*��switch���ʵ�ֹ���ѡ��*/
  {
 case 1: if(head==NULL)
  {printf("\nû���κ�ѧ������!\n");return(head);}/*����Ϊ��*/
  else
  {
     printf("---------------------------------------------------------\n");
     printf("|ѧ��\t|����\t|����\t|��ѧ\t|Ӣ��\t|�ܷ�\t|ƽ����\t|\n");
     printf("---------------------------------------------------------\n");/*��ӡ�����*/
     while(p!=NULL)
     {
      sum1=p->chinese+p->mathmatic+p->english;  /*��������ܷ�*/                            
      ave1=sum1/3;                             /*�������ƽ����*/
                     printf("|%d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|%.1f\t|%.1f\t|\n",p->number,p->name,p->chinese,p->mathmatic,p->english,sum1,ave1);                                     /*��ӡ���*/
      printf("---------------------------------------------------------\n");/*��ӡ�����*/
     p=p->next;}
    }
return(head);    break;
  case 2: if(head==NULL)
    {printf("\nû���κ�ѧ������!\n");return(head);}           /*����Ϊ��*/
     while(p!=NULL)
     { 
      sum1=sum1+p->chinese;
      sum2=sum2+p->mathmatic;
      sum3=sum3+p->english;                          /*�����ܷ�*/
       y=y+1;
       ave1=sum1/y;
       ave2=sum2/y;
       ave3=sum3/y;                                  /*����ƽ����*/
       p=p->next;/*ʹpָ����һ�����*/
       }
     printf("����ƽ������%.1f\n",ave1);
     printf("��ѧƽ������%.1f\n",ave2);
     printf("Ӣ��ƽ������%.1f\n",ave3);                   /*��ӡ���*/
      return(head); break;
  case 3: 
   if(head==NULL)
   {printf("\nû���κ�ѧ������!\n");return(head);}           /*����Ϊ��*/
    min=max=p->chinese+p->mathmatic+p->english;
   while(i<n)
  {   
    i=i+1;
    sum1=p->chinese+p->mathmatic+p->english;           /*��������ܷ�*/
    if(max<sum1)
    {
     max=sum1;
     strcpy(maxname,p->name);
     }
if(min>sum1)
  {
     min=sum1;
     strcpy(minname,p->name);
   }
  p=p->next;
  }
  printf("�ܷ���߷�:%.1f,������%s��",max,maxname);
  printf("\n");
  printf("�ܷ���ͷ�:%.1f,������%s",min,minname);
  printf("\n");
 return(head); break;
 default :printf("�������,������!\n");
 }
 return(head);
}

/*==========menu==========*/
/*����menu,���ܣ��˵�ѡ�����*/
int menu(int k) 
{
 int i;
 printf("\t\t\t\tѧ���ɼ�����ϵͳ\n");
 printf("\n");
 for(i=0;i<80;i++)
    printf("*");
printf("1�༭ѧ���ĳɼ�\t\t\t2��ʾѧ���ĳɼ�\t\t\t3��ѯѧ���ĳɼ�\n");
printf("4���ѧ���ĳɼ�\t\t\t5ɾ��ѧ���ĳɼ�\t\t\t6ѧ���ɼ�����\n");
printf("7����ѧ��������\t\t\t8ͳ��ѧ���ĳɼ�\t\t\t9��ȡѧ���ĳɼ�\n");
/*�˵�ѡ�����*/ 
for(i=0;i<80;i++)
printf("*");
printf("��ӭ����ѧ���ɼ�����ϵͳ����ѡ������Ҫ�Ĳ���(ѡ��(0)�˳�):");
scanf("%d",&k);/*ѡ�����*/
 //getchar();
return (k);
}

/*==========������==========*/
/*������main,���ܣ�ͨ������creat,search,dele,add,print,ststistics,save,sortdata�Ⱥ�����ʵ��ѧ���ɼ���ѯϵͳ����*/
void main() 
{
int k;
score *head=0,*stu=0;
while(1)
{
k=menu(k);
switch(k)                                                /*��switch���ʵ�ֹ���ѡ��*/
{case 1:head=creatlink();break;                              /*���ô���������*/
 case 2: print(head); break;                                 /*������ʾѧ�����Ϻ���*/
 case 3: head=search (head);break;                           /*���óɼ���ѯ����*/ 
 case 4: head=add (head,stu);break;                          /*����׷��ѧ�����Ϻ���*/
 case 5: head=dele (head); break;                            /*����ɾ��ѧ�����Ϻ���*/
 case 6: sortdata(head);break;                               /*����������*/
 case 7: save (head);break;                                 /*���ñ��溯��*/
 case 8: statistics(head); break;                             /*����ͳ�ƺ���*/
 case 9: head=loadfile(head);break;                          /*���ļ������¼����*/
 case 0:exit(0);/*�˳�ϵͳ������������*/
 default: printf("�������,������!\n"); }
}
}
