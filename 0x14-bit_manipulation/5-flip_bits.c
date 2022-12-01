#include "main.h"

/**
 * flip_bits - compares two binary numbers in terms of bit flipping
 * @n: first number
 * @m: second number
 *
 * Return: the number of bits you would need to flip to get from n to m
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int count = 0;
	unsigned long int diff = n ^ m;

	while (diff)
	{
		count += (diff & 1);
		diff >>= 1;
	}

	return (count);
}
