#include<iostream>
#include<cassert>

using namespace std;

int strlen( const char * str )
{
    int len = 0;
    assert(str != NULL);
    while( *str++ )
        ++len;
    return len;
}

int strlen1( const char * str )
{
    assert(str != NULL);
    const char * temp = str;
    while( *str++ );
    return (str - temp - 1);
}

int main()
{
    cout<<strlen1("xxxx");
    cout<<strlen("xxxx");
}
