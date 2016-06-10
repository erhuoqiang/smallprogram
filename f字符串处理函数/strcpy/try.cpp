#include<iostream>
#include<cassert>

using namespace std;

char * strcpy_m( char * dest, const char * src)
{
    assert(dest != NULL && src != NULL);
    char * temp = dest;   //±£´æÊ×µØÖ·
    while( (*dest++ = *src++) != '\0' );
    return temp;
}
int main()
{
    char dest[100];
    cout<<strcpy_m(dest,"qiang zhiq ");
}
