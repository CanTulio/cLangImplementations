#include "data.h"


void swap (DATA v[], int imax, int end) {

    int aux = v[end];
    v[end] = v[imax];
    v[imax] = aux;

}


void bubbleSort (DATA v[], int start, int end ) {
    
    int i,j, swapped = 1;

    for (i = start; swapped && i < end; i++) {
        for (j = 0; j < end - i; j++) {

            swapped = 0;
            if ( v[j + 1] < v[j] ) {
                swap (v, j, j+1);
                swapped = 1;
            }
        }
    }
}



int *generatesRandomArray(int *v, int size) {
    v = malloc(size * sizeof(int));
    for (int i = 0; i < size; v[i++] = rand()%size);
    return v;
}


int main () {

    int max = 100;
    int  * v = generatesRandomArray (v, max);
    for (int i = 0; i < max; printf("%d ", v[i++] ) );
    printf ("\n------------\n");
    bubbleSort(v, 0, max);
    for (int i = 0; i < max; printf("%d ", v[i++] ) );
    return 0;
    
}