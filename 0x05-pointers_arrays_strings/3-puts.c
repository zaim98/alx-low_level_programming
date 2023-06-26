#include "main.h"
/**
 * _puts - Entry
 * Description THis code prints a string, followed by a new line
 * @str: Pointer
 * Return: void
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

	_putchar('\n');
}
