#include <stdio.h>
#include <stdlib.h>

/**
 * struct node_sl
 * @ data
 * @ next
 * Description: singly list implementation
 */
 struct node_sl
 {
   int data;
   struct node_sl *next;
 };

typedef struct node_sl node_sl;
//node_sl *head;


int main()
{
  node_sl *head;
  node_sl *new_node, *temp;
  int choice, count;

  //head = (node_sl *)malloc(sizeof(node_sl));
  //temp = (node_sl *)malloc(sizeof(node_sl));
  head = NULL;
  choice = 1;

  while (choice == 1)
  {
    new_node = (node_sl*)malloc(sizeof(node_sl));

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
  temp = head;
  count = 0;
  while (temp != NULL)
  {
    printf("%d: %d\n", count, temp->data);
    temp = temp->next;
    count++;
  }
  return 0;
}
