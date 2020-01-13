#include "morpion.h"

const int tailleGrille = 3;

void initMorpion() {
	for (int i = 0; i < tailleGrille; i++) {
		for (int j = 0; j < tailleGrille; j++) {
			morpion[i][j] = VIDE;
		}
	}
}

int jouer(morpion m, int i, int j, int joueur) {
	if (m[i][j] != VIDE) {
		return 1;
	} else {
		m[i][j] = joueur;
		return 0;
	}
}

int gagnant(morpion m, int joueur) {
	for (int i = 0; i < tailleGrille; i++) {
		for (int j = 0; j < tailleGrille; j++) {
			if (m[i][j] == joueur) {
				// verifie si m[i][j] est aligné avec n-1 autres
			}
		}
	}
}