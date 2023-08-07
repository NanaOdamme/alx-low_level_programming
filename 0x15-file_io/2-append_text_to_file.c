#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file to append to.
 * @text_content: A NULL-terminated string to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 * If filename is NULL, return -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, text_length;
	ssize_t bytes_written;

	if (filename == NULL)
		return (-1);

	/* Open the file for appending (do not create if not exists)*/
	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (-1);
	/* Failed to open the file or do not have required permissions*/

	if (text_content != NULL)
	{
		/* Calculate the length of the text_content*/
		text_length = 0;
		while (text_content[text_length])
			text_length++;

		/* Write the text_content to the file*/
		bytes_written = write(file_descriptor, text_content, text_length);
		if (bytes_written != text_length)
		{
			close(file_descriptor);
			return (-1); /* Failed to write to the file*/
		}
	}

	/* Close the file and return success*/
	close(file_descriptor);
	return (1);
}
