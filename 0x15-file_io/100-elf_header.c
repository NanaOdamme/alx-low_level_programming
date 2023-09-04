#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

#define ELF_MAGIC_SIZE 4

void print_error(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(98);
}

void print_elf_header_info(Elf64_Ehdr *elf_header){
	int i;
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < ELF_MAGIC_SIZE; i++) {
        printf("%02x ", elf_header->e_ident[i]);
    }
    printf("\n");

    printf("  Class:                             %s\n", elf_header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf("  Data:                              %s\n", elf_header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", elf_header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (elf_header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("UNIX - Solaris\n");
            break;
        default:
            printf("<unknown: %d>\n", elf_header->e_ident[EI_OSABI]);
            break;
    }
    printf("  ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (elf_header->e_type) {
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        default:
            printf("0x%x\n", elf_header->e_type);
            break;
    }
    printf("  Entry point address:               0x%lx\n", (unsigned long)elf_header->e_entry);
}

int main(int argc, char *argv[]) {
	Elf64_Ehdr elf_header;
	const char *filename = argv[1];
    int fd = open(filename, O_RDONLY);

    if (argc != 2) {

        print_error("Usage: elf_header elf_filename");
    }
    if (fd == -1) {
        print_error("Error opening file");
    }

    if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header)) {
        print_error("Error reading ELF header");
    }

    if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0) {
        print_error("Not an ELF file");
    }

    print_elf_header_info(&elf_header);

    close(fd);
    return 0;
}

