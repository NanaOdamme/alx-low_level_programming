#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a file with the specified content.
 * @filename: The name of the file to create.
 * @text_content: A NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t write_result;

	if (filename == NULL)
		return (-1); /* Return -1 if filename is NULL */

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	if (text_content != NULL)
	{
		write_result = write(fd, text_content, strlen(text_content));
		if (write_result == -1)
		{
			close(fd);
			return (-1); /* Return -1 if write fails */
		}
	}
		close(fd);
		return (1); /* Return 1 on success */
}
/**
 * main - Entry point of the program.
 *
 * This function demonstrates the usage of the create_file function by
 * creating a file named "example.txt" with the specified text content.
 *
 * Return: Always 0.
 */
int main(void)
{
	const char *filename = "example.txt";
	char *text_content = "This is the content of the file.";

	int result = create_file(filename, text_content);

	if (result == -1)
		printf("Failed to create or write to the file.\n");
	else
		printf("File created and written successfully.\n");

	return (0);
}
