#include <stdio.h>
#include "main.h"

/**
 * main - entry point
 * @argc: num of args
 * @argv: vector of args
 * Return: 0
 */

int main(int argc, __attribute__((unused)) char *argv[])
{
	printf("%d\n", argc - 1);
	return (0);
}
