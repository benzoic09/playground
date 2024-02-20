#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number to extract the bit from.
 * @index: The index of the bit to retrieve (starting from 0).
 * Return: The value of the bit at the given index or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(n) * 8) /* Check if the index is out of range */
		return (-1);

	return ((n >> index) & 1); /* Shift right to the index and extract the bit */
}
