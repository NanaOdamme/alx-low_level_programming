#include <stdlib.h>
#include "dog.h"

/**
 * _strcpy - Copies the string pointed to by src to dest
 * @dest: Pointer to the destination buffer
 * @src: Pointer to the source string
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strlen - Returns the length of a string
 * @s: Pointer to the string
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog, else  NULl
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new;
	int l1, l2;

	l1 = _strlen(name);
	l2 = _strlen(owner);

	new = malloc(sizeof(dog_t));
	if (new == NULL)
		return (NULL);

	new->name = malloc(sizeof(char) * (l1 + 1));
	if (new->name == NULL)
	{
		free(new);
		return (NULL);
	}
	new->owner = malloc(sizeof(char) * (l2 + 1));
	if (new->owner == NULL)
	{
		free(new);
		free(new->name);
		return (NULL);
	}
	_strcpy(new->name, name);
	_strcpy(new->owner, owner);
	new->age = age;

	return (new);
}
