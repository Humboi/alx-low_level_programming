#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: binary number
 *
 * Return: converted number, or 0 if b is NULL or not a binary number
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int index;

	if (b == NULL)
		return (0);

	for (index = 0; b[index] != '\0'; index++)
	{
		if (b[index] != '0' && b[index] != '1')
			return (0);

		num <<= 1;

		if (b[index] == '1')
			num += 1;
	}

	return (num);
}
