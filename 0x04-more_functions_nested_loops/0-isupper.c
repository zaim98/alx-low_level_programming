#include "main.h"
/**
 * _isupper - Entry point
 * Description: This program checks if the character is uppercase
 * @c:  the argument number of the  function
 * Return: 1 if uppercase character 0 if it's not
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
