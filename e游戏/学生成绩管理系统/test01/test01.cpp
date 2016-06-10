#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct scorenode)
#define DEBUG

/*===========数据结构==========*/
struct scorenode
{
	int number;				//学生学号
	char name[10];			//学生姓名
	float chinese;			//语文成绩
	float mathmatic;		//数学成绩
	float english;			//英语成绩 
	struct scorenode *next;
};
typedef struct scorenode score;		//定义结构体变量
int n,k; 
/*n,k为全局变量，本程序中的函数均可以使用它,分别用于记数和标记*/

/*==========创建链表==========*/
/*函数creatlink,功能：创建链表，此函数带回一个指向链表头的指针*/
score *creatlink()
{
	score*head;
	score *p1,*p2,*p3,*max;
	int i,j;
	float fen;
	char t[10];
	n=0;
	p1=p2=p3=(score *)malloc(LEN);head=p3;					//开辟一个新单元
	printf("请输入学生资料，输0退出!\n");
	repeat1: printf("请输入学生学号(学号应大于0)：");		//输入学号，学号应大于0
	scanf("%d",&p1->number);
	while(p1->number<0)
	{
		getchar();
		printf("输入错误，请重新输入学生学号:");
		scanf("%d",&p1->number);}							//输入学号为字符或小于0时，程序报错，提示重新输入学号 
		if(p1->number==0)
		goto end;											//当输入的学号为0时，转到末尾，结束创建链表
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
						printf("学号重复,请重输!\n");
						 goto repeat1;
						/*当输入的学号已经存在，程序报错，返回前面重新输入*/
					}
				}     
			}          
		}
	printf("请输入学生姓名：");
	scanf("%s",&p1->name);                                          /*输入学生姓名*/
	printf("请输入语文成绩(0~100)：");            /*输入语文成绩，成绩应在0-100*/
	scanf("%f",&p1->chinese);
	while(p1->chinese<0||p1->chinese>100)
	{
		getchar();
		printf("输入错误，请重新输入语文成绩");           /*输入错误，重新输入语文成绩直到正确为止*/
       scanf("%f",&p1->chinese);}
       printf("请输入数学成绩(0~100)：");            /*输入数学成绩，成绩应在0-100*/
       scanf("%f",&p1->mathmatic);
    while(p1->mathmatic<0||p1->mathmatic>100)
   {getchar();
    printf("输入错误，请重新输入数学成绩");           /*输入错误，重新输入数学成绩直到正确为止*/
    scanf("%f",&p1->mathmatic);}
    printf("请输入英语成绩(0~100)：");                       /*输入英语成绩，成绩应在0-100*/
    scanf("%f",&p1->english);
    while(p1->english<0||p1->english>100)
    {getchar();
     printf("输入错误，请重新输入英语成绩");
     scanf("%f",&p1->english);}                     /*输入错误，重新输入英语成绩直到正确为止*/
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
    printf("请输入学生资料，输0退出!\n");
