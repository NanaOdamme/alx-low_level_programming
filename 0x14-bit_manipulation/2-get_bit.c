#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number whose bit value to retrieve.
 * @index: The index of the bit to get (starting from 0).
 *
 * Return: The value of the bit at the
 * specified index or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
unsigned long int mask;

if (index >= sizeof(unsigned long int) * 8)
{
return (-1); /* Return -1 if the index is out of range*/
}

mask = 1UL << index;

if (n & mask)
{
return (1); /* Bit is set (1) at the given index*/
}
else
{
return (0); /* Bit is unset (0) at the given index*/
}
}
