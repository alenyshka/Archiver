#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 255

struct Queue
{
	struct Queue *left_ptr;
	struct Queue *right_ptr;
	struct Queue *next_ptr;
	char symbol;
	char code[MAX_PATH];
	long int frequency;
};

union Code
{
	unsigned char ch;
	struct byte
	{
		unsigned bite1:1;
		unsigned bite2:1;
		unsigned bite3:1;
		unsigned bite4:1;
		unsigned bite5:1;
		unsigned bite6:1;
		unsigned bite7:1;
		unsigned bite8:1;
	} byte;
};

int QueueEnqueue(struct Queue *q, char text_symbol);
int QueueCounting(struct Queue **tail_ptr, struct Queue **head_ptr);
int IsEmpty(struct Queue *headPtr);

void QueueSort(struct Queue *q, struct Queue *headPtr);
void ClearInputBuffer();
void OpenFile(char *fileName, FILE **sourceFile);
void WarningFunction(char c);
void MakeCodes(struct Queue *root);

Queue *MakeTree(struct Queue *mtQueue[], int k);

int main() {
	struct queue *q;
	char file_name[MAX_PATH];
	FILE *source_file, *temp_file, *final_file;
	OpenFile(file_name, &source_file);
	while(!getchar());
	return 0;
}

//Добавление элемента в очередь
int QueueEnqueue(struct Queue *q, char text_symbol) {
	struct Queue *head_ptr;
	struct Queue *temporary;
	head_ptr = q;
	if(!q) {
		q = (struct Queue *)malloc(1*sizeof(struct Queue));
		q->symbol = text_symbol;
		return 0;
	}
	while (q != NULL) {
		if (q->symbol == text_symbol) {
			q->frequency++;
			return 0;
		}
		q = q->next_ptr;
	}
	temporary = (struct Queue *)malloc(1 * sizeof(struct Queue));
	q = temporary;
	q->symbol = text_symbol;
	q = head_ptr;
	return 0;
}

//Проверка на пустоту очереди 
int IsEmpty(struct Queue *head_ptr) {
	return head_ptr == NULL;
}

//Функция сортировки очереди
void queueSort(struct Queue *q, struct Queue *head_ptr)
{
	/*
			    ЗДЕСЬ 
				МОГЛА 
				 БЫТЬ 
			   ФУНКЦИЯ 
		      СОРТИРОКИ
		       ОЧЕРЕДИ
	*/
}
/*
void sort(struct Queue *head_ptr) {
	struct Queue *c, *subptr=this;
	while(current->next!=NULL){
			subptr=this;
			while(subptr->next!=NULL){
				if((subptr->freq) > (subptr->next->freq))
					this->swap(subptr);
				subptr=subptr->next;
			}
			current=current->next;
		}	
	}
	*/
void OpenFile(char *file_name, FILE **source_file) {
	// доделать
	printf("Enter name of file - ");
	scanf("%s", file_name);
	ClearInputBuffer();
	*source_file = fopen( file_name, "r");
	while (!source_file);
	if (source_file == NULL) {
		WarningFunction('f');
		WarningFunction('e');
		while(!getchar());
		exit(0);
	} else {
		printf("\nFile %s open successfully!\n", file_name);
	}
}
//Создание дерева Хаффмана
Queue *MakeTree(struct queue *q, int k)
{
	int i, j;
	struct Queue *temp;
	temp = (struct Queue *)malloc(sizeof(struct Queue));
	temp->frequency = q->frequency + q->frequency;
	temp->code[0] = 0;
	temp->left_ptr = mtQueue[k-1];
	temp->right_ptr = mtQueue[k-2];
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
	return MakeTree(mtQueue, k - 1);
}

int QueueCounting(struct Queue **tail_ptr, struct Queue **head_ptr) {
	int i;
	struct Queue *temp_tail = *tail_ptr;
	while (temp_tail->next_ptr != *head_ptr) { 
		i++;
	}
	return i;
}

void makeCodes(struct Queue *root) {
	if(root->left_ptr) {
		strcpy(root->left_ptr->code, root->code);
		strcat(root->left_ptr->code, "0");
		return makeCodes(root->left_ptr);
	}
	if(root->right_ptr) {
		strcpy(root->right_ptr->code, root->code);
		strcat(root->right_ptr->code, "1");
		return makeCodes(root->right_ptr);
	}
}


void WarningFunction(char c) {
	switch(c) {
		case 'a': {
			printf("\nFatal error! Something wrong with memory allocation. ");
			printf("Please reboot the programm.");
			while (!getchar());
			exit(0);
			break;
			}
		case 'b': {
			printf("Incorrect input. Write only digits: ");
			break;
			}
		case 'd': {
			printf("Incorrect input. Write only letters or top register: ");
			break;
			}
		case 'e': {
			printf("\nPress any key to continue . . . \n");
			break;
			}
		case 'f': {
			printf("File not found!");
			printf("\nThe specified file isn't present in an initial directory");
			printf("\nWrite name of file again:");
			break;
			}
	}
}

int QueueLength() {
		struct Queue *current;
		int i = 1;
		while(current->next_ptr != NULL) {
			i++;
			current = current->next_ptr;
		}
		return i;
}

/*

Make tree
int MakeTree(CHuffmanNode nodes[], bool bSetCodes = true)
{
	CHuffmanNode* pNodes[256], *pNode;
	// add used ascii to Huffman queue
	int nNodeCount = 0;
	for(int nCount = 0; nCount < 256 && nodes[nCount].nFrequency; nCount++)
		pNodes[nNodeCount++] = &nodes[nCount];
	int nParentNode = nNodeCount, nBackNode = nNodeCount-1;
	while(nBackNode > 0)
	{
		// parent node
		pNode = &nodes[nParentNode++];
		// pop first child
		pNode->pLeft = PopNode(pNodes, nBackNode--, false);
		// pop second child
		pNode->pRight = PopNode(pNodes, nBackNode--, true);
		// adjust parent of the two poped nodes
		pNode->pLeft->pParent = pNode->pRight->pParent = pNode;
		// adjust parent frequency
		pNode->nFrequency = pNode->pLeft->nFrequency + pNode->pRight->nFrequency;
		// insert parent node depending on its frequency
		for(int i = nBackNode; i >= 0; i--)
			if(pNodes[i]->nFrequency >= pNode->nFrequency)
				break;
		memmove(pNodes+i+2, pNodes+i+1, (nBackNode-i)*sizeof(int));
		pNodes[i+1] = pNode;
		nBackNode++;
	}
	// set tree leaves nodes code
	if(bSetCodes)
		for(nCount = 0; nCount < nNodeCount; nCount++)
			SetNodeCode(&nodes[nCount]);

	return nNodeCount;
}
*/