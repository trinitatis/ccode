#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 2

int main(void) {
    size_t size = INITIAL_SIZE;
    int* seq = (int*)calloc(size, sizeof(int));
    char ch = 0;
    int item = 0;
    size_t idx = 0;

    while (item != -1) {
    scanf("%d%c", &item, &ch);
     seq[idx] = item;
     if ( idx + 1 == size) {
        size++;
        seq = realloc(seq, size * sizeof(int));
     }
     idx++;
    }

    for (int* ptr = seq; *ptr != -1; ptr++) printf("%d", *ptr);

    free(seq);

    return 0;
}
