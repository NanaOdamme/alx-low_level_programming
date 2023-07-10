#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenate two input strings
 * @s1: first string to concatenate
 * @s2: second string to concatenate
 *
 * Return: pointer to the concatenated string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *cat;
	int ind1, ind2, ind_cat;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	ind1 = ind2 = 0;
	while (s1[ind1] != '\0')
		ind1++;
	while (s2[ind2] != '\0')
		ind2++;

	cat = malloc(sizeof(char) * (ind1 + ind2 + 1));
	if (cat == NULL)
		return NULL;

	ind1 = ind_cat = 0;
	while (s1[ind1] != '\0')
	{
		cat[ind_cat] = s1[ind1];
		ind1++;
		ind_cat++;
	}

	ind2 = 0;
	while (s2[ind2] != '\0')
	{
		cat[ind_cat] = s2[ind2];
		ind2++;
		ind_cat++;
	}

	cat[ind_cat] = '\0';  /* Add null terminator */

	return cat;
}
