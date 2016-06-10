#include<stdio.h>

char * Get_Prefix(const char * src, const char * dest)
{
	int tempcount = 0, sumcount = 0;
	const char * temppos = NULL;
	const char * tempdest = dest;
	if(src == NULL || dest == NULL)
	{
		return NULL;
	}

	while(*src && *dest)
	{
		if(*src == *dest)
		{
			tempcount++;
			dest++;
			if(tempcount > sumcount)
			{
				sumcount = tempcount;
				temppos = src;
			}
		}
		else
		{
			tempcount = 0;	
			dest = tempdest;
		}
		src++;
	}
	temppos = temppos - sumcount + 1;
	for(tempcount = 0; tempcount < sumcount; ++tempcount)
	{
		putchar(*(tempcount + temppos));	
	}
	return temppos;
}

int main()
{
	char a[100],b[100];
	gets(a);
	gets(b);
	Get_Prefix(a,b);
}
