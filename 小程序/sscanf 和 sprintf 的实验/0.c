#include<stdio.h>

void main()
{
	char temp[20] = "-2876.99812376443";
	char temp1[20];
	float b;
	sscanf(temp,"%f",&b);
	sprintf(temp1,"%f",b);
		printf("%f %s",b,temp1);
}
	