repeat2:printf("请输入学生学号(学号应大于0)：");
    scanf("%d",&p1->number);                            /*输入学号，学号应大于0*/
    while(p1->number<0)
   {getchar();
    printf("输入错误,请重新输入学生学号:");
       scanf("%d",&p1->number);}          /*输入学号为字符或小于0时，程序报错，提示重新输入学号*/
  if(p1->number==0)
   goto end;                             /*当输入的学号为0时，转到末尾，结束创建链表*/
  else
  {
  p3=head;
  if(n>0)
   {for(i=0;i<n;i++)
      {if(p1->number!=p3->number)
    p3=p3->next;
    else 
    {printf("学号重复,请重输!\n");
     goto repeat2;                       /*当输入的学号已经存在，程序报错，返回前面重新输入*/
        }
    }     
   }          
  }
  printf("请输入学生姓名：");
  scanf("%s",&p1->name);                             /*输入学生姓名*/
  printf("请输入语文成绩(0~100)：");
   scanf("%f",&p1->chinese);           /*输入语文成绩，成绩应在0-100*/
  while(p1->chinese<0||p1->chinese>100)
{
getchar();
   printf("输入错误，请重新输入语文成绩");
   scanf("%f",&p1->chinese);}             /*输入错误，重新输入语文成绩直到正确为止*/
   printf("请输入数学成绩(0~100)：");
   scanf("%f",&p1->mathmatic);        /*输入数学成绩，成绩应在0-100*/
  while(p1->mathmatic<0||p1->mathmatic>100)
{
getchar();
   printf("输入错误，请重新输入数学成绩");
   scanf("%f",&p1->mathmatic);}              /*输入错误，重新输入数学成绩直到正确为止*/
   printf("请输入英语成绩(0~100)：");
   scanf("%f",&p1->english);                 /*输入英语成绩，成绩应在0-100*/
   while(p1->english<0||p1->english>100)
   {getchar();
   printf("输入错误，请重新输入英语成绩");
   scanf("%f",&p1->english);}               /*输入错误，重新输入英语成绩直到正确为止*/
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
          p1->number=k;                    /*交换前后结点中的学号值，使得学号大者移到后面的结点中*/
         strcpy(t,max->name);
         strcpy(max->name,p1->name);
         strcpy(p1->name,t);                /*交换前后结点中的姓名，使之与学号相匹配*/
         fen=max->chinese;
         max->chinese=p1->chinese;
         p1->chinese=fen;                     /*交换前后结点中的语文成绩，使之与学号相匹配*/
         fen=max->mathmatic;
         max->mathmatic=p1->mathmatic;
         p1->mathmatic=fen;                   /*交换前后结点中的数学成绩，使之与学号相匹配*/
         fen=max->english;
         max->english=p1->english;
         p1->english=fen;                     /*交换前后结点中的英语成绩，使之与学号相匹配*/
         }
    }
                           /*重新使max,p指向链表头*/
  } 
p2->next=NULL;                                       /*链表结尾*/
  printf("输入的学生数为:%d个!\n",n);
 return(head);
}



/*==========显示数据==========*/
/*函数print,功能：显示学生成绩*/
void print(score *head)
{
 score *p;
 if(head==NULL)      
     {printf("\n没有任何学生资料!\n");}
 else
  { printf("%d\n",n);
   printf("-----------------------------------------\n");
printf("|学号\t|姓名\t|语文\t|数学\t|英语\t|\n");
   printf("-----------------------------------------\n");                       /*打印表格域*/
 p=head;
   do
    {printf("|%d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|\n",p->number,p->name,p->chinese,p->mathmatic,p->english);
     printf("-----------------------------------------\n");               /*打印表格域*/
     p=p->next;}while (p!=NULL);                            /*打印完成了*/
  }
}

/*==========添加学生数据==========*/
/*函数add,功能：追加学生资料,并且将所有学生资料按学号排序*/
score *add(score *head,score *stu)
{
 score *p0,*p1,*p2,*p3,*max;
 int i,j;
 float fen;
 char t[10];  
 p3=stu=(score *)malloc(LEN);                           /*开辟一个新单元*/
  printf("\n输入要增加的学生的资料!");
  repeat4: printf("请输入学生学号(学号应大于0)：");
  scanf("%d",&stu->number);                              /*输入学号，学号应大于0*/
  while(stu->number<0)
   { getchar();
    printf("输入错误，请重新输入学生学号:");
    scanf("%d",&stu->number);}               /*输入错误，重新输入学号*/         
    if(stu->number==0)                  
   goto end2;                              /*当输入的学号为0时，转到末尾，结束追加*/
  else 
  { 
   p3=head;
   if(n>0)
   {   for(i=0;i<n;i++)
      {   if(stu->number!=p3->number)
            p3=p3->next;
          else 
          {printf("学号重复,请重输!\n");
           goto repeat4;       /*当输入的学号已经存在，程序报错，返回前面重新输入*/
          }
      }     
   }          
 }
 printf("输入学生姓名：");
 scanf("%s",stu->name);                         /*输入学生姓名*/
 printf("请输入语文成绩(0~100)：");
 scanf("%f",&stu->chinese);                     /*输入语文成绩，成绩应在0-100*/
 while(stu->chinese<0||stu->chinese>100)
  {  getchar();
     printf("输入错误，请重新输入语文成绩");
     scanf("%f",&stu->chinese);}                /*输入错误，重新输入语文成绩直到正确为止*/
      printf("请输入数学成绩(0~100)：");
      scanf("%f",&stu->mathmatic);                  /*输入数学成绩，成绩应在0-100*/
     while(stu->mathmatic<0||stu->mathmatic>100)
     {  getchar();
        printf("输入错误，请重新输入数学成绩");
        scanf("%f",&stu->mathmatic);}            /*输入错误，重新输入数学成绩直到正确为止*/
        printf("请输入英语成绩(0~100)：");
        scanf("%f",&stu->english);                /*输入英语成绩，成绩应在0-100*/
       while(stu->english<0||stu->english>100)
       {   getchar();
           printf("输入错误，请重新输入英语成绩");
           scanf("%f",&stu->english);
}                                  /*输入错误，重新输入英语成绩直到正确为止*/
p1=head;
p0=stu;
if(head==NULL)
  {  head=p0;p0->next=NULL;}              /*当原来链表为空时，从首结点开始存放资料*/
 else                                   /*链表不为空*/
 {
  if(p1->next==NULL)                    /*找到原来链表的末尾*/
  {
   p1->next=p0;
   p0->next=NULL;                    /*将它与新开单元相连接*/
  }
   else
  {
    while(p1->next!=NULL)                /*还没找到末尾，继续找*/
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
         p1->number=k;                /*交换前后结点中的学号值，使得学号大者移到后面的结点中*/
        strcpy(t,max->name);
        strcpy(max->name,p1->name);
        strcpy(p1->name,t);                   /*交换前后结点中的姓名，使之与学号相匹配*/
        fen=max->chinese;
        max->chinese=p1->chinese;
        p1->chinese=fen;                /*交换前后结点中的语文成绩，使之与学号相匹配*/
        fen=max->mathmatic;
        max->mathmatic=p1->mathmatic;
        p1->mathmatic=fen;                 /*交换前后结点中的数学成绩，使之与学号相匹配*/
        fen=max->english;
        max->english=p1->english;
        p1->english=fen;                   /*交换前后结点中的英语成绩，使之与学号相匹配*/
       }
  }
    max=head;p1=head ;                    /*重新使max,p指向链表头*/
  } end2:
 printf("现在的学生数为:%d个!\n",n);
 return(head);
}

