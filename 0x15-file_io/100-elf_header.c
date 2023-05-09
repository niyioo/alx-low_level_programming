#include "main.h"
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_error - print error message
 * @msg: error message
 */

void print_error(char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * print-header - print header file
 * @hdr: header message
 */

void print_header(Elf64_Ehdr *hdr)
{
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", hdr->e_ident[i]);
	}
	printf("\n");
	printf("  Class:                             %s\n", hdr->e_ident[EI_CLASS]
			== ELFCLASS64 ? "ELF64" : "ELF32");
	printf("  Data:                              %s\n", hdr->e_ident[EI_DATA]
			== ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d%s\n", hdr->e_ident[EI_VERSION],
			hdr->e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");
	printf("  OS/ABI:                            ");
	switch (hdr->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - GNU\n");
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
			printf("<unknown: %x>\n", hdr->e_ident[EI_OSABI]);
	}
	printf("  ABI Version:                       %d\n", hdr->e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	switch (hdr->e_type)
	{
		case ET_NONE:
			printf("NONE (No file type)\n");
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
			printf("<unknown: %x>\n", hdr->e_type);
	}
	printf("  Entry point address:               %lx\n", hdr->e_entry);
	printf("\n");
}

/**
 * main - displays the information contained in the ELF header at the start
 *        of an ELF file.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: If successful - EXIT_SUCCESS.
 * If failure - EXIT_FAILURE.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}
	int fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		print_error("Error: Couldn't open file");
	}

	Elf64_Ehdr header;

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: Cannot read from file %s\n", filename);
		close(fd);
		exit(98);
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", filename);
		close(fd);
		exit(98);
	}

	printf("Magic:   %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
			header.e_ident[EI_MAG0], header.e_ident[EI_MAG1], header.e_ident[EI_MAG2], header.e_ident[EI_MAG3],
			header.e_ident[EI_MAG4], header.e_ident[EI_MAG5], header.e_ident[EI_MAG6], header.e_ident[EI_MAG7],
			header.e_ident[EI_MAG8], header.e_ident[EI_MAG9], header.e_ident[EI_MAG10], header.e_ident[EI_MAG11],
			header.e_ident[EI_MAG12]);

	printf("Class:                             %s\n", class[header.e_ident[EI_CLASS]]);

	printf("Data:                              %s\n", data[header.e_ident[EI_DATA]]);

	printf("Version:                           %d%s\n", header.e_ident[EI_VERSION], header.e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");

	printf("OS/ABI:                            %s\n", osabi[header.e_ident[EI_OSABI]]);

	printf("ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);

	printf("Type:                              %s\n", type[header.e_type]);

	printf("Entry point address:               0x%lx\n", header.e_entry);

	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}

	return (0);
}
