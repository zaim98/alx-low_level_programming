#include "main.h"
/**
  *print_most_numbers - Entry point
  *Description: This program displays numbers from 0 to 9.
  *Return: always 0 success
 */
void print_most_numbers(void)
{
	int num = 0;

	while (num <= 9)
	{
		if (num != 2 && num != 4)
		{
			_putchar('0' + num);
		}
		num++;
	}
	_putchar('\n');
}
