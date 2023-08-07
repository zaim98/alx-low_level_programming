#include "main.h"
#include <elf.h>
void print_title(char *title);
/**
 * errors - prints some errors
 * @msg: the error msg
 * Return: void
 */
void errors(char *msg)
{
	/* writing the error */
	int len = 0;
	for (len = 0; msg[len]; len++)
		;

	write(STDERR_FILENO, msg, len);
	exit(98);
}

/**
 * print_type - prints type
 * @buffer: contains type info
 * Return: void
 */
void print_type(char *buffer)
{
	print_title("Type");
	switch (buffer[6])
	{
		case ET_NONE:
			printf("NONE (None)");
			break;
		case ET_REL:
			printf("REL (Relocatable file)");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)");
			break;
		case ET_CORE:
			printf("CORE (Core file)");
			break;
		default:
			printf("<unknown>: %x", buffer[6]);
			break;
	}
	printf("\n");
}

/**
 * print_ABI_version - prints the ABI version
 * @buffer: contains the ABI version
 * Return: void
 */
void print_ABI_version(char *buffer)
{
	print_title("ABI Version");
	printf("%d", buffer[8]);
	printf("\n");
}

/**
  *Add similar functions with proper comments for print_entry,
  *print_OS_ABI, print_version, print_data, print_magic, print_class
 */
/**
 * print_title - printing titles with proper alignment
 * @title: the title
 * Return: void
 */
void print_title(char *title)
{
	int size = 37;
	int len, i;

	printf("  ");
	printf("%s:", title);

	for (len = 0; title[len]; len++)
		;

	for (i = 0; i < size - 3 - len; i++)
		printf(" ");
}

/**
 * main - print an ELF header and such
 * @argc: count of args
 * @argv: vector of args
 * Return: int or exit code
 */
int main(int argc, char **argv)
{
	/* declarations */
	int fd, readVal, i;
	char buffer[16];
	char match[4] = {0x7f, 'E', 'L', 'F'};

	/* too many args? too few? */
	if (argc != 2)
		errors("Improper usage\n");

	/* file descriptor, opening */
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		errors("Could not open the file\n");

	/* reading */
	readVal = read(fd, buffer, 16);
	if (readVal == -1)
		errors("Could not read from the file\n");

	/* checking for elfage */
	for (i = 0; i < 4; i++)
	{
		if (buffer[i] != match[i])
			errors("Sorry, it's not an ELF file!\n");
	}

	/* printing the header! */
	printf("ELF Header:\n");
	print_magic(buffer);
	print_class(buffer);
	print_data(buffer);
	print_version(buffer);
	print_OS_ABI(buffer);
	print_ABI_version(buffer);
	print_type(buffer);
	print_entry();

	/* close and check for close */
	if (close(fd))
		errors("Could not close the file");

	return (0);
}
