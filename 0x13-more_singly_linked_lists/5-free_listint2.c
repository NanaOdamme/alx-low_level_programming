#include "lists.h"

/**
 * free_listint2 - frees list and set head to null
 * @head: pointer to pointer head
 */

void free_listint2(listint_t **head)
{
	while (*head != NULL)
	{
		listint_t *temp = *head;
		*head = (*head)->next;
		free(temp);
	}

	*head = NULL;

}
