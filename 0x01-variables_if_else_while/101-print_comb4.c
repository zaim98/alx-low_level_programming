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
		int d1;
		int d2;
		int d3 = 0;

		while (d3 < 10)
		{
			d2 = 0;
			while (d2 < 10)
			{
				d1 = 0;
				while (d1 < 10)
				{
					if (d1 != d2 && d2 != d3 && d3 < d2 && d2 < d1)
					{
						putchar('0' + d3);
						putchar('0' + d2);
						putchar('0' + d1);
						if (d1 + d2 + d3 != 9 + 8 + 7)
						{
							putchar(',');
							putchar(' ');
						}
					}
					d1++;
				}
				d2++;
			}
			d3++;
		}
		putchar('\n');
		return (0);
}
