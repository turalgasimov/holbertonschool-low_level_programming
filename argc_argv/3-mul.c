#include <stdio.h>
#include "main.h"

/**
 * main - entry point
 * @argc: num of args
 * @argv: vector of args
 * Return: 0
 */

int main(int argc, int *argv[])
{
	if (argc != 3)
		printf("Error\n");

	printf("%d\n", argv[1] * argv[2]);

	return (0);
}
