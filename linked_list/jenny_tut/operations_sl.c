#include "lists.h"

void printlist(node_sl *head)
{
	node_sl *temp;
	int count;

	temp = head;
		count = 0;
		while (temp->next || temp->data)
		{
			printf("%d: %d\n", count, temp->data);
			temp = temp->next;
			count++;
		}
	}

	node_sl *create_node(node_sl *head)
{
	node_sl *temp, *new_node;
	int choice = 1;

	//head = 0;
	while (choice == 1)
	{
	new_node = (node_sl *)malloc(sizeof(node_sl));

	printf("Enter the data: ");
	scanf("%d", &new_node->data);

	new_node->next = NULL;

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

	printf("Do you want to continue (0: No, 1: Yes) ? ");
	scanf("%d", &choice);
	}
	return (head);
}


int main(void)
{
	node_sl *head;

	head = 0;
	head = create_node(head);
	printlist(head);
	return (0);
}
