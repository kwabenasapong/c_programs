#ifndef _LIST_H_
#define  _LIST_H_

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
   struct node *next;
 };

typedef struct node_sl node_sl;
node_sl *head; 

/**
 * struct node_dl
 * @ data
 * @ next
 * @ prev
 * Description: singly list implementation
 */
 struct node_dl
 {
   int data;
   struct node *next;
   struct node *prev;
 };

typedef struct node_sl node_dl;
node_dl *head;


#endif /*  _LIST_H_ */
