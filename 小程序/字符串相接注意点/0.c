#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
/*
malloc（）可能返回NULL 因为内存肯能分配不足 
其次 字符串 最后面要加‘\0’ 数组可以没有
最后就是调用malloc后最好释放 因为 有的程序是死循环 不会结束 不能无限制的调用堆 所以用完内存记得free(r)；
*/
char * str_cat(char *s, char *t)
{
	char *r;
	r = (char *)malloc(strlen(s) + strlen(t) + 1);
//assert(r);
	if(!r)
	{
		exit(1);
	}
	strcpy(r, s);
	strcat(r, t);
	return r;
}

int main()
{
	char a[10] = "xxx", b[10] = "xsdafd";
	char *r = NULL;
	r = str_cat(a, b);
	printf("%s\n",r);
	free(r);
}