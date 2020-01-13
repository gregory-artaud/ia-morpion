#include "../morpion/morpion.h"
#include "affConsole.h"
#include <stdio.h>
/*
Affiche la grille de morpion passer en paramètre
*/
void affichageMorpion (morpion * M) {
  printf("\t");
	for (int k=0; k<M->taille; k++)
    printf("  %d ",k);

  printf("\n");
  printf("\n\t");
  for (int i=0; i<M->taille; i++)
    printf("----");
  printf("-\n");

  for (int i = 0; i<M->taille; i++) {
    printf("%d\t", i);
    for (int j = 0; j<M->taille; j++) {
      switch (M->grille[i][j]) {
        case -1 :
          printf("|   ");
          break;
        case 0 :
          printf("| X ");
          break;
        case 1 :
          printf("| O ");
          break;
        default :
          printf("| ? ");
          break;
      }
    }
    printf("|\n\t-");

    for (int l=0; l<M->taille; l++)
      printf("----" );
    printf("\n");
  }
  printf("\n");
}

int demandeTaille () {
  int taille, lecture;
  printf("Veuillez rentrer la taille de la grille (supérieur à 2) : ");
  lecture = scanf("%d", &taille);

  if (lecture == 0 || taille < 3)
    return -1;

  return taille;
}
