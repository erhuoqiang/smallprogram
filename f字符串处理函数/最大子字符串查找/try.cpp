#include<iostream>
#include<cassert>
#include<cstdlib>
using namespace std;

int strlen_m( const char * str )
{
    assert(str != NULL);
    const char * temp = str;
    while( *str++ );
    return (str - temp - 1);
}

const char * strfind(const char *src, const char *sub)
{
	const char * tempsrc = NULL;
	const char * tempsub = NULL;
    assert(src != NULL && sub != NULL);

    while(*src)
    {
        if( *src == *sub)
        {
            tempsrc = src;
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

void * memcpy_m(void * dest, const void * src, int size)
{
    assert((dest != NULL) && (src != NULL) && (size >0));
    char * tempdest = (char *)dest;
    char * tempsrc = (char *)src;
    while( size-- > 0 )
    {
        *tempdest++ = *tempsrc++;
    }
    return dest;
}

char * max_commonstr(const char * src, const char * sub)
{
    assert(src != NULL && sub != NULL);

    int i = 0, j = 0, len = 0;;
    char * tempsub = NULL;
    const char * longstr = src;
    const char * shortstr = sub;

    len = strlen_m(shortstr);
    if( strlen_m(longstr) <  len )
    {
        longstr = sub;
        shortstr = src;
    }

    if( strfind(longstr, shortstr) != NULL )   //分清长短后直接先比一次
    {
        return (char *)shortstr;
    }

    tempsub = (char *)malloc( len );

    for( i = len - 1; i > 0; --i)   //搜索的子字符串长度 由大到小，这样就没必要分清哪个公共字符串长了。
    {
        for(j = 0; j <= len - i; ++j)
        {
            memcpy_m( tempsub, sub + j, i );
            tempsub[i] = '\0';
            if( strfind(src, tempsub) != NULL)
                return tempsub;
        }
    }
    return NULL;
}
int main()
{
    cout<<max_commonstr("xiao zhi qiang", "xiazhi")<<endl;
}
