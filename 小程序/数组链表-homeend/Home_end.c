#include<stdio.h>

#define LEN 10001
int current = 0, last = 0;
char str[LEN];
int next[LEN];

int strlen_my(const char * src)
{
    const char * temp = src;
    if( src == NULL )
    {
        return 0;
    }
    while(*src++);
    return src - temp - 1;
}

int main(int argc, char **argv)
{

    int i = 0;  //�����±�
    int len = 0;  //�ַ�������
    char ch = 0;  //�����ַ�����ʱ����

    while( scanf("%s", str+1) == 1 )
    {
        i = current = last = 0;
        len = strlen_my(str + 1);
        next[0] = 0; //��һ��Ҫ��ӡ�ַ��±��ʼ��

        for(i = 1; i <= len; i++)
        {
            ch = str[i];
            if( ch == '[' )
                current = 0;
            else if( ch == ']' )
                current = last;
            else
            {
                next[i] = next[current];
                next[current] = i;
                if(last == current) last = i;
                current = i;
            }
        }
        for( i = next[0]; i != 0; i = next[i] )
        {
            putchar(str[i]);
        }
        putchar('\n');
    }
    return 0;
}
