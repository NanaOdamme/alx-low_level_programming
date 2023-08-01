#include "lists.h"
/*
 * free_listint2 - frees a list
 *
 * @head: pointer to head
 *
 * return: nothing
 */


void free_listint2(listint_t **head)
{
	listint_t *freed;

	if (head == NULL || *head == NULL)
	{
		return;
	}

	while (*head != NULL)
	{
		freed = *head;
		*head = (*head)->next;
		free(freed);
	}

	*head = NULL;
}
