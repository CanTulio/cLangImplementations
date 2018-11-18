#include "data.h"

typedef struct node {
    DATA info;
    struct node* father;
    struct node* r;
    struct node* l;
} Node;

typedef Node* nptr;