#include "hash_tables.h"

/**
 * hash_table_set - adds an element to hash table
 * @ht: hash table
 * @key: key of element
 * @value: value associated with that key
 *
 * Return: 1 if success, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new, *runner;

	if (ht == NULL || key == NULL || strlen(key) == 0 ||
	    strcmp(key, "") == 0 || value == NULL || ht->size == 0 ||
	    ht->array == NULL)
		return (0);

	index = key_index((unsigned char *)key, ht->size);
	for (runner = ht->array[index]; runner != NULL; runner = runner->next)
	{
		if (strcmp(runner->key, key) == 0)
		{
			if (strcmp(runner->value, value) != 0)
			{
				free(runner->value);
				runner->value = strdup(value);
				if (runner->value == NULL)
					return (0);
			}
			return (1);
		}
	}
	new = create_ht_node(key, value);
	if (new == NULL)
		return (0);
	new->next = ht->array[index];
	ht->array[index] = new;
	return (1);
}

/**
 * create_ht_node - creates a new ht node
 * @key: key of new node
 * @value: value of new node
 *
 * Return: new node
 */

hash_node_t *create_ht_node(const char *key, const char *value)
{
	hash_node_t *new;

	new = malloc(sizeof(hash_table_t *));
	if (new == NULL)
		return (NULL);
	new->key = strdup(key);
	if (new->key == NULL)
		return (NULL);
	new->value = strdup(value);
	if (new->value == NULL)
		return (NULL);
	return (new);
}

