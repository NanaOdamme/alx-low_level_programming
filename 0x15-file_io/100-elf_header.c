#include "main.h"
#include <elf.h>

/**
 * print_error - Print error message to stderr and exit with status code 98.
 * @error_message: The error message to display.
 */
void print_error(const char *error_message) {
	dprintf(STDERR_FILENO, "%s\n", error_message);
	exit(98);
}

/**
 * print_elf_header_info - Print information contained in the ELF header.
 * @elf_header: The ELF header structure to display information from.
 */
void print_elf_header_info(Elf64_Ehdr elf_header)
{
	int i;
    const char *class_strings[] = {
        "None",
        "ELF32",
        "ELF64",
    };
    const char *data_strings[] = {
        "None",
        "2's complement, little-endian",
        "2's complement, big-endian",
    };
    const char *osabi_strings[] = {
        "UNIX System V ABI",
        "HP-UX",
        "NetBSD",
        "Linux",
        "Solaris",
        "AIX",
        "FreeBSD",
        "Tru64 UNIX",
        "ARM architecture",
        "Stand-alone (embedded) application",
    };
    const char *type_strings[] = {
        "NONE (Unknown type)",
        "REL (Relocatable file)",
        "EXEC (Executable file)",
        "DYN (Shared object file)",
        "CORE (Core file)",
    };
    printf("Magic:   ");
    i = 0;
    while (i < EI_NIDENT)
        printf("%02x ", elf_header.e_ident[i]);
    printf("\n");
    printf("Class:                             %s\n",
	class_strings[elf_header.e_ident[EI_CLASS]]);
    printf("Data:                              %s\n",
	data_strings[elf_header.e_ident[EI_DATA]]);
    printf("Version:                           %d\n", 
	elf_header.e_ident[EI_VERSION]);
    printf("OS/ABI:                            %s\n", 
	osabi_strings[elf_header.e_ident[EI_OSABI]]);
    printf("ABI Version:                       %d\n", 
	elf_header.e_ident[EI_ABIVERSION]);
    printf("Type:                              %s\n", 
	type_strings[elf_header.e_type]);
    printf("Entry point address:               %#lx\n", 
	(unsigned long)elf_header.e_entry);
    i++;
}
/**
 * main - Copy the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 98 on incorrect number of arguments,
 *         98 on file opening error, 98 on ELF header reading error,
 *         98 on non-ELF file error.
 */
int main(int argc, char *argv[]) {
	Elf64_Ehdr elf_header;
	ssize_t bytes_read;
	int fd;
	const char *filename;

    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    filename = argv[1];
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        print_error("Error: Can't open the file");
    }

    bytes_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));
    if (bytes_read != sizeof(Elf64_Ehdr)) {
        close(fd);
        print_error("Error: Can't read the ELF header");
    }

    if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
        elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
        elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
        elf_header.e_ident[EI_MAG3] != ELFMAG3) {
        close(fd);
        print_error("Error: Not an ELF file");
    }

    print_elf_header_info(elf_header);

    close(fd);
    return 0;
}

