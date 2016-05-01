#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

#define LEN sizeof(struct student)

int n;

struct student
{
	char name[20];
	int num;
	int score;
	struct student * next;
};

typedef struct student student;


student * creatline()
{
	student *head, *p1, *p2, *p3, *max;
	int i, j, fen;
	char t[20];
	 p1 = p2 = p3 = (student *)malloc(LEN);
	head = NULL;
a:	printf("请输入大于0的学号(输入0退出!):");
	p1->num = 0;
	scanf("%d", &p1->num);

	if(p1->num < 0)
	{
		printf("输入错误");
		goto  a;
	}
	else if( p1->num == 0 )
	{
		goto end;
	}

	p3 = head;
	n = 0;
	for( i = 0; i < n; i++)
	{
		if( p1->num == p3->num )
		{
			printf("学号重复,请重新输入!按0退出\n");
			goto a;
		}
			p3 = p3->next;
			
		
	}

	printf("请输入名字:");
	scanf("%s", p1->name);

A:	printf("请输入成绩:");
	p1->score = 0;
	scanf("%d", &p1->score);
	if( p1->score > 100 || p1->score < 0 )
	{
		printf("输入错误!\n");
		goto  A;
	}

	while( p1->num != 0)
	{
		n++;
		if(n ==1)
			head = p1;
		else
			p2->next = p1;
			p2 = p1;
			p1 = (struct student *)malloc(LEN);

B:	printf("请输入大于0的学号（输入0退出）:");
			p1->num = 0;
			scanf("%d", &p1->num);
			if(p1->num < 0)
			{
				printf("输入错误");
				goto  B;
			}
			else if( p1->num == 0 )
			{
				goto end;
			}

			p3 = head;
			
			for( i = 0; i < n; i++)
			{
				if( p1->num == p3->num )
				{
					printf("学号重复,请重新输入!\n");
					goto B;
				}
					p3 = p3->next;
					
				
			}
			printf("请输入名字:");
			scanf("%s", p1->name);

		b:	printf("请输入成绩:");
			p1->score = 0;
			scanf("%d", &p1->score);
			if( p1->score > 100 || p1->score < 0 )
			{
				printf("输入错误!\n");
				goto  b;
			}
			

	}

end:
	for(i = 0; i < n -1; i++)
	{
		max = p1 = head;
		for( j = 0; j < n -1 -i; j++)
		{
		   max = p1;
		p1=p1->next;
       if(max->num > p1->num)
        {
          fen = max->num;
          max->num = p1->num;
          p1->num = fen;                    
         strcpy(t,max->name);
         strcpy(max->name,p1->name);
         strcpy(p1->name,t);                
         fen = max->score;
         max -> score = p1->score;
         p1->score = fen;                     
                             
         }

		}
	}
	p2 -> next = NULL;
	return head;

}

int search( student * head)
{
	int num = 0, i = 0, j, k, m = 0, l;
	char a[20];
	student * p3 = head;
	printf("1根据学号查询，2根据名字");
	scanf("%d",&i);
	if( i == 1)
	{
D:	printf("请输入要查询的学号，按0返回上一级:");
	scanf("%d", &num);
			if(num < 0)
			{
				printf("输入错误\n");
				goto  D;
			}
			else if( num == 0 )
			{
				goto end;
			}
	while( head != NULL && head -> num != num  )
	{
		head = head->next;
	}
	if(head == NULL)
	{
		printf("输入错误，不存在此学号!\n");
		head = p3;
		goto D;
	}
	else
	{
		printf("-----------------------------------------\n");
		printf("|学号\t\t|姓名\t|成绩\t|\n");
		printf("-----------------------------------------\n");                       /*打印表格域*/
		printf("%-18d%s\t %d\n",head->num, head->name, head->score);
		head = head -> next;
	}
	head = p3;
	goto D;
end:
	return 0;
	}
	else
	{
		printf("请输入要查询的关键字:");
		scanf("%s", a);
		l = strlen(a);
		printf("关键字长:%d\n", l);
		while( head != NULL )
		{
			for( k = 0; k < l; k++ )
			{
				for( j = 0; j < strlen( head->name ); j++ )
				{
					//printf("%c\n", *(head->name+j));
					if ( a[k] == *(head->name+j) )
					{
						m++;
					}
				}
			}
			if( m > 1)
			{
			printf("-----------------------------------------\n");
			printf("|学号\t\t|姓名\t|成绩\t|\n");
			printf("-----------------------------------------\n");                       /*打印表格域*/
			printf("%-18d%s\t %d\n",head->num, head->name, head->score);
			
			}
			else
			{
				printf("无相关信息");
			}
			head = head -> next;
			m = 0;
		}
			
	}
}
void print(student * head)
{

	if(head==NULL)
     {printf("\n没有任何学生资料!\n");}
 else
  { printf("总数n=%d\n",n);
   printf("-----------------------------------------\n");
printf("|学号\t\t|姓名\t|成绩\t|\n");
   printf("-----------------------------------------\n");                       /*打印表格域*/

	while(head != NULL)
	{
		printf("%-18d%s\t%d\n",head->num, head->name, head->score);
		head = head -> next;
	}
}
}

