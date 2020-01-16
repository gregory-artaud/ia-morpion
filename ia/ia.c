#include "../morpion/morpion.h"
#include "../affConsole/affConsole.h"
#include "ia.h"
#include <limits.h>
#include <stdio.h>

/*
Partie max de l'algorithme MinMax. Le but est de trouver le score le plus petit
pour chaque branche possible.
Renvoie le score.
*/
int max (morpion *M) {
  int score, valeur;

  if (gagnant(M, JOUEUR1) == 1) return 10;
  else if (gagnant(M, JOUEUR2) == 1) return -10;
  else if (gagnant(M, JOUEUR2) == -1) return 0;

  score = INT_MIN;

  for (int i=0; i < M->taille; i++) {
    for (int j=0; j< M->taille; j++) {
      if (M->grille[i][j] == VIDE) {
        M->grille[i][j] = JOUEUR1;
        valeur = min(M);

        if (score < valeur)
          score = valeur;
        M->grille[i][j] = VIDE;
      }
    }
  }
  return score;
}

/*
Partie min de l'algorithme MinMax. Le but est de trouver le score le plus haut
pour chaque branche possible.
Renvoie le score.
*/
int min (morpion *M) {
  int score, valeur;

  if (gagnant(M, JOUEUR1) == 1) return 10;
  else if (gagnant(M, JOUEUR2) == 1) return -10;
  else if (gagnant(M, JOUEUR2) == -1) return 0;

  score = INT_MAX;

  for (int i=0; i < M->taille; i++) {
    for (int j=0; j< M->taille; j++) {
      if (M->grille[i][j] == VIDE) {
        M->grille[i][j] = JOUEUR2;
        valeur = max(M);

        if (score > valeur)
          score = valeur;
        M->grille[i][j] = VIDE;
      }
    }
  }
  return score;
}

/*
Algorithme permettant de faire jouer l'IA basé sur le modèle MinMax
Renvoie les coordonnées de où va jouer l'IA.
*/
coordonnees minmax (morpion *M) {
  int score, valeur;
  coordonnees C;
  C.i = 0;
  C.j = 0;

 score = INT_MAX;
 for (int i=0; i < M->taille; i++) {
   for (int j=0; j < M->taille; j++) {
     if (M->grille[i][j] == VIDE) {
       M->grille[i][j] = JOUEUR2;
       valeur = max(M);

       if (score > valeur) {
         score = valeur;
         C.i = i;
         C.j = j;
       }
       M->grille[i][j] = VIDE;
     }
   }
 }

 return C;
}

/*
Partie max de l'algorithme MinMax Alpha-Beta. Le but est de trouver le score le plus bas
pour chaque branche possible. Si on trouve le score le plus bas, on n'explore
pas les autres branches
Renvoie le score.
*/
int maxAB (morpion *M) {
  int score, valeur;

  if (gagnant(M, JOUEUR1) == 1) return 10;
  else if (gagnant(M, JOUEUR2) == 1) return -10;
  else if (gagnant(M, JOUEUR2) == -1) return 0;

  score = INT_MIN;

  for (int i=0; i < M->taille; i++) {
    for (int j=0; j< M->taille; j++) {
      if (M->grille[i][j] == VIDE) {
        M->grille[i][j] = JOUEUR1;

        if (score != 10)
          valeur = minAB(M);

        if (score < valeur)
          score = valeur;
        M->grille[i][j] = VIDE;
      }
    }
  }
  return score;
}

/*
Partie min de l'algorithme MinMax Alpha-Beta. Le but est de trouver le score le plus haut
pour chaque branche possible. Si on trouve le score le plus haut, on n'explore
pas les autres branches
Renvoie le score.
*/
int minAB (morpion *M) {
  int score, valeur;

  if (gagnant(M, JOUEUR1) == 1) return 10;
  else if (gagnant(M, JOUEUR2) == 1) return -10;
  else if (gagnant(M, JOUEUR2) == -1) return 0;

  score = INT_MAX;

  for (int i=0; i < M->taille; i++) {
    for (int j=0; j< M->taille; j++) {
      if (M->grille[i][j] == VIDE) {
        M->grille[i][j] = JOUEUR2;
        if (score != -10)
          valeur = maxAB(M);

        if (score > valeur)
          score = valeur;
        M->grille[i][j] = VIDE;
      }
    }
  }
  return score;
}

/*
Algorithme permettant de faire jouer l'IA basé sur le modèle MinMax Alpha-Beta
Renvoie les coordonnées de où va jouer l'IA.
*/
coordonnees minmaxAB (morpion *M) {
  int score, valeur;
  coordonnees C;
  C.i = 0;
  C.j = 0;

 score = INT_MAX;
 for (int i=0; i < M->taille; i++) {
   for (int j=0; j < M->taille; j++) {
     if (M->grille[i][j] == VIDE) {
       M->grille[i][j] = JOUEUR2;
       printf("i : %d, j : %d\n",i,j);
       if (score != -10)
          valeur = maxAB(M);

       if (score > valeur) {
         score = valeur;
         C.i = i;
         C.j = j;
       }
       M->grille[i][j] = VIDE;
     }
   }
 }

 return C;
}