/*==========查询数据==========*/
/*函数search,功能：查询学生成绩*/
score *search(score *head)
{
 int number;
 score *p1,*p2;
 printf("输入要查询的学生的学号：");
 scanf("%d",&number);
while(number!=0)
{
  if(head==NULL)
  { printf("\n没有任何学生资料!\n");return(head);}
   printf("-----------------------------------------\n");
   printf("|学号\t|姓名\t|语文\t|数学\t|英语\t|\n");
   printf("-----------------------------------------\n");/*打印表格域*/
   p1=head;
   while(number!=p1->number&&p1->next!=NULL)
    {p2=p1;p1=p1->next;} 
   if(number==p1->number)  
   {   printf("|%d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|\n",p1->number,p1->name,p1->chinese,p1->mathmatic,p1->english);
       printf("-----------------------------------------\n");
}                    /*打印表格域*/
   else 
      printf("%d不存在此学生!\n",number);
   printf("输入要查询的学生的学号,");
  scanf("%d",&number);
}
printf("已经退出了!\n");
return(head);
}

/*==========删除数据==========*/
/*函数dele，功能：删除学生资料*/
score *dele(score *head) 
{
 score *p1,*p2;
 int number;
 printf("输入要删除的学生的学号(输入0时退出):");
 scanf("%d",&number);
 getchar();
 while(number!=0)                                  /*输入学号为0时退出*/
 {
  if(head==NULL)
  {
   printf("\n没有任何学生资料!\n");
   return(head);
  }
  
  p1=head;
   while(number!=p1->number&&p1->next!=NULL)  /*p1指向的不是所要找的首结点，并且后面还有结点*/
   {
   p2=p1;p1=p1->next;
   }                                            /*p1后移一个结点*/
   if(number==p1->number)                                 /*找到了*/
  {
   if(p1==head)
    head=p1->next;                          /*若p1指向的是首结点，把地二个结点地址赋予head*/
   else 
    p2->next=p1->next;                    /*否则将下一个结点地址 赋给前一结点地址*/
   printf("删除:%d\n",number);n=n-1;
   }
  else
   printf("%d不存在此学生!\n",number);          /*找不到该结点*/
   printf("输入要删除的学生的学号:");
   scanf("%d",&number);
   getchar();
 }
#ifdef DEBUG 
 printf("已经退出了!\n");
#endif
printf("现在的学生数为:%d个!\n",n);
 return(head);
}

