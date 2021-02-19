#include "functions.h"
int main() {
    int k,t;
    struct matrix matrix;
    input(&matrix);
    printmatrix(&matrix);
    k=countermax(&matrix);
    t=countermin(&matrix);
    sortirovka(k,t,&matrix);
    //printvector(&matrix,k);

    printmatrix(&matrix);
    destroym(&matrix);
    return 0;
}
