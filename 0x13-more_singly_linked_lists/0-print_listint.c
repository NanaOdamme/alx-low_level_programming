#include "lists.h"

/**
 * print_listint - function to print elements of the list
 * @h: pointer to head of list
 * Return: count
 */

size_t print_listint(const listint_t *h)
{
size_t count = 0;

while (h != NULL)
{
printf("%d\n", h->n);
h = h->next;
count++;
}

return (count);
}
