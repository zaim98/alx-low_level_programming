#include <stdio.h>
/**
  *main - Entry point
  *Description: This program Prints the first 98 Fibonacci numbers
  *And starting with 1 and 2, separated by a comma followed by a space.
  *Return: Always 0.
 */
int main(void)
{
	int tir;
	unsigned long fibric1 = 0, fibric2 = 1, sum;
	unsigned long fibric1_half1, fibric1_half2, fibric2_half1, fibric2_half2;
	unsigned long half1, half2;

	for (tir = 0; tir < 92; tir++)
	{
		sum = fibric1 + fibric2;
		printf("%lu, ", sum);
		fibric1 = fibric2;
		fibric2 = sum;
	}
	fibric1_half1 = fibric1 / 10000000000;
	fibric2_half1 = fibric2 / 10000000000;
	fibric1_half2 = fibric1 % 10000000000;
	fibric2_half2 = fibric2 % 10000000000;
	for (tir = 93; tir < 99; tir++)
	{
		half1 = fibric1_half1 + fibric2_half1;
		half2 = fibric1_half2 + fibric2_half2;
		if (fibric1_half2 + fibric2_half2 > 9999999999)
		{
			half1 += 1;
			half2 %= 10000000000;
		}
		printf("%lu%lu", half1, half2);
		if (tir != 98)
			printf(", ");
		fibric1_half1 = fibric2_half1;
		fibric1_half2 = fibric2_half2;
		fibric2_half1 = half1;
		fibric2_half2 = half2;
	}
	printf("\n");
	return (0);
}
