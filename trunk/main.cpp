///////////////////////////////////////////////////////
//
// Create files @ main.cpp
// Author(s): pcpl2
//
//////////////////////////////////////////////////////

#include <stdio.h>

int i = 1;
int files = 0;
char *szBuffer = "Test file needed to benchmark disk" ;
char filename[25];
int bot = 0;

struct data {
	char s[4194304];
};

data ds;


void datas(void) { 
   unsigned long int is; 

   for(is = 0; is < 4194304; is++) { 

      ds.s[is] = is & 0xff; 
   } 
} 

void create_files_text(const char * file)
{

	FILE * ftest = fopen(file, "a");

	if(ftest)
	{

	fputs(szBuffer,ftest);

	fclose(ftest);
	}

}

void create_files_binary(const char * file)
{

	FILE * ftest = fopen(file, "wb");

	if(ftest)
	{

	fwrite(&ds , sizeof(char), sizeof(ds.s), ftest);

	fclose(ftest);
	}
}

int main()
{
	datas();

	printf("Binary file [1] or Text file [2] \n");
	scanf("%d", &bot); 

	switch( bot )
	{
	case 1:
		printf("Files: \n");
		scanf("%d", &files);

		while(i <= files)
		{

			sprintf(filename, "file-%d", i);
			create_files_binary(filename);

		 i++;
		}
	 break;
    
	case 2:
		printf("Files: \n");
		scanf("%d", &files);

		while(i <= files)
		{

			sprintf(filename, "file-%d.txt", i);
			create_files_text(filename);

		 i++;
		}
	 break;
    
	default:
	    break;
	}

	return 0;
}