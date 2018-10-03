#include "data.h"
void swap (DATA v[], int imax, int end) {

    int aux = v[end];
    v[end] = v[imax];
    v[imax] = aux;

}


void insertionSort(DATA v[], int start, int end) {
    int OrderedIndex, UnorderedIndex;

    for (UnorderedIndex = start + 1; UnorderedIndex <= end; UnorderedIndex ++) { //Invariant : All elements Smaller than UnorderedIndex are Sorted

        for (OrderedIndex = UnorderedIndex - 1; OrderedIndex > 0 && v[OrderedIndex] < v [OrderedIndex - 1]; OrderedIndex --)
            swap(v, OrderedIndex-1, OrderedIndex  );
            // Invariant : All elements  smaller than OrderedIndex are certainly sorted.

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
    insertionSort(v, 0, max);
    for (int i = 0; i < max; printf("%d ", v[i++] ) );
    return 0;
    
}