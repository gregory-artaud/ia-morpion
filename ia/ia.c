#include "../morpion/morpion.h"
#include "ia.h"
#include <limits.h>
#include <stdio.h>

int max (morpion *M) {
  int score, valeur;

  if (gagnant(M, JOUEUR1) == 1) return 10;
  else if (gagnant(M, JOUEUR2) == 1) return -10;
  else if (gagnant(M, JOUEUR2) == -1) return 0;

  score = INT_MIN;

  for (int i=0; i < M->taille; i++) {
    for (int j=0; j< M->taille; j++) {
      printf("max : i : %d, j : %d\n",i,j);
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

int min (morpion *M) {
  int score, valeur;

  if (gagnant(M, JOUEUR1) == 1) return 10;
  else if (gagnant(M, JOUEUR2) == 1) return -10;
  else if (gagnant(M, JOUEUR2) == -1) return 0;

  score = INT_MAX;

  for (int i=0; i < M->taille; i++) {
    for (int j=0; j< M->taille; j++) {
      printf("min : i : %d, j : %d\n",i,j);
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

coordonnees minmax (morpion *M) {
  int score, valeur;
  coordonnees C;
  C.i = 0;
  C.j = 0;

 score = INT_MAX;
 for (int i=0; i < M->taille; i++) {
   for (int j=0; j < M->taille; j++) {
     printf("i : %d, j : %d\n",i,j);
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
