#include<stdio.h>
#include<windows.h>
#include <conio.h>

char filename[60] = "123.txt";
char BUFFER[500] = "";
char *p = BUFFER;
char *temp = NULL;
FILE * fp = NULL;
int mode = 0;
char passwd[10] = "454923998";
char input[10] = "";

extern void mode_change();

void gotoxy(int x,int y)
{
 COORD loc;
 loc.X  = x;
 loc.Y  =  y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
}

void open_file()
{
	if( (fp = fopen( filename,"a+" )) == NULL )
	{
		printf("打开失败");
		printf("\n");
		exit(1);
	}
	p = BUFFER;
	while(!feof(fp))
	{
		fscanf(fp,"%c", p);
		p++;
	}
	*p = 0;
	printf("%s文件内容为：\n",filename);
	printf("%s\n\n\n",BUFFER);
	fclose(fp);
}

void ADD_passwd()
{
	if( (fp = fopen( filename,"w+" )) == NULL )
	{
		printf("加密失败");
		printf("\n");
		exit(1);
	}
	else
		printf("加密成功");
	p = BUFFER;
	while(*p)
	{
		*p = *p + 2;
		p++;
	}
	printf("加密后%s文件内容为：\n",filename);
	printf("%s\n\n\n",BUFFER);
	fprintf(fp,"%s",BUFFER);
	fclose(fp);
}

void SUB_passwd()
{
    if( (fp = fopen( filename,"w+" )) == NULL )
	{
		printf("解密失败");
		printf("\n");
		exit(1);
	}
	else
		printf("解密成功");
	p = BUFFER;
	while(*p != 0)
	{
		*p = *p - 2;
		p++;
	}
	printf("解密后%s文件内容为：\n",filename);
	printf("%s\n\n\n",BUFFER);
	fprintf(fp,"%s",BUFFER);
	fclose(fp);
}

void mode_change()
{
		printf("请选择加密（1）还是解密（0）退出（3）:\n");
		scanf("%d",&mode);
		if( 1 == mode )
		{
			ADD_passwd();
			mode_change();
		}
		else if( 0 == mode )
		{
			SUB_passwd();
			mode_change();
		}
		else 
		{
			printf("退出程序\n"); 
			exit(1);
		}
}


void Judge_passwd()
{
	int count = 0;
	temp = input;
	printf("请输入9位密码:\n");
	for(count = 0; count < 9; count++)
	{
		*temp++ = getch();
		gotoxy(count,1);
		putchar('*');
	}
	count = 0;
	printf("\n");
	p = passwd;
	temp = input;
	while((*p++) == *temp++ && count < 10)
	{
		count++;
	}
	if(count >= 9)
	{
		printf("密码正确.\n");
		printf("请输入需要处理的文件路径:\n");
		scanf("%s",filename);
		open_file();
		mode_change();
	}
	else
	{
		printf("密码错误.\n程序退出.\n");
		exit(1);
	}
}

int main()
{
	Judge_passwd();
}


		