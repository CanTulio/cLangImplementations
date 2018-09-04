#include "queueArray.h"
#include <stdlib.h>

qup createQueue (int size)
{
    qup Q;
    Q -> start = Q -> end = 0;
    Q -> max = size;
    Q -> v = malloc(size * sizeof (DATA) );
    return Q;
}

void insertInQueue (qup Q, DATA content)
{
    if (  ( (Q -> end + 1) % Q -> max ) == Q -> start ) 
    {
        resize (Q, 2 * Q -> max);
    }

    Q -> v [ Q-> end] = content;
    Q -> end = (Q -> end + 1) % Q -> max;
}

int emptyQueue(qup Q)
{
    return (Q -> start == Q -> end);
}

int removeFromQueue (qup Q)
{
    if (emptyQueue(Q))
        return 0;
    Q -> start = (Q -> start + 1) % Q -> max;
    return 1;
}

DATA firstInQueue (qup Q)
{
    return ( Q -> v[Q -> start] );
}

void resizeQueue (qup Q, int newSize)
{
    DATA * NewArray = malloc ( newSize * sizeof (DATA) );
    for (int i = 0; i < Q -> end; i++)
    {
        NewArray[i] = Q -> v[i];
    }

    free ( Q ->v );
    Q -> v = NewArray;
    Q -> max = newSize;
    free (NewArray);

}