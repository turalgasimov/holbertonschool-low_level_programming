#include "main.h"

/**
 * error_exit - entry
 * @msg: msg
 */

void error_exit(const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * check_elf - entry
 * @e_ident: var to check
 */

void check_elf(unsigned char *e_ident)
{
	if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
	e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
		error_exit("Error: Not an ELF file");
}

/**
 * print_magic - entry
 * @e: var to check
 */

void print_magic(unsigned char *e)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", e[i]);
	printf("\n");
}

/**
 * print_class - entry
 * @e: var to check
 */

void print_class(unsigned char *e)
{
	printf("  Class:                             ");

	if (e[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else if (e[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else
		printf("Invalid class\n");
}

/**
 * print_data - entry
 * @e: var to check
 */

void print_data(unsigned char *e)
{
	printf("  Data:                              ");

	if (e[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("Invalid data encoding\n");
}

/**
 * print_version - entry
 * @e: var to check
 */

void print_version(unsigned char *e)
{
	printf("  Version:                           %d (current)\n",
	       e[EI_VERSION]);
}

/**
 * print_osabi - entry
 * @e: var to check
 */

void print_osabi(unsigned char *e)
{
	printf("  OS/ABI:                            ");

	switch (e[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	default:
		printf("Other\n");
	}
}

/**
 * print_abi - entry
 * @e: var to check
 */

void print_abi(unsigned char *e)
{
	printf("  ABI Version:                       %d\n",
	       e[EI_ABIVERSION]);
}

/**
 * print_type - entry
 * @h: var to check
 */

void print_type(Elf64_Ehdr *h)
{
	printf("  Type:                              ");

	if (h->e_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (h->e_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (h->e_type == ET_REL)
		printf("REL (Relocatable file)\n");
	else
		printf("Other\n");
}

/**
 * print_entry - entry
 * @h: var to check
 */

void print_entry(Elf64_Ehdr *h)
{
	printf("  Entry point address:               0x%lx\n",
	       h->e_entry);
}

/**
 * main - entry
 * @argc: count
 * @argv: list
 * Return: int
 */

int main(int argc, char *argv[])
{
	int fd;
	unsigned char ident[EI_NIDENT];
	Elf32_Ehdr h32;
	Elf64_Ehdr h64;

	if (argc != 2)
		error_exit("Usage: elf_header elf_filename");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: Can't open file");
	if (read(fd, ident, EI_NIDENT) != EI_NIDENT)
		error_exit("Error: Can't read file");
	check_elf(ident);

	lseek(fd, 0, SEEK_SET);
	printf("ELF Header:\n");
	print_magic(ident);
	print_class(ident);
	print_data(ident);
	print_version(ident);
	print_osabi(ident);
	print_abi(ident);

	if (ident[EI_CLASS] == ELFCLASS32)
	{
		if (read(fd, &h32, sizeof(h32)) != sizeof(h32))
			error_exit("Error: Can't read file");
		print_type(h32.e_type);
		print_entry(h32.e_entry);
	}
	else
	{
		if (read(fd, &h64, sizeof(h64)) != sizeof(h64))
			error_exit("Error: Can't read file");
		print_type(h64.e_type);
		print_entry(h64.e_entry);
	}

	close(fd);
	return (0);
}
