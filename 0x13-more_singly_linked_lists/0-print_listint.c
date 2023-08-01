#include "lists.h"

/**
 * print_listint - function to print elements of the list
 * @h: pointer to head of list
 * Return: count
 */

size_t print_listint(const listint_t *h)
{
size_t count = 0;
const listint_t *current = h;

while (current != NULL)
{
printf("%d\n", current->n);
count++;
current = current->next;
}

return (count);
}
