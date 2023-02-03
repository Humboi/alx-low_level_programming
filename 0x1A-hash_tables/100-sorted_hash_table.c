#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hashtable
 * @size: size of hash table
 *
 * Return: point to hash table, or NULL if failure
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int index;

	if (size <= 0)
		return (NULL);
	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;
	ht->array = malloc(sizeof(shash_node_t) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	for (index = 0; index < size; index++)
	{
		ht->array[index] = NULL;
	}
	return (ht);
}


/**
 * shash_table_set - sets a value at a key in a hash tabe
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: 1 if success, 0 otherwise
*/

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *runner, *new;
	unsigned long int index;

	if (ht == NULL || strcmp(key, "") == 0 || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	runner = ht->array[index];
	while (runner != NULL)
	{
		if (strcmp(runner->key, key) == 0)
		{
			free(runner->value);
			runner->value = strdup(value);
			if (runner->value == NULL)
				return (0);
			return (1);
		}
		runner = runner->next;
	}
	new = create_sht_node(key, value);
	if (new == NULL)
		return (0);
	new->next = ht->array[index];
	ht->array[index] = new;
	new->snext = NULL;
	new->sprev = NULL;
	return (add_sht_node(ht, new));
}

/**
 * create_sht_node - makes new sht node
 * @key: key
 * @value: value
 *
 * Return: pointer to new node or NULL if failure
 */

shash_node_t *create_sht_node(const char *key, const char *value)
{
	shash_node_t *new;

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
		return (NULL);
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (NULL);
	}
	new->value = strdup(value);
	if (new->value == NULL)
	{
		free(new->key);
		free(new);
		return (NULL);
	}
	new->next = new->snext = new->sprev = NULL;
	return (new);
}

/**
 * add_sht_node - adds node to sorted hash table
 * @ht: hash table
 * @node: node to add
 *
 * Return: 1 if successful, 0 otherwise
 */

int add_sht_node(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *runner;

	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		return (1);
	}
	runner = ht->shead;
	while (runner != NULL)
	{
		if (strcmp(node->key, runner->key) < 0)
		{
			node->snext = runner;
			node->sprev = runner->sprev;
			runner->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				ht->shead = node;
			return (1);
		}
		runner = runner->snext;
	}

	node->sprev = ht->stail;
	ht->stail->snext = node;
	ht->stail = node;
	return (1);
}


/**
 * shash_table_get - gets the value at a key in a hash table
 * @ht: hash table
 * @key: key
 *
 * Return: value at key, or NULL if key does not exist
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *runner;
	unsigned long int index;

	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	runner = ht->array[index];
	while (runner != NULL)
	{
		if (strcmp(runner->key, key) == 0)
			return (runner->value);
		runner = runner->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints the sorted hash table
 * @ht: hash table
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *runner;
	int first_check = 0;

	if (ht == NULL)
		return;
	printf("{");
	for (runner = ht->shead; runner != NULL; runner = runner->snext)
	{
		if (first_check == 0)
			first_check = 1;
		else
			printf(", ");
		printf("'%s': '%s'", runner->key, runner->value);
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints the sorted hash table in reverse
 * @ht: hash table
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *run_rev;
	int first_check = 0;

	if (ht == NULL)
		return;
	printf("{");
	for (run_rev = ht->stail; run_rev != NULL; run_rev = run_rev->sprev)
	{
		if (first_check == 0)
			first_check = 1;
		else
			printf(", ");
		printf("'%s': '%s'", run_rev->key, run_rev->value);
	}
	printf("}\n");

}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: hash table
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *runner, *tmp;
	unsigned int index;

	if (ht == NULL)
		return;
	for (index = 0; index < ht->size; index++)
	{
		runner = ht->array[index];
		while (runner != NULL)
		{
			tmp = runner->next;
			free(runner->value);
			free(runner->key);
			free(runner);
			runner = tmp;
		}
	}
	free(ht->array);
	free(ht);
}

