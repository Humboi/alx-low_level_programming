#include "main.h"

/**
 * clear_bit - sets value of bit at given index to 0
 * @n: binary number
 * @index: postition to set bit value to 0
 *
 * Return: 1 if success, -1 if failure
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (n == NULL || index > sizeof(unsigned long int) * 8)
		return (-1);

	*n &= ~(1 << index);

	return (1);
}