student * add( student * old_head)
{
	student *head, *p1, *p2, *p3, *max;
	int i, j, fen, k;
	char t[20];
	 p1 = p2 = p3 = (student *)malloc(LEN);
	head = NULL;
a:	printf("请输入大于0的学号(输入0退出!):");
	p1->num = 0;
	scanf("%d", &p1->num);

	if(p1->num < 0)
	{
		printf("输入错误");
		goto  a;
	}
	else if( p1->num == 0 )
	{
		goto end;
	}

	p3 = head;
	k = 0;
	for( i = 0; i < k; i++)
	{
		if( p1->num == p3->num )
		{
			printf("学号重复,请重新输入!按0退出\n");
			goto a;
			
		}
		p3 = p3->next;
	}

	printf("请输入名字:");
	scanf("%s", p1->name);

A:	printf("请输入成绩:");
	p1->score = 0;
	scanf("%d", &p1->score);
	if( p1->score > 100 || p1->score < 0 )
	{
		printf("输入错误!\n");
		goto  A;
	}

	while( p1->num != 0)
	{
		k++;
		if(n == 1)
			head = p1;
		else
			p2->next = p1;
			p2 = p1;
			p1 = (struct student *)malloc(LEN);

B:	printf("请输入大于0的学号（输入0退出）:");
			p1->num = 0;
			scanf("%d", &p1->num);
			if(p1->num < 0)
			{
				printf("输入错误");
				goto  B;
			}
			else if( p1->num == 0 )
			{
				goto end;
			}

			p3 = head;
			
			for( i = 0; i < k; i++)
			{
				if( p1->num == p3->num )
				{
					printf("学号重复,请重新输入!\n");
					goto B;
				}
					p3 = p3->next;
			}
			printf("请输入名字:");
			scanf("%s", p1->name);

		b:	printf("请输入成绩:");
			p1->score = 0;
			scanf("%d", &p1->score);
			if( p1->score > 100 || p1->score < 0 )
			{
				printf("输入错误!\n");
				goto  b;
			}
	}

end:
	
	p2 -> next = old_head;

	n = k + n;
	printf("%d\n", n);

	for(i = 0; i < n -1; i++)
	{
		max = p1 = head;
		for( j = 0; j < n -1 - i; j++)
		{
		   max = p1;
		p1=p1->next;
       if(max->num > p1->num)
        {
          fen = max->num;
          max->num = p1->num;
          p1->num = fen;                    
         strcpy(t,max->name);
         strcpy(max->name,p1->name);
         strcpy(p1->name,t);                
         fen = max->score;
         max -> score = p1->score;
         p1->score = fen;                     
                             
         }

		}
	}
	
	return head;
}

student * del(student *head)
{
	
	int num = 0;
	student * p1 = head, * p2 = NULL;
	if(head == NULL)
	{
		printf("数据库为空");
		return 0;
	}
	printf("请输入你要删除的学号:");
	
	scanf("%d", &num);
	while(p1->next != NULL && p1->num != num)
	{
		p2 = p1; p1 = p1->next;
	}
	if(num == p1->num)
	{
		if(p1 == head)
		{
			head = p1->next;
			free(p1);
		}
		else
		{
			p2->next = p1->next;
			free(p1);
		}
		printf("已删除 %d",num);
	}
	else
		printf("没有此学生的学号");
	return head;
}

