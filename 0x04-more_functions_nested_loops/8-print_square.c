#include "main.h"
/**
  *print_square - Entry
  *Description: checks square
  *@size: number to be printed
  *Return:void
 */
void print_square(int size)
{
	int num = 0, count;

	while (num < size && size > 0)
	{
		count = 0;
		while (count < size)
		{
			_putchar('#');
			count++;
		}
		_putchar('\n');
		num++;
	}
	if (num == 0)
		_putchar('\n');
}
