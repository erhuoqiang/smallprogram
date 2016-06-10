#include<stdio.h>
#include<string.h>

int main()
{
	int i, abc, de, x, y, z, count = 0, ok;
	char s[20], buf[99];
A: count = 0;
	scanf("%s", s);
	for( abc = 111; abc <= 999; abc++)
		for( de = 11; de <= 99; de++)
		{
			x = abc*(de%10);
			y = abc*(de/10);
			z = abc*de;
			sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);
			ok = 1;
			for( i = 0; i < strlen(buf) ; i++) //sizeof 是总长度 strlen 是有效长度
				if( strchr(s, buf[i]) == NULL )
				{	
					ok = 0; 
				}
			if(ok)
			{
				printf("<%d>\n", ++count);
				printf("%5d\nX%4d\n-----\n%5d\n%4d\n----\n%5d\n\n", abc, de, x, y, z);
			}
		}

			printf("%d\n", count);
		goto A;
}