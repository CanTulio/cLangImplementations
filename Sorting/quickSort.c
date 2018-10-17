#include "data.h"


void quicksort(int *v, int start, int end);
int *generatesRandomArray(int *v, int size);
void swap (DATA v[], int imax, int end);

int *generatesRandomArray(int *v, int size) {
    v = malloc(size * sizeof(int));
    for (int i = 0; i < size; v[i++] = rand()%size);
    return v;
}

void swap (DATA v[], int imax, int end) {

    int aux = v[end];
    v[end] = v[imax];
    v[imax] = aux;

}



int main () {

    int max = 100;
    int  * v = generatesRandomArray (v, max);
    for (int i = 0; i < max; printf("%d ", v[i++] ) );
    printf ("\n------------\n");
    quicksort(v, 0, max);
    for (int i = 0; i < max; printf("%d ", v[i++] ) );

    return 0;
    
}

int separate(int *v, int start, int end) {
    int i, wall = start-1, pivot = v[end-1];
    for (i = start; i < end; i++) {
        if (v[i] <= pivot) { //e se não colocasse igual?
        //sem o igual, não colocaria o pivo no lugar certo ao fim da execução
            
            wall++;
            swap(v, wall, i);
        }
    }
    return wall;
}

void quicksort(int *v, int start, int end) {
    int pivot;
    if ( (end - start) > 0 ) {
        pivot = separate(v, start, end);
        quicksort(v, start, pivot);
        quicksort(v, pivot+1, end);
    } 
}