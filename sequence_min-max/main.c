#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 8

struct Sequence {
    int len;
    int capacity;
    int data[0];
};

void input(struct Sequence* seq, int* error);
void output(struct Sequence* seq);

int main(void) {
    int error = 0;
    struct Sequence* seq = malloc(sizeof(struct Sequence) + sizeof(int) * CHUNK_SIZE);
    seq->len = 0;
    seq->capacity = CHUNK_SIZE;

    input(seq, &error);
    if (error) {
        printf("ERROR\n");
    } else {
        output(seq);
    }
      
    free(seq);

    return 0;
}

void input(struct Sequence* seq, int* error) {
    int item = 0;
    int idx = 0;
    char ch = 0;
    struct Sequence* new;

    while ( item != -1 ) {
        if ( scanf("%d%c", &item, &ch) != 2 || (item != -1 && ch != ' ') ) {
            *error = 1;  // bad input
            break;
        }
        if (seq->len + 1 > seq->capacity) {
            seq->capacity = seq->capacity + CHUNK_SIZE;
            new = realloc(seq, sizeof(struct Sequence) + sizeof(int) * seq->capacity);
            if (new == NULL) {
                *error = 1;  // out of memory
                break;
            }
            seq = new;
        }
        seq->data[idx++] = item;
        seq->len++;
    }
}

void output(struct Sequence* seq) {

    for (int* ptr = seq->data; *ptr != -1; ptr++) {
        printf("%d ", *ptr);
    }
    printf("\nlen: %d; size: %d", seq->len, seq->capacity);
}