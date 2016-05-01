#include<stdio.h>
#include<assert.h>

const char * strfind(const char *src, const char *sub)
{
	const char * tempsrc = NULL;
	const char * tempsub = NULL;
    assert(src != NULL && sub != NULL);

    while(*src)
    {
        if( *src == *sub)
        {
            tempsrc = src;    //src和sub当前的字符已经比较过了为什么tempsrc不等于 src +１保证sub只有一个字符的情况下也可以查的到
							  //保证sub只有一个字符的情况下也可以查的到同时必须用临时变量保存src和sub当前的值用于参与下面运算	
			tempsub = sub;
            while(*tempsrc == *tempsub)
            {
                if( *(++tempsub) == 0 )
                {
                    return src;
                }
				tempsrc++;
            }
        }
        src++;
    }
    return NULL;

}
int main()
{
    printf("%s\n",strfind("aasdf", "s") );
	printf("%s\n",strfind("aasdf", "as") );
	printf("%s\n",strfind("aasdf", "f") );
}
