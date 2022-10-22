#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{

	unsigned char buffer[100];
	
	FILE *ptr;
	ptr = fopen("MainDriver.o","rb"); 	
	fread(buffer,sizeof(buffer),1,ptr); // read 10 bytes to buffer

	int isELF = 0, isEXE = 0, isRel = 0; 
    
	//printf("--> %x",buffer[1]);
	if(buffer[0] == 0x7f)
	{
		if(buffer[1] == 0x45)
		{
			if(buffer[2] == 0x4c)
			{
				isELF = 1;
				if(buffer[16] == 0x01)
					isRel = 1; //Relocatable file. 
				else if(buffer[16] == 0x02)
					isEXE = 1;
			}
		}
	}

	if(isELF)
	{
		printf("\n\nThe File is Elf ");
		if(isRel)
			printf("with File Type Relocatable. ");
		else if(isEXE)
			printf("with File Type Executable. ");
		else
			printf("with File Type Something else");
		printf("\n\n");
	}	


	system("readelf -h  MainDriver.o");

	// printf("%x %d\n", buffer[16], strlen(buffer));

	// int i = strcmp(buffer," ELF   ");

	// printf("\n--> %d\n", i);
	//system("hexdump -C MainDriver.o | head ");

	// printf("%s",a);

	// FILE *file;
  
	// char data[50];
  
	// file = fopen("MainDriver.o", "b"); 
  
	// if (file == NULL)
	// {
	// 	printf("Error opening file.\n");
  	// }
	
	// fgets ( data, 50, file );
	
	// printf("%s", data);
	
	
	// //ReadFile("MainDrive.c");
	// return 0;
}



/*
int main(void)
{
	FILE *file;
  
	char data[50];
  
	file = fopen("MainDrive.c", "rb"); 
  
	if (file == NULL)
	{
		printf("Error opening file.\n");
  	}
	
	fgets ( data, 50, file );
	
	printf("%s", data);
	
	
	ReadFile("MainDrive.c");
	return 0;
}

void ReadFile(char *name)
{
	FILE *file;
	char *buffer;
	unsigned long fileLen;

	//Open file
	file = fopen(name, "rb");
	if (!file)
	{
		fprintf(stderr, "Unable to open file %s", name);
		return;
	}
	
	//Get file length
	fseek(file, 0, SEEK_END);
	fileLen=ftell(file);
	fseek(file, 0, SEEK_SET);

	//Allocate memory
	buffer=(char *)malloc(fileLen+1);
	if (!buffer)
	{
		fprintf(stderr, "Memory error!");
                                fclose(file);
		return;
	}

	//Read file contents into buffer
	fread(buffer, fileLen, 1, file);
	fclose(file);

	//Do what ever with buffer

	free(buffer);
}

*/