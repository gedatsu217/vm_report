#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

const int x = 0;

int main(int argc, char* argv[]) {
  printf("x addr: %p\n", &x);
  return 0;
}
