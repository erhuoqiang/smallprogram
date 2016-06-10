#include<iostream>
#include<cassert>

using namespace std;

char * str_replace(const char * src, const char * sub, const char * rep, char * result)
{
    assert(src != NULL && sub != NULL && result !=NULL);

    const char *tempsrc = NULL;
    const char *tempsub = NULL;
    const char *temprep = NULL;
    char * tempresult = result;
    while(*src)
    {
        *result++ = *src;
        if(*src == *sub)
        {
            tempsrc = src;
            tempsub = sub;

            while(*tempsrc == *tempsub)
            {
                if(*++tempsub == '\0')
                {
                    result--;
                    temprep = rep;
                    while(*temprep)
                    {
                        *result++ = *temprep++;
                    }
                    src = tempsrc;
                }
                tempsrc++;
            }
        }
        src++;
    }
    *result = '\0';
    return tempresult;
}

int main()
{
    char src[] = "hanying xi huan hanying";
    char sub[] = "hanying";
    char rep[]= "why";
    char res[100] = "";
    cout<<str_replace(src, sub, rep, res)<<endl;
    cout<<str_replace("abcdefcdg", "cd", "123", res)<<endl;
    cout<<res<<endl;
}
