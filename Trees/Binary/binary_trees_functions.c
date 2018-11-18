#include "binary_tree.h"
#include <stdio.h>

int countNodes(nptr t) {
    if (t == NULL) return 0;
    return(countNodes(t->l) + countNodes(t->r) + 1);
}

int heightTree(nptr t) { // given that t is the root. If you only have access to a arbitrary node from the tree (that isn't the root), just run upwars on the tree, then run heightTree(t)
    int r,l;
    if (t == NULL) return -1;
    r = heightTree(t->r);
    l = heightTree(t->l);
    if (r > l)
        return (r + 1);
    else    
        return (l + 1);
}

int is_ancestor (nptr q, nptr r) {
    //function that returns if q is a ancestor of r
    nptr aux = r;
    while (aux != NULL && aux != q) {
        aux = aux->father;
    }

    return (aux == q);
}

int level(nptr p) { // assuming that p is not null...
    int cont = 0;
    while (p != NULL) {
        p = p->father;
        cont++;
    }
    return cont;
}

nptr closest_common_ancestor(nptr p, nptr q) {
    int p_level = level(p);
    int q_level = level(q);
    while (p_level > q_level) {
        q = q->father;
        q_level--;
    }

    while (q_level > p_level) {
        p = p->father;
        p_level--;
    }

    while (p != q) {
        p = p->father;
        q = q->father;
    }

    return p;
}