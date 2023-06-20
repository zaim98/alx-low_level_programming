/**
 *_islower - Entry poit
 *Description: This code checks for lowercase
 *Return: 1 if it's lowercase
 *else: 0
 *@c: The charector in ASCII CODE
 */
int _islower(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}
