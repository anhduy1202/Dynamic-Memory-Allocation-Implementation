#include <stdio.h>
#include <stdlib.h>

#include "block_list.h"
#include "my_malloc.h"

#define MB (1024 * 1024)
#define GB (1024 * MB)

#define DEFAULT_NUMBER_OF_ALLOCS 10
#define MAX_SIZE_REQUESTED 1024
#define MALLOC my_malloc
#define FREE my_free

// Define block list, memory block
BlockEntry free_blocks_list;
BlockEntry allocated_blocks_list;

int main(int argc, char *argv[]) {

  // first param is number of text MALLOC(s. Default if it's not specfied
  int num_allocs = (argc > 1) ? atoi(argv[1]) : DEFAULT_NUMBER_OF_ALLOCS;

  void **test_alloced_blocks = MALLOC(sizeof(void *) * num_allocs);

  for (int ix = 0; ix < num_allocs; ix++) {
    // note that 0 (zero) IS a valid block size!
    unsigned block_size = rand() % MAX_SIZE_REQUESTED;
    if (ix == 0) {
      // test that zero-size wqorks correctly
      block_size = 0;
    }

    test_alloced_blocks[ix] = MALLOC(block_size);
    printf("%3d: %5d bytes, %p - %p\n", ix, block_size, test_alloced_blocks[ix],
           test_alloced_blocks[ix] + block_size);
  }

  for (int ix = 0; ix < num_allocs; ix++) {
    FREE(test_alloced_blocks[ix]);
    printf("%3d: FREE(ing) %p\n", ix, test_alloced_blocks[ix]);
  }

  size_t block_size = 1 * MB;
  for (int ix = 0; ix < num_allocs; ix++) {
    void *block = MALLOC(block_size);
    FREE(block);
    printf("%3d: alloced and FREE(d) %15lu bytes chunk %p\n", ix, block_size,
           block);
    block_size *= 8;
  }

  return 0;
}