#include <stdio.h>
#include <stdlib.h>

#include "my_malloc.h"

void* my_malloc(size_t requested_size)
{
  void* base_pointer = malloc(requested_size);
  fprintf(stderr,"Called my_malloc with %u returning %p\n", requested_size, base_pointer);
  return base_pointer;
}

void my_free( void* base_pointer )
{
  fprintf(stderr,"Called my_free with %p\n", base_pointer);
  free(base_pointer);
}
