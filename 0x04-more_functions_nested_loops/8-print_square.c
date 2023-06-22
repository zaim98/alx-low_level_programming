#include "main.h"
/**
  *print_square - Entry
  *Description: checks square
  *@n : number to be printed
  *Return:void
 */
void print_square(int n)
{
	int num = 0, count;

	while (num < n && n > 0)
	{
		count = 0;
		while (count < n)
		{
			_putchar('#');
			count++;
		}
		_putchar('\n');
		num;
	}
	if (num == 0)
		_putchar('\n');
}
