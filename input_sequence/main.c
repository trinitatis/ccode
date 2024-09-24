#include <stdio.h>
#include <stdlib.h>
#include "input_sequence.h"

int main(void) {
    Sequence inp;

    printf("Enter the sequence:\n");
    inp = input();

    output(inp);  // test output

    free(inp.seq);

    return 0;
}