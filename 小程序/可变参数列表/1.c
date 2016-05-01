
#include<stdio.h>

typedef char * va_mylist;
#define _INSIZEOF(X) ((sizeof(X) + sizeof(int) - 1 ) & ~(sizeof(int) - 1))
#define va_start(ap, v)   (ap = ((va_mylist)&v + _INSIZEOF(v)))
#define va_arg(ap, t)     (*(t *)((ap += _INSIZEOF(t)) - _INSIZEOF(t)))
#define va_end(ap)  (ap = (va_mylist)0)

void get_num( int num )
{
  int temp = num / 10;
  if(temp != 0)
	  get_num(temp);
  putchar(num % 10 + 48);
}

void My_Printf( char * string,...)
{
	char * p = NULL;
	va_mylist value; //value is char *
	va_start( value, string);
	(value = ((va_mylist)&string + _INSIZEOF(string)))
	while(*string)
	{
		switch(*string)
		{
		case '%':
			switch(*++string)
			{
				case 'c':
                putchar(va_arg(value ,  char) );
                (*(char *)((value += _INSIZEOF(char)) - _INSIZEOF(char)))
							string++;
							break;
				case's':
				    		p = va_arg(value, char * );
							while( *p )
							{
								putchar(*p++);
							}
							string++;
							break;
				case 'd':
		        			get_num(va_arg(value,  int) );
							string++;
							break;
			}
			break;
		case '/':
			switch(*++string)
			{
				case 'n':
						putchar('\n');
						string++;
						break;
			}
			break;
		default:
			putchar(*string++);
			break;
		}
	}
	va_end(value);
}

int main()
{
	char a = 'a',b = 'b';
	char c[50] = "XT UNIVERSITY";
	int i = 556;
	My_Printf(" a = %c \n b = %c \n i = %d\n %s\n",a,b,i,c);
}

