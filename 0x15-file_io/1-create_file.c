#include "main.h"
/**
 * _strlen - Calculates the length of a string.
 * @s: The string to find the length of.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; s[len]; len++)
	{}
	return (len);
}

/**
 * create_file - Creates a file and writes content into it.
 * @filename: The name of the file to be created.
 * @text_content: The text content to be written into the new file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int len;
	int fd, writeVal;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fd < 0)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	len = _strlen(text_content);
	writeVal = write(fd, text_content, len);
	if (writeVal < 0 || writeVal != len)
		return (-1);

	return (1);
}
