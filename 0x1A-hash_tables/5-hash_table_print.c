#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: hash table to print
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *run;
	unsigned int index;
	int check = 0;

	if (ht == NULL)
		return;
	printf("{");
	for (index = 0; index < ht->size; index++)
	{
		for (run = ht->array[index]; run != NULL; run = run->next)
		{
			if (check != 0)
				printf(", ");
			printf("'%s': '%s'", run->key, run->value);
			check = 1;
		}
	}
	printf("}\n");
}

