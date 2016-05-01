#include<iostream>
#include<cassert>

using namespace std;

int strlen( const char * str )
{
    assert(str != NULL);
    const char * temp = str;
    while( *temp++ );
    return (temp - str - 1);
}
bool isRevStr(const char * str)
{
    int len = 0;
    int temp = 0;
    assert(str != NULL);
    len = strlen(str) - 1;
    while( temp != len )
    {
        if( *(str + temp++) != *(str + len--) )
        {
            return false;
        }
    }
    return true;
}

int main()
{
    isRevStr("a121a")? cout<<"yes":cout<<"no";
    cout<<endl;
}
