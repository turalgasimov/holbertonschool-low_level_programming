#include "main.h"

int main()
{
	const char *filename = "main.h";
	size_t letters = 100;

	ssize_t res = read_textfile(filename, letters);
	printf("\n-----------x\nPrinted: %zd|\n-----------x\n", res);
	return (0);
}