#include "main.h"

/**
 * read_textfile - entry
 * @filename: filename
 * @letters: num of letters
 * Return: num of letters / 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buff;
	ssize_t bytesRead, bytesWrit;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		close(fd);
		return (0);
	}

	buff = (char *)malloc(letters);
	if (buff == NULL)
	{
		free(buff);
		close(fd);
		return (0);
	}

	bytesRead = read(fd, buff, letters);
	if (bytesRead == -1) {
		close(fd);
		return (0);
	}

	bytesWrit = write(STDOUT_FILENO, buff, bytesRead);
	if (bytesWrit == -1) {
		close(fd);
		return (0);
	}

	close(fd);
	return (bytesRead);
}
