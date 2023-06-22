#include "main.h"
/**
 * _isdigit - Entry point
 * Description: This program checks if the character is uppercase
 * @c:  the argument number of the  function
 * Return: 1 if uppercase character 0 if it's not
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
