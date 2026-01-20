#include "main.h"

int main()
{
	const char *filename = "main.h";
	size_t letters = 15;

	ssize_t res = read_textfile(filename, letters);
	printf("-----------x\nPrinted: %zd|\n-----------x\n", res);
	return (0);
}