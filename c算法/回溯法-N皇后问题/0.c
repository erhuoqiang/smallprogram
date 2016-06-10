/***********************************************************************************
遍历法 是用循环吧棋子放好后 在去检查 ，这样相对回溯法 多做了许多没必要的操作
回溯法 是一遍放旗子一边检查 当检测到不可能的情况则不会继续  一般多用递归。
递归一般占用资源多 但是比较好用 使用需要根绝场合需要判断是否合适。
************************************************************************************/
#include<stdio.h>

#define NN 8
int value[NN][NN];
int num; //当前操作的行数
int time; //计算满足一共有几种摆法

/*********************************
		判断下棋坐标是否满足条件
***********************************/
int judge_postition( int x, int y )
{
	register int i = 0;
	int tempx = x, tempy = y;

	for( i = 0; i < x; i++ )  
	{
		if( 1 == value[i][y] ) 
		{
			return 0;
		}
	}
	while( tempx > 0 && tempy > 0 )
	{
		if(value[--tempx][--tempy] == 1)
		{
			return 0;
		}
	}
	tempx = x, tempy = y;
	while( tempy < NN-1 && tempx >0 )
	{
		if(value[--tempx][++tempy] == 1)
		{
			return 0;
		}
	}

	return 1;

}
void display()
{
	int i = 0, j = 0; 
	for( i = 0; i < NN; i++ )
	{
		for( j = 0; j < NN; j++ )
		{
			printf(" %d ",value[i][j]);
		}
		printf("%\n");
	}
	printf("%\n");
}
void queen()
{
	register int i = 0,j = 0;;
	for( i = 0; i < NN; i++ )
	{
		if(judge_postition(num,i))
		{
			value[num][i] = 1;
			num++;
			if(num == NN)
			{
				time++;
				display();
			}
			queen();
			
			if( i == NN - 1 && num >= 0 ) //当一行中遍历坐标满足条件的最后一列结束后，需要退回上一层 ，并清空上一层
			{
				num--;
				for(j = 0; j < NN; j++ )
				value[num][j] = 0;
			}
		}
		else    
		{
			if( i == NN - 1 && num >= 0 ) //当一行中遍历后，没有满足条件的坐标，需要退回上一层 ，并清空上一层
			{
					num--;
					for(j = 0; j < NN; j++ )
					value[num][j] = 0;
			}
			continue;
		}
	}	

}	
	

int main()
{
	queen();
	printf("%d\n",time);
	return 0;
}

