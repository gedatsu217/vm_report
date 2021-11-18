#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <elf.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    fprintf(stderr, "invalid args\n");
    return 0;
  }
  int fd = open(argv[1], O_RDWR);
  struct stat stat_buf;
  fstat(fd, &stat_buf);
  Elf64_Ehdr* ehdr = mmap(NULL, stat_buf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
  ehdr->e_ident[3] = 'T';
  printf("%#x\n", ehdr->e_ident[0]);
  printf("%c\n", ehdr->e_ident[1]);
  printf("%c\n", ehdr->e_ident[2]);
  printf("%c\n", ehdr->e_ident[3]);
  munmap(ehdr, stat_buf.st_size);
  close(fd);
  return 0;
}
