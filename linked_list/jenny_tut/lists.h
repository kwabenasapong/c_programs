#ifndef _LISTS_H_
#define _LISTS_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct node_sl
{
	int data;
	struct node_sl *next;
}node_sl;


typedef struct node_dl
{
	int data;
	struct node_dl *next;
	struct node_dl *prev;
}node_dl;


#endif /* _LIST_H_ */
