#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct tree_element
{
	tree_element *next=NULL;
	tree_element *previous=NULL;

	tree_element *left=NULL;
	tree_element *right=NULL;

	char symbol=NULL;
	int frequency=0;
};

tree_element sorting_queue(tree_element *&root)
{
	tree_element *temp;
	temp = root;
	int mas[1024];
	int i = 0;

	while (temp != NULL)
	{
		mas[i] = temp->frequency;
		temp = temp->next;
		i++;
	}
	
	for (int j = 1; j < i; j++)
	{
		int tmp = mas[j];
		for (int k = j - 1; k >= 0;k--)
		{
			if (mas[k] < tmp) { break; }

			mas[k + 1] = mas[k];
			mas[k] = tmp;
		}
	}
	temp = root;

	tree_element *temp_2=NULL;

	for (int j = 0; j < i; j++)
	{
		int l = 0;
		while (l != j)
		{
			temp = temp->next;
			l++;
		}

		while (temp->frequency!=mas[j])
		{
			temp=temp->next;
		}

		int k = 0;
		
		temp_2 = root;
		while (k != j)
		{
			temp_2 = temp_2->next;
			k++;
		}

		char swap;
		int swap_;

		swap = temp->symbol;
		swap_ = temp->frequency;

		temp->frequency = temp_2->frequency;
		temp->symbol = temp_2->symbol;

		temp_2->frequency = swap_;
		temp_2->symbol = swap;
		
		temp = root;
	}
	
	return *root;
}