I am dealing with the concept of **monoid** now.

A **monoid** is just a *function* that performs an *associative binary operation*
on arguments of a certain type.

An *identity* element is defined such that performing the operation on the identity as one of the arguments returns the other argument.
That's all.

Here I tried to create a monoid for strings.
I also try *to prove* that it is a monoid:
 - сhecking the associativity of an operation;
 - сhecking that a certain identity element works as expected;
 - it's possible to create a new value by combining values ​​using a monoid.

Also I define a Functor type. It's just a function that can map the values. I used the _strcat()_.
And here functor is a _endofunctor_ — a functor that maps values ​​of a certain _category_ to values ​​of the same category.
Here by the concept of _category_ I mean the _type_: built-in type or user-defined type.
```C
char *strcat(char *strDestination, const char *strSource);
```
Since the function `strcat` (as functor) arguments are of the same type as the return value I assume that this is an endofunctor.
