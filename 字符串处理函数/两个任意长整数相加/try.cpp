#include<iostream>
#include<cassert>
#include<cstdlib>

using namespace std;

int strlen_my( const char * str )
{
    assert(str != NULL);
    const char * temp = str;
    while( *str++ );
    return (str - temp - 1);
}

char * int_add(const char * fir, const char * sec)
{
    assert(fir != NULL && sec != NULL);
    int longer = strlen_my(fir) - 1;
    int shorter = strlen_my(sec) - 1;
    const char *temp = NULL;
    if(longer < shorter)
    {
        longer ^= shorter;
        shorter ^= longer;
        longer ^= shorter;
        temp = fir;
        fir = sec;
        sec =temp;
    }
    char * res = (char *)malloc( longer + 3 );

    int k = longer + 1;
    int c = 0;
    res[k] = '\0';
    while(shorter>=0)
    {
        res[k] = (fir[longer] - 48 + sec[shorter] - 48 + c) % 10 + 48;
        c = (fir[longer] - 48 + sec[shorter] - 48 + c) /10;
        longer--;
        shorter--;
        k--;
    }
    while(longer>=0)
    {
        res[k] = (fir[longer] - 48  + c) % 10 + 48;
        c = (fir[longer] - 48 + c) /10;
        longer--;
        k--;
    }
    res[k] = c + 48;
    if(res[0] == 48)
    {
        return res + 1;
    }
    else
    {
        return res;
    }
}

int main()
{
    char num1[]= "11111111111";
    char num2[] =  "2222222222222";
  cout<<int_add(num1,num2);
}