student * score_sort(student * head)
{
	student *p1 = head, *max = NULL;
	char t[20] = "", flag = 1;
	int fen = 0, num = 0, i = 0, j = 0;
	for( i = 0; i < n - 1 && flag; i++)
	{
		p1 = max = head;
		flag = 0;
		for(j = 0; j < n - 1 - i; j++)
		{
			p1 = max;
			max = max->next;
			if( max->score < p1->score )
			{
				 fen = max->score;
				 max->score = p1->score;
				 p1->score = fen;
				
				 strcpy(t, max->name);
				 strcpy(max->name,p1->name);
				 strcpy(p1->name,t);                
				
				 fen = max->num;
				 max -> num = p1->num;
				 p1->num = num;
				 flag = 1;
			}
		}
	}
	printf("排序成功\n");
	return head;
}


int save(student * head)  
{ 
  FILE * fp = NULL;
  student *p1 = head; 
  if( (fp = fopen("C:\\Users\\Administrator\\Desktop\\xx.txt", "w+")) == NULL)
  {
	  printf("打开失败");
	  printf("\n");
	  return 0;
  }
  while(p1 != NULL)
  {
	  fprintf(fp,"%d\t%s\t%d\n", p1->num, p1->name, p1->score);
	  p1 = p1->next;
  }
  fclose(fp);
  printf("OK");
  return 0;
}


student *loadfile(void)
{
  student *p1 = NULL, *p2 = NULL, *head = NULL;

  FILE *fp;

  if((fp=fopen("C:\\Users\\Administrator\\Desktop\\xx.txt","r+"))==NULL)
  {
	  printf("不能打开文件!\n");
	  return 0;
  }
  
  head = p1 = p2 = (student *)malloc(LEN);                                            /*开辟一个新单元*/
  fscanf(fp,"%d%s%d",&p1->num,p1->name,&p1->score);
  //printf("|%d\t|%s\t|%d\n",p1->num,p1->name,p1->score);
    /*文件读入与显示*/
  //head=NULL;
  while(!feof(fp))
  {
	   printf("|%d\t|%s\t|%d\n",p1->num,p1->name,p1->score);
	   n++;
	   if(n==1) 
		   head=p1;
	   else
		   p2->next=p1;
		   p2=p1;
		   p1=(student *)malloc(LEN);                       
		   fscanf(fp,"%d%s%d", &p1->num, p1->name, &p1->score);   
  }
 p2->next = NULL;
printf("-----------------------------------------\n");                 
  fclose(fp);                                               
      
 return (head);
}
char menu(void)
{
    int i = 0, k = 0;
    printf("                            学生成绩管理系统（MADE BY QIANG)");
    printf("\n");
     for(i=0;i<80;i++)
        printf("*");
    printf("1编辑学生的成绩\t\t\t2显示学生的成绩\t\t\t3查询学生的成绩\n");
    printf("4添加学生的成绩\t\t\t5删除学生的成绩\t\t\t6学生成绩排序\n");
    printf("7保存学生的资料\t\t\t8统计学生的成绩\t\t\t9读取学生的成绩\n");
    for(i=0;i<80;i++)
        printf("*");
    printf("欢迎进入学生成绩管理系统，请选择您所要的操作(选择(0)退出):");
   // setbuf(stdin,NULL); //清除缓存  避免在输入一个字符 和回车后'\n' 回车被下次的scanf读取 
	//fflush(stdin);
	//scanf(" %c",&k);
	scanf("\n%c",&k);
	system("cls");
    return (k-48);
}
int main()
{
	
    student *head = NULL;
    char k = 0;
//	freopen("output1.txt", "w", stdout);
    while(1)
    {
       k =  menu();
       switch(k)
       {
       case 1: head = creatline(); break;
       case 2:  print(head); break;
       case 3:  search(head); break;
       case 4:  head = add(head); break;
       case 5:  head = del(head); break;
       case 6: head = score_sort(head);break;
       case 7: save(head);  break;
       case 8: break;
       case 9: head = loadfile(); break;
       case 0: exit(0);
       default: printf(" \n输入错误请重新输入!\n");

       }
    }
    return 0;
}



















