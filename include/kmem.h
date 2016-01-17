#ifndef __KMEM_H__
#define __KMEM_H__

#include <common.h>

/*
 * This function provides simple dynamic memory allocation that may be used
 * before any memory management has been initialised. This is useful, because
 * sometimes it is needed to dynamically allocate memory for some data
 * structures that are in use even before virtual memory management is ready.
 * This function does it be pretending that the kernel's .bss section ends
 * further than it originally did. In odred to allocate N bytes of memory, it
 * pushes the pointer to the end of kernel's image by N bytes. This way such
 * dynamically allocated structures are appended to the memory already occupied
 * by kernel data. The extended end of kernel image is stored in
 * km_kernel_bss_end, the physical memory manager will take it into account
 * when started.
 *
 * The returned pointer is word-aligned. The block is filled with 0's.
 */
void* km_early_alloc(size_t size) __attribute__((warn_unused_result));

/* Initializes km subsystem. */
void km_init();

#endif // __KMEM_H__