#include<stdio.h>

int my_strlen(const char * str)
{
	const char * temp = str;
	if(str == NULL)
		return -1;
	while(*str++);
	return str - temp - 1;
}

char* StrRev(char * str, int len)
{
	char *begin = str;
	char *end = str + len -1;
	if(NULL == str || len < 0)
		return NULL;
	while(begin < end)
	{
		*begin ^= *end;
		*end ^= *begin;
		*begin++ ^= *end--;
	}
	return str;
} 

char * StrShift(char * str, int shift_num,int len)
{	
	int pos = (shift_num + len) % len;
	if(str == NULL || len < 0)
		return NULL;
	StrRev(str, len - pos);
	StrRev(str + len - pos, pos);
	StrRev(str, len);
	return str;
}

int main(int argc, char **argv)
{
	char str[] ="ABCDE";
	int num = 0;
	while(scanf("%d", &num))
	{
		printf("%s\n",StrShift(str, num, my_strlen(str)));
	}
}
		
