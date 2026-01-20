#include "main.h"

/**
 * append_text_to_file - entry
 * @filename: filename
 * @text_content: string
 * Return: 1/-1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytesWrit;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_APPEND);
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
