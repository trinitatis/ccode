#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 4

void output(int* seq);
int* min(int*seq);
int* max(int*seq);
void swap(int* a, int* b);

int main(void) {
    int error = 0;
    int len = CHUNK_SIZE;
    int* seq = (int*)malloc(sizeof(int) * len);

    int item = 0;
    int idx = 0;
    char ch = 0;

    while ( item != -1 ) {
        if ( scanf("%d%c", &item, &ch) != 2 || (item != -1 && ch != ' ') ) {
            error = 1;  // bad input
            break;
        }
        seq[idx] = item;
        if (idx + 1 > len) {
            len += CHUNK_SIZE;
            if  ( !(seq = realloc(seq, len * sizeof(int))) ) {
               error = 1;  // bad alocation
               break;
            }
        }
        idx++;
    }

    if (error) {
        printf("ERROR..\n");
    } else {
        swap(min(seq), max(seq));
        output(seq);
    }
      
    free(seq);

    return 0;
}

void output(int* seq) {
    for (int* ptr = seq; *ptr != -1; ptr++) printf("%d ", *ptr);
}

int* min(int*seq) {
    int* ptr_min = seq;
    int min = *ptr_min;

    for (int* ptr = seq; *ptr != -1; ptr++) {
        if (*ptr < min) {
            min = *ptr;
            ptr_min = ptr;
        }
    }
    return ptr_min;
}

int* max(int*seq) {
    int* ptr_max = seq;
    int max = *ptr_max;

    for (int* ptr = seq; *ptr != -1; ptr++) {
        if (*ptr > max) {
            max = *ptr;
            ptr_max = ptr;
        }
    }
    return ptr_max;
}

void swap(int* a, int* b) {
    int tmp = *a;

    *a = *b;
    *b = tmp;
}