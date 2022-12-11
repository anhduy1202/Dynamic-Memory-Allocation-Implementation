
// GLOBAL: free_blocks_list: List (Array) of free blocks of memory (can be
// array, LL, MinHEap...)
// (
//   void* block_base;
//   unsigned block_size;
// )
// GLOBAL: allocated_blocks_list: List (Array) of in-use blocks of memory (can
// be array, LL, MinHEap...)
// (
//   void* block_base;
//   unsigned block_size;
// )

// // ASSUME that block list is a fixed size array
// BLOCK_LIST STUFF:

// - ADD ENTRY (base pointer, size)
// if number of entries in list is less than list_size
//    create entry
//    add at end
//    increase number of entries in list
//   return
// return LIST_FULL

// - REMOVE ENTRY (base pointer)
// for each entry in list
//   if entry's base pointer = test_value
//     move all subsequent list entries left by one
//     return
// return: NOT FOUND

// - FIND BY BASE PTR (test_value)
// for each entry in list
//   if entry's base pointer = test_value
//     return this entry
// return: NOT FOUND

// - FIND SIZE GREATER EQUAL THAN (test_size)
// for each entry in list
//   if entry's size value >= test_size
//     return this entry
// return: NOT FOUND

// - DEFRAGMENT
// if list is empty
//     return
// sort list by base_pointer
// current_block = list[0]
// for (ix in 1..block count)
//   if 1 + the end of current_block = list[ix] base pointer
//     // they are adjacent
//     current_block.size += list[ix].size
//     "delete" list[ix]
//   else
//     current_block = list[ix]
