#ifndef COAL_COAL_H
#define COAL_COAL_H

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

/* this defines coal_cfunspec, any attributes
   and the var and val datatypes. */
#include <coal/private/cdefs.h>

/* Functions */

/**
 * coal_acquire
 *
 * Indicates to the implementation that an object has gotten
 * yet another owner.
 *
 * @param  (var) object to own
 * @return (var) object that was passed
 */
coal_cfunspec var coal_acquire (var object);

/**
 * coal_construct
 *
 * This is the equivalent of new for objects that have been
 * pre-allocated, typically on the stack. Using this function
 * to allocate a singleton type object might result in
 * unexpected or undefined behavior.
 *
 * See new().
 *
 * @param  (val) class to be instantiated
 * @param  (var) object with allocated space
 * @param  (...) arguments for the class constructor
 * @return (var) new instance of class
 */
coal_cfunspec var coal_construct (val class, var object, ...);

/**
 * coal_del
 *
 * Indicates to the implementation that an object is no
 * longer owned.
 *
 * @param (var) object to discard
 */
coal_cfunspec void coal_del (var object);

/**
 * coal_instanceof
 *
 * Determines if the object is an instance of class or any of
 * its subclasses. This means that if an object "o" is an
 * instance of a class "klass", then coal_instanceof(o, k)
 * will return true if klass is a subclass of k.
 *
 * coal_instanceof(non_null, object()) - true
 *
 * @param  (val) object to check type of
 * @param  (class) type to check against
 * @return (bool) true if object is of type class
 */
coal_cfunspec bool coal_instanceof (val object, val class);

/**
 * coal_new
 *
 * Creates and returns a new instance of a class.
 *
 * @param  (val) class to be instantiated
 * @param  (...) arguments for the class constructor
 * @return (var) new instance of class
 */
coal_cfunspec var coal_new (val class, ...) coal_funattr_malloc;

/**
 * coal_throw
 *
 * Throws an exception.
 * Currently everything is a valid exception.
 *
 * Note that this function does not return.
 *
 * @param (var) throwable object
 */
noreturn coal_cfunspec void coal_throw (var object);

/* Functions - end */

#ifdef COAL_NAMESPACE_POLLUTE
# define acquire(o)           coal_acquire(o)
# define construct(c, o, ...) coal_construct(c, o, __VA_ARGS__)
# define del(o)               coal_del(o)
# define instanceof(o, c)     coal_instanceof(o, c)
# define new(c, ...)          coal_new(c, __VA_ARGS__)
# define throw(o)             coal_throw(o)
#endif

#endif /* COAL_COAL_H */
