#include <stdlib.h>
#include <stdio.h>
#include "../morpion/morpion.h"
#include "affConsole.h"

int main(void) {
	int n;
	n = demandeTaille();
	if (n == -1) {
		printf("Valeur donnée non supérieur à 3.\n");
		exit(1);
	}

	morpion M = (char**)malloc(sizeof(char*)*n);
	for (int i=0; i<n; i++)
		M[i] = (char*)malloc(sizeof(char)*n);

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			M[i][j]=-1;

	M[1][1] = 0;
	M[2][1] = 1;

	affichageMorpion (M, n);
	return EXIT_SUCCESS;
}
