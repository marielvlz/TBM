#include <stdio.h>
#include <math.h>
//Este programa calcula el calor de pi
int main(int argc, char* argv[]){
	int i = 4;
	int j;
	double pi = 0;
	for (j = 3; j <= 999999; j+=2){ //j+=2 es lo mismo que j = j + 2
		pi = pi + ((double)- i/j);
		j = j + 2;
		pi = pi + ((double) i/j);
	}//for
		pi += i;
	printf ("El valor de pi, segun la Serie de Leibniz, es: \n%.54lf", pi);
	return 0;
} //main 
