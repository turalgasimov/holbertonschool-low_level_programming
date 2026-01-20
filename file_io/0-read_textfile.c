#include "main.h"

/**
 * read_textfile - entry
 * @filename: filename
 * @letters: num of letters
 * Return: num of letters / 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, i;
	char buff[sizeof(size_t)];
	ssize_t bytesRead, bytesWrit, count;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	bytesRead = read(fd, buff, letters);
	if (bytesRead == -1)
		return (0);

	i = 0;
	count = 0;
	while (buff[i] != '\0')
	{
		bytesWrit = write(1, &buff[i], 1);
		if (bytesWrit == -1)
			return (0);
		count++;
		i++;
	}

	close(fd);
	return (count);
}
