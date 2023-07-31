#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: Double pointer to the head of the linked list.
 *
 * Return: The size of the list that was freed.
 */

size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *temp;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		count++;

		if (temp >= current)
		{
			*h = NULL;
			return (count);
		}

		current = temp;
	}

	*h = NULL;
	return (count);
}
