#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
/*
malloc�������ܷ���NULL ��Ϊ�ڴ���ܷ��䲻�� 
��� �ַ��� �����Ҫ�ӡ�\0�� �������û��
�����ǵ���malloc������ͷ� ��Ϊ �еĳ�������ѭ�� ������� ���������Ƶĵ��ö� ���������ڴ�ǵ�free(r)��
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