#include "lists.h"

/**
 * add_nodeint_end - inserts a new node at end of list
 * @head: pointer to pointer head
 * @n: value of new node
 * Return: null if memory alloc. fails else returns new node
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newNode = (listint_t *)malloc(sizeof(listint_t));

	if (newNode == NULL)
	{
		return (NULL);
	}

	newNode->n = n;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
		return (newNode);
	}

	listint_t *current = *head;

	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = newNode;

	return (newNode);
}
