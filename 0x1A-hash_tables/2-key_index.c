#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"

/**
 * key_index - Get the index for a key in a hash table
 * @key: The key to be hashed
 * @size: Size of the array for the hash table
 *
 * Return: The index at which the key should be stored in the hash table array.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;
	unsigned long int index;

	/*Calculate the hash value using hash_djb2*/
	hash_value = hash_djb2(key);

	/*Calculate the index by taking the modulo of the hash value with the size*/
	index = hash_value % size;

	return (index);
}
