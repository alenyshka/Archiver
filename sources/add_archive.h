#include "tree.h"

tree_element *root;
char* input_text;
int text_lenght;

char enter_text(char *&input_text, int text_lenght)
{
	FILE *f;
	if (!(f = fopen("input.txt", "a")))
		return 0;
	printf("\nEnter the text:");
	fflush(stdin);
	gets(input_text);
	fprintf(f, "%s", input_text);
	return *input_text;
}

tree_element create_queue(tree_element *&root, char *&input_text, int text_lenght)
{
	for (int i = 0; input_text[i]!='\0'; i++)
	{
		add_in_queue(root, input_text[i]);
	}
	return *root;
}