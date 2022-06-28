#include "main.h"
#include <stdlib.h>

/**
 * strdup - entry point
 * @str: char pointer
 * Return:a pointer to the array, or NULL if it fails
 */
 char *_strdup(char *str)
{
	char *s;
	unsigned int i;
	int slen;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		;
	slen = i;
	s = malloc(slen * sizeof(char));
	for (i = 0; str[i] != '\0'; i++)
	{
		s[i] = str[i];
	}
	if (s == NULL)
		return (NULL);
	free(s);
	return (s);
}
