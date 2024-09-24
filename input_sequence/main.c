#include <stdio.h>
#include <stdlib.h>
#include "input.h"

int main(void) {
    Sequence inp;

    printf("Enter the sequence:\n");
    inp = input();

    printf("\nSize: %d", inp.size);

    free(inp.seq);

    return 0;
}