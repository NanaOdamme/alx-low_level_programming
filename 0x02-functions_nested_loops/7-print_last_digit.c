#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @num: the int to extract the last digit from
 * Return: lastDigit
 */
int print_last_digit(int num)
{
	int lastDigit;

	if (num < 0)
	num = -num;

	lastDigit = num % 10;

	if (lastDigit < 0)
		lastDigit = -lastDigit;

	_putchar(lastDigit + '0');

	return (lastDigit);
}
