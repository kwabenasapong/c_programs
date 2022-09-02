#include "lists.h"

void printlist(node_sl *head)
{
	node_sl *temp;
	int count;

	temp = head;
	count = 0;
	while (temp->next != NULL)
	{
		printf("%d: %d\n", count, temp->data);
		temp = temp->next;
		count++;
	}

}

node_sl *create_node(node_sl *head, node_sl *new_node, int data)
{
	node_sl *temp = NULL;

	//head = NULL;
	//new_node = (node_sl *)malloc(sizeof(node_sl));
	new_node->data = data;

	if (head == NULL)
	{
		head = new_node;
		temp = head;
	}
	else
	{
		temp->next = new_node;
		temp = new_node;
	}
	free(new_node);
	return (head);
}


int main(void)
{
	node_sl *head = NULL, *new_node;
	int choice, data;

	new_node = (node_sl *)malloc(sizeof(node_sl));
	new_node->next = NULL;
	//new_node = 0;
	choice = 1;
	while (choice == 1)
	{
		printf("Enter the data to be store in list: \n");
		data = new_node->data;
		scanf("%d", &data);
		head = create_node(head, new_node, data);
		printf("do you want to continue (0: No | 1: Yes) ?\n");
		scanf("%d", &choice);
	}
	printlist(head);
	printf("%d\n", new_node->data);
	return (0);
}
