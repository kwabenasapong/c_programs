#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/* Declarations */
void print_char(va_list);
void print_int(va_list);
void print_float(va_list);
void print_string(va_list);

/**
 * print_all - main function
 * @format: restricts format passed to function
 *
 * Description: prints all variables char, int
 * float and strings.
 */

void print_all(const char * const format, ...)
{
	va_list arg;
	int i, j;
	char *sep = "";
	get_type var[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string}
	};

	va_start(arg, format);

	for (i = 0; format && (*(format + i)); i++)
	{
		for (j = 0; (j < 4 && (*(format + i)) != *(var[j].type_defn)); j++)
			;

		if (j < 4)
		{
			printf("%s", sep);
			var[j].print(arg);
			sep = ", ";
		}
	}
	printf("\n");

	va_end(arg);
}

/**
 * print_char - print all char variable types
 * @arg: pass char variable
 */
void print_char(va_list arg)
{
	printf("%c", va_arg(arg, int));
}

/**
 * print_int -print all int variable types
 * @arg: pass int variable
 */
void print_int(va_list arg)
{
	printf("%d", va_arg(arg, int));
}

/**
 * print_float - print all float variables
 * @arg: pass float variable
 */
void print_float(va_list arg)
{
	printf("%f", va_arg(arg, double));
}

/**
 * print_string - print all string variables
 * @arg: pass string variable
 */
void print_string(va_list arg)
{
	char *str;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		printf("nil");
		return;
	}

	printf("%s", str);
}

