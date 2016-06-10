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
 //fflush(stdout);  //马上输出stdout
 }// while(1) break;
 //while(1) continue;
//continue 不能退出while（1） break才可以

}