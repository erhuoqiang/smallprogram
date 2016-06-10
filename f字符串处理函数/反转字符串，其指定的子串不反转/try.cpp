#include<iostream>
#include<cassert>

using namespace std;

int strlen(const char * str)
{
    assert(str != NULL);
    const char *temp = str;
    while(*str++ != '\0');
    return (str - temp -1);
}

char *revstr(char * str, const char * sub)
{
    assert(str != NULL && sub != NULL);
    char * tempstr = NULL;
    const char * tempsub = NULL;
    char * start = NULL;
    char * endstr = NULL;
    char * tempsrc = str;
    while(*str)
    {
        if(*str == *sub)
        {
            tempstr = str;
            tempsub = sub;
            start = tempstr;
            while( *tempstr == *tempsub++ )
            {
                if(*tempsub == '\0')
                {
                    endstr = tempstr;
                    while(start < endstr)
                    {
                        *start ^= *endstr;
                        *endstr ^= *start;
                        *start++ ^= *endstr--;
                    }
                }
                tempstr++;
            }
        }
        str++;
    }
    start = tempsrc;
    endstr = tempsrc + strlen(start) - 1;
    while(start < endstr)
    {
        *start ^= *endstr;
        *endstr ^= *start;
        *start++ ^= *endstr--;
    }
    return tempsrc;
}

int main()
{
    char a[] = "Welcom you, my friend";
    cout<<revstr(a, "end");
}
