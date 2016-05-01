#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>

#define MAX(A, B) ((A)>(B)?(A):(B))
#define ESC 27

int value[4][4];
int score;
extern void Control();
void Init_value()
{
	int temp[2][2];
	int j,i;
	for( i = 0; i < 4; i++)
		for( j = 0; j < 4; j++)
			value[i][j] = 0;
	srand(time(NULL));
	temp[0][0] = rand() % 4;
	temp[0][1] = rand() % 4;
	temp[1][0] = rand() % 4;
	temp[1][1] = rand() % 4;
	while(temp[0][0] == temp[1][0] && temp[0][1] == temp[1][1])
	{
		temp[0][0] = rand() % 4;
		temp[0][1] = rand() % 4;
		temp[1][0] = rand() % 4;
		temp[1][1] = rand() % 4;
	}
	if( rand() % 10 > 5)    //��ʼ�� ���������� ��һ������Ԫ�ض���2���ڶ��ž���һ��2��1��4
	{
		value[temp[0][0]][temp[0][1]] = 2;
		value[temp[1][0]][temp[1][1]] = 4;
	}
	else
	{
		value[temp[0][0]][temp[0][1]] = 2;
		value[temp[1][0]][temp[1][1]] = 2;
	}
}

void Display_value()
{
	int j,i;
	system("cls");
	printf("*  *  *  *  *\n");
	for( i = 0; i < 4; i++)
	{
		printf("*");
		for( j = 0; j < 4; j++)
		{
			if(value[i][j] == 0) 
				printf("   ");
			else
			{
				printf("%3d", value[i][j]);
			}
		}
		printf("\n");
	}
	printf("\t\t������%d\n \n\n\t���������.��ESC�˳���Ϸ.", score);
}

int if_full()
{
	int x, y;

	for(x = 0; x< 4; x++)
		for(y = 0; y < 4; y++)
		{
			if(value[x][y] == 0)
			{
				return 0;
			}
		}
	return 1;
	
}


int if_over()
{
	int x, y;

	for(x = 0; x< 4; x++)
	{
		for(y = 2; y >= 0; y--)
		{
			if(value[x][y] == value[x][y + 1])
			{
				return 0;
			}
		}
	}
	for(x = 0; x< 4; x++)
	{
		for(y = 1; y <= 3; y++)
		{
			if(value[x][y] == value[x][y - 1])
			{
				return 0;
			}
		}
	}
	for(y = 0; y< 4; y++)
	{
		for(x = 1 ; x <= 3; x++)
		{
			if(value[x][y] == value[x - 1][y])
			{		
				return 0;
			}
		}
	}
	for(y = 0; y< 4; y++)
	{
		for(x = 2 ; x <= 0; x--)
		{
			if(value[x][y] == value[x + 1][y])
			{		
				return 0;
			}
		}
	}
	
		
		return 1;
}
void add_num()
{
	int temp[2];
	int times = 0, x, y, flag = 1;;
	srand(time(NULL));
	temp[0] = rand() % 4;
	temp[1] = rand() % 4;
	while(value[temp[0]][temp[1]] != 0)
	{
		times++;   //���ڼ��� ������� ���������  �����ѭ������7�κ�û�ҵ� VALUE����0��λ�� �Ͱ������������һ�� 
		if(times > 7)    // �ҵ���һ��Ϊ0 ������Ȼ�������µ�Ԫ��
		{
			for(x = 0; x< 4 && flag; x++)
				for(y = 0; y < 4; y++)
				{
					if(value[x][y] == 0)
					{
						flag = 0;
						break;
					}
				}
			temp[0] = x - 1;
			temp[1] = y;
		}
		else
		{
			temp[0] = rand() % 4;
			temp[1] = rand() % 4;
		}
		
	} 
	times = 0;
	if( rand() % 10 > 7)    // �½�һ���� ���������� ��һ��Ԫ����2���ڶ�����4 �ĵĸ���Сһ��
		value[temp[0]][temp[1]] = 4;
	else
		value[temp[0]][temp[1]] = 2;
}

int num[4] = {0};
void Move_right()
{
	int x, y;
	int temp[4] = {0}, count = 0;
	for(x = 0; x< 4; x++)
	{
		for(y = 0; y < 4; y++)
		{
		
			if(value[x][y] != 0)
			{
				temp[count] = value[x][y];
				count++;
		
			}
		
		}
		num[x] = 4 - count;	
		for(y = 3; y >= 0; y--)
		{
			if(count > 0)
			{
				count--;
				value[x][y] = temp[count];
				temp[count] = 0;
				
			}
			else
				value[x][y] = 0;
		}
		count = 0;
	}

}

