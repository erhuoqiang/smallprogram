#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#include<windows.h>

char a[12][12]; // 未知的 
char b[12][12]; // 答案 只有* . 
char c[12][12]; // 答案包括 附近有几颗雷

int n, num; //n是剩余炸弹的位数 ,num是需要插旗的个数 也就是最开始炸弹的个数
char position[8][2] = {{0,-1},{0,1},{1,0},{-1,0},{-1,1},{1,-1},{1,1},{-1,-1}};

void display(char (*a)[12])
{
	int i, j;
	 system("cls"); // 清屏
	for(i = 0; i < 11; i++)		
	{
		for(j = 0; j < 11; j++)
		{
			printf(" %c ", *(*(b+i)+j));
		}
		printf("\n");
	}
		printf("\n");

	for(i = 0; i < 11; i++)		
	{
		for(j = 0; j < 11; j++)
		{
			printf(" %c ", *(*(a+i)+j));
		}
		printf("\n");
	}
}

void get_randb(char (*b)[12])
{

		int i, j;
		n = num = 0;
		srand(time(NULL));
		for( i = 1; i <=10; i++)
		for( j = 1; j <= 10; j++)
		{	
			b[i][j] = rand()%10 + 48;
			if(b[i][j] == 0 + 48) //限制炸弹的个数
			{
				n++;
				num++;
				b[i][j] = '*';
			}
			else 
				b[i][j] = '.';
		}
}

void refresh(char (*a)[12])
{
	int i, j;
		for(i = 0; i < 11; i++)
	{
		for(j = 0; j < 11; j++)
		{
			a[i][j] = 3;
		}
	}
	for(i = 0; i < 11; i++)
		a[0][i] = i + 48;
	for(i = 1; i < 11; i++)
		a[i][0] = i + 48;
}

void get_c(char (*b)[12], char (*c)[12])
{
	int i, j, s = 0, k;
		for(i = 1; i < 11; i++)
	{
		for(j = 1; j < 11; j++)
		{
				for(k = 0; k < 8; k++)
			if(b[i+position[k][0]][j+position[k][1]] == '*')
			{	s++;	}
			c[i][j] = s + 48;
			s = 0;
		}
	}
}

void init()
{
	refresh(a);
	refresh(b);
	refresh(c); //刷新a,b,c
	get_randb(b); // 获取随机列表b
	get_c(b, c); // 获取坐标炸弹个数
//isplay(c); 
	display(b);
}
/******找附近的炸弹数量***/
void dfs(int i, int j)
{
	int k;

	for(k = 0; k < 8; k++)
		if(c[i+position[k][0]][j+position[k][1]] == '.')
			a[i+position[k][0]][j+position[k][1]] = ' ';
		else
		a[i+position[k][0]][j+position[k][1]] = c[i+position[k][0]][j+position[k][1]];

	a[i][j] = ' ';
	c[i][j] = '.';
	for(k = 0; k < 8; k++)
		if(c[i+position[k][0]][j+position[k][1]] == '0')
		{	
			dfs(i+position[k][0] ,j+position[k][1]);
		}	
}
/******找出相邻的0****/
void find_zero(int i, int j)
{
	int k;

	for(k = 0; k < 8; k++)
		if(c[i+position[k][0]][j+position[k][1]] == '.')
			a[i+position[k][0]][j+position[k][1]] = ' ';
		else
		a[i+position[k][0]][j+position[k][1]] = c[i+position[k][0]][j+position[k][1]];

	a[i][j] = ' ';
	c[i][j] = '.';
	for(k = 0; k < 4; k++)
		if(c[i+position[k][0]][j+position[k][1]] == '0')
		{	
			dfs(i+position[k][0] ,j+position[k][1]);
		}	
}

int main()
{
	int i, j,  temp = 0, flag = 0, qi = 0, flag2; //k是代表8个坐标  ,i,j这里是坐标 
	init();
	while(1)
	{
b:		printf("GAME BEGIN!");
		display(b);
		display(a);
a:		printf("现在还有几颗炸弹：%d ",n);	
		printf("已经插的旗子：%d ",qi);
		printf("需要的旗子:%d \n",num);
		
		printf("请选择挖1埋0:");
		assert(scanf("%d",&flag));
	if(flag)
	{
		printf("\n请输入要挖的坐标(格式：x.y):");
		scanf("%d.%d", &i, &j);
		if(i > 10 || j > 10 || i < 1 || j < 1)
		{
			printf("输入错误！\n");
			goto a;
		}
		 if(b[i][j] == '*')
		{
			a[i][j] = '*';
			display(a);
			printf("踩到炸弹了笨蛋!\n");
			printf("是否重新玩耍?(回车继续)");
			getchar();getchar();
			init();
		 }
		else
		{
			if(c[i][j] == '0')
			{
			//	printf("%d ,%d", i, j);
				find_zero(i,j);
			}
			else
			{
		//	printf("%c",c[i][j]);
			if(c[i][j] == '.')
				a[i][j] = '0';
			a[i][j] = c[i][j];
			}
			display(a);
			goto a;
		}
	} 
	else
	{
		printf("选择0取消埋1埋:");
		scanf("%d", &flag2);
	 if(flag2)
	 {
		printf("\n请输入要埋的坐标(格式：x.y):");
		scanf("%d.%d", &i, &j);
		if(i > 10 || j > 10 || i < 1 || j < 1)
		{
			printf("输入错误！\n");
			goto a;
		}
		
		qi++;
		a[i][j] = 'Y';
		 if(b[i][j] == '*')
		{
			 n--;
			 
			if(n == 0 && qi == num)
			{
				printf("你赢啦！\n你赢啦！\n你赢啦！\n你赢啦！\n");	
				printf("是否重新玩耍?(回车继续)");
				getchar();getchar();
				init();
				goto b;
			}

		} 
	 }
		else
		{
		printf("\n请输入要埋的坐标(格式：x.y):");
		scanf("%d.%d", &i, &j);
		if(i > 10 || j > 10 || i < 1 || j < 1)
		{
			printf("输入错误！\n");
			goto a;
		}
		if(a[i][j] == 'Y')
		{	
			qi--;
			a[i][j] = 3;
		}
		else
		{	
			printf("此点没有埋");
			goto a;
		}
		}
		
	}

	}

	
}
