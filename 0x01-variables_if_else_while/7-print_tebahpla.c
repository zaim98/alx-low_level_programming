#include <stdio.h>
/**
  *main - Entry point
  *Description: This code displays lowercase in reverse
  *Return: 0 always success
  */
int main(void)
{
	int alpha = 122;

	while (alpha >= 97)
	{
		putchar(alpha);
		alpha--;
	}
	putchar('\n');
	return (0);
}
