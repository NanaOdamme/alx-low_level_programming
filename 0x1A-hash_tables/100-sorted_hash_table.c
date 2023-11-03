#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"
/**
 * shash_table_create - Create a sorted hash table
 * @size: Size of the array for the hash table
 *
 * Return: Pointer to the newly created sorted hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table = NULL;
	unsigned long int i;

	if (size < 1)
		return (NULL);
	new_table = malloc(sizeof(shash_table_t));
	if (new_table == NULL)
		return (NULL);
	new_table->array = malloc(sizeof(shash_node_t *) * size);
	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		new_table->array[i] = NULL;
	}
	new_table->size = size;
	new_table->shead = NULL;
	new_table->stail = NULL;
	return (new_table);
}

/**
 * shash_table_set - Add an element to the sorted hash table
 * @ht: The sorted hash table to add or update the key/value
 * @key: The key to be added/updated
 * @value: The value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node = NULL, *current = NULL, *prev = NULL;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);
	current = ht->shead;
	while (current != NULL && strcmp(current->key, key) < 0)
	{
		prev = current;
		current = current->snext;
	}
	if (current != NULL && strcmp(current->key, key) == 0)
	{
		free(current->value);
		current->value = strdup(value);
		return (1);
	}
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
        	free(new_node);
        	return (0);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}
	new_node->snext = current;
	new_node->sprev = prev;
	if (prev != NULL)
		prev->snext = new_node;
	else
		ht->shead = new_node;
	if (current != NULL)
		current->sprev = new_node;
	else
		ht->stail = new_node;
	return (1);
}

/**
 * shash_table_get - Retrieve the value associated with a key
 * @ht: The sorted hash table to look into
 * @key: The key you are looking for
 *
 * Return: The value associated with the key, or NULL if key couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *current;

	if (ht == NULL || key == NULL || *key == '\0')
	{
		return (NULL);
	}
	current = ht->shead;
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			return (current->value);
		}
			current = current->snext;
	}
	return (NULL);
}

/**
 * shash_table_print - Print the contents of the sorted hash table
 * @ht: The sorted hash table to be printed
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;
	printf("{");
	for (node = ht->shead; node != NULL; node = node->snext)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->snext != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Print the contents of the sorted hash table in reverse order
 * @ht: The sorted hash table to be printed
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;
	printf("{");
	for (node = ht->stail; node != NULL; node = node->sprev)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->sprev != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Delete the sorted hash table and free all memory
 * @ht: The sorted hash table to be deleted
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *temp;

	if (ht == NULL)
		return;
	for (node = ht->shead; node != NULL; node = temp)
	{
		temp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
	}
	free(ht->array);
	free(ht);
}
