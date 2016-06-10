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
            tempsrc = src;    //src��sub��ǰ���ַ��Ѿ��ȽϹ���Ϊʲôtempsrc������ src +����֤subֻ��һ���ַ��������Ҳ���Բ�ĵ�
							  //��֤subֻ��һ���ַ��������Ҳ���Բ�ĵ�ͬʱ��������ʱ��������src��sub��ǰ��ֵ���ڲ�����������	
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
