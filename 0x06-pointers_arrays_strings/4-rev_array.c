#include "main.h"
/**
 * reverse_array - Entry
 * Description: This program reverse a int array
 * @a: pointer
 * @n: array length
 * Return: void
 */

void reverse_array(int *a, int n)
{
	int i = 0, qeyb;

	for (qeyb = n / 2; qeyb > 0; qeyb--, i++)
	{
		a[n - i - 1] += a[i];
		a[i] = a[n - i - 1] - a[i];
		a[n - i - 1] = a[n - i - 1] - a[i];
	}
}

