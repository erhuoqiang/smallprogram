#include<stdio.h>
#include<string.h>
#include<windows.h>

#define SIZE 300
char DIR[SIZE];
char BUFFER_DES[SIZE];
char inc[8];
void copy_include(char * const des)
{
	char DIR[SIZE];
	char BUFFER_DES[SIZE];
	char inc[8];
	FILE *fp_src = NULL,*fp_des = NULL;
	int pos = 0;
	char  * p_des = NULL,* p_dir = DIR;
	if( (fp_des = fopen( des, "a+")) == NULL ) 
	{
		printf(" Cann't open des_flie \n");
		exit(1);
	}
	p_des = BUFFER_DES;
	while( (*p_des++ = fgetc(fp_des)) != '#' ) 
		if(fgetc(fp_des) == EOF) 
		{
			fclose(fp_des);
			return ;
		}
			
	p_des--;
	
	fgets(inc, 8, fp_des);
	

	if(strcmp(inc,"include") == 0)
	{
		while(fgetc(fp_des) != '<');
		while((*p_dir++ = fgetc(fp_des)) != '>');
		*--p_dir = '\0';
		//printf("%s",DIR);
		if( (fp_src = fopen( DIR, "a+")) == NULL ) 
		{
			printf(" Cann't open src_flie \n");
			exit(1);
		}
		else
		{
			copy_include(DIR);
		}
		while( (*p_des++ = fgetc(fp_src)) != EOF );
		--p_des;
		while( (*p_des++ = fgetc(fp_des)) != EOF );
		*--p_des = '\0';
		fclose((fp_src,fp_des));
		if( (fp_des = fopen( des, "w+")) == NULL ) 
		{
			printf(" Cann't open des_flie \n");
			exit(1);
		}
		fprintf(fp_des,"%s",BUFFER_DES);
		fclose(fp_des);
	}
	else
	{
	//	printf("Ã»ÓÐ°üº¬INCLUDE");
	}

}


int main()
{
	copy_include("des.txt");
	return 0;
}