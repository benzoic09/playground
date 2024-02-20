#include "main.h"
#include <fcntl.h>
#include <string.h>

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 */

int create_file(const char *filename, char *text_content)
{
	int file_des;
	ssize_t _write;
	ssize_t len = 0;

	if (filename == NULL)
		return (-1);

	file_des = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file_des == -1)
	return (-1);

	if (text_content != NULL)
	{

		while (text_content[len] != '\0')
			len++;
	}

		_write = write(file_des, text_content, len);
		if (_write == -1 || file_des == -1)
			return (-1);

		close(file_des);
		return (1);
}


