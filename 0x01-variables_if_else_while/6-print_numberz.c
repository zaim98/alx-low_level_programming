#include <stdio.h>
/**
  *main - Entry poit 
  *Description: This code prints digits of base ten using putchar
  *Return: 0 always success
 */
int main(void)
{
	int n;
	for (n = 0; n <= 9; n++)
	{
		putchar(n + 48);
	}
	putchar('\n');
	return (0);
}

