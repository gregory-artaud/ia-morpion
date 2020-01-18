#include <stdlib.h>
#include "morpion.h"

/*
Crée et initialise la grille de morpion en fonction de la taille choisie.
Renvoie le morpion.
*/
morpion * creerMorpion(int taille) {
	morpion * m = (morpion *)malloc(sizeof(morpion));

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

	return m;
}

/*
Joue à l'emplacement indiqué dans les paramètres avec le symbole du joueur passé
en paramètre.
Renvoie 0 si il n'y a pas d'erreur et 1 si il y a une erreur.
*/
int jouer(morpion * m, int i, int j, int joueur) {
	if ((i >= 0) && (j >= 0) && (i < m->taille) && (j < m->taille)) {
		if (m->grille[i][j] != VIDE) {
			return 1;
		} else {
			m->grille[i][j] = joueur;
			return 0;
		}
	}

	return 1;
}

/*
Fonction vérifiant si un joueur a gagné en alignant des symboles sur une ligne
Renvoie 1 si il a aligné ses symboles sur une ligne. Sinon, renvoie 0.
*/
int aligneLigne(morpion * m, int ligne, int joueur) {
	if (m->grille[0][ligne] == joueur) {
		for (int i = 0; i < m->taille - 1; i++) {
			if (m->grille[i][ligne] != m->grille[i + 1][ligne]) return 0;
		}
		return 1;
	}

	return 0;
}

/*
Fonction vérifiant si un joueur a gagné en alignant des symboles sur une colonne
Renvoie 1 si il a aligné ses symboles sur une colonne. Sinon, renvoie 0.
*/
int aligneColonne(morpion * m, int colonne, int joueur) {
	if (m->grille[colonne][0] == joueur) {
		for (int i = 0; i < m->taille - 1; i++) {
			if (m->grille[colonne][i] != m->grille[colonne][i + 1]) return 0;
		}
		return 1;
	}

	return 0;
}

/*
Fonction vérifiant si un joueur a gagné en alignant des symboles sur une diagonale
Renvoie 1 si il a aligné ses symboles sur une diagonale. Sinon, renvoie 0.
*/
int aligneDiag(morpion * m, int joueur) {
	int res = 1;
	if (m->grille[0][0] == joueur) {
		for (int i = 0; i < m->taille - 1; i++) {
			if (m->grille[i][i] != m->grille[i + 1][i + 1]) res = 0;
		}
		if (res == 1) return res;
	}

	res = 1;
	if (m->grille[0][m->taille - 1] == joueur) {
		for (int i = 0; i < m->taille - 1; i++) {
			if (m->grille[i][m->taille - 1 - i] != m->grille[i + 1][m->taille - 2 - i]) res = 0;
		}
		if (res == 1) return res;
	}

	return 0;
}


/*
Fonction vérifiant si un joueur a gagné la partie. Pur cela on vérifie
les lignes, colonnes et diagonale de la grille.
Renvoie 1 si il a gagné. Sinon, renvoie 0.
*/
int gagnant(morpion * m, int joueur) {
	int i, j;
	int estPasPlein = 0;
	for (i = 0; i < m->taille; i++)
		for (j = 0; j < m->taille; j++)
			if (m->grille[i][j] == VIDE) estPasPlein = 1;

	for (i = 0; i < m->taille; i++)
		if (aligneLigne(m, i, joueur) || aligneColonne(m, i, joueur) || aligneDiag(m, joueur))
			return 1;

	if (estPasPlein == 0) return -1;


	return 0;
}
