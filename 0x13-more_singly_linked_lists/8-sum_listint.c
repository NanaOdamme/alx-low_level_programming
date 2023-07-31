#include "lists.h"

/**
 * sum_listint - calculates the sum of all the data of list
 * @head: head of list
 * Return: sum of the data
 */
int sum_listint(listint_t *head)
{
	int sumUp = 0;

	while (head != NULL)
	{
		sumUp += head->n;
		head = head->next;
	}

	return (sumUp);
}
