#include <stdio.h>

/**
 * Tutorial programme
 * to understand structures in c
 */

struct User
{
	char *name;
	char *email;
	int age;
};

int main(void)
{
	struct User user;
	struct User user1;
	struct User *ptr;

	ptr = &user1;
	/* Dereferencing the pointer before access
	 * of the data with '.' symbol */

	(*ptr).name = "Kwabena Sapong";
	/* Using the '->' works the same, and is so 
	 * much easier */
	ptr->email = "kwabenasapong@gmail.com";

	user.name = "Foo Bar";
	user.email = "foo@hbtn.io";
	user.age = 98;
	return (0);
}
