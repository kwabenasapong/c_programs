#include <stdarg.h>

/**
 * print_numbers - entry point
 *
 * @separator: constant char
 * @n: constant unsigned integer variable
 * @...: variable number of args
 *
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	
	va_list args;
	unsigned int j, add_all;

	if (n == 0)
		return (0);
	va_start (args, n);

	add_all = 0;
	for (j = 0; j < n; j++)
		printf("%d", va_arg(args, int));
		if (args == NULL)
			printf("%c", separator);

	printf("\n");

	va_end (args);
	return (add_all);
	
}
