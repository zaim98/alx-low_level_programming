#include <stdio.h>
/**
  *main - Entry point
  *Description: This program Prints first 50 Fibonacci numbers.
  *starting 1 and 2.
  *And separated them by a comma followed by a space.
  *Return: Always 0.
 */
int main(void)
{
	int tir;
	unsigned long fibric1 = 0, fibric2 = 1, sum;

	for (tir = 0; tir < 50; tir++)
	{
		sum = fibric1 + fibric2;
		printf("%lu", sum);
		fibric1 = fibric2;
		fibric2 = sum;
		if (tir == 49)
			printf("\n");
		else
			printf(", ");
	}
	return (0);
}
