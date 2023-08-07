#include "main.h"
#include <elf.h>

void print_title(char *title);

/**
 * print_errors - prints some errors
 * @msg: the error msg
 *
 * Return: void
 */
void print_errors(char *msg)
{
	/* declarations */
	int len;

	/* writing the error */
	for (len = 0; msg[len]; len++)
		;
	write(STDERR_FILENO, msg, len);

	exit(98);
}

/**
 * print_type - prints type
 * @buffer: contains type info
 *
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
 *
 * Return: void
 */
void print_ABI_version(char *buffer)
{
	/* handling the ABI set */
	print_title("ABI Version");

	printf("%d", buffer[8]);

	printf("\n");
}

/**
 * print_entry - prints the ELF entry point address
 *
 */
void print_entry(void)
{
	Elf64_Ehdr h;
	int i = 0, len = 0;
	unsigned char *p = (unsigned char *)&h.e_entry;

	printf("  Entry point address:               0x");
	if (h.e_ident[EI_DATA] == ELFDATA2MSB)
	{
		i = h.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!p[i])
			i--;
		printf("%x", p[i--]);
		for (; i >= 0; i--)
			printf("%02x", p[i]);
		printf("\n");
	}
	else
	{
		i = 0;
		len = h.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!p[i])
			i++;
		printf("%x", p[i++]);
		for (; i <= len; i++)
			printf("%02x", p[i]);
		printf("\n");
	}
}

/**
 * print_OS - printing the os/abi
 * @buffer: contains os/abi info
 *
 * Return: void
 */
void print_OS(char *buffer)
{
	/* handling the OS ABI set */
	print_title("OS/ABI");

	switch (buffer[7])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - GNU");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64");
			break;
		default:
			printf("<unknown: %x>", (unsigned int)buffer[7]);
	}
	printf("\n");
}

/**
 * print_version - printing version
 * @buffer: contains version
 *
 * Return: void
 */
void print_version(char *buffer)
{
	/* handling the version set */
	print_title("Version");

	switch (buffer[6])
	{
		case EV_NONE:
			printf("0");
			break;
		case EV_CURRENT:
			printf("1 (current)");
			break;
		default:
			printf("%d <unknown: %%lx>", (int)buffer[6]);
	}

	printf("\n");
}

/**
 * print_data - printing the data handling
 * @buffer: contains data handling info
 *
 * Return: void
 */
void print_data(char *buffer)
{
	/* handling the data set */
	print_title("Data");

	switch (buffer[5])
	{
		case ELFDATANONE:
			printf("none");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian");
			break;
		default:
			printf("<unknown: %x>", (unsigned int)buffer[5]);
	}

	printf("\n");
}

/**
 * print_magic - printing the Magic we need
 * @buffer: contains magic
 *
 * Return: void
 */
void print_magic(char *buffer)
{
	/* declarations */
	int i;

	/* handling the magics */
	printf("  Magic:   ");
	for (i = 0; i < 16; i++)
		printf("%.2x ", buffer[i]);
	printf("\n");
}

/**
 * print_class - printing the class, in class
 * @buffer: the buffer containing class or none
 *
 * Return: void
 */
void print_class(char *buffer)
{
	/* handling the class */
	print_title("Class");

	switch (buffer[4])
	{
		case ELFCLASSNONE:
			printf("none");
			break;
		case ELFCLASS32:
			printf("ELF32");
			break;
		case ELFCLASS64:
			printf("ELF64");
			break;
		default:
			printf("<unknown: %x>", (unsigned int)buffer[4]);
	}
	printf("\n");
}

/**
 * print_title - printing titles since 2020
 * @title: the title
 *
 * Return: void
 */
void print_title(char *title)
{
	/* declarations */
	int size = 37;
	int len, i;

	/* handling the titles & spaces */
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
 *
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
		print_errors("Improper usage\n");

	/* file descriptor, opening */
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)

		print_errors("Could not open the file\n");

	/* reading */
	readVal = read(fd, buffer, 16);
	if (readVal == -1)
		print_errors("Could not read from the file\n");

	/* checking for elfage */
	for (i = 0; i < 4; i++)
	{
		if (buffer[i] != match[i])
			print_errors("Sorry, it's not an ELF file!\n");
	}

	/*printing the header! */
	printf("ELF Header:\n");
	print_magic(buffer);
	print_class(buffer);
	print_data(buffer);
	print_version(buffer);
	print_OS(buffer);
	print_ABI_version(buffer);
	print_type(buffer);
	print_entry();

	/* close and check for close */
	if (close(fd))
		print_errors("Could not close the file");

	return (0);
}
