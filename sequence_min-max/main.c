#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 8

void input(int* seq, int* error);
void output(int* seq);

int main(void) {
    int error = 0;
    int* seq = malloc(sizeof(int) * CHUNK_SIZE);
    int len = sizeof(*seq) / sizeof(int);

    printf("len: %d\n", len);

    input(seq, &error);
    if (error) {
        printf("ERROR\n");
    } else {
        output(seq);
    }
      
    free(seq);

    return 0;
}

void input(int* seq, int* error) {
    int item = 0;
    int idx = 0;
    char ch = 0;

    while ( item != -1 ) {
        if ( scanf("%d%c", &item, &ch) != 2 || (item != -1 && ch != ' ') ) {
            *error = 1;  // bad input
            break;
        }
        seq[idx++] = item;
    }
}

void output(int* seq) {
    for (;*seq != -1; seq++) printf("%d ", *seq);
}