#include "data.h"
void swap (DATA v[], int imax, int end);
void selection (DATA v[], int n);
int *generatesRandomArray(int *v, int size);

void swap (DATA v[], int imax, int end) {

    int aux = v[end];
    v[end] = v[imax];
    v[imax] = aux;

}

void selection (DATA v[], int n) {
    int i, j, imin;
    for (i = 0; i < n; i++) {
        imin = i; // Invariant : all elements of v[i], with imin <= i
        // are sorted. (vacuosly true for i = 0)
        for (j = i+1; j < n; j++) {
            if (v[j] < v[imin]) //invariant : all elements v[k], with
            // k being >= j are greater than any element of v[y], with
            // y <= imin.
                imin = j;
        }

        swap (v, imin, i);
    }
    
}

int *generatesRandomArray(int *v, int size) {
    v = malloc(size * sizeof(int));
    for (int i = 0; i < size; v[i++] = rand()%size);
    return v;
}


int main () {

    int max = 1000;
    int  * v = generatesRandomArray (v, max);
    for (int i = 0; i < max; printf("%d ", v[i++] ) );
    printf ("\n------------\n");
    selection(v, max);
    for (int i = 0; i < max; printf("%d ", v[i++] ) );
    return 0;
    
}