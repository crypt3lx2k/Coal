#ifndef __COAL_OBJECT_ORIENTATION_H
#define __COAL_OBJECT_ORIENTATION_H

#ifndef __COAL_IMPLEMENTATION_H
# error "Never include <coal/core/object_orientation.h> directly; use <coal/implementation.h> instead."
#endif

/* the typedef might go away
   so don't rely on it */
#define class(name)		    \
  struct name

#define extends(name) \
  const class(name) name##__

/**
 * INHERIT_METHOD
 * Tags a method for inheritance.
 */
#define INHERIT_METHOD 0

#endif /* __COAL_OBJECT_ORIENTATION_H */
