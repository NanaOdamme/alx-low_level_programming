#include <stdlib.h>
#include "main.h"

/**
 * num_of-words - helper function to count the number of words in a string
 * @string: string to evaluate
 *
 * Return: number of words
 */
int num_of_words(char *string)
{
	int flag, count, w;

	flag = 0;
	w = 0;

	for (count = 0; string[count] != '\0'; count++)
	{
		if (string[count] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return (w);
}
/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **M, *tp;
	int ind, J = 0, len = 0, word, count = 0, begin, finish;

	while (*(str + len))
		len++;
	word = num_of_words(str);
	if (word == 0)
		return (NULL);

	M = (char **) malloc(sizeof(char *) * (word + 1));
	if (M == NULL)
		return (NULL);

	for (ind = 0; ind <= len; ind++)
	{
		if (str[ind] == ' ' || str[ind] == '\0')
		{
			if (count)
			{
				finish = ind;
				tp = (char *) malloc(sizeof(char) * (count + 1));
				if (tp == NULL)
					return (NULL);
				while (begin < finish)
					*tp++ = str[begin++];
				*tp = '\0';
				M[J] = tp - count;
				J++;
				count = 0;
			}
		}
		else if (count++ == 0)
			begin = ind;
	}

		M[J] = NULL;

	return (M);
}
