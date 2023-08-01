#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a list
 * @head: head of list
 * @index:desired index value
 * Return: null if head is null otherwise return head
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	i = 0;
	while (head != NULL && i < index)
	{
		head = head->next;
		i++;
	}

	if (head == NULL)
	{
		return (NULL);
	}

	return (head);
}
