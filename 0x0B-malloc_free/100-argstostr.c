#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all command-line arguments into a single string
 * @ac: number of command-line arguments
 * @av: array of command-line arguments
 *
 * Return: pointer to the concatenated string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	int ind, K, rnd = 0, length = 0;
	char *string;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (ind = 0; ind < ac; ind++)
	{
		K = 0;
		while (av[ind][K])
		{
			length++;
			K++;
		}
	}
		length += ac;

	string = malloc(sizeof(char) * (length + 1));
	if (string == NULL)
		return (NULL);

	ind = 0;
	while (ind < ac)
	{
		K = 0;
		while (av[ind][K])
		{
			string[rnd] = av[ind][K];
			rnd++;
			K++;
		}
		if (string[rnd] == '\0')
		{
			string[rnd++] = '\n';
		}
		ind++;
	}

	return (string);
}
