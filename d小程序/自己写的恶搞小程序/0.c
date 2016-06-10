#include<stdio.h>
#include<string.h>

char name[10] = "xxx.txt";
char address[100] = "C:\\Users\\Administrator\\Desktop\\";
//name[3] = '2'; name[4] = '.'; name[5] = 't'; name[6] = 'x'; name[7] = 't'; name[8] = 0;

int main()
{
	FILE *fp = NULL;
	int i = 0, j = 0, k = 0;	
	for(i = 48 ; i < 52; i++)
	{
		name[0] = i;
		for(j = 48 ; j < 52; j++)
		{
			name[1] = j;
			for(k = 48 ; k < 49; k++)
			{
				name[2] = k;
				strcpy(address, "C:\\Users\\Administrator\\Desktop\\");
				strcat(address, name);
				if((fp=fopen(address,"w+"))!=NULL)
				 {
					  fprintf(fp,"ÄãÊÇÖí ÄãÊÇÖí ÄãÊÇÖí ÄãÊÇÖí \nÄãÊÇÖí ÄãÊÇÖí ÄãÊÇÖí ");
					  fclose(fp);
				 }
					 
			}
		}
	}
//	while(1);
}

 
