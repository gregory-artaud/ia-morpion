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

int demandeCase(morpion * m) {
  int res;
  printf("? ");
  scanf("%d", &res);
  while((res < 0) || (res >= m->taille)) {
    printf("\nEntrée invalide, reessayez :");
    scanf("%d", &res);
  }
  return res;
}

void jouePartie(morpion * m) {;
  int i, j;
  int gagnant1, gagnant2;
  int tour = 0;

  gagnant1 = gagnant(m, JOUEUR1);
  gagnant2 = gagnant(m, JOUEUR2);
  while ((gagnant1 == 0) && (gagnant2 == 0)) {
    affichageMorpion(m);
    printf("C'est au tour de Joueur %d :\n", tour % 2 + 1);
    do {
      printf("Saisissez la première coordonnée :\n");
      i = demandeCase(m);
      printf("la seconde :\n");
      j = demandeCase(m);
    } while (jouer(m, i, j, tour % 2) != 0);
    gagnant1 = gagnant(m, JOUEUR1);
    gagnant2 = gagnant(m, JOUEUR2);
    tour++;
  }

  affichageMorpion(m);
  if (gagnant1 == gagnant2) {
    printf("Match Nul\n");
  } else if (gagnant1 == 1) {
    printf("Le joueur 1 a gagné !\n");
  } else if (gagnant2 == 1) {
    printf("Le joueur 2 a gagné !\n");
  }
}
