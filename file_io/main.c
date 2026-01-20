#include "main.h"

int main()
{
	const char *filename = "test.txt";
	char *text_content = "Saam Eekim";

	int res = append_text_to_file(filename, text_content);
	printf("%d\n", res);

	return (0);
}