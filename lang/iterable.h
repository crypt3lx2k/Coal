#ifndef COAL_LANG_ITERABLE_H__
#define COAL_LANG_ITERABLE_H__

#include <coal/coal.h>

/**
 * coal_lang_iterable
 * Metaclass for iterable objects.
 *
 * @extends coal_lang_metaclass
 * @constructor takes 10 arguments
 * @param (const char *) name of class
 * @param (const class(metaclass) *) super class
 * @param (size_t) size of instances in bytes
 * @param (int (*cmp)(const var, const var)) pointer to comparison function
 * @param (var (*constructor)(var, va_list *)) pointer to constructor
 * @param (var (*destructor)(var)) pointer to destructor
 * @param (bool (*equals)(const var, const var)) pointer to equality function
 * @param (int (*hashCode)(const var)) pointer to hash function
 * @param (var (*toString)(const var)) pointer to string function
 * @param (var (*iterator)(const var)) pointer function that returns an iterator for the object
 */
cfundecl__ (const var coal_lang_iterable (void));

#ifdef LANG_NAMESPACE_POLLUTE
# define iterable coal_lang_iterable
#endif

#endif /* COAL_LANG_ITERABLE_H__ */
