#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 255

struct queue
{
	struct queue *leftPtr;
	struct queue *rightPtr;
	struct queue *nextPtr;
	char symbol;
	char code[MAX_PATH];
	long int frequency;
};

union code
{
	unsigned char ch;
	struct byte
	{
		unsigned bite1 : 1;
		unsigned bite2 : 1;
		unsigned bite3 : 1;
		unsigned bite4 : 1;
		unsigned bite5 : 1;
		unsigned bite6 : 1;
		unsigned bite7 : 1;
		unsigned bite8 : 1;
	} byte;
};


int queueEnqueue(struct queue *q, char textSymbol);
void queueSort(struct queue *q, struct queue *headPtr);
int isEmpty(struct queue *headPtr);
void clearInputBuffer();
void openFile(char *fileName, FILE **sourceFile);
void warningFunction(char c);
void makeCodes(struct queue *root);
queue *makeTree(struct queue *mtQueue[], int k);

int main()
{
	struct queue *q;
	char fileName[MAX_PATH];
	FILE *sourceFile, *tempFile, *finalFile;
	openFile(fileName, &sourceFile);
	while (!getchar());
	return 0;
}

//Добавление элемента в очередь
int queueEnqueue(struct queue *q, char textSymbol)
{
	struct queue *headPtr;
	struct queue *temporary;
	headPtr = q;
	if (!q)
	{
		q = (struct queue *)malloc(1 * sizeof(struct queue));
		q->symbol = textSymbol;
		return 0;
	}
	while (q != NULL)
	{
		if (q->symbol == textSymbol)
		{
			q->frequency++;
			return 0;
		}
		q = q->nextPtr;
	}
	temporary = (struct queue *)malloc(1 * sizeof(struct queue));
	q = temporary;
	q->symbol = textSymbol;
	q = headPtr;
	return 0;
}

//Проверка на пустоту очереди 
int isEmpty(struct queue *headPtr)
{
	return headPtr == NULL;
}

//Функция сортировки очереди
void queueSort(struct queue *tail)
{
	system("cls");
	char swapStr[MAX_PATH];
	struct queue *temp = NULL;
	for (; tail; tail = tail->nextPtr)
	{
		if (strcmp(tail->code, tail->nextPtr->code) > 0)
		{
			strcpy(swapStr, tail->code);
			strcpy(tail->code, tail->nextPtr->code);
			strcpy(tail->nextPtr->code, swapStr);
		}
	}
}

void openFile(char *fileName, FILE **sourceFile)
{
	// доделать
	printf("Enter name of file - ");
	scanf_s("%s", fileName);
	clearInputBuffer();
	*sourceFile = fopen(fileName, "r");
	while (!sourceFile);
	if (sourceFile == NULL)
	{
		warningFunction('f');
		warningFunction('e');
		while (!getchar());
		exit(0);
	}
	else
	{
		printf("\nFile %s open successfully!\n", fileName);
	}
}
//Создание дерева Хаффмана
queue *makeTree(struct queue *mtQueue[], int k)
{
	int i, j;
	struct queue *temp;
	temp = (struct queue *)malloc(sizeof(struct queue));
	temp->frequency = mtQueue[k - 1]->frequency + mtQueue[k - 2]->frequency;
	temp->code[0] = 0;
	temp->leftPtr = mtQueue[k - 1];
	temp->rightPtr = mtQueue[k - 2];
	if (k == 2)
	{
		return temp;
	}/*				 циклы в рекурсии ?!
	 else
	 {
	 for (i = 0; i < k; i++)
	 {
	 if (temp->frequency > mtQueue[i]->frequency)
	 {
	 for (j = k; j > i; j--)
	 {
	 mtQueue[j] = mtQueue [j - 1];
	 }
	 mtQueue[i] = temp;
	 break;
	 }
	 }
	 }*/
	return makeTree(mtQueue, k - 1);
}

void makeCodes(struct queue *root)
{
	if (root->leftPtr)
	{
		strcpy(root->leftPtr->code, root->code);
		strcat(root->leftPtr->code, "0");
		return makeCodes(root->leftPtr);
	}
	if (root->rightPtr)
	{
		strcpy(root->rightPtr->code, root->code);
		strcat(root->rightPtr->code, "1");
		return makeCodes(root->rightPtr);
	}
}


void warningFunction(char c)
{
	switch (c)
	{
	case 'a':
		printf("\nFatal error! Something wrong with memory allocation. ");
		printf("Please reboot the programm.");
		while (!getchar());
		exit(0);
		break;
	case 'b':
		printf("Incorrect input. Write only digits: ");
		break;
	case 'd':
		printf("Incorrect input. Write only letters or top register: ");
		break;
	case 'e':
		printf("\nPress any key to continue . . . \n");
		break;
	case 'f':
		printf("File not found!");
		printf("\nThe specified file isn't present in an initial directory");
		printf("\nWrite name of file again:");
		break;
	}
}