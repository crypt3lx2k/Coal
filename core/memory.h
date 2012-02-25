#ifndef COAL_CORE_MEMORY_H__
#define COAL_CORE_MEMORY_H__

#ifndef COAL_CORE_IMPLEMENTATION_H__
# error "Never include <coal/core/memory.h> directly; use <coal/core/implementation.h> instead."
#endif

/**
 * coal_core_malloc
 * See malloc (3).
 * The purpose of this function
 * is to throw an exception in the event
 * that malloc (3) fails.
 *
 * @param  (size_t) number of bytes to allocate
 * @return (void *) pointer to allocated memory
 */
cfundecl__ (void * coal_core_malloc (size_t size)) __attribute__ ((malloc));

/**
 * coal_core_realloc
 * See realloc (3).
 * See coal_core_malloc.
 *
 * @param  (void *) pointer to memory block
 * @param  (size_t) size in bytes of new block
 * @return (void *) reallocated block
 */
cfundecl__ (void * coal_core_realloc (void * ptr, size_t size));

#endif /* COAL_CORE_MEMORY_H__ */
