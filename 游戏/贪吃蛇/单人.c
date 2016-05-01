#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include <conio.h>
#include<setjmp.h>

#define ESC 27  //ESC对应的ASCII

jmp_buf buf;
/*颜色对应值：
　　0=黑色                8=灰色　　
  　 1=蓝色                9=淡蓝色                　　
　　2=绿色                10=淡绿色       0xa        　　
　　3=湖蓝色          11=淡浅绿色        0xb　
　　4=红色                12=淡红色        0xc　　
　　5=紫色                13=淡紫色        0xd        　　
　　6=黄色                14=淡黄色        0xe        　　
　　7=白色                15=亮白色        0xf
　　也可以吧这些值设置成常量。
*/

int Speed = 3000;
int Score = 0;

typedef struct Position
{
	int x;
	int y;
	struct Position * next;
}position;

position * tail = NULL,* head = NULL;  //蛇头 蛇尾

/*********************蛇身初始化函数******************/
void Snack_Position_Init(void)
{
	position * temp = NULL;
	head = (position *)malloc(sizeof(position));
	head->x = 5;
	head->y = 10;
	temp = (position *)malloc(sizeof(position));
	head->next = temp;
	temp->x = 6;
	temp->y = 10;
	tail = (position *)malloc(sizeof(position));
	tail->next = NULL;
	temp->next = tail;
	tail->x = 7;
	tail->y = 10;
}

/**********************显示坐标跳转*******************/
void gotoxy(int x,int y)
{
 COORD loc;
 loc.X  = x;
 loc.Y  =  y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
}

/***********************显示蛇身**********************/
void Display_Snack(position * head)
{
    int flag = 0;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);  //设置字体颜色  1是蓝色

	while(head->next != NULL)
	{
		gotoxy(head->x,head->y);
        putchar('#');
		head = head->next;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//设置字体颜色  2绿色
	gotoxy(head->x,head->y);
	putchar('@');
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);   //设置字体颜色  7是白色默认
}

/***********************延时函数**********************/
void Delay_ms(int ms)
{
	register int  i,j;
	for( i = 0; i < 11000; i++)
		for( j = 0; j < ms; j++)
			;
}
/***********************显示分数**********************/
void Display_Score(void)
{
	gotoxy(43,18);
	printf("score:%d",Score);
	gotoxy(0,0);
}

/***********************显示边界**********************/
void Display_Border(void)
{
	register int i;
	for(i = 0;i < 20;i++)
	{
		gotoxy(0,i);
		putchar('*');
	}
	for(i = 0;i < 40;i++)
	{
		gotoxy(i,0);
		putchar('*');
	}
	for(i = 0;i < 20;i++)
	{
		gotoxy(40,i);
		putchar('*');
	}
	for(i = 0;i < 40;i++)
	{
		gotoxy(i,20);
		putchar('*');
	}
	gotoxy(42,5);
	printf("wasd控制方向，ESC退出,不可以反向走。");
	gotoxy(42,6);
	printf("吃越多走越快");
	Display_Score();

}


/***********************移动蛇身**********************/
void Move_Snack(position * head)
{
	gotoxy(head->x,head->y);
	putchar(' ');
	while(head->next != NULL )
	{
     head->x = head->next->x;
	 head->y = head->next->y;
	 head = head->next;
	}
}

/***********************吃到一个果实后增加蛇身长度**********************/
void Insert_Snack()
{
	position * temp;
	temp = (position *)malloc(sizeof(position));
	temp->next = head;
	head = temp;
}


int Fruit_Flag = 0,Fruit_x,Fruit_y;   //果实是否吃到标志位，和果实坐标 xy

/***********************随机生成果实**********************/
void Rand_Fruit()
{
	if( 0 == Fruit_Flag )
	{
	Fruit_x = rand()%38 + 1;
	Fruit_y = rand()%18 + 1;
	Fruit_Flag = 1;
	}

	gotoxy(Fruit_x, Fruit_y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	putchar('*');
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}


/**************************方向键控制移动******************************/
char direction = 'd';    //方向键
extern void Judge();
char value = 0;
int turn = 0;
void Move()
{
	if(_kbhit())
	{
		 direction = getch();
		 if(direction == ESC)
		{
		  system("cls");
		  puts("游戏退出成功!");
		  system("pause");
		  exit(0);
		}
	}
    Move_Snack(head);
A:	switch(direction)
	{
	case 'w':if( turn != 2 ){tail->y--;turn = 1;}else{direction = value;goto A;} break;
	case 'a':if( turn != 3 ){tail->x--;turn = 4;}else{direction = value;goto A;} break;
	case 's':if( turn != 1 ){tail->y++;turn = 2;}else{direction = value;goto A;} break;
	case 'd':if( turn != 4 ){tail->x++;turn = 3;}else{direction = value;goto A;} break;
	default: direction = value;goto A;break;
	}
	value = direction;
    Rand_Fruit();
	Judge(head);
    Display_Snack(head);
	Delay_ms(Speed);
}

/**************************判断输赢******************************/
void Judge(position * head)
{
	if( Fruit_x == tail->x && Fruit_y == tail->y )
	{
		Insert_Snack();
		//move_position(head);
		Speed -= 200;
		Score++;
		Display_Score();
		Fruit_Flag = 0;
	}
	if( tail->x == 40 || 0 == tail->y ||  tail->x == 0 || 20 == tail->y )
	{
		gotoxy(42,8);
		printf("YOU ARE LOSER!  按任意键重新开始.");
		direction = 'd';
        Fruit_Flag = 0;
        Score = 0;
        Speed = 3000;
        value = 0;
        turn = 0;
		fflush(stdin);
		Delay_ms(10000);
		getch();
		system("cls");
		longjmp(buf,1);
	}
	while(head != tail)
	{
		if( tail->x == head->x && head->y == tail->y )
		{
			gotoxy(42,8);
			printf("YOU ARE LOSER!按任意键重新开始.");
			direction = 'd';
			Fruit_Flag = 0;
			Score = 0;
			Speed = 3000;
		    value = 0;
            turn = 0;
			fflush(stdin);

			Delay_ms(10000);

            getch();
            system("cls");
            longjmp(buf,1);
		}
		else
			head = head->next;
	}
}





int main()
{
    setjmp(buf);   //记录当前位置
	Snack_Position_Init();  //蛇身初始化函数
	Display_Border();
	while(1)
	Move();
}

