#include "main.h"

/**
 * _abs - computes the absolute value of a number
 * @num: The number to compute the absolute value of
 *
 * Return: The absolute value of the number
 */
int _abs(int num)
{
	if (num < 0)
	{
		return (-num);
	}
	else
	{
		return (num);
	}
}
