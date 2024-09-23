#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 4

void input(int* seq, int* len, int* error);
void output(int* seq);

int main(void) {
    int error = 0;
    int len = CHUNK_SIZE;
    int* seq = (int*)malloc(sizeof(int) * len);

    input(seq, &len, &error);
    if (error) {
        printf("ERROR\n");
    } else {
        output(seq);
    }
      
    //free(seq);

    return 0;
}

void input(int* seq, int* len, int* error) {
    int item = 0;
    int idx = 0;
    char ch = 0;

    while ( item != -1 ) {
        if ( scanf("%d%c", &item, &ch) != 2 || (item != -1 && ch != ' ') ) {
            *error = 1;  // bad input
            break;
        }
        printf("idx:%d, len:%d\n", idx, *len);
        seq[idx] = item;
        if (idx + 1 > *len) {
            *len += CHUNK_SIZE;
            if  ( (seq = realloc(seq, *len * sizeof(int))) ) {
                printf("seq[%d]==%d\n", idx, seq[idx]);
            } else {
                *error = 1;
                break;
            }
        }
        idx++;
    }
 
}

void output(int* seq) {
    for (;*seq != -1; seq++) printf("%d ", *seq);
}