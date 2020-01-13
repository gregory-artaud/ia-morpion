#include <stdlib.h>
#include "morpion.h"

void initMorpion(morpion * m, int taille) {
	m->taille = taille;

	m->grille = (char **)malloc(sizeof(char *) * m->taille);
	for (int i = 0; i < m->taille; i++) {
		m->grille[i] = (char *)malloc(sizeof(char) * m->taille);
	}

	for (int i = 0; i < m->taille; i++) {
		for (int j = 0; j < m->taille; j++) {
			m->grille[i][j] = VIDE;
		}
	}
}

int jouer(morpion * m, int i, int j, int joueur) {
	if (m->grille[i][j] != VIDE) {
		return 1;
	} else {
		m->grille[i][j] = joueur;
		return 0;
	}
}

int aligneLigne(morpion * m, int ligne, int joueur) {
	if (m->grille[0][ligne] == joueur) {
		for (int i = 0; i < m->taille - 1; i++) {
			if (m->grille[i][ligne] != m->grille[i + 1][ligne]) return 0;
		}
		return 1;
	}

	return 0;
}

int aligneColonne(morpion * m, int colonne, int joueur) {
	if (m->grille[colonne][0] == joueur) {
		for (int i = 0; i < m->taille - 1; i++) {
			if (m->grille[colonne][i] != m->grille[colonne][i + 1]) return 0;
		}
		return 1;
	}

	return 0;
}

int aligneDiag(morpion * m, int joueur) {
	int res = 1;
	if (m->grille[0][0] == joueur) {
		for (int i = 0; i < m->taille - 1; i++) {
			if (m->grille[i][i] != m->grille[i + 1][i + 1]) res = 0;
		}
		if (res == 1) return res;
	}

	if (m->grille[m->taille][0] == joueur) {
		for (int i = 0; i < m->taille; i++) {
			if (m->grille[m->taille - i -1][i] != m->grille[m->taille - i - 2][i + 1]) res = 0;
		}
		if (res == 1) return res;
	}

	return 0;
}

int gagnant(morpion * m, int joueur) {
	int i, j;
	int estPasPlein = 0;
	// vérifie les alignements
	for (i = 0; i < m->taille; i++)
		for (j = 0; j < m->taille; j++)
			if (m->grille[i][j] == VIDE) estPasPlein = 1;

	for (i = 0; i < m->taille; i++)
		if (aligneLigne(m, i, joueur) || aligneColonne(m, i, joueur) || aligneDiag(m, joueur))
			return 1;

	if (estPasPlein == 0) return -1;


	return 0;
}
