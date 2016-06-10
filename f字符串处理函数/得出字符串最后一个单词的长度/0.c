#include<stdio.h>
#include<string.h>


int my_strlen(const char * src)
{
    const char * temp = src;
    if(src == NULL)
        return -1;
    while(*src++);
    return src - temp - 1;
}


const char * my_strstr(const char *src, const char dest)
{
	const char * temp = src;
	if(src == NULL)
		return NULL;
	while(*src != dest && *src != 0)
	{
		src++;
	} 
	if(*src == 0)
		return NULL;
	return src;
}

int get_last_num(const char *src)
{
   const char * temp = src;
   if(src == NULL)
       return -1;
   while((src = my_strstr(temp,' ')) != NULL)
   {
	   temp = src + 1;
   }
  
   return  my_strlen(temp);
}
int main()
{
    char a[100];
	gets(a);  //不能用scanf("%s",a)因为用这个碰到空格就结束输入了
	printf("%d", get_last_num(a));
}
