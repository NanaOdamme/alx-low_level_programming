#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position in list
 * @head: Double pointer to the head of the linked list
 * @idx: Index of the list where the new node should be added (starting at 0)
 * @n: The value to be stored in the new node
 *
 * Return: The address of the new node
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;

	if (head == NULL || idx == 0)
	{
		listint_t *new_node = (listint_t *)malloc(sizeof(listint_t));

		if (new_node == NULL)
		{
			return (NULL);
		}

		new_node->n = n;
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	listint_t *current = *head;

	for (i = 0; current != NULL && i < idx - 1; i++)
	{
		current = current->next;
	}

	if (current == NULL || current->next == NULL)
		return (NULL);

	listint_t *new_node = (listint_t *)malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = currect->next;
	current->next = new_node;

	return (new_node);
}

