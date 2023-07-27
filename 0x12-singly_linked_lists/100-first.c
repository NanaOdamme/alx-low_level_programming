#include <stdio.h>

void insert_first(void) __attribute__ ((constructor));

/**
 * insert_first - prints a sentence before the main
 * function is executed
 */
void insert_first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
