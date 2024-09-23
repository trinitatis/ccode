#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 8

void input(int* seq, int* error);

int main(void) {
    int error = 0;
    int* seq;
    
    seq = malloc(sizeof(int) * CHUNK_SIZE);

    input(seq, &error);
    
    if (error) printf("ERROR\n");
       
    free(seq);

    return 0;
}


void input(int* seq, int* error) {
    int item = 0;
    int idx = 0;
    char ch = 0;

    while ( item != -1 ) {
        if ( scanf("%d%c", &item, &ch) != 2 || (item != -1 && ch != ' ') ) {
            *error = 1;
            break;
        }
        seq[idx++] = item;
    }
}