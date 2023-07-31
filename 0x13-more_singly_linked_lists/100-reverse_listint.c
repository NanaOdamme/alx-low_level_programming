#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: Double pointer to the head of the linked list.
 *
 * Return: A pointer to the first node of the reversed list.
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *next_node, *prev, *current;

	if (*head == NULL || (*head)->next == NULL)
		return (*head);

	prev = NULL;
	current = *head;

	while (current != NULL)
	{
		next_node = current->next;

		current->next = prev;
		prev = current;
		current = next_node;
	}

	*head = prev;
	return (*head);
}

