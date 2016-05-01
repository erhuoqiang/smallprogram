#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include <conio.h>
#include<setjmp.h>

#define ESC 27  //ESC��Ӧ��ASCII

jmp_buf buf;
/*��ɫ��Ӧֵ��
����0=��ɫ                8=��ɫ����
  �� 1=��ɫ                9=����ɫ                ����
����2=��ɫ                10=����ɫ       0xa        ����
����3=����ɫ          11=��ǳ��ɫ        0xb��
����4=��ɫ                12=����ɫ        0xc����
����5=��ɫ                13=����ɫ        0xd        ����
����6=��ɫ                14=����ɫ        0xe        ����
����7=��ɫ                15=����ɫ        0xf
����Ҳ���԰���Щֵ���óɳ�����
*/

int Speed = 3000;
int Score = 0;

typedef struct Position
{
	int x;
	int y;
	struct Position * next;
}position;

position * tail = NULL,* head = NULL;  //��ͷ ��β

/*********************�����ʼ������******************/
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

/**********************��ʾ������ת*******************/
void gotoxy(int x,int y)
{
 COORD loc;
 loc.X  = x;
 loc.Y  =  y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
}

/***********************��ʾ����**********************/
void Display_Snack(position * head)
{
    int flag = 0;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);  //����������ɫ  1����ɫ

	while(head->next != NULL)
	{
		gotoxy(head->x,head->y);
        putchar('#');
		head = head->next;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//����������ɫ  2��ɫ
	gotoxy(head->x,head->y);
	putchar('@');
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);   //����������ɫ  7�ǰ�ɫĬ��
}

/***********************��ʱ����**********************/
void Delay_ms(int ms)
{
	register int  i,j;
	for( i = 0; i < 11000; i++)
		for( j = 0; j < ms; j++)
			;
}
/***********************��ʾ����**********************/
void Display_Score(void)
{
	gotoxy(43,18);
	printf("score:%d",Score);
	gotoxy(0,0);
}

/***********************��ʾ�߽�**********************/
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
	printf("wasd���Ʒ���ESC�˳�,�����Է����ߡ�");
	gotoxy(42,6);
	printf("��Խ����Խ��");
	Display_Score();

}


/***********************�ƶ�����**********************/
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

/***********************�Ե�һ����ʵ������������**********************/
void Insert_Snack()
{
	position * temp;
	temp = (position *)malloc(sizeof(position));
	temp->next = head;
	head = temp;
}


int Fruit_Flag = 0,Fruit_x,Fruit_y;   //��ʵ�Ƿ�Ե���־λ���͹�ʵ���� xy

/***********************������ɹ�ʵ**********************/
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


/**************************����������ƶ�******************************/
char direction = 'd';    //�����
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
		  puts("��Ϸ�˳��ɹ�!");
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

/**************************�ж���Ӯ******************************/
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
		printf("YOU ARE LOSER!  ����������¿�ʼ.");
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
			printf("YOU ARE LOSER!����������¿�ʼ.");
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
    setjmp(buf);   //��¼��ǰλ��
	Snack_Position_Init();  //�����ʼ������
	Display_Border();
	while(1)
	Move();
}

