#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: Pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
size_t count = 0;
const listint_t *current = head;

while (current != NULL)
{
printf("[%p] %d\n", (const void *)current,  current->n);
count++;
if (count == 10)
{
break;
}
current = current->next;
}

if (head == NULL)
{
exit(98);
}

return (count);
}

