#include "main.h"
/**
 * _strlen - Entry
 * Description: This program Returns the length of a string.
 * @s: The string to get the length of.
 *
 * Return: The length of @str.
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}
