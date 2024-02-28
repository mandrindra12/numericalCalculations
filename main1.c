#include <stdio.h>
#include <stdlib.h>

void display_result(float *x, int dim);
void get_data(int *dim, float ***a, float **b, float **x);
void gauss(float **a, float *b, float *x, int dim);
void cleanup(float **ptr0, float *ptr, int dim);


int main() {
	printf("Resolution de A.x = B par la methode de Gauss:\n");
// Data
	int dim = 3;
	float **a = NULL;
	float *b = NULL;
	float *x = NULL;
	get_data(&dim, &a, &b, &x);

// Calcul: methode de Gauss
	gauss(a, b, x, dim);

// result
	display_result(x, dim);
	display_result(b, dim);
	

	return 0;
}
void gauss(float **a, float *b, float *x, int dim) {
	printf("Methode de Gauss effectuee\n");
}
void cleanup(float **ptr0, float *ptr, int dim) {
	if( ptr != NULL) {
		free(ptr);
	}
	if(ptr0 != NULL) {
		for(int i = 0; i<dim; i++) {
			free(ptr0[i]);
		}
		free(ptr0);
	}
}
void get_data(int *dim, float ***a, float **b, float **x) {
	float *v =  NULL;
	*dim = 4;
	v = (float*)malloc(sizeof(float)**dim);
	if(v == NULL) {
		exit(1);
		cleanup(NULL, v, 0);
	}
	for(int i = 0; i < *dim; i++) v[i] = i;
	*x = v;
	*b = v;
	float **y = (float**)malloc(*dim*sizeof(float*));
	if(y == NULL) exit(1);
	for(int i = 0; i < *dim; i++) {
		y[i] = (float*)malloc(sizeof(float)**dim);
		if(y[i] == NULL) {
			cleanup(y, NULL, i);
			exit(1);
		}
	}
	*a = y;
	printf("Voici les donnees\n");
}

void display_result(float *x, int dim) {
	printf("Voici le vecteur x\n");
	for(int i = 0; i<dim; i++) {
		printf("%f\t", x[i]);
	}
}
