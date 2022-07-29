#include <stdio.h>

/**
 * main - program prints items in av
 * @ac: the number of items in av
 * @av: a NULL terminated array of strings
 * Return: 0 always (success)
 */
int main(int ac, char **av)
{
	int i = 0;

	while (i < ac)
	{
		printf("%s\n", av[i]);
		i++;
	}
	*av[i] = '\0';
	printf("%d\n", ac);
	return (0);
}
