#include <stdlib.h>

#ifndef MY_MALLOC
#define MY_MALLOC

void* my_malloc(size_t requested_size);
void my_free( void* base_pointer );

#endif