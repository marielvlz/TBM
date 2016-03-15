#include "librerias.h"

int kSize=11;

void imprime_arreglo(int* array, int size) {
	for (int i = 0; i < size; ++i){
		printf("%d ", array[i]);
	}
	printf("\n");
}

void swap(int* a, int* b){
	double c;
	c=*a;
	*a=*b;
	*b=c;
}

int pivote(int u[], int v, int w){
	int x= u[v];
	int i= v - 1;
	int j= w; 
	while (1){
		do j--;
		while (u[j]>x);
		do i++;
		while (u[i]<x);
		if (i<j){
			swap(&u[i], &u[j]);
		}
		else {
			return j + 1;
		}
	}
}

void resuelve_con_hoare (int u[], int size, int start, int end){
	int solve;
	if (end - start < 2)
		return;
	solve = pivote (u, start, end);
	resuelve_con_hoare(u, kSize, start, solve);
	resuelve_con_hoare(u, kSize, solve, end);
}

int main(int argc, char* argv[]){
	int array[] = {111, 17, 1, 5, 23, 6, 9, 20, 62, 44, 230896};
	imprime_arreglo(array, kSize);
	resuelve_con_hoare(array, kSize,0, kSize);
	imprime_arreglo(array, kSize);
	return 0;
}