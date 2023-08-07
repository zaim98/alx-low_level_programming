#include "main.h"
/**
 * print_errors - function to display error messages and exit
 * @message: the error message to be displayed
 * @file: the name of the file associated with the error
 * @exit_val: the exit status to use when terminating the program
 * Return: void
 */
void print_errors(char *message, char *file, int exit_val)
{
	dprintf(STDERR_FILENO, "%s%s\n", message, file);
	exit(exit_val);
}

/**
 * main - copies data from one file to another
 * @argc: the number of arguments passed to the program
 * @argv: pointer to an array containing the arguments
 * Return: 0 on success, other values on failure
 */
int main(int argc, char **argv)
{
	int fd_dest, fd_src, read_val, write_val;
	char buffer[1024];

	if (argc != 3)
		print_errors("Usage: cp file_from file_to", "", 97);

	fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_dest == -1)
		print_errors("Error: Can't write to ", argv[2], 99);

	fd_src = open(argv[1], O_RDONLY);
	if (fd_src == -1)
		print_errors("Error: Can't read from file ", argv[1], 98);

	do {
		read_val = read(fd_src, buffer, 1024);
		if (read_val == -1)
			print_errors("Error: Can't read from file ", argv[1], 98);

		write_val = write(fd_dest, buffer, read_val);
		if (write_val == -1 || write_val != read_val)
			print_errors("Error: Can't write to ", argv[2], 99);

	} while (write_val == 1024);

	if (close(fd_src))
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_src);
		exit(100);
	}

	if (close(fd_dest))
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_dest);
		exit(100);
	}

	return (0);
}
