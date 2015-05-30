#include "tree.h"

tree_element *root;
char* input_text;
int text_lenght;

char memory_add(char *&input_text, int &text_lenght)
{
	printf("\nEnter text lenght:");
	scanf_s("%d", &text_lenght);
	printf("\n");
	input_text = (char*)malloc(text_lenght*sizeof(char));
	return *input_text;
}

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

char recursion(tree_element *&temp, char **&table, int &table_lenght, char *str,int j) {
	if (temp->symbol != '\0') {
		table[table_lenght][0] = temp->symbol;
		int k = 0;
		while (str[k] != '\0') {
			table[table_lenght][k + 1] = str[k];
			k++;
		}
		table[table_lenght][k + 2] = '\0';
		table_lenght++;
	}
	if (temp->left != NULL) {
		str[j] = '0';
		str[j + 1] = '\0';
		recursion(temp->left, table, table_lenght, str, j+1);
	}
	if (temp->right!= NULL) {
		str[j] = '1';
		str[j + 1] = '\0';
		recursion(temp->right, table, table_lenght, str, j+1);
	}
	return **table;
}

tree_element create_table(tree_element *&root,char **&table,int &table_lenght)
{
	tree_element *temp;
	temp = root;
	table_lenght=0;
	char* str;
	str = (char*)calloc(15, sizeof(char));
	int j = 0;
	recursion(temp, table, table_lenght, str, j);
	return *root;
}