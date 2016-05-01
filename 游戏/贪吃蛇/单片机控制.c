#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <winnt.h>
#include<setjmp.h>

#define ESC 27  //ESC对应的ASCII
#define BAUD_RATE 9600

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

HANDLE hCom;
char inputData[1024]="  ";
char outputData[1024];
int sizeBuffer = 1;
int length;
COMMTIMEOUTS TimeOuts; /*定义超时变量*/
DCB dcb;/*串口DCB设置*/


int Speed = 20000;
int Score_one = 0;
int Score_two = 0;

typedef struct Position
{
	int x;
	int y;
	struct Position * next;
}position;


/***********************串口初始化******************/
void COM_Init()
{
    hCom = CreateFile("COM1",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);


    /*强制类型转换-1为HANDLE类型*/
    if(hCom == (HANDLE)-1)
    {
        printf("open COM failed\n");
        exit(1);
    }

    /* 超时设置 */
    TimeOuts.ReadIntervalTimeout=1000;
    TimeOuts.ReadTotalTimeoutMultiplier=500;
    TimeOuts.ReadTotalTimeoutConstant=5000;
    TimeOuts.WriteTotalTimeoutMultiplier=500;
    TimeOuts.WriteTotalTimeoutConstant=2000;

    /* 写入串口超时参数,出错返回0*/
    if(!SetCommTimeouts(hCom,&TimeOuts))
    {
        printf("写入超时参数错误");
        exit(1);
    }

    /* 设置输入输出缓冲区参数，返回非0表示成功 */
    if(!SetupComm(hCom,1024,1024))
    {
        printf("设置串口读写缓冲区失败\n");
        exit(1);
    }

    /* 获取当前串口状态信息(只需要修改部分串口信息),调用失败返回0*/
    if(!GetCommState(hCom,&dcb))
    {
        printf("获取串口属性失败\n");
        exit(1);
    }


    /*具体情况，具体对待*/
    dcb.BaudRate = BAUD_RATE;
    dcb.ByteSize = 8;
    dcb.Parity = NOPARITY;    /*无校验*/
    dcb.StopBits=ONESTOPBIT; /*1位停止位*/

    if(!SetCommState(hCom,&dcb))
    {
        printf("设置串口参数出错\n");
        exit(1);
    }

}
position * tail_one = NULL,* head_one = NULL;  //蛇1头 蛇1尾

/*********************蛇身1初始化函数******************/
void Snack_Position_Init(void)
{
	position * temp = NULL;
	head_one = (position *)malloc(sizeof(position));
	head_one->x = 5;
	head_one->y = 15;
	temp = (position *)malloc(sizeof(position));
	head_one->next = temp;
	temp->x = 6;
	temp->y = 15;
	tail_one = (position *)malloc(sizeof(position));
	tail_one->next = NULL;
	temp->next = tail_one;
	tail_one->x = 7;
	tail_one->y = 15;
}

position * tail_two = NULL,* head_two = NULL;  //蛇2头 蛇2尾
/*********************蛇身2初始化函数******************/
void Snack_two_Position_Init(void)
{
	position * temp = NULL;
	head_two = (position *)malloc(sizeof(position));
	head_two->x = 34;
	head_two->y = 5;
	temp = (position *)malloc(sizeof(position));
	head_two->next = temp;
	temp->x = 33;
	temp->y =5;
	tail_two = (position *)malloc(sizeof(position));
	tail_two->next = NULL;
	temp->next = tail_two;
	tail_two->x = 32;
	tail_two->y = 5;
}

/**********************显示坐标跳转*******************/
void gotoxy(int x,int y)
{
 COORD loc;
 loc.X  = x;
 loc.Y  =  y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
}

