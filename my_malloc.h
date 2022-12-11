#include <stdlib.h>

#ifndef MY_MALLOC
#define MY_MALLOC

void *my_malloc(size_t requested_size);
void my_free(void *base_pointer);
void *my_realloc(void *base_pointer, size_t new_size);

#endif