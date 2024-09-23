#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 2

void input(int* seq);
void output(int* seq);

int main(void) {
    int* seq = (int*)calloc(INITIAL_SIZE, sizeof(int));

    input(seq);
    output(seq);

    free(seq);

    return 0;
}


void output(int* seq) {
    printf("OUTPUT: ");
    for (int* ptr = seq; *ptr != -1; ptr++) printf("%d", *ptr);
}

void input(int* seq) {
    int size = INITIAL_SIZE;
    char ch = 0;
    int item = 0;
    int idx = 0;
    int* new = NULL;

    while (item != -1) {
        scanf("%d%c", &item, &ch);
        seq[idx] = item;
        if (idx + 1 == size) {
            size++;
            new = (int*)realloc(seq, sizeof(seq) + sizeof(int));
            /* For test */
            printf("idx:%d size:%d sizeof:%d\t", idx, size, (int)sizeof(new)); for (int i = 0; i <= idx; i++) printf("%d", seq[i]); printf("\n");
            seq = new;
        }
        idx++;
    }
}