/***********************显示蛇身1**********************/
void Display_Snack_one(position * head)
{
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
/***********************显示蛇身2**********************/
void Display_Snack_two(position * head)
{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);  //设置字体颜色  1是蓝色

        while(head->next != NULL)
        {
            gotoxy(head->x,head->y);
            putchar('*');
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
	printf("红蛇:%d",Score_one);
	gotoxy(0,0);
	gotoxy(43,19);
	printf("绿蛇:%d",Score_two);
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
	gotoxy(42,2);
	printf("红蛇wasd控制方向，ESC退出,不可以反向走。");
    gotoxy(42,4);
	printf("绿蛇方向键控制，ESC退出,不可以反向走。");
	gotoxy(42,6);
	printf("吃越多走越快 空格键暂停");
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

/***********************吃到一个果实后增加蛇身1长度**********************/
void Insert_Snack_one()
{
	position * temp;
	temp = (position *)malloc(sizeof(position));
	temp->x = head_one->x;
	temp->y = head_one->y;
	temp->next = head_one;
	head_one = temp;

}

/***********************吃到一个果实后增加蛇身2长度**********************/
void Insert_Snack_two()
{
	position * temp;
	temp = (position *)malloc(sizeof(position));
	temp->x = head_one->x;
	temp->y = head_one->y;
	temp->next = head_two;
	head_two = temp;
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

/**********************释放蛇身**********************/
void Free_Snack(position * head)
{
    position * temp = NULL;
    for(; head!= NULL; head =temp)
    {
        temp = head->next;
        free(head);
    }
}



/**************************方向键控制移动******************************/
char direction = 'd';    //方向键
extern void Judge_one();
extern void Judge_two();
char value = 0;
int turn = 0;
char direction_two = 52;    //方向键
char value_two = 0;
int turn_two = 0;

void Move(void)
{

    if(_kbhit())
	{
		  direction_two = direction = getch();
		  if(direction == 32)
          {
            gotoxy(10,10);
            printf("暂停");
            while(1)
            {
               if(getch() == 32);
               {
                   system("cls");
                   Display_Border();
                   break;
               }
            }
          }
		 if(direction == ESC)
		{
		  system("cls");
		  puts("游戏退出成功!");
		  system("pause");
		  exit(0);
		}
	}
	Move_Snack(head_two);
    Move_Snack(head_one);


A:	switch(direction)
	{
	case 'w':if( turn != 2 ){tail_one->y--;turn = 1;value = direction;}else{direction = value;goto A;} break;
	case 'a':if( turn != 3 ){tail_one->x--;turn = 4;value = direction;}else{direction = value;goto A;} break;
	case 's':if( turn != 1 ){tail_one->y++;turn = 2;value = direction;}else{direction = value;goto A;} break;
	case 'd':if( turn != 4 ){tail_one->x++;turn = 3;value = direction;}else{direction = value;goto A;} break;
	default: direction = value;goto A;break;
	}

    if( ReadFile(hCom,inputData,sizeBuffer,&length,NULL) != 0)
    {
        direction_two = inputData[0];
    }

B:	switch(direction_two)
	{
	case 56:if( turn_two != 2 ){tail_two->y--;turn_two = 1;	value_two = direction_two;}else{direction_two = value_two;goto B;} break;
	case 52:if( turn_two != 3 ){tail_two->x--;turn_two = 4;	value_two = direction_two;}else{direction_two = value_two;goto B;} break;
	case 53:if( turn_two != 1 ){tail_two->y++;turn_two = 2;	value_two = direction_two;}else{direction_two = value_two;goto B;} break;
	case 54:if( turn_two != 4 ){tail_two->x++;turn_two = 3;	value_two = direction_two;}else{direction_two = value_two;goto B;} break;
	default: direction_two = value_two;goto B;break;
	}

    Rand_Fruit();

	Judge_one(head_one);

    Display_Snack_one(head_one);
    Judge_two(head_two);
    Display_Snack_two(head_two);


	Delay_ms(Speed);

}



/**************************判断输赢******************************/
void Judge_one(position * head)
{
	if( Fruit_x == tail_one->x && Fruit_y == tail_one->y )
	{
		Insert_Snack_one();
		//move_position(head);
		Speed -= 200;
		Score_one++;
		Display_Score();
		Fruit_Flag = 0;
	}
	if( tail_one->x == 40 || 0 == tail_one->y ||  tail_one->x == 0 || 20 == tail_one->y )
	{
		gotoxy(44,12);
		printf("红蛇输了  按回车键重新开始.");
			direction = 'd';
			Fruit_Flag = 0;
			Score_one = 0;
			Score_two = 0;
			Speed = 20000;
		    value = 0;
            turn = 0;
            direction_two = 52;    //方向键
            value_two = 0;
            turn_two = 0;
		fflush(stdin);
		Free_Snack(head_one);
            Free_Snack(head_two);
		getchar();
		system("cls");

		longjmp(buf,1);
	}
	while(head != tail_one)
	{
		if( tail_one->x == head->x && head->y == tail_one->y )
		{
			gotoxy(44,12);
			printf("红蛇输了  按回车键重新开始.");
			direction = 'd';
			Fruit_Flag = 0;
			Score_one = 0;
			Score_two = 0;
			Speed = 20000;
		    value = 0;
            turn = 0;
            direction_two = 52;    //方向键
            value_two = 0;
            turn_two = 0;
			fflush(stdin);
            Free_Snack(head_one);
            Free_Snack(head_two);

            getchar();
            system("cls");

            longjmp(buf,1);
		}
		else
			head = head->next;
	}

     head = head_two;
    while(head != tail_two)
	{
		if( tail_one->x == head->x && head->y == tail_one->y )
		{
			gotoxy(44,12);
			printf("撞一起了  按回车键重新开始.");
            direction = 'd';
			Fruit_Flag = 0;
			Score_one = 0;
			Score_two = 0;
			Speed = 20000;
		    value = 0;
            turn = 0;
            direction_two = 52;    //方向键
            value_two = 0;
            turn_two = 0;

			fflush(stdin);
            Free_Snack(head_one);
            Free_Snack(head_two);

            getchar();
            system("cls");

            longjmp(buf,1);
		}
		else
			head  = head ->next;
	}

}

void Judge_two(position * head)
{
	if( Fruit_x == tail_two->x && Fruit_y == tail_two->y )
	{
		Insert_Snack_two();
		//move_position(head);
		Speed -= 200;
		Score_two++;
		Display_Score();
		Fruit_Flag = 0;
	}
	if( tail_two->x == 40 || 0 == tail_two->y ||  tail_two->x == 0 || 20 == tail_two->y )
	{
		gotoxy(44,12);
		printf("绿蛇输了  按回车键重新开始.");
            direction = 'd';
			Fruit_Flag = 0;
			Score_one = 0;
			Score_two = 0;
			Speed = 20000;
		    value = 0;
            turn = 0;
            direction_two = 52;    //方向键
            value_two = 0;
            turn_two = 0;
		fflush(stdin);
		Free_Snack(head_one);
            Free_Snack(head_two);
		getchar();
		system("cls");

		longjmp(buf,1);
	}
	while(head != tail_two)
	{
		if( tail_two->x == head->x && head->y == tail_two->y )
		{
			gotoxy(44,12);
			printf("绿蛇输了  按回车键重新开始.");
            direction = 'd';
			Fruit_Flag = 0;
			Score_one = 0;
			Score_two = 0;
			Speed = 20000;
		    value = 0;
            turn = 0;
            direction_two = 52;    //方向键
            value_two = 0;
            turn_two = 0;

			fflush(stdin);
            Free_Snack(head_one);
            Free_Snack(head_two);

            getchar();
            system("cls");

            longjmp(buf,1);
		}
		else
			head  = head ->next;
	}

    head = head_one;
    while(head != tail_one)
	{
		if( tail_two->x == head->x && head->y == tail_two->y )
		{
			gotoxy(44,12);
			printf("撞一起了  按回车键重新开始.");
            direction = 'd';
			Fruit_Flag = 0;
			Score_one = 0;
			Score_two = 0;
			Speed = 20000;
		    value = 0;
            turn = 0;
            direction_two = 52;    //方向键
            value_two = 0;
            turn_two = 0;

			fflush(stdin);
            Free_Snack(head_one);
            Free_Snack(head_two);

            getchar();
            system("cls");

            longjmp(buf,1);
		}
		else
			head  = head ->next;
	}
}




int main()
{
    COM_Init();
    setjmp(buf);   //记录当前位置
	Snack_Position_Init();  //蛇身初始化函数
    Snack_two_Position_Init();
	Display_Border();
	while(1)
    {
       	Move();
    }

}

