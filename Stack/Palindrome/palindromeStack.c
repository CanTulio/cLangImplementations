#include "StackArray.h"
#include <stdio.h>

int checksPalindrome ( char word[], int size )
// returns 1 if its a palindrome, 0 if its not.
{
    stp p;
    int metade = 0;
    p = CreatesStack(size);
    for (int i = 0; word[i] != 0; i++)
    {
        if ( (word[i] == 'a' || (word[i] == 'b') ) && !metade)
        {
            StackPush(word[i], p);
            printf ("Topo : %c\n", StackTop(p));
        }
        if (word[i] == 'c') metade = 1;
        
        if (metade) 
        {
            if ( word[i] != StackTop(p) && word[i] != 'c' ) return 0;
            StackPop(p);
        }
        
    }

    return 1;

}



int main() 
{   
    char word[] = "ababcbaba";
    printf ("The result is .... %d\n", checksPalindrome(word,10) );
    return 0;
}