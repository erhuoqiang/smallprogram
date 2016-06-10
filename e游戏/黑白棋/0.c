#include<stdio.h>
#include<windows.h>

char dis[9][9];
int score[2] = {2,2};

void Init_dis()
{
	register int i, j;
	for(i = 1; i < 9; i++)
		dis[0][i] = 48 + i;

	for(i = 1; i < 9; i++)
		dis[i][0] = 48 + i;

	for(i = 1 ; i < 9; i++)
		for(j = 1; j < 9; j++)
			dis[i][j] = ' ';
		dis[0][0] = '*';
		dis[4][4] = '#';
		dis[4][5] = '0';
		dis[5][4] = '0';
		dis[5][5] = '#';
}
void delayms(int ms)
{
	int i,j;
	for( i = 0 ; i < 65222; i++)
		for(j = 0; j < ms; j++)
			;
}
void display()
{
	register int i, j, k;
	system("cls");
	printf("\n");
	for(i = 0 ; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			printf(" %c |", dis[i][j]);
		}
		printf("\n");
	
		for(k = 0; k < 9; k++)
			printf(" ---");
			printf("\n");
	}
	printf("\n Computer is '#'; You are '0'; You first;\n");
	printf(" Your score : %d \n Computer's score : %d \n", score[0],score[1]);
	printf(" Please input postition x.y :");
	
}

int way[8][2] = { {0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1} };

/**************************用户输入的判断*********************************/
int Input_Judge(int x, int y)
{
	register int i = 0;
	int turn_num = 0;
	int temp_x = x, temp_y = y;
	int flag = 0;
	if(dis[x][y] != ' ')
	{
		return 0;
	}
	for( i = 0; i < 8 ; i++)
	{
		temp_x = x;
		temp_y = y;
		turn_num = 0;
		while(temp_x > 0 && temp_x < 10 && temp_y > 0 && temp_y < 10 &&dis[ temp_x + way[i][0] ][ temp_y + way[i][1] ] == '#')
		{
			temp_x = temp_x + way[i][0];
			temp_y = temp_y + way[i][1];
			turn_num++;
		}
		if(temp_x > 0 && temp_x < 10 && temp_y > 0 && temp_y < 10 && dis[ temp_x + way[i][0] ][ temp_y + way[i][1] ] == '0' && turn_num != 0 )
		{
			score[0] += turn_num;
			score[1] -= turn_num;
			dis[x][y] = '0';
			flag = 1;
			while(turn_num)
			{
				dis[ x + turn_num * way[i][0] ][ y + turn_num * way[i][1] ] = '0';
				turn_num--;
			}
		}
	}
	if(flag == 0)
		return 0;
	else
	{
		score[0] += 1;
		return 1;
	}
}
/***************************电脑下棋位置判断 三个难度选择*************************/
void Computer_Easy_Judge()
{
	register int x = 0, y = 0, i = 0;
	int turn_num = 0;
	int temp_x = x, temp_y = y;
	int flag = 0;
	for( x = 1; x < 9; x++ )
	{
		for( y = 1; y < 9; y++ )
		{
			if(dis[x][y] != ' ')
			{
				continue;
			}
			for( i = 0; i < 8 ; i++)
			{
				temp_x = x;
				temp_y = y;
				turn_num = 0;
				while( dis[ temp_x + way[i][0] ][ temp_y + way[i][1] ] == '0')
				{
					temp_x = temp_x + way[i][0];
					temp_y = temp_y + way[i][1];
					turn_num++;
				}
				if(dis[ temp_x + way[i][0] ][ temp_y + way[i][1] ] == '#' && turn_num != 0 )
				{
					score[1] += turn_num;
					score[0] -= turn_num;
					dis[x][y] = '#';
					flag = 1;
					while(turn_num)
					{
						dis[ x + turn_num * way[i][0] ][ y + turn_num * way[i][1] ] = '#';
						turn_num--;
					}
				}	
			}
			if(flag != 0)
				{
					score[1] += 1;
					return;
				}
		}
	}
}    

