#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a linked list
 * @head: double pointer to the list_t list
 * @str: new string to add in the node
 *
 * Return: the address of the new element, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
 list_t *nlink;
 unsigned int l = 0;

 while (str[l])
 l++;

 nlink = malloc(sizeof(list_t));
 if (!nlink)
 return (NULL);

 nlink->str = strdup(str);
 nlink->len = l;
 nlink->next = (*head);
 (*head) = nlink;

 return (*head);
}

