#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: Double pointer to the head of the linked list.
 *
 * Return: A pointer to the first node of the reversed list.
 */

listint_t *reverse_listint(listint_t **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return (*head);

	listint_t *prev = NULL;
	listint_t *current = *head;

	while (current != NULL)
	{
		listint_t *next_node = current->next;

		current->next = prev;
		prev = current;
		current = next_node;
	}

	*head = prev;
	return (*head);
}

