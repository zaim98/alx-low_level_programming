#include "main.h"

/**
 * _memset - Entry
 * Description: This program fills memory with constant bytes
 * @s: pointer to char params
 * @b: data to change
 * @n: index
 * Return: *s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int f;

	for (f = 0; f < n; f++)
	{
		s[f] = b;
	}
	return (s);
}

