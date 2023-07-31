#include "lists.h"

/**
 * pop_listint - deletes the first node
 * @head: pointer to the pointer head
 * Return: returns 0 if list empty else data of the next node
 */

int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp;

	if (*head == NULL)
	{
		return (0);
	}
	data = (*head)->n;
	temp = *head;

	*head = (*head)->next;
	free(temp);

	return (data);
}
