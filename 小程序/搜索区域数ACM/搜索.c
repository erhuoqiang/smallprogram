#include <string.h>
#include <stdio.h>
//#include <memory.h>
char map[111][111];
int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
void dfs(int x,int y)
{
	int i;
	map[x][y] = '.';
	for(i=0;i<8;i++) if(map[x+dir[i][0]][y+dir[i][1]] == 'w') dfs(x+dir[i][0],y+dir[i][1]);
}

int main()
{
	int n,m,i = 0,j,cnt=0;
	cnt++,i++;
	printf("%d\n",i);
	return 0;
}