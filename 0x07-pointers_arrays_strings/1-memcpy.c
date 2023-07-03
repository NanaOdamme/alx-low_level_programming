#include "main.h"

/**
 * _memcpy - Copies a memory area from source to destination.
 * @dest: Pointer to the destination memory area.
 * @src: Pointer to the source memory area.
 * @n: Number of bytes to be copied.
 *
 * Return: Pointer to the destination memory area.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	for (unsigned int a = 0; a < n; a++)
	{
		dest[a] = src[a];
	}
	return (dest);
}
