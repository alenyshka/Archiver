#include "tree.h"

tree_element *root;
char* input_text;
int text_lenght;

tree_element create_queue(tree_element *&root, char *&input_text, int text_lenght)
{
	for (int i = 0; input_text[i]!='\0'; i++)
	{
		add_in_queue(root, input_text[i]);
	}
	return *root;
}