#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodePtr;

struct node
{
	int data;
	nodePtr next;
};
typedef struct node node;

int main(int argc, const char **argv)
{
	nodePtr first = NULL;

	first = malloc(sizeof(node));
	first->next = NULL;
	first->data = 61;

	first->next = malloc(sizeof(node));
	(first->next)->next = NULL;
	(first->next)->data = 62;

	nodePtr temp = malloc(sizeof(node));
	temp->next = first;
	first =  temp;
	printf("Hello, Ghana\n");
}
