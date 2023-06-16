#include <stdio.h>
/**
 * main - Entry point
 * Description: This code prints possible combinations of digits
 * Return: 0 always success
 */
int main(void)
{
	int n1, n2;

	for (n1 = 0; n1 <= 9; n1++)
	{
		for (n2 = 0; n2 <= 9; n2++)
		{
			putchar('0' + n1);
			putchar('0' + n2);
			putchar(',');
		}
	}
	putchar('\n');
	return (0);
}
