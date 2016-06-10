#include<stdio.h>
#include<stdlib.h>

int my_strlen(const char * src)
{
	const char * temp = src;
	if(src == NULL)
		return -1;
	while(*src++);
	return src - temp - 1;
}

char *  right_move(char * a, int k)
{
	int length = 0, count = 0 , i = 0;
	char * temp = NULL;
	if( a == NULL || k < 0 )
		return NULL;
    length = my_strlen(a);
	count = k % length;
	
	temp = (char *)malloc(length);
	for(; i < length; i++)
		temp[i] = a[i];

	for(i = 0; i < length; i++)
		a[ (i + count)%length ] = temp[i];
	free(temp);
	temp = NULL;
	return a;
}

char * remove_repition(char * src)
{
	char dest[26];
	char temp[26];
	int i = 0, j = 0;
	char * head = src;
	int length = my_strlen(src);
	src += (length - 1);
	if(src == NULL)
			return NULL;

	for( i = 0; i < 26; i++)
	{
		temp[i] = -1;
	}

	while(length--)
	{
		if(*src >= 97 && *src <= (97 + 25))
		{
			if( temp[*src - 97] == -1)
			{
				dest[j] = *src;
				j++;
				temp[*src - 97] = 0;
			}
		}
		src--;
	
	}
	for( i = 0; i < j; i++ )
	{
		src[i] = dest[ j - i - 1 ];
	}
	src[i] = 0;
	return src;
}

	

int main()
{
	char a[] = "bbcacdwwcadcadfdc";
	printf( "%s\n", remove_repition(a) );
}
		