#include "add_archive.h"

char *output_text;
int output_lenght;

char* extracting(char *archive, int archive_lenght, char *&output_text, int &out_lenght)
{
	out_lenght = 0;

	for (int i = 0; i < archive_lenght; i++)
	{
		for (int j = 0; j < table_lenght; j++)
		{
			int k = 1;
			bool flag = 0;
			while (table[j][k] != '\0')
			{
				if (archive[i + k - 1] != table[j][k])
				{
					flag = 1;
				}
				k++;
			}
			if (flag == 0)
			{
				output_text[out_lenght] = table[j][0];
				output_text[out_lenght+1] = '\0';
				out_lenght++;
				i = i + k - 2;
				break;
			}
		}
	}
	return output_text;
}