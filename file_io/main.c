#include "main.h"

int main()
{
	const char *filename = "test.txt";
	char *text_content = "Saam Eekim";

	create_file(filename, text_content);

	return (0);
}