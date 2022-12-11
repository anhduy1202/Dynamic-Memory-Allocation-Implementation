
#include <stdlib.h>

typedef struct memory_block {
  void *block_base;
  size_t block_size;
} Block;

typedef struct block_list {
  int length;
  Block *blocks;
} BlockEntry;

// ASSUME that block list is a fixed size array

// BLOCK_LIST STUFF:
// - ADD ENTRY (base pointer, size)
void *add_entry(void *base_pointer, Block block);
void *remove_entry(void *base_pointer);
void *order_array(BlockEntry *block_list);
// - REMOVE ENTRY (base pointer)
// - FIND BY BASE PTR (test_value)
// - FIND SIZE GREATER EQUAL THAN (test_size)
// - DEFRAGMENT
