#include<stdio.h>
#define BUFSIZ  50
main()
 {
 int c;
static char buf[BUFSIZ];
 setbuf(stdout, buf);
 while((c = getchar()) != EOF)
 { 
	 putchar(c);
	 printf("%s",buf);
 //fflush(stdout);  //�������stdout
 }// while(1) break;
 //while(1) continue;
//continue �����˳�while��1�� break�ſ���

}