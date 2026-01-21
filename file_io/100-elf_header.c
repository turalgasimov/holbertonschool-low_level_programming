#include "main.h"

/**
 * swap_uint16 - swaps endianness of uint16
 * @val: value to swap
 * Return: swapped value
 */
uint16_t swap_uint16(uint16_t val)
{
	return ((val << 8) | (val >> 8));
}

/**
 * swap_uint32 - swaps endianness of uint32
 * @val: value to swap
 * Return: swapped value
 */
uint32_t swap_uint32(uint32_t val)
{
	return (((val << 24) & 0xff000000) |
	       ((val << 8)  & 0x00ff0000) |
	       ((val >> 8)  & 0x0000ff00) |
	       ((val >> 24) & 0x000000ff));
}

/**
 * swap_uint64 - swaps endianness of uint64
 * @val: value to swap
 * Return: swapped value
 */
uint64_t swap_uint64(uint64_t val)
{
	return (((val << 56) & 0xff00000000000000ULL) |
	       ((val << 40) & 0x00ff000000000000ULL) |
	       ((val << 24) & 0x0000ff0000000000ULL) |
	       ((val << 8)  & 0x000000ff00000000ULL) |
	       ((val >> 8)  & 0x00000000ff000000ULL) |
	       ((val >> 24) & 0x0000000000ff0000ULL) |
	       ((val >> 40) & 0x000000000000ff00ULL) |
	       ((val >> 56) & 0x00000000000000ffULL));
}

/**
 * display_error - entry
 * @message: string
 */
void display_error(const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(98);
}

/**
 * print_magic - prints the magic bytes
 * @elf_header: pointer to ELF header
 */
void print_magic(Elf64_Ehdr *elf_header)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", elf_header->e_ident[i], i < EI_NIDENT - 1 ? " " : "\n");
}

/**
 * print_class - prints the class
 * @elf_header: pointer to ELF header
 */
void print_class(Elf64_Ehdr *elf_header)
{
	printf("  Class:                             ");
	switch (elf_header->e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_header->e_ident[EI_CLASS]);
	}
}

/**
 * print_data - prints the data encoding
 * @elf_header: pointer to ELF header
 */
void print_data(Elf64_Ehdr *elf_header)
{
	printf("  Data:                              ");
	switch (elf_header->e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_header->e_ident[EI_DATA]);
	}
}

/**
 * print_version - prints the version
 * @elf_header: pointer to ELF header
 */
void print_version(Elf64_Ehdr *elf_header)
{
	printf("  Version:                           %d",
		elf_header->e_ident[EI_VERSION]);
	if (elf_header->e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * print_osabi - prints the OS/ABI
 * @elf_header: pointer to ELF header
 */
void print_osabi(Elf64_Ehdr *elf_header)
{
	printf("  OS/ABI:                            ");
	switch (elf_header->e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_header->e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - prints the ABI version
 * @elf_header: pointer to ELF header
 */
void print_abi(Elf64_Ehdr *elf_header)
{
	printf("  ABI Version:                       %d\n",
		elf_header->e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints the type
 * @elf_header: pointer to ELF header
 */
void print_type(Elf64_Ehdr *elf_header)
{
	printf("  Type:                              ");
	switch (elf_header->e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_header->e_type);
	}
}

/**
 * print_entry - prints the entry point address
 * @elf_header: pointer to ELF header
 */
void print_entry(Elf64_Ehdr *elf_header)
{
	printf("  Entry point address:               ");
	if (elf_header->e_ident[EI_CLASS] == ELFCLASS32)
		printf("0x%x\n", (unsigned int)elf_header->e_entry);
	else
		printf("0x%lx\n", (unsigned long)elf_header->e_entry);
}

/**
 * display_elf_header - entry
 * @filename: string
 */
void display_elf_header(const char *filename)
{
	int fd, needs_swap = 0;
	Elf64_Ehdr elf_header;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		display_error("Failed to open the file");
	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
		display_error("Failed to read the ELF header");
	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
	    elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
	    elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
	    elf_header.e_ident[EI_MAG3] != ELFMAG3)
		display_error("Not a valid ELF file");
#if __BYTE_ORDER == __LITTLE_ENDIAN
	if (elf_header.e_ident[EI_DATA] == ELFDATA2MSB)
		needs_swap = 1;
#elif __BYTE_ORDER == __BIG_ENDIAN
	if (elf_header.e_ident[EI_DATA] == ELFDATA2LSB)
		needs_swap = 1;
#endif
	if (needs_swap)
	{
		elf_header.e_type = swap_uint16(elf_header.e_type);
		elf_header.e_entry = swap_uint64(elf_header.e_entry);
	}
	/* Display the required information */
	printf("ELF Header:\n");
	print_magic(&elf_header);
	print_class(&elf_header);
	print_data(&elf_header);
	print_version(&elf_header);
	print_osabi(&elf_header);
	print_abi(&elf_header);
	print_type(&elf_header);
	print_entry(&elf_header);
	close(fd);
}

/**
 * main - entry
 * @argc: count
 * @argv: list
 * Return: int
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
		display_error("Usage: elf_header elf_filename");

	display_elf_header(argv[1]);
	return (0);
}
