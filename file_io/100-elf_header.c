#include "main.h"

/**
 * error_exit - prints error message and exits with code 98
 * @msg: error message to print
 */
void error_exit(const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * check_elf - checks whether a file is an ELF file
 * @e: pointer to ELF identification bytes
 */
void check_elf(unsigned char *e)
{
	if (e[EI_MAG0] != ELFMAG0 ||
	    e[EI_MAG1] != ELFMAG1 ||
	    e[EI_MAG2] != ELFMAG2 ||
	    e[EI_MAG3] != ELFMAG3)
		error_exit("Error: Not an ELF file");
}

/**
 * print_magic - prints ELF magic bytes
 * @e: pointer to ELF identification bytes
 */
void print_magic(unsigned char *e)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x", e[i]);
	printf("\n");
}

/**
 * print_class - prints ELF class
 * @e: pointer to ELF identification bytes
 */
void print_class(unsigned char *e)
{
	printf("  Class:                             ");
	if (e[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (e[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("Invalid class\n");
}

/**
 * print_data - prints ELF data encoding
 * @e: pointer to ELF identification bytes
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
 * print_version - prints ELF version
 * @e: pointer to ELF identification bytes
 */
void print_version(unsigned char *e)
{
	printf("  Version:                           %d (current)\n",
	       e[EI_VERSION]);
}

/**
 * print_osabi - prints ELF OS/ABI
 * @e: pointer to ELF identification bytes
 */
void print_osabi(unsigned char *e)
{
	printf("  OS/ABI:                            ");
	if (e[EI_OSABI] == ELFOSABI_SYSV)
		printf("UNIX - System V\n");
	else if (e[EI_OSABI] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");
	else if (e[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else
		printf("Other\n");
}

/**
 * print_abi - prints ELF ABI version
 * @e: pointer to ELF identification bytes
 */
void print_abi(unsigned char *e)
{
	printf("  ABI Version:                       %d\n",
	       e[EI_ABIVERSION]);
}

/**
 * print_type - prints ELF file type
 * @type: ELF file type
 */
void print_type(uint16_t type)
{
	printf("  Type:                              ");
	if (type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (type == ET_REL)
		printf("REL (Relocatable file)\n");
	else
		printf("Other\n");
}

/**
 * print_entry - prints ELF entry point address
 * @entry: entry point address
 */
void print_entry(unsigned long entry)
{
	printf("  Entry point address:               0x%lx\n",
	       entry);
}

/**
 * main - displays ELF header information
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on failure
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
