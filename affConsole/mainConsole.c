#include <stdlib.h>
#include <stdio.h>
#include "../morpion/morpion.h"
#include "affConsole.h"

int main(void) {
	int n, mode;
	n = demandeTaille();
	if (n == -1) {
		printf("Valeur donnée non supérieur à 3.\n");
		exit(1);
	}

	m = demandeMode();

	morpion * M = creerMorpion (n);
	jouePartie(M, mode);

	return EXIT_SUCCESS;
}
