#include<stdio.h>
#include<assert.h>
void change(char *src)
{
	char *ptr = src, *start = src, *end = src;	
	assert(src != NULL);
	while(*ptr != '\0')
	{
		if(*ptr == ' ')
		{
			end = ptr - 1;
			while(start < end)
			{
				*start ^= *end;
				*end ^= *start;
				*start++ ^= *end--;
			}
			start = ptr + 1;
		}
		
		ptr++;
	}
	end = ptr -1;
	while(start < end)
	{
		*start ^= *end;
		*end ^= *start;
		*start++ ^= *end--;
	}
	start = src;
	end = ptr - 1;
	while(start < end)
	{
		*start ^= *end;
		*end ^= *start;
		*start++ ^= *end--;
	}
}

			
int main()
{
	char a[100] = "xiao zhi qiang";

	change(a);
	printf("%s",a);
}