void Move_left()
{
	int x, y;
	int temp[4] = {0}, count = 0;
	for(x = 0; x< 4; x++)
	{
		for(y = 0; y < 4; y++)
		{
			if(value[x][y] != 0)
			{
				temp[count] = value[x][y];
				count++;
			}
		}
		num[x] = 4 - count;
		for(y = 0; y < 4; y++)
		{
			if(y < count)
			{
				value[x][y] = temp[y];
				temp[y] = 0;
				
			}
			else
				value[x][y] = 0;
		}
		count = 0;
	}	
}
void Move_up()
{
	int x, y;
	int temp[4] = {0}, count = 0;
	for(y = 0; y< 4; y++)
	{
		for(x = 0; x < 4; x++)
		{
			if(value[x][y] != 0)
			{
				temp[count] = value[x][y];
				count++;
			}
		}
		num[y] = 4 - count;
		for(x = 0; x < 4; x++)
		{
			if(x < count)
			{
				value[x][y] = temp[x];
				temp[x] = 0;
				
			}
			else
				value[x][y] = 0;
		}
		count = 0;
	}	
}

void Move_down()
{
	int x, y;
	int temp[4] = {0}, count = 0;
	for(y = 0; y< 4; y++)
	{
		for(x = 0; x < 4; x++)
		{
			if(value[x][y] != 0)
			{
				temp[count] = value[x][y];
				count++;
			}
		}
		num[y] = 4 - count;
		for(x = 3; x >= 0; x--)
		{
			if(count > 0)
			{
				count--;
				value[x][y] = temp[count];
				temp[count] = 0;
				
			}
			else
				value[x][y] = 0;
		}
		count = 0;
	}	
}
void  Judge_right()
{
	int y, x;
	Move_right();
	for(x = 0; x< 4; x++)
	{
		for(y = 2; y >= num[x]; y--)
		{
			if(value[x][y] == value[x][y + 1])
			{
			
				value[x][y + 1] *= 2;
				value[x][y] = 0;
				score = MAX( score, value[x][y + 1]);
				if( score == 2048 )
					printf("��2048��");
				break;
			}
		}
	}
	if( if_full() && if_over())
	{
		   // system("cls");
		 printf("\n��Ϸ��������:%d\n���س���ʼ", score);
		 // system("pause");
		  getchar();
		  Init_value();
		  Display_value();
	      Control();
		  
	}
	if( !(if_full()) )
	{
		Move_right();
		add_num();
	}
}

void Judge_left()
{
	int y, x;
	Move_left();
	for(x = 0; x< 4; x++)
	{
		for(y = 1; y <= 3 - num[x]; y++)
		{
			if(value[x][y] == value[x][y - 1])
			{
				value[x][y - 1] *= 2;
				value[x][y] = 0;
				score = MAX( score, value[x][y - 1]);
				if( score == 2048 )
					printf("��2048��");
				break;
			}
		}
	}
	if( if_full() && if_over())
	{
		   // system("cls");
		  printf("\n��Ϸ��������:%d\n���س���ʼ", score);
		 // system("pause");
		  getchar();
		  Init_value();
		  Display_value();
	      Control();
		 
	}
	if( !(if_full()))
	{
		Move_left();
		add_num();
	}
}
void Judge_up()
{
	int y, x;

	Move_up();
	
	for(y = 0; y< 4; y++)
	{
		for(x = 1 ; x <= 3 - num[y]; x++)
		{
			if(value[x][y] == value[x - 1][y])
			{
				value[x - 1][y] *= 2;
				value[x][y] = 0;
				score = MAX( score, value[x - 1][y]);
				if( score == 2048 )
					printf("��2048��");
				break;
			}
		}
	}
	if( if_full() && if_over())
	{
		 // system("cls");
		  printf("\n��Ϸ��������:%d\n���س���ʼ", score);
		 // system("pause");
		  getchar();
		  Init_value();
		  Display_value();
	      Control();
		  
	}
	if( !(if_full()) )
	{
		Move_up();
		add_num();
	}

}
void Judge_down()
{
	int y, x;
	Move_down();
	for(y = 0; y< 4; y++)
	{
		for(x = 2; x >= num[y]; x--)
		{
			if(value[x][y] == value[x + 1][y])
			{
				value[x + 1][y] *= 2;
				value[x][y] = 0;
				score = MAX( score, value[x + 1][y]);
				if( score == 2048 )
					printf("��2048��");
				break;
			}
		}
	}
	if( if_full() && if_over() )
	{
		  // system("cls");
		  printf("\n��Ϸ��������:%d\n���س���ʼ", score);
		 // system("pause");
		  getchar();
		  Init_value();
		  Display_value();
	      Control();
		  
	}
	if( !(if_full()) )
	{
		Move_down();
		add_num();
	}


}

void Control()
{
	char ch;
	while(1)
	{
		ch = getch();
		if(ch == ESC)
		{
		  system("cls");
		  puts("��Ϸ�˳��ɹ�!");
		  system("pause");
		  exit(0);
		}
		switch( ch )          //�������ֵ�Ǻ���ĸKMPH��Ӧ��
		{
		 case 72:  Judge_up();
					break;      //��
	     case 80:  Judge_down();
					break;         //��
	 	 case 75:  Judge_left();
				    break;      //��
		 case 77:  Judge_right();
			        break;     //��
		 default:	break;
		}
		Display_value();
	}

}
int main()
{
	//system("color 4e");
	Init_value();
	Display_value();
	Control();
}



	
	
	
	