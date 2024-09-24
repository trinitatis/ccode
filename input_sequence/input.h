#ifndef INPUT_H
#define INPUT_H

typedef char I_type;

typedef struct Sequence_tag {
    int size;
    I_type* seq;
} Sequence;

Sequence input(void);
// output(I_type* seq);

#endif