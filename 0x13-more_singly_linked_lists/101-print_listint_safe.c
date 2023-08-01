#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: Pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
const listint_t *slow = head;
const listint_t *fast = head;
size_t node_count = 0;

while (slow && fast && fast->next)
{
printf("[%p] %d\n", (void *)slow, slow->n);
slow = slow->next;
fast = fast->next->next;
node_count++;

if (slow == fast)
{
exit(98);
}
}

if (slow)
{
printf("[%p] %d\n", (void *)slow, slow->n);
node_count++;
}

return (node_count);
}
