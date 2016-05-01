#include<stdio.h>

int count = 0;
char * GET(char *p1,char *p2)
{
		
	char * temp = NULL, *start = p1, *dest = p2;
	while( *p1 != 0)
	{
		start = p1,dest = p2;
		count = 0;
		while( *dest != 0 && *start != *dest )dest++;
		if(*dest != 0)
		{
			temp = dest;
			while(*start == *dest && *start != 0 && *dest != 0)
			{
				start++,dest++; 
				count++;
			}
			if(count >= 2)
				return temp;
		}
		p1++;
	}
	return NULL;
}
int main()
{
	int i = 0;
	char p2[100],p1[100];
	char *s = NULL;
	scanf("%s%s",p1,p2);
	s = GET(p1,p2);
	if( s != NULL)
	{	//printf("%s",s);
	for ( i = 0; i < count ; i++)
    	printf("%c",*s++);

	}
}