#include "main.h"
/**
 *print_alphabet_x10 - Entry point
 *Description: prints alpha in lowercase 10 times
 *Return: always 0 success
 */
void print_alphabet_x10(void)
{
	int i = 0, x;

	while (i < 10)
	{
		for (x = 97; x <= 122; x++)
		{
			_putchar(x);
		}
		_putchar('\n');
		i++;
	}
}
