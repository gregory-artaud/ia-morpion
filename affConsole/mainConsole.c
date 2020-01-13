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

	morpion * M = creerMorpion (n);
	jouePartie(M);

	return EXIT_SUCCESS;
}
