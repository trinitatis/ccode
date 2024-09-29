I am dealing with the concept of **monoid** now.

A **monoid** is just a *function* that performs an *associative binary operation*
on arguments of a certain type.

An *identity* element is defined such that performing the operation on the identity as one of the arguments returns the other argument.
That's all.

Here I tried to create a monoid for strings.
I also try *to prove* that it is a monoid:
 - сhecking the associativity of an operation;
 - сhecking that a certain identity element works as expected.