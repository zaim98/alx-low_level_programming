#include <stdio.h>
/**
  *main - Entry point
  *Description: This program Prints the sum of even-valued Fibonacci sequence
  *By considering the terms in the Fibonacci sequence whose values do not
  *exceed 4,000,000
  *Return: Always 0.
 */
int main(void)
{
	unsigned long fibric1 = 0, fibric2 = 1, fibricsum;
	float total_sum;

	while (1)
	{
		fibricsum = fibric1 + fibric2;
		if (fibricsum > 4000000)
			break;
		if ((fibricsum % 2) == 0)
			total_sum += fibricsum;
		fibric1 = fibric2;
		fibric2 = fibricsum;
	}
	printf("%.0f\n", total_sum);
	return (0);
}
