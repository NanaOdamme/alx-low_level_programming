#include "main.h"

/**
 * exit_with_error - Print error message and exit with the specified exit code.
 * @exit_code: The exit code to return.
 * @format: The format string for the error message.
 */
void exit_with_error(int exit_code, const char *format, ...)
{
	va_list args;

	va_start(args, format);

	dprintf(STDERR_FILENO, "Error: ");
	vdprintf(STDERR_FILENO, format, args);
	dprintf(STDERR_FILENO, "\n");
	va_end(args);
	exit(exit_code);
}

/**
 * main - Copy the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 97 on incorrect number of arguments,
 *         98 on file reading error, 99 on file writing error,
 *         100 on file descriptor closing error.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	if (argc != 3)
		exit_with_error(97, "Usage: cp file_from file_to");

/*Open the source file for reading*/
	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		exit_with_error(98, "Can't read from file %s", argv[1]);

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR |
				 S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (file_to == -1)
		exit_with_error(99, "Can't write to file %s", argv[2]);

	while ((bytes_read = read(file_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(file_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			close(file_from);
			close(file_to);
			exit_with_error(99, "Can't write to file %s", argv[2]);
		}
	}
	if (bytes_read == -1)
		exit_with_error(98, "Can't read from file %s", argv[1]);

	if (close(file_from) == -1)
		exit_with_error(100, "Can't close fd %d", file_from);
	if (close(file_to) == -1)
		exit_with_error(100, "Can't close fd %d", file_to);

	return (0);
}
