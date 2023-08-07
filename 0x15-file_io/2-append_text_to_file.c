#include "main.h"
/**
 * _strlen - Calculates the length of a string.
 * @s: The string to measure the length of.
 *
 * Return: The length of the string (excluding the null-terminator).
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; s[len]; len++)
	{}
	return (len);
}

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: The name of the file.
 * @text_content: The text to append.
 *
 * Return: 1 on success and -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, writeVal, len;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_APPEND);
	if (fd < 0)
		return (-1);
	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}
	len = _strlen(text_content);
	writeVal = write(fd, text_content, len);
	if (writeVal < 1 || writeVal != len)
		return (-1);
	return (1);
}
