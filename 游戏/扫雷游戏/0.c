#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#include<windows.h>

char a[12][12]; // δ֪�� 
char b[12][12]; // �� ֻ��* . 
char c[12][12]; // �𰸰��� �����м�����

int n, num; //n��ʣ��ը����λ�� ,num����Ҫ����ĸ��� Ҳ�����ʼը���ĸ���
char position[8][2] = {{0,-1},{0,1},{1,0},{-1,0},{-1,1},{1,-1},{1,1},{-1,-1}};

void display(char (*a)[12])
{
	int i, j;
	 system("cls"); // ����
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
			if(b[i][j] == 0 + 48) //����ը���ĸ���
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
	refresh(c); //ˢ��a,b,c
	get_randb(b); // ��ȡ����б�b
	get_c(b, c); // ��ȡ����ը������
//isplay(c); 
	display(b);
}
/******�Ҹ�����ը������***/
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
/******�ҳ����ڵ�0****/
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
	int i, j,  temp = 0, flag = 0, qi = 0, flag2; //k�Ǵ���8������  ,i,j���������� 
	init();
	while(1)
	{
b:		printf("GAME BEGIN!");
		display(b);
		display(a);
a:		printf("���ڻ��м���ը����%d ",n);	
		printf("�Ѿ�������ӣ�%d ",qi);
		printf("��Ҫ������:%d \n",num);
		
		printf("��ѡ����1��0:");
		assert(scanf("%d",&flag));
	if(flag)
	{
		printf("\n������Ҫ�ڵ�����(��ʽ��x.y):");
		scanf("%d.%d", &i, &j);
		if(i > 10 || j > 10 || i < 1 || j < 1)
		{
			printf("�������\n");
			goto a;
		}
		 if(b[i][j] == '*')
		{
			a[i][j] = '*';
			display(a);
			printf("�ȵ�ը���˱���!\n");
			printf("�Ƿ�������ˣ?(�س�����)");
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
		printf("ѡ��0ȡ����1��:");
		scanf("%d", &flag2);
	 if(flag2)
	 {
		printf("\n������Ҫ�������(��ʽ��x.y):");
		scanf("%d.%d", &i, &j);
		if(i > 10 || j > 10 || i < 1 || j < 1)
		{
			printf("�������\n");
			goto a;
		}
		
		qi++;
		a[i][j] = 'Y';
		 if(b[i][j] == '*')
		{
			 n--;
			 
			if(n == 0 && qi == num)
			{
				printf("��Ӯ����\n��Ӯ����\n��Ӯ����\n��Ӯ����\n");	
				printf("�Ƿ�������ˣ?(�س�����)");
				getchar();getchar();
				init();
				goto b;
			}

		} 
	 }
		else
		{
		printf("\n������Ҫ�������(��ʽ��x.y):");
		scanf("%d.%d", &i, &j);
		if(i > 10 || j > 10 || i < 1 || j < 1)
		{
			printf("�������\n");
			goto a;
		}
		if(a[i][j] == 'Y')
		{	
			qi--;
			a[i][j] = 3;
		}
		else
		{	
			printf("�˵�û����");
			goto a;
		}
		}
		
	}

	}

	
}
