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

#define ESC 27  //ESC��Ӧ��ASCII
#define BAUD_RATE 9600

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

HANDLE hCom;
char inputData[1024]="  ";
char outputData[1024];
int sizeBuffer = 1;
int length;
COMMTIMEOUTS TimeOuts; /*���峬ʱ����*/
DCB dcb;/*����DCB����*/


int Speed = 20000;
int Score_one = 0;
int Score_two = 0;

typedef struct Position
{
	int x;
	int y;
	struct Position * next;
}position;


/***********************���ڳ�ʼ��******************/
void COM_Init()
{
    hCom = CreateFile("COM1",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);


    /*ǿ������ת��-1ΪHANDLE����*/
    if(hCom == (HANDLE)-1)
    {
        printf("open COM failed\n");
        exit(1);
    }

    /* ��ʱ���� */
    TimeOuts.ReadIntervalTimeout=1000;
    TimeOuts.ReadTotalTimeoutMultiplier=500;
    TimeOuts.ReadTotalTimeoutConstant=5000;
    TimeOuts.WriteTotalTimeoutMultiplier=500;
    TimeOuts.WriteTotalTimeoutConstant=2000;

    /* д�봮�ڳ�ʱ����,������0*/
    if(!SetCommTimeouts(hCom,&TimeOuts))
    {
        printf("д�볬ʱ��������");
        exit(1);
    }

    /* ��������������������������ط�0��ʾ�ɹ� */
    if(!SetupComm(hCom,1024,1024))
    {
        printf("���ô��ڶ�д������ʧ��\n");
        exit(1);
    }

    /* ��ȡ��ǰ����״̬��Ϣ(ֻ��Ҫ�޸Ĳ��ִ�����Ϣ),����ʧ�ܷ���0*/
    if(!GetCommState(hCom,&dcb))
    {
        printf("��ȡ��������ʧ��\n");
        exit(1);
    }


    /*�������������Դ�*/
    dcb.BaudRate = BAUD_RATE;
    dcb.ByteSize = 8;
    dcb.Parity = NOPARITY;    /*��У��*/
    dcb.StopBits=ONESTOPBIT; /*1λֹͣλ*/

    if(!SetCommState(hCom,&dcb))
    {
        printf("���ô��ڲ�������\n");
        exit(1);
    }

}
position * tail_one = NULL,* head_one = NULL;  //��1ͷ ��1β

/*********************����1��ʼ������******************/
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

position * tail_two = NULL,* head_two = NULL;  //��2ͷ ��2β
/*********************����2��ʼ������******************/
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

/**********************��ʾ������ת*******************/
void gotoxy(int x,int y)
{
 COORD loc;
 loc.X  = x;
 loc.Y  =  y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
}

/***********************��ʾ����1**********************/
void Display_Snack_one(position * head)
{
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
/***********************��ʾ����2**********************/
void Display_Snack_two(position * head)
{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);  //����������ɫ  1����ɫ

        while(head->next != NULL)
        {
            gotoxy(head->x,head->y);
            putchar('*');
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
	printf("����:%d",Score_one);
	gotoxy(0,0);
	gotoxy(43,19);
	printf("����:%d",Score_two);
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
	gotoxy(42,2);
	printf("����wasd���Ʒ���ESC�˳�,�����Է����ߡ�");
    gotoxy(42,4);
	printf("���߷�������ƣ�ESC�˳�,�����Է����ߡ�");
	gotoxy(42,6);
	printf("��Խ����Խ�� �ո����ͣ");
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

/***********************�Ե�һ����ʵ����������1����**********************/
void Insert_Snack_one()
{
	position * temp;
	temp = (position *)malloc(sizeof(position));
	temp->x = head_one->x;
	temp->y = head_one->y;
	temp->next = head_one;
	head_one = temp;

}

/***********************�Ե�һ����ʵ����������2����**********************/
void Insert_Snack_two()
{
	position * temp;
	temp = (position *)malloc(sizeof(position));
	temp->x = head_one->x;
	temp->y = head_one->y;
	temp->next = head_two;
	head_two = temp;
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

/**********************�ͷ�����**********************/
void Free_Snack(position * head)
{
    position * temp = NULL;
    for(; head!= NULL; head =temp)
    {
        temp = head->next;
        free(head);
    }
}



/**************************����������ƶ�******************************/
char direction = 'd';    //�����
extern void Judge_one();
extern void Judge_two();
char value = 0;
int turn = 0;
char direction_two = 52;    //�����
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
            printf("��ͣ");
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
		  puts("��Ϸ�˳��ɹ�!");
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



/**************************�ж���Ӯ******************************/
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
		printf("��������  ���س������¿�ʼ.");
			direction = 'd';
			Fruit_Flag = 0;
			Score_one = 0;
			Score_two = 0;
			Speed = 20000;
		    value = 0;
            turn = 0;
            direction_two = 52;    //�����
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
			printf("��������  ���س������¿�ʼ.");
			direction = 'd';
			Fruit_Flag = 0;
			Score_one = 0;
			Score_two = 0;
			Speed = 20000;
		    value = 0;
            turn = 0;
            direction_two = 52;    //�����
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
			printf("ײһ����  ���س������¿�ʼ.");
            direction = 'd';
			Fruit_Flag = 0;
			Score_one = 0;
			Score_two = 0;
			Speed = 20000;
		    value = 0;
            turn = 0;
            direction_two = 52;    //�����
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
		printf("��������  ���س������¿�ʼ.");
            direction = 'd';
			Fruit_Flag = 0;
			Score_one = 0;
			Score_two = 0;
			Speed = 20000;
		    value = 0;
            turn = 0;
            direction_two = 52;    //�����
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
			printf("��������  ���س������¿�ʼ.");
            direction = 'd';
			Fruit_Flag = 0;
			Score_one = 0;
			Score_two = 0;
			Speed = 20000;
		    value = 0;
            turn = 0;
            direction_two = 52;    //�����
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
			printf("ײһ����  ���س������¿�ʼ.");
            direction = 'd';
			Fruit_Flag = 0;
			Score_one = 0;
			Score_two = 0;
			Speed = 20000;
		    value = 0;
            turn = 0;
            direction_two = 52;    //�����
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
    setjmp(buf);   //��¼��ǰλ��
	Snack_Position_Init();  //�����ʼ������
    Snack_two_Position_Init();
	Display_Border();
	while(1)
    {
       	Move();
    }

}