/*==========排序==========*/
/*定义排序函数。此函数带回一个指向链表头的指针*/
score *sortdata(score *head) 
 { 
  score *p,*max;
  int  i,j,x;
  float fen;
  char t[10];
  if(head==NULL)
  {printf("\n没有任何学生资料，请先建立链表!\n");return(head);}           /*链表为空*/
  max=p=head;
  
  for(i=0;i<80;i++)
  printf("*");
    printf("1按学生学号排序\t2按学生姓名排序\t3按语文成绩排序\n");
    printf("4按数学成绩排序\t5按英语成绩排序\t\n");
  for(i=0;i<80;i++)
  printf("*");
  printf("请选择操作:");
  scanf("%d",&x);                                 /*选择操作*/
  getchar();
  switch(x)                                         /*用switch语句实现功能选择*/
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
        p->number=k;               /*交换前后结点中的学号值，使得学号大者移到后面的结点中*/
        strcpy(t,max->name);
        strcpy(max->name,p->name);
        strcpy(p->name,t);          /*交换前后结点中的姓名，使之与学号相匹配*/
        fen=max->chinese;
        max->chinese=p->chinese;
        p->chinese=fen;            /*交换前后结点中的语文成绩，使之与学号相匹配*/
        fen=max->mathmatic;
        max->mathmatic=p->mathmatic;
        p->mathmatic=fen;            /*交换前后结点中的数学成绩，使之与学号相匹配*/
        fen=max->english;
        max->english=p->english;
        p->english=fen;               /*交换前后结点中的英语成绩，使之与学号相匹配*/
          }
 }
      max=head;p=head;/*重新使max,p指向链表头*/
     }
       print(head);break;/*打印值排序后的链表内容*/
   case 2 :   for(i=1;i<n;i++)
        {
    for(j=i+1;j<=n;j++)
    {
     max=p;
     p=p->next;
      if(strcmp(max->name,p->name)>0)/*strcmp=>字符串比较函数*/
      {
       strcpy(t,max->name);/*strcpy=>字符串复制函数*/
       strcpy(max->name,p->name);
       strcpy(p->name,t);          /*交换前后结点中的姓名，使得姓名字符串的值大者移到后面的结点中*/
       k=max->number;
       max->number=p->number;
       p->number=k;                 /*交换前后结点中的学号值，使之与姓名相匹配*/
     fen=max->chinese;
       max->chinese=p->chinese;
       p->chinese=fen;                        /*交换前后结点中的语文成绩，使之与姓名相匹配*/
       fen=max->mathmatic;
       max->mathmatic=p->mathmatic;
       p->mathmatic=fen;               /*交换前后结点中的数学成绩，使之与姓名相匹配*/
       fen=max->english;
       max->english=p->english;
       p->english=fen;                 /*交换前后结点中的英语成绩，使之与姓名相匹配*/
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
        p->chinese=fen;          /*交换前后结点中的语文成绩，使得语文成绩高者移到后面的结点中*/
       k=max->number;
       max->number=p->number;
       p->number=k;             /*交换前后结点中的学号，使之与语文成绩相匹配*/
      strcpy(t,max->name);
      strcpy(max->name,p->name);
      strcpy(p->name,t);           /*交换前后结点中的姓名，使之与语文成绩相匹配*/
      fen=max->mathmatic;
      max->mathmatic=p->mathmatic;
      p->mathmatic=fen;              /*交换前后结点中的数学成绩，使之与语文成绩相匹配*/
      fen=max->english;
      max->english=p->english;
      p->english=fen;                 /*交换前后结点中的英语成绩，使之与语文成绩相匹配*/
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
         p->mathmatic=fen;      /*交换前后结点中的数学成绩，使得数学成绩高者移到后面的结点中*/
         k=max->number;
        max->number=p->number;
        p->number=k;                  /*交换前后结点中的学号，使之与数学成绩相匹配*/
       strcpy(t,max->name);
       strcpy(max->name,p->name);
       strcpy(p->name,t);               /*交换前后结点中的姓名，使之与数学成绩相匹配*/
      fen=max->chinese;
      max->chinese=p->chinese;
      p->chinese=fen;                    /*交换前后结点中的语文成绩，使之与数学成绩相匹配*/
      fen=max->english;
      max->english=p->english;
      p->english=fen;                    /*交换前后结点中的英语成绩，使之与数学成绩相匹配*/
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
         p->english=fen;      /*交换前后结点中的英语成绩，使得英语成绩高者移到后面的结点中*/
        k=max->number;
        max->number=p->number;
        p->number=k;              /*交换前后结点中的学号，使之与英语成绩相匹配*/
       strcpy(t,max->name);
      strcpy(max->name,p->name);
      strcpy(p->name,t);             /*交换前后结点中的姓名，使之与英语成绩相匹配*/
      fen=max->chinese;
      max->chinese=p->chinese;
      p->chinese=fen;               /*交换前后结点中的语文成绩，使之与英语成绩相匹配*/
      fen=max->mathmatic;
      max->mathmatic=p->mathmatic;
      p->mathmatic=fen;             /*交换前后结点中的数学成绩，使之与英语成绩相匹配*/
      }
     }
      p=head;
      max=head;
   }
    print(head);
    break;
   default :printf("输入错误,请重试! \n");
  }
   return (0);
}

