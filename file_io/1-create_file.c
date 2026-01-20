#include "main.h"

/**
 * create_file - entry
 * @filename: filename
 * @letters: num of letters
 * Return: num of letters / 0
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytesWrit;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		bytesWrit = write(fd, text_content, strlen(text_content));
		if (bytesWrit == -1)
			return (-1);
	}

	close(fd);
	return (1);
}
