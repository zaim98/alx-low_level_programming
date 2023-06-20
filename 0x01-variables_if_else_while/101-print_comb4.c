#include <stdio.h>
/**
 *main - Entry point
 *Description: This code prints possible combinations of digits
 *Return: 0 always success
 */
int main(void)
{
	int d1, d2, d3;

	for (d1 = 0; d1 <= 7; d1++)
	{
		for (d2 = 0; d2 <= 9; d2++)
		{
			for (d3 = 0; d3 <= 9; d3++)
				if (d1 == 7 && d2 == 8 && d3 == 9)
					break;
			putchar('0' + d1);
			putchar('0' + d2);
			putchar('0' + d3);
			if (!(d1 == 7 && d2 == 8 && d3 == 8))
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
		putchar('\n');
		return (0);
}
