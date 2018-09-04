#include <stdlib.h>


typedef char DATA;

typedef struct {
    DATA *content;
    int top;
    int max;
} Stack;

typedef  Stack * stp;

stp CreatesStack (int size);
void Resize (stp S, int NewSize);
int StackEmpty (stp S);
int StackPush (DATA newContent, stp S);
DATA StackPop(stp S);
DATA StackTop(stp S);
void DestroyStack(stp S);