/*==========保存数据==========*/
/*函数save,功能：保存学生的资料*/
save(score *p1) 
{ 
  FILE *fp;
  char filepn[20];/*用来存放文件保存路径以及文件名*/
  printf("请输入文件路径及文件名:");
 scanf("%s",filepn);
 if((fp=fopen(filepn,"w+"))==NULL)
 {
  printf("不能打开文件!\n");
  return 0;
 }
    fprintf(fp,"            学生成绩管理系统             \n");
   fprintf(fp,"\n");
    fprintf(fp,"-----------------------------------------\n");
 fprintf(fp,"|学号\t|姓名\t|语文\t|数学\t|英语\t|\n");
    fprintf(fp,"-----------------------------------------\n");             /*打印表格域*/
 while(p1!=NULL)
 {
 fprintf(fp,"%d\t%s\t%.1f\t%.1f\t%.1f\t\n",p1->number,p1->name,p1->chinese,p1->mathmatic,p1->english);
 p1=p1->next;                                          /*下移一个结点*/
}
 fclose(fp);
 printf("文件已经保存!\n");
 return 0;
}

/*==========调入文件==========*/
/*函数loadfile，功能:从文件读入学生记录*/
score *loadfile(score *head)
{
   score *p1,*p2;
   int m=0;
   char filename[10];
  FILE *fp;
  printf("请输入文件路径及文件名:");
  scanf("%s",filename);/*输入文件路径及名称*/
  if((fp=fopen(filename,"r+"))==NULL)
 {
  printf("不能打开文件!\n");
  return 0;
 }
     fscanf(fp,"            学生成绩管理系统             \n");
     fscanf(fp,"\n");
        fscanf(fp,"-----------------------------------------\n");
  fscanf(fp,"|学号\t|姓名\t|语文\t|数学\t|英语\t|\n");
        fscanf(fp,"-----------------------------------------\n");                        /*读入表格域*/
  printf("            学生成绩管理系统             \n");
     printf("\n");
        printf("-----------------------------------------\n");
  printf("|学号\t|姓名\t|语文\t|数学\t|英语\t|\n");
        printf("-----------------------------------------\n");                         /*打印表格域*/
  m=m+1;  
  if(m==1)
  {
  
  p1=(score *)malloc(LEN);                                            /*开辟一个新单元*/
  fscanf(fp,"%d%s%f%f%f",&p1->number,p1->name,&p1->chinese,&p1->mathmatic,&p1->english);
         printf("|%d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|\n",p1->number,p1->name,p1->chinese,p1->mathmatic,p1->english);
    /*文件读入与显示*/
  head=NULL;
  do
  {
   n=n+1;
   if(n==1) head=p1;
   else p2->next=p1;
   p2=p1;
   p1=(score *)malloc(LEN);                        /*开辟一个新单元*/
      fscanf(fp,"%d%s%f%f%f\n",&p1->number,p1->name,&p1->chinese,&p1->mathmatic,&p1->english);
            printf("|%d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|\n",p1->number,p1->name,p1->chinese,p1->mathmatic,p1->english);
           /*文件读入与显示*/
  }while(!feof(fp));
  p2->next=p1;
  p1->next=NULL;
  n=n+1; 
 }
printf("-----------------------------------------\n");                   /*表格下线*/
  fclose(fp);                                               /*结束读入，关闭文件*/
      
 return (head);
}

