#include<iostream>
using namespace std;

char * int_to_str(int num,  char *  str)
{
    int i = 0;
	int j = 0;
    char * p = str;
	char temp = 0;
    if(str == NULL) return NULL;
    if(num  <  0)
    {
            str[i++] = '-';
            num = -num;
			j++;
    }
    while(num != 0)
    {
            str[i++] = num % 10 + '0';
            num = num / 10;
    }
	str[i--] = '\0';
	while( j < i )
	{
		temp = str[j];
		str[j++] = str[i];
		str[i--] = temp;;
	}
    return p;
}

int str_to_int(const char * str,  bool * ok)
{
        int num = 0;
        const char * value = str;
        if( str == NULL)
            *ok = 0;
        else
             *ok = 1;
        if(*str == '-')
        {
            str++;
        }

        while( *str <= '9'&&*str >='0')
        {
            num = num * 10 + *str++  - 48;
        }
        if(*value ==  '-')
            return -num;
        return num;
}

int main(int argc, char **argv)
{
    bool ok = 0;
    char temp[10];
    int num = 10001;
    cout<< int_to_str(-454923, temp)<<endl;
    cout<<str_to_int("10005", &ok)<<endl;
}
