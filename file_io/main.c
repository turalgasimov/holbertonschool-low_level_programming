#include "main.h"

int main()
{
	const char *filename = "main.h";
	size_t letters = 8;

	read_textfile(filename, letters);
	printf("\n");
	return (0);
}