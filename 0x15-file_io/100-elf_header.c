#include "main.h"
#include <elf.h>

void ptitle(char *title);

/**
 * errors - prints some errors
 * @msg: the error msg
 * Return: void
 */
void errors(char *msg)
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
 * ptype - prints type
 *
 * @buffer: contains type info
 * Return: void
 */
void ptype(char *buffer)
{
	ptitle("Type");
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
 * pABIversion - prints the ABI version
 * @buffer: contains the ABI version
 *
 * Return: void
 */
void pABIversion(char *buffer)
{
	/* handling the ABI set */
	ptitle("ABI Version");

	printf("%d", buffer[8]);

	printf("\n");
}

/**
 * pentry - prints the ELF entry point address
 *
 */
void pentry(void)
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
 * pos - printing the os/abi
 * @buffer: contains os/abi info
 *
 * Return: void
 */
void pos(char *buffer)
{
	/* handling the OS ABI set */
	ptitle("OS/ABI");

	switch (buffer[7])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX");
			break;
			errors("Could not read from the file\n");
			/* checking for elfage */
			for (i = 0; i < 4; i++)
			{
				if (buffer[i] != match[i])
					errors("Sorry, it's not an ELF file!\n");
			}
			/*printing the header! */
			printf("ELF Header:\n");
			pmagic(buffer);
			pclass(buffer);
			pdata(buffer);
			pversion(buffer);
			pos(buffer);
			pABIversion(buffer);
			ptype(buffer);
			pentry();
			/* close and check for close */
			if (close(fd))
				errors("Could not close the file");

			return (0);
	}


