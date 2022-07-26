#include <stdlib.h>
#include <stdio.h>

int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen(s + 1));
}

char *_strcpy(char *dest, char *src)
{
	int i, l;

	l = _strlen(src);
	for (i = 0; i < l; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

struct User
{
	char *name;
	char *email;
	int age;
};

struct User *new_user(char *name, char *email, int age)
{
	struct User *user;

	user = malloc(sizeof(struct User));
	if (user == NULL)
		return (NULL);

	user->name = name;
	user->email = email;
	user->age = age;

	return user;
}

int main(void)
{
	struct User *user;
	char store_name[4];

	user = new_user("Foo", "foo@foo.bar", 98);
	if (user == NULL)
		return (1);
	printf("User %s created !\n", user->name);
	printf("name length: %d\n", _strlen(user->name));
	printf("name stored is: %s\n", _strcpy(store_name, user->name));
	printf("His email is: %s\n", user->email);
	printf("And he is %d years old\n", user->age);
	return (0);
}
