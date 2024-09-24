#ifndef INPUT_SEQUENCE_H
#define INPUT_SEQUENCE_H

typedef char I_type;

typedef struct Sequence_tag {
    int     size;
    I_type* seq;  
} Sequence;

Sequence input(void);
void output(Sequence seq);

#endif