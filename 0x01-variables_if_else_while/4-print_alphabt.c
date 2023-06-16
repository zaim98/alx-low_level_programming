#include <stdio.h>
/**
 *main - Entry poit or main function
 *Description: This program display alphabet in lowecase
 *Then skips q and e
 *Return: (0) always success
 */
int main(void)
{
	char alpha = 'a';

	while (alpha <= 'z')
	{
		if (alpha != 'e' && alpha != 'q')
		{
		putchar(alpha);
		}
		alpha++;
	}
	putchar('\n');
	return (0);
}

