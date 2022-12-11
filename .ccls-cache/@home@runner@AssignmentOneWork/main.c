#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_NUMBER_OF_ALLOCS 10
#define MAX_SIZE_REQUESTED 1024

int main(int argc, char* argv[]) {
  
  // first param is number of text mallocs. Default if it's not specfied
  int num_allocs = (argc>1)? atoi(argv[1]) : DEFAULT_NUMBER_OF_ALLOCS;

  void** test_alloced_blocks = malloc(sizeof(void*) * num_allocs);
  
  for (int ix=0; ix<num_allocs; ix++) {
    // note that 0 (zero) IS a valid block size!
    unsigned block_size = rand() % MAX_SIZE_REQUESTED;

    test_alloced_blocks[ix] = malloc(block_size);
    printf("%3d: %5d bytes, %p - %p\n",ix,block_size,test_alloced_blocks[ix],test_alloced_blocks[ix]+block_size-1);
  }

 for (int ix=0; ix<num_allocs; ix++) {
    free(test_alloced_blocks[ix]);
    printf("%3d: freeing %p\n",ix,test_alloced_blocks[ix]);
  }
  
  return 0;
}