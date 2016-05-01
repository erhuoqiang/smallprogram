/***********************************************************************************
������ ����ѭ�������ӷźú� ��ȥ��� ��������Ի��ݷ� ���������û��Ҫ�Ĳ���
���ݷ� ��һ�������һ�߼�� ����⵽�����ܵ�����򲻻����  һ����õݹ顣
�ݹ�һ��ռ����Դ�� ���ǱȽϺ��� ʹ����Ҫ����������Ҫ�ж��Ƿ���ʡ�
************************************************************************************/
#include<stdio.h>

#define NN 8
int value[NN][NN];
int num; //��ǰ����������
int time; //��������һ���м��ְڷ�

/*********************************
		�ж����������Ƿ���������
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
			
			if( i == NN - 1 && num >= 0 ) //��һ���б��������������������һ�н�������Ҫ�˻���һ�� ���������һ��
			{
				num--;
				for(j = 0; j < NN; j++ )
				value[num][j] = 0;
			}
		}
		else    
		{
			if( i == NN - 1 && num >= 0 ) //��һ���б�����û���������������꣬��Ҫ�˻���һ�� ���������һ��
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

