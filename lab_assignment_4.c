#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	node * current = head;
	int nodeNum = 0;
	if(head == NULL){
		return NULL;
	}

	while(current->next != NULL){
		current = current -> next;
		nodeNum++;
	}
	return nodeNum;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	node* current = head;
	int len = length(head);

	if (head == NULL) {
		return NULL;
	}
	
	char* result = (char*)malloc(sizeof(len + 1));
	current = head;

    int i;
	
		for (i=0 ; i < len; i++) {
			result[i] = current->letter;
			current = current->next;

		}
		result[i] = '\0';
	return result;
}


// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* current = *pHead;
	
	node* newNode = malloc(sizeof(node));
	newNode->letter = c;
	newNode->next = NULL;
	if(*pHead==NULL){
	    *pHead=newNode;
	}
	else{
	 //create a node   
		while(current->next!=NULL){
			current = current->next;
		}
    	current->next = newNode;
    }
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node * current = *pHead;
	node* next = NULL;

	while(current != NULL){
		next = current ->next;
		free(current);
		current = next;
	}
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("/Users/gabrielhernandez/Desktop/CS1/input.txt","r");//remove the path in order to compile the program

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}