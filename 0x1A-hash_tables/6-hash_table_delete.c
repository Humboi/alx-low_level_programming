#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: hash table
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *run, *tmp;
	unsigned long int i;

	if (ht == NULL || ht->size == 0 || ht->array == NULL)
		return;
	for (i = 0; i < ht->size; i++)
	{
		for (run = ht->array[i]; run != NULL; run = tmp)
		{
			tmp = run->next;
			free(run->key);
			free(run->value);
			free(run);
		}
	}
	free(ht->array);
	free(ht);
}

