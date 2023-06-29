#include "main.h"
/**
 * *_strncat - Entry
 * Description: This code concatenates n bytes of two strings
 * @dest: pointer destination
 * @src: pointer source
 * @n: number of bytes
 * Return: void
 */

char *_strncat(char *dest, char *src, int n)
{

	int dest_len, n;

	for (dest_len = 0; dest[dest_len] != '\0'; dest_len++)
		;

	for (i = 0; n < n && src[n] != '\0'; n++)
		dest[dest_len + n] = src[n];


	dest[dest_len + i] = '\0';

	return (dest);
}

