#include "main.h"
/**
  *print_diagonal - Entry point
  *Description: This program prints line.
  *@n: arg
  *Return: always 0 success
 */
void print_diagonal(int n)
{
	int i = 0;

	while (i < n && n > 0)
	{
		_putchar('\\');
		i++;
	}
	_putchar('\n');
}
