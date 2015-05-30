#include"extracting.h"

int main()
{
	table= (char**)calloc(1024, sizeof(char*));
	for (int i = 0; i < 1024; i++)
	{
		table[i] = (char*)calloc(10, sizeof(char));
	}
	
	archive = (char*)calloc(archive_lenght, sizeof(char));

	output_text = (char*)calloc(1024, sizeof(char));



	memory_add(input_text, text_lenght);
	enter_text(input_text, text_lenght);
	create_queue(root, input_text, text_lenght);
	sorting_queue(root);
	create_tree(root);
	create_table(root, table, table_lenght);
	archiving(input_text, text_lenght, archive, archive_lenght, table, table_lenght);
	
	printf("\n\nARCHIVE:");
	for (int i = 0; i < archive_lenght; i++) { printf("%c", archive[i]); }
	printf("\n\n");
	system("pause");

	extracting(archive, archive_lenght, output_text, output_lenght);
	printf("\n\nOutput_text:");
	for (int i = 0; i < output_lenght; i++) { printf("%c", output_text[i]); }
	printf("\n\n");
	system("pause");
	return 0;

}