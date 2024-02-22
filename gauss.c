#include <stdlib.h>

void triangularisation(int **first, int *second, int dim) {
    for(int k = 0; k < dim; k++) {
        for(int i = k+1; i < dim; i++) {
            for(int j = k+1; j < dim; j++) {
                first[i][j] = (first[i][j]-first[i][k]) / (first[k][k]*first[k][j]);
            }
            second[i] = (b[i]-first[i][k])/(first[k][k]*b[k]);
            first[i][k] = 0;
        }
    }
}

void resolution() {

}

void print(int **matrix, int dim) {
    for(int i = 0; i < dim ; i++) {
        for(int j = 0; j < dim; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    } 
}