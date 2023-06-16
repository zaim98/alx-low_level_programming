#include <stdio.h>
/**
  *main - Entry poit
  *Description: All single digit numbers of base 10
  *Return: (0) always success
 */
int main(void)
{
	int n;

	for (n = 0; n <= 9; n++)
	{
		printf("%d", n);
	}
	printf("\n");
	return (0);
}
