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
        printf("\nMAIN:");output(seq);
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
        seq[idx] = item;
        if (idx + 1 > *len) {
            *len += CHUNK_SIZE;
            if  ( !(seq = realloc(seq, *len * sizeof(int))) ) {
               *error = 1;
                break;
            }
        }
        idx++;
    }
    printf("INPUT:");output(seq);
 
}

void output(int* seq) {
    for (int* ptr = seq; *ptr != -1; ptr++) printf("%d ", *ptr);
}