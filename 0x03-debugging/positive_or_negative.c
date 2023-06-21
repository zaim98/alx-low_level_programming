#include "main.h"
/* more headers goes there */
/* betty style doc for function main goes there */
/**
  *positive_or_negative - main poit
  *Description: This code gets number
  *@i: The number to be check
  *then tells us if its zero negative or possitive
  *Return: (0) always success
  */
void positive_or_negative(int i)
{
	if (i > 0)
	{
		printf("%d, is positiven", i);
	}
	else if (i < 0)
	{
		printf("%d, is negativen", i);
	}
	else
	{
		printf("%d is zero\n", i);
	}
}
