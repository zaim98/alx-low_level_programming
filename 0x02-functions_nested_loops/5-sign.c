#include "main.h"
/**
 *print_sign - Entry point
 *Description: function that prints sign number
 *@n : thr numer to check
 *Return: always 0 succcess
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar(43);
		return (1);
	}
	else if (n < 0)
	{
		_putchar(45);
		return (-1);
	}
	else
	{
		_putchar(48);
		return (0);
	}
}
