#include "data.h"
int *generatesRandomArray(int *v, int size);
void merge(int v[], int start1, int start2, int end);
void mergesort(int *v, int start, int end);

int *generatesRandomArray(int *v, int size) {
    v = malloc(size * sizeof(int));
    for (int i = 0; i < size; v[i++] = rand()%size);
    return v;
}

void merge(int v[], int start1, int start2, int end) {
    /*Function that takes an array with two sorted partitions (one starting at
    start1, the other starting at start2) and interweave then. */

    int *aux = malloc((end-start1)*(sizeof(int)));

    int i = start1,j = start2,k = 0;
    while (i < start2 && j < end) {
        if (v[i] < v[j]) {
            aux[k++] = v[i++];
        }
        else {
            aux[k++] = v[j++];
        }
    }

    while (i < start2) {
        aux[k++] = v[i++];
    }

    while (j < end) {
        aux[k++] = v[j++];
    }

    for (i = start1, k = 0; i < end; v[i] = aux[k], i++, k++);
    free(aux);
}

void mergesort(int *v, int start, int end) {
    int middle = (start+end)/2;
    if (end > start + 1) {
        mergesort(v, start, middle);
        mergesort(v, middle, end);
        merge(v,start, middle, end);
    }
}


int main () {

    int max = 100;
    int  * v = generatesRandomArray (v, max);
    for (int i = 0; i < max; printf("%d ", v[i++] ) );
    printf ("\n------------\n");
    mergesort(v, 0, max);
    for (int i = 0; i < max; printf("%d ", v[i++] ) );
    return 0;
    
}