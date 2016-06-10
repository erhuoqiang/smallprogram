#include<stdio.h>
#include<string.h>

void get_next( char * next, char * T)
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	
	while( i <=  strlen(T + 1)  )
	{
		if( j == 0 || T[j] == T[i] )
		{
			i++;
			j++;
			if( T[i] != T[j] )
				next[i] = j;
			else
				next[i] = next[j];
		}

		else
		{
			j = next[j];
		}
	}

}

 int Index_KMP ( char * S, char * T, int pos)
 {
	 int i = pos;
	 int j = 0;
	 char next[255] = {0};
	 get_next(next,T);
	 while(  j <= strlen(T + 1)  && i <= strlen(S + 1))
	 {
		 if( j == 0 || S[i] == T[j] )
		 {
			 ++i;
			 ++j;
		 }
		 else
		 {
			 j = next[j];
		 }
	 }
		 if ( j > strlen(T  + 1) )
			 return i - strlen(T + 1);
		 else
			 return 0;
		 
 }
int tem = 0;
int search( char * S, char * T)
{
	tem = Index_KMP(S,T, tem);
		printf("%d ",tem );
		return tem;
}
void main()
{
	 char temp[200], s[400];
	 scanf("%s", temp + 1);
	 scanf("%s", s + 1 );
     while (search(s,temp) != 0);
	 
	 
}