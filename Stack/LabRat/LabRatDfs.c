#include <stdio.h>
#include "LabRatDfs.h"
#include "../StackArray.h"

void printfSolution (int lab[], int lines,int col, Pos Rat, Pos Cheese)
{
    stp P  = CreatesStack(lines*col);
    Pos Current, Next, Last;
    Current.x = Rat.x; Current.y = Rat.y;

    int hasSolution = 1, ok = 1, movs = 0;
    int next;
    // int i,j;
    // i = j = 0;

    while ( Cheese.x != Current.x && Current.y != Cheese.y && hasSolution = 1 )
    {   
        next = posProx(lab);
        if (next != -1)
        {
            if (StackEmpty(P)) hasSolution = 0;
            if (next = 1) Current.y ++;
            if (next = 2) Current.x ++;
            if (next = 3) Current.y --;
            if (next = 4) Current.x --;
            movs++;
            StackPush(Current, P); // modificar : Current não é inteiro
        }

        else 
        {
            Last = StackTop(P);
        }
    }
}