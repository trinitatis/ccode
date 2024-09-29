/*
** Monoid here
**
**      type:       char (*)[10]
**      functor:    strcat()
**      identity:   ""
**
*/
#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef char T[10];
typedef char* (*Functor)(char* restrict, const char* restrict);

int main(void) {
    Functor f = strcat;
    T identity = "";
    T x = "test";
    T y = "123";
    T z = "456";

    assert(x == f(x, identity));
    assert(f(f(x, y), z) == f(x, f(y, z)));

    return 0;
}