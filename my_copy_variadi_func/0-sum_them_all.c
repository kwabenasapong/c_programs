#include <stdarg.h>

/**
 * sum_them_all - entry point
 * @n: constant unsigned integer variable
 *
 * Return: integer
 */
int sum_them_all(const unsigned int n, ...)
{
	
	va_list args;
	unsigned int j, add_all;

	if (n == 0)
		return (0);
	va_start (args, n);

	add_all = 0;
	for (j = 0; j < n; j++)
		add_all += va_arg(args, int);

	va_end (args);
	return (add_all);
	
}
