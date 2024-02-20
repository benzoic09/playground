#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: A pointer to the text to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file_des;
	ssize_t _write;
	ssize_t len = 0;

	if (filename == NULL)
		return (-1);

	file_des = open(filename, O_WRONLY | O_APPEND);
	if (file_des == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
			len++;
	}

	_write = write(file_des, text_content, len);
	if (_write == -1)
	{
		close(file_des);
		return (-1);
	}

	close(file_des);
	return (1);
}
