#include "StackArray.h"

stp CreatesStack (int size) //
{
    stp S = malloc( sizeof(Stack) );
    S -> content = malloc ( size * sizeof(DATA));
    S -> top = 0; S -> max = size;
    return S;
}

void Resize (stp S, int NewSize) // 
{
    DATA * New;

    New = malloc(NewSize * sizeof(DATA) );
    for (int i = 0; i <= S -> top; i++)
    {
        New[i] = S -> content [i];
    }
    free (S -> content);
    S -> content =  New;
    S -> max = NewSize;
    New = NULL;
    free(New);
}

int StackEmpty (stp S) //
{ 
    return (S -> top == 0);
}

int StackPush (DATA newContent, stp S) //
{   
    if ( S -> top != S -> max) 
    { 
        S -> content [ S-> top] = newContent;
        S -> top ++;
        return 1;
    }
    else //FullStack
    {
        return 0;
    }
}

DATA StackPop(stp S) //
{
    if ( StackEmpty(S) )
    {
        return -1;
    }
    
    DATA top;
    top =  S -> content[ S -> top -1];
    S -> top --;
    return top;
}


DATA StackTop ( stp S )  //
{
    return (S -> content[S -> top - 1]);
}

void DestroyStack (stp S)
{
    free(S);
}