void Computer_Medium_Judge()
{
	register int x = 0, y = 0, i = 0;
	int turn_num = 0;
	int temp_x = x, temp_y = y;
	int flag = 0;
	int pattern_flag = 1;
	if(pattern_flag)
	{
		for( x = 1; x < 9; x++ )
		{
			for( y = 1; y < 9; y++ )
			{
				if(dis[x][y] != ' ')
				{
					continue;
				}
				for( i = 0; i < 8 ; i++)
				{
					temp_x = x;
					temp_y = y;
					turn_num = 0;
					while( dis[ temp_x + way[i][0] ][ temp_y + way[i][1] ] == '0')
					{
						temp_x = temp_x + way[i][0];
						temp_y = temp_y + way[i][1];
						turn_num++;
					}
					if(dis[ temp_x + way[i][0] ][ temp_y + way[i][1] ] == '#' && turn_num != 0 )
					{
						score[1] += turn_num;
						score[0] -= turn_num;
						dis[x][y] = '#';
						flag = 1;
						while(turn_num)
						{
							dis[ x + turn_num * way[i][0] ][ y + turn_num * way[i][1] ] = '#';
							turn_num--;
						}
					}	
				}
				if(flag != 0)
					{
						score[1] += 1;
						return;
					}
				}
			}
		pattern_flag = 0;
		}
		else
		{
			for( y = 1; y < 9; y++ )
			{
			for( x = 1; x < 9; x++ )
			{
				if(dis[x][y] != ' ')
				{
					continue;
				}
				for( i = 0; i < 8 ; i++)
				{
					temp_x = x;
					temp_y = y;
					turn_num = 0;
					while( dis[ temp_x + way[i][0] ][ temp_y + way[i][1] ] == '0')
					{
						temp_x = temp_x + way[i][0];
						temp_y = temp_y + way[i][1];
						turn_num++;
					}
					if(dis[ temp_x + way[i][0] ][ temp_y + way[i][1] ] == '#' && turn_num != 0 )
					{
						score[1] += turn_num;
						score[0] -= turn_num;
						dis[x][y] = '#';
						flag = 1;
						while(turn_num)
						{
							dis[ x + turn_num * way[i][0] ][ y + turn_num * way[i][1] ] = '#';
							turn_num--;
						}
					}	
				}
				if(flag != 0)
					{
						score[1] += 1;
						return;
					}
				}
			}
				pattern_flag = 1;
		}
}    
void Computer_Difficult_Judge()
{
	register int x = 0, y = 0, i = 0;
	int turn_num = 0;
	int temp_x = x, temp_y = y;
	int flag = 0;
	int sum = 0, max = 0, xx = 0, yy = 0;
	for( x = 1; x < 9; x++ )
	{
		for( y = 1; y < 9; y++ )
		{
			if(dis[x][y] != ' ')
			{
				continue;
			}
			sum = 0;
			for( i = 0; i < 8 ; i++)
			{
				temp_x = x;
				temp_y = y;
				turn_num = 0;
				while(dis[ temp_x + way[i][0] ][ temp_y + way[i][1] ] == '0')
				{
					temp_x = temp_x + way[i][0];
					temp_y = temp_y + way[i][1];
					turn_num++;
				}
				if( dis[ temp_x + way[i][0] ][ temp_y + way[i][1] ] == '#' && turn_num != 0 )
				{
					sum += turn_num;
					flag = 1;
				}	
			}
			if(flag != 0)
			{
				max = sum > max ? (xx = x, yy = y,sum) : max;
				flag = 0;
			}
		}
	}
	
			for( i = 0; i < 8 ; i++)
			{
				temp_x = xx;
				temp_y = yy;
				turn_num = 0;
				while( dis[ temp_x + way[i][0] ][ temp_y + way[i][1] ] == '0')
				{
					temp_x = temp_x + way[i][0];
					temp_y = temp_y + way[i][1];
					turn_num++;
				}
				if(dis[ temp_x + way[i][0] ][ temp_y + way[i][1] ] == '#' && turn_num != 0 )
				{
					
					while(turn_num)
					{
						dis[ xx + turn_num * way[i][0] ][ yy + turn_num * way[i][1] ] = '#';
						turn_num--;
					}
				}	
			}
			score[1] += 1 + max;
			score[0] -= max;
			dis[xx][yy] = '#';

}      

void Judge_win()
{
	register i, j;
	for( i = 1; i < 9; i++)
		for(j = 1; j < 9; j++)
			if( dis[i][j] == ' ')
				return ;
	if(score[0] > score[1])
	{
		printf("You are winner!!!!");
	}
	else if(score[1] == score[0])
	{
		printf("Both are winner!!!!");
	}
	else
	{
		printf("You are loser!!!!");
	}
	while(1);
}


int main()
{
	int x = 0, y = 0;
	int pattern = 0;
	Init_dis();
	printf("\nPlease select difficulty 1. EASE 2. Medium 3. Difficult:");
D:	scanf("%d",&pattern);
	
	
	switch(pattern)
	{
	case 1:    
				display();
				while(1)
				{
			A:			scanf("%d.%d",&x, &y);
						if( Input_Judge(x, y) )
						{
							display();	
							Judge_win();
							delayms(5000);
							Computer_Easy_Judge();
							display();	
						}
						else
						{
							display();
							printf(" Please input against:");
							goto A;
						}
				}
	case 2:
			display();
			while(1)
				{
			B:		scanf("%d.%d",&x, &y);
					if( Input_Judge(x, y) )
					{
						display();	
						Judge_win();
						delayms(5000);
						Computer_Medium_Judge();
						display();	
					}
					else
					{
						display();
						printf(" Please input against:");
						goto B;
					}
				
				}
	
	case 3:
			display();
			while(1)
				{
			C:		scanf("%d.%d",&x, &y);
					if( Input_Judge(x, y) )
					{
						display();	
						Judge_win();
						delayms(5000);
						Computer_Difficult_Judge();
						display();	
					}
					else
					{
						display();
						printf(" Please input against:");
						goto C;
					}
				
				}
	default :
		printf("Input Error.Please select against:");
		goto D;
	}
		
}