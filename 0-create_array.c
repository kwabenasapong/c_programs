#include "main.h"
#include <stdlib.h>

/**
 * create_array - entry point
 * @size: unsigned integer
 * @c: char
 * Return:a pointer to the array, or NULL if it fails
 */
 char *create_array(unsigned int size, char c)
{
	char *ar;
	unsigned int i;

	if (size == 0)
		return (NULL);
	ar = malloc(size * sizeof(char));
	if (ar == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		ar[i] = c;
	}
	return (ar);
}
