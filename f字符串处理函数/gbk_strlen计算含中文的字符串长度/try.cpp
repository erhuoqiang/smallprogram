#include<iostream>
#include<cassert>

using namespace std;

int gbk_strlen(const char * src)
{
    assert(src != NULL);
    const char * p = src;

    while(*p)
    {
        if(*p < 0 && (*(p+1) < 0 || *(p+1) > 63))
        {
            p = p+2;
            src++;
        }
        else
            p++;
    }
    return p - src;
}

int main()
{
    cout<<gbk_strlen("xia0־ǿ");
}
