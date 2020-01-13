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

	morpion * M;
	initMorpion (M, n);

	jouer (M, 2, 2, 0);
	jouer (M, 1, 1, 0);
	jouer (M, 0, 0, 0);
	jouer (M, 1, 2, 1);
	jouer (M, 0, 2, 1);

	affichageMorpion (M);
	printf("%d\n", gagnant(M, 1));
	//printf("%d\n", gagnant(M, 0));
	return EXIT_SUCCESS;
}
