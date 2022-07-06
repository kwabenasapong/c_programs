#include <stdio.h>
#include <stdlib.h>

void add(int a, int b)
{
    printf("Addition is %d\n", a+b);
}
void subtract(int a, int b)
{
    printf("Subtraction is %d\n", a-b);
}
void multiply(int a, int b)
{
    printf("Multiplication is %d\n", a*b);
}

int main(int a, char **b)
{
	void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
	unsigned int ch;

	printf("Enter choice: 0 for add, 1 for subtract and "
		"2 for multiply\n");
	scanf("%d", &ch);

	if (a != 3)
	{
		printf("Error: Too manu arguments\n");
		return (1);
	}

	if (ch > 2)
		return (0);
	(*fun_ptr_arr[ch])(atoi(b[1]), atoi(b[2]));
	return (0);
}
