#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 *         The function sets the head to NULL.
 */
size_t free_listint_safe(listint_t **h)
{
listint_t *current = *h;
listint_t *next;
size_t node_count = 0;

while (current != NULL)
{
next = current->next;
free(current);
current = next;
node_count++;

if (current == *h)
{
*h = NULL;
break;
}
}

return (node_count);
}

