#include "main.h"

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{

	FILE *file;
	char *buffer;
	ssize_t _read;
	ssize_t _write;


	if (filename == NULL)
		return (0);

	file = fopen(filename, "r");

	if (file == NULL)
		return (0);

	buffer = malloc(letters);

	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}

	_read = fread(buffer, 1, letters, file);

	fclose(file);

	if (_read <= 0)
	{
		free(buffer);
		return (0);
	}

		 _write = write(STDOUT_FILENO, buffer, _read);

		free(buffer);
		if (_write != _read)
			return (0);

		return (_write);
	}
