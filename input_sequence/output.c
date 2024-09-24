#include <stdio.h>
#include "input_sequence.h"

void output(Sequence seq) {
    printf("Size: %d\n", seq.size);
    for (I_type* ptr = seq.seq; ptr - seq.seq < seq.size; ptr++)
        printf("%c", *ptr);
}