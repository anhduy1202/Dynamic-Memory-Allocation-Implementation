#include <stdio.h>
#include <stdlib.h>

#include "my_malloc.h"

void *my_malloc(size_t requested_size) {
  void *base_pointer = sbrk(0);
  sbrk(requested_size);
  fprintf(stderr, "Called my_malloc with %u returning %p\n", requested_size,
          base_pointer);
  return base_pointer;
}

void my_free(void *base_pointer) {
  void *free_ptr = sbrk(0);
  sbrk(0);
  base_pointer = free_ptr;
  fprintf(stderr, "Called my_free with %p\n", base_pointer);
}

void *my_realloc(void *base_pointer, size_t new_size) {
  void *ptr = sbrk(0);
  sbrk(new_size);
  base_pointer = ptr;
  return base_pointer;
}