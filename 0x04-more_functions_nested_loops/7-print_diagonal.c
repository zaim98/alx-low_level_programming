#include "main.h"
/**
  *print_diagonal - Entry point
  *Description: This program prints line.
  *@n: arg
  *Return: always 0 success
 */
void print_diagonal(int n)
{
	int i = 0, j;

	while (i < n && n > 0)
	{
		j = 0;
		while (j < i)
		{
			_putchar(' ');
			j++;
		}
		_putchar('\\');
		_putchar('\n');
		i++;
	}
	if (i == 0)
		_putchar('\n');
}
