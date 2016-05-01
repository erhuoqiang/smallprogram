#include<stdio.h>
#include<windows.h>
int main()
{	
	char z[]="asfafdfa\n";
	char a[]="    asdfa\n";
	char b[]="     daf\n";
	char c[]="     adsf\n";
	char d[]="     a\n";
	char e[]="     a\n";
	char f[]="     a\n";
	char g[]="     dd\n";
	char h[]="     ad\n";
	char k[]="             asd\n";
	char j[]="                                 dasf\n  ";

	int i;
		for(i=0;i<strlen(z);i++)
	{
		Sleep(80);
		printf("%c",z[i]);
	}
     	for(i=0;i<strlen(a);i++)
	{
		Sleep(115);
		printf("%c",a[i]);
	}
		for(i=0;i<strlen(b);i++)
	{
		Sleep(115);
		printf("%c",b[i]);
	}
		for(i=0;i<strlen(c);i++)
	{
		Sleep(115);
		printf("%c",c[i]);
	}

		for(i=0;i<strlen(d);i++)
	{
		Sleep(115);
		printf("%c",d[i]);
	}

		for(i=0;i<strlen(e);i++)
	{
		Sleep(115);
		printf("%c",e[i]);
	}

		for(i=0;i<strlen(f);i++)
	{
		Sleep(115);
		printf("%c",f[i]);
	}
		 for(i=0;i<strlen(g);i++)
	{
		Sleep(115);
		printf("%c",g[i]);
	}
		  for(i=0;i<strlen(h);i++)
	{
		Sleep(115);
		printf("%c",h[i]);
	}

	    for(i=0;i<strlen(k);i++)
	{
		Sleep(115);
		printf("%c",k[i]);
	}
		for(i=0;i<strlen(j);i++)
	{
		Sleep(115);
		printf("%c",j[i]);
	}


while(1);

}