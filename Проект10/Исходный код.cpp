#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
void Enter_Data(FILE*);
int main(int)
{
	FILE*first_file, *compressed_file;
	if (!(first_file = fopen("first_file.txt", "r+")) || !(compressed_file = fopen("compressed_file.txt", "r+")))
	{
		printf("File cannot be created\n"); _getch();
		return 1;
	}

	Enter_Data(first_file);
	
	fclose(first_file);
	fclose(compressed_file);
	_getch();
}

void Enter_Data(FILE* first_file)
{
	char STR[100];
	do
	{
		printf("Enter string; Empty string is exit program\n");
		gets(STR);
		if (*STR = '\0') break;
		strcat(STR, "\n");
		fputs(STR, first_file);
	} while (*STR != '\n');
}