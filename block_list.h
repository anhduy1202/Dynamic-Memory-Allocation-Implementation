
#include <stdlib.h>

typedef struct block_list {
  void *block_base;
  size_t block_size;
} BlockEntry, *BlockList;

// ASSUME that block list is a fixed size array
// BLOCK_LIST STUFF:

// - ADD ENTRY (base pointer, size)
// - REMOVE ENTRY (base pointer)
// - FIND BY BASE PTR (test_value)
// - FIND SIZE GREATER EQUAL THAN (test_size)
// - DEFRAGMENT
