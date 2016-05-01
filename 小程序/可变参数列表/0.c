#include<stdarg.h>
#include<stdio.h>
#define aaax xxxx
typedef char asdfa;
void get_num( int num )
{
  int temp = num / 10;
  if(temp != 0)
	  get_num(temp);
  putchar(num % 10 + 48);
}
	
void my_printf( char * string,...)
{	
	char * p = NULL;	
	va_list value;
	va_start( value, string);
	while(*string)
	{
		switch(*string)
		{
		case '%':
			switch(*++string)
			{
				case 'c':
							putchar(va_arg(value,  char) );
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
				case '%':
		        			putchar( '%' );
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
				case 't': 
						putchar('\t');
						string++;
						break;
				case '/': 
						putchar('/');
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
	char c[50] = "adfafdfa";
	int i = 548;
	my_printf("%c,%c,%d %s%%///t\n",a,b,i,c);
	//my_printf("%d",312.2);
}