/*==========统计==========*/
/*函数statistics,功能：统计学生成绩*/
score *statistics(score *head)
{
float sum1=0,sum2=0,sum3=0,ave1=0,ave2=0,ave3=0,max=0,min=0;
  char maxname[10],minname[10];
  score *p;
  int x,y=0,i=0;
  p=head;
  printf("1个人总分和平均分\t2单科平均分\t3总分最高分和最低分\n");
  scanf("%d",&x);
  getchar();
switch(x)                /*用switch语句实现功能选择*/
  {
 case 1: if(head==NULL)
  {printf("\n没有任何学生资料!\n");return(head);}/*链表为空*/
  else
  {
     printf("---------------------------------------------------------\n");
     printf("|学号\t|姓名\t|语文\t|数学\t|英语\t|总分\t|平均分\t|\n");
     printf("---------------------------------------------------------\n");/*打印表格域*/
     while(p!=NULL)
     {
      sum1=p->chinese+p->mathmatic+p->english;  /*计算个人总分*/                            
      ave1=sum1/3;                             /*计算个人平均分*/
                     printf("|%d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|%.1f\t|%.1f\t|\n",p->number,p->name,p->chinese,p->mathmatic,p->english,sum1,ave1);                                     /*打印结果*/
      printf("---------------------------------------------------------\n");/*打印表格域*/
     p=p->next;}
    }
return(head);    break;
  case 2: if(head==NULL)
    {printf("\n没有任何学生资料!\n");return(head);}           /*链表为空*/
     while(p!=NULL)
     { 
      sum1=sum1+p->chinese;
      sum2=sum2+p->mathmatic;
      sum3=sum3+p->english;                          /*计算总分*/
       y=y+1;
       ave1=sum1/y;
       ave2=sum2/y;
       ave3=sum3/y;                                  /*计算平均分*/
       p=p->next;/*使p指向下一个结点*/
       }
     printf("语文平均分是%.1f\n",ave1);
     printf("数学平均分是%.1f\n",ave2);
     printf("英语平均分是%.1f\n",ave3);                   /*打印结果*/
      return(head); break;
  case 3: 
   if(head==NULL)
   {printf("\n没有任何学生资料!\n");return(head);}           /*链表为空*/
    min=max=p->chinese+p->mathmatic+p->english;
   while(i<n)
  {   
    i=i+1;
    sum1=p->chinese+p->mathmatic+p->english;           /*计算个人总分*/
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
  printf("总分最高分:%.1f,姓名：%s、",max,maxname);
  printf("\n");
  printf("总分最低分:%.1f,姓名：%s",min,minname);
  printf("\n");
 return(head); break;
 default :printf("输入错误,请重试!\n");
 }
 return(head);
}

/*==========menu==========*/
/*函数menu,功能：菜单选择界面*/
int menu(int k) 
{
 int i;
 printf("\t\t\t\t学生成绩管理系统\n");
 printf("\n");
 for(i=0;i<80;i++)
    printf("*");
printf("1编辑学生的成绩\t\t\t2显示学生的成绩\t\t\t3查询学生的成绩\n");
printf("4添加学生的成绩\t\t\t5删除学生的成绩\t\t\t6学生成绩排序\n");
printf("7保存学生的资料\t\t\t8统计学生的成绩\t\t\t9读取学生的成绩\n");
/*菜单选择界面*/ 
for(i=0;i<80;i++)
printf("*");
printf("欢迎进入学生成绩管理系统，请选择您所要的操作(选择(0)退出):");
scanf("%d",&k);/*选择操作*/
 //getchar();
return (k);
}

/*==========主函数==========*/
/*主函数main,功能：通过调用creat,search,dele,add,print,ststistics,save,sortdata等函数，实现学生成绩查询系统功能*/
void main() 
{
int k;
score *head=0,*stu=0;
while(1)
{
k=menu(k);
switch(k)                                                /*用switch语句实现功能选择*/
{case 1:head=creatlink();break;                              /*调用创建链表函数*/
 case 2: print(head); break;                                 /*调用显示学生资料函数*/
 case 3: head=search (head);break;                           /*调用成绩查询函数*/ 
 case 4: head=add (head,stu);break;                          /*调用追加学生资料函数*/
 case 5: head=dele (head); break;                            /*调用删除学生资料函数*/
 case 6: sortdata(head);break;                               /*调用排序函数*/
 case 7: save (head);break;                                 /*调用保存函数*/
 case 8: statistics(head); break;                             /*调用统计函数*/
 case 9: head=loadfile(head);break;                          /*从文件调入记录函数*/
 case 0:exit(0);/*退出系统，返回主界面*/
 default: printf("输入错误,请重试!\n"); }
}
}
