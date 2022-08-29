#include <stdio.h>
#include <stdlib.h>


/**
 * struct node - linked list
 * @data: int type
 * @next: pointer
 */
struct Node
{
	int data;
	struct Node* next;
};


/**
 * printList - prints content of list
 * @n: passed struct Node*
 */
size_t printList(struct Node* n)
{
	unsigned int i = 0;
	for (n; n != NULL; n = n->next, i++)
	{
		printf("[%d] %d ", i, n->data);
	//	n = n->next;
	}
	return (i);
}



/**
 * main - entry point
 * return: 0 always
 */
int main()
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	struct Node* fourth = NULL;

	head = (struct Node*) malloc(sizeof(struct Node));
	second= (struct Node*) malloc(sizeof(struct Node));
	third = (struct Node*) malloc(sizeof(struct Node));
	fourth = (struct Node*) malloc(sizeof(struct Node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = fourth;

	fourth->data = 4;
	fourth->next = NULL;

	printList(head);

	return (0);
}
