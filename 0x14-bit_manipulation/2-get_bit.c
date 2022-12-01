#include "main.h"

/**
 * get_bit - returns value of a bit at a given index
 * @n: binary number
 * @index: index to find bit at
 *
 * Return: value of bit at index
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index > sizeof(unsigned long int) * 8)
		return (-1);

	return (n >> index & 1);
}
