#include <stdio.h>
/**
  *main - Entry point
  *Description: This code prints possible combinations of digits
  *Return: 0 always success
  */
int main(void)
{
	int num;

	for (num = 48; num <= 57; num++)
	{
		putchar(num);
		if (num == 57)
		{
			continue;
		}
		putchar(',');
		putchar(' ');
	}
	putchar('\n');
	return (0);
}
