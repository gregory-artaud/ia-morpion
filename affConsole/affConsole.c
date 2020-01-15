#include "../morpion/morpion.h"
#include "../ia/ia.h"
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
	scanf("%d", &res);
	while((res < 0) || (res >= m->taille)) {
	printf("Entrée invalide, veuillez reessayez : ");
	scanf("%d", &res);
	}
	return res;
}

int demandeMode() {
	int res;
	printf("Quel mode de jeu ? (1. J vs J, 2. J vs Ordi)\n");
	scanf("%d", &res);
	while((res < 0) || (res > 2)) {
    	printf("Entrée invalide, veuillez reessayez : ");
    	scanf("%d", &res);
  	}
  	return res;
}

void jouePartie(morpion * m, int mode) {;
	if (mode == NORMAL_MODE) {
    joueJoueur (m);
  }
  else if (mode == IA_MODE) {
    joueIA (m);
  }
}

void joueJoueur (morpion * m) {
  int gagnant1, gagnant2;
  int i, j;
	int tour = 0;

  gagnant1 = gagnant(m, JOUEUR1);
  gagnant2 = gagnant(m, JOUEUR2);
  while ((gagnant1 == 0) && (gagnant2 == 0)) {
    affichageMorpion(m);
    printf("C'est au tour de Joueur %d : \n", tour % 2 + 1);
    do {
      printf("Saisissez la ligne : ");
      i = demandeCase(m);
      printf("Saisissez la colonne : ");
      j = demandeCase(m);
    } while (jouer(m, i, j, tour % 2) != 0);
    gagnant1 = gagnant(m, JOUEUR1);
    gagnant2 = gagnant(m, JOUEUR2);
    tour++;
  }
  finPartie (m, gagnant1, gagnant2);
}

void joueIA (morpion *m) {
	int gagnant1, gagnant2;
  int i, j;
	int tour = 0;
	coordonnees c;

  gagnant1 = gagnant(m, JOUEUR1);
  gagnant2 = gagnant(m, JOUEUR2);
  while ((gagnant1 == 0) && (gagnant2 == 0)) {
    affichageMorpion(m);
    printf("C'est au tour de Joueur %d : \n", tour % 2 + 1);
    if (tour % 2 == 1) {
      c = minmaxAB(m);
      jouer(m, c.i, c.j, JOUEUR2);
    } else {
      do {
        printf("Saisissez la ligne : ");
        i = demandeCase(m);
        printf("Saisissez la colonne : ");
        j = demandeCase(m);
      } while (jouer(m, i, j, tour % 2) != 0);
    }
    gagnant1 = gagnant(m, JOUEUR1);
    gagnant2 = gagnant(m, JOUEUR2);
    tour++;
  }
  finPartie (m, gagnant1, gagnant2);
}

void finPartie (morpion * m, int gagnant1, int gagnant2) {
	affichageMorpion(m);
	if (gagnant1 == gagnant2) {
		printf("Match Nul\n");
	} else if (gagnant1 == 1) {
		printf("Le joueur 1 a gagné !\n");
	} else if (gagnant2 == 1) {
		printf("Le joueur 2 a gagné !\n");
	}
}
