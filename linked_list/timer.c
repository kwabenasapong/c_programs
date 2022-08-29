#include <stdio.h>

/**
 * struct my_time - holds time elements
 * @hours: hour elements
 * @minutes: min.elements
 * @seconds: s elements
 */
struct my_time
{
	int hours;
	int minutes;
	int seconds;
};

void display(struct my_time *t);
void update(struct my_time *t);
void delay(void);

void main(void)
{
	struct my_time systime;

	systime.hours = 0;
	systime.minutes = 0;
	systime.seconds = 0;

	for (;;)
	{
		update(&systime);
		display(&systime);
	}
}

void update(struct my_time *t)
{
	t->seconds++;
	if (t->seconds == 60)
	{
		t->seconds = 0;
		t->minutes++;
	}
	if (t->minutes == 60)
	{
		t->minutes = 0;
		t->hours++;
	}
	if (t->hours == 24)
		t->hours = 0;
	delay();
}

void display(struct my_time *t)
{
	printf("%0d:", t->hours);
	printf("%0d:", t->minutes);
	printf("%0d\n", t->seconds);
}

void delay(void)
{
	long int t;
	for (t = 1; t < 128000;++t)
		;
}
