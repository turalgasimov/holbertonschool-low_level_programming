#include "main.h"

/**
 * main - entry
 * @argc: count
 * @argv: list
 * Return: 97/98/99/100
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to, fd_out;
	ssize_t bytesRead, bytesWrit;
	char *file_from, *file_to, buff[1024];

	if (argc != 3)
	{
		printf("Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = argv[1];
	file_to = argv[2];

	fd_from = open(file_from, O_RDONLY);
	bytesRead = read(fd_from, buff, sizeof(buff));
	if (fd_from == -1 || bytesRead == -1)
	{
		dprintf(fd_from, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	fd_to = open(file_to, O_RDWR | O_CREAT | O_TRUNC, 0664);
	bytesWrit = write(fd_to, buff, sizeof(buff));
	if (fd_to == -1 || bytesWrit == -1)
	{
		dprintf(fd_to, "Error: Can't write to %s", file_to);
		exit(99);
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		fd_out = (fd_from == -1) ? fd_from : fd_to;
		dprintf(fd_out, "Error: Can't close fd %d", fd_out);
	}

	return (0);
}
