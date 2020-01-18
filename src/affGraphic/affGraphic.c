#include "../core/morpion/morpion.h"
#include "../core/ia/ia.h"
#include <stdio.h>
#include "affGraphic.h"

void affichageMorpion (morpion * M) {
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