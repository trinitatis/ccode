#include <stdio.h>
#include <stdlib.h>

#include "input_sequence.h"

#define INITIAL_SIZE 2

Sequence input(void) {
    Sequence result;
    I_type* inp = (I_type*)calloc(INITIAL_SIZE, sizeof(I_type));
    I_type* new = NULL;
    I_type item = 0;
    I_type sentinel = '\n';  // last element of sequence
    int current_size = INITIAL_SIZE;
    int error = 0;

    int idx = 0;
    while (item != sentinel) {
        if (scanf("%c", &item) != 1) {
            error = 1;
            break;
        }
        inp[idx] = item;
        if (idx + 1 == current_size) {
            current_size++;
            new = (I_type*)realloc(inp, sizeof(I_type) * current_size);
            if (new) {
                inp = new;
            } else {
                error = 2;
                break;
            }
        }
        idx++;
    }
    if (error == 1) {
        printf("ERROR: Bad input ..");
        free(inp);
        inp = NULL;
    }
    if (error == 2) {
        printf("ERROR: Out of memory ..");
    }
    result.size = --idx;
    result.seq = inp;
    return result;
}