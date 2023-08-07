#include "main.h"

/**
 * create_file - Creates a file and writes the specified text content to it.
 * @filename: The name of the file to create.
 * @text_content: A NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure
 * The created file will have the permissions: rw-------.
 * If the file already exists, it will be truncated.
 * If filename is NULL, return -1.
 * If text_content is NULL, create an empty file.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor;
	ssize_t bytes_written;
	int text_length;

	if (filename == NULL)
		return (-1);

	/* Open the file for writing(create if not exists,truncate if exists)*/
	file_descriptor = open(filename, O_WRONLY | O_CREAT
				| O_TRUNC, S_IRUSR | S_IWUSR);
	if (file_descriptor == -1)
		return (-1); /* Failed to create or open the file */

	if (text_content != NULL)
	{
		/* Calculate the length of the text_content */
		text_length = 0;
		while (text_content[text_length])
			text_length++;

		/* Write the text_content to the file */
		bytes_written = write(file_descriptor, text_content, text_length);
		if (bytes_written != text_length)
		{
			close(file_descriptor);
			return (-1); /* Failed to write to the file */
		}
	}

	/* Close the file and return success */
	close(file_descriptor);
	return (1);
}

