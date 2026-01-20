#include "main.h"

/**
 * check_elf - entry
 * @e_ident: var to check
 */

void check_elf(unsigned char *e_ident)
{
	if (e_ident[EI_MAG0] != ELFMAG0 ||
	    e_ident[EI_MAG1] != ELFMAG1 ||
	    e_ident[EI_MAG2] != ELFMAG2 ||
	    e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

/**
 * print_magic - entry
 * @e_ident: var to check
 */

void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", e_ident[i]);
	printf("\n");
}

/**
 * print_class - entry
 * @e_ident: var to check
 */

void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else
		printf("Invalid class\n");
}

/**
 * print_data - entry
 * @e_ident: var to check
 */

void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("Invalid data encoding\n");
}

/**
 * print_version - entry
 * @e_ident: var to check
 */

void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d (current)\n",
	       e_ident[EI_VERSION]);
}

/**
 * print_osabi - entry
 * @e_ident: var to check
 */

void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
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
 * @e_ident: var to check
 */

void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
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
	ssize_t r;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}

	r = read(fd, &header, sizeof(header));
	if (r != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		close(fd);
		exit(98);
	}

	check_elf(header.e_ident);

	printf("ELF Header:\n");
	print_magic(header.e_ident);
	print_class(header.e_ident);
	print_data(header.e_ident);
	print_version(header.e_ident);
	print_osabi(header.e_ident);
	print_abi(header.e_ident);
	print_type(&header);
	print_entry(&header);

	close(fd);
	return (0);
}
