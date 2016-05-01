#include<iostream>
#include<cassert>

using namespace std;

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

int main()
{
    char dest[100];
    memcpy_m(dest, "qiang", 4);
    dest[4] = '\0';
    cout<<dest;
}
