#include <coal/coal.h>

#include <coal/errors/IllegalStateException.h>
#include <coal/errors/NullPointerException.h>

var coal_acquire (var object) {
  if (IS_GARBAGE(object))
    coal_throw(coal_new(coal_errors_IllegalStateException(),
			"%s: tried to acquire an object with a zero reference count",
			__func__));

  return INCREMENT_REFERENCE_COUNT(object);
}

void coal_del (var object) {
  if (object == NULL)
    return;

  DECREMENT_REFERENCE_COUNT(object);

  if (IS_GARBAGE(object))
    free(coal_base_Object_destructor(object));
}

bool coal_instanceof (val object, val class) {
  const class(MetaClass) * current;

  if (class == NULL)
    coal_throw(coal_new(coal_errors_NullPointerException(),
			"%s: null class description",
			__func__));

  current = coal_base_Object_getClass(object);

  if (current == class)
    return true;

  do {
    current = current->super;

    if (current == class)
      return true;
  } while (current != coal_base_Object());

  return false;
}

var coal_new (val _class, ...) {
  const class(MetaClass) * class = _class;
  class(Object) * object;
  va_list ap;

  if (class == NULL)
    coal_throw(coal_new(coal_errors_NullPointerException(),
			"%s: null class description",
			__func__));

  CheckAndThrowMissingException("coal_new", _class, coal_base_MetaClass());

  object->class = class;
  object->reference_count = 1;

  va_start(ap, _class);
  object = coal_base_Object_constructor(object, &ap);
  va_end(ap);

  return object;
}

void coal_throw (var throwable) {
  fprintf(stderr, "exception at %p\n", throwable);
  exit(EXIT_FAILURE);
}
