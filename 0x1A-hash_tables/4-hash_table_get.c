#include "hash_tables.h"

/**
 * hash_table_get - returns value associated with a certain key
 * @ht: hash table
 * @key: key
 *
 * Return: value
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *runner;

	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (NULL);
	index = key_index((unsigned char *)key, ht->size);
	for (runner = ht->array[index]; runner != NULL; runner = runner->next)
	{
		if (strcmp(runner->key, key) == 0)
			return (runner->value);
	}
	return (NULL);
}

