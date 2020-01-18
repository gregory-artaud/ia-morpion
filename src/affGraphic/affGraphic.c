#include "../core/morpion/morpion.h"
#include "../core/ia/ia.h"
#include <stdio.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include "affGraphic.h"

Uint32 COULEUR_BLANC;
Uint32 COULEUR_NOIR;
Uint32 COULEUR_ROUGE;
SDL_Surface * surface_ecran;

void affichageMorpion (morpion * M) {
	int x1, x2, y1, y2, nb_cases;

	// affichage des barres verticales de la grille
  	for (int i = 0; i < M->taille - 1; i++)
  	{
  		x1 = (LARGEUR_FENETRE / M->taille) * (i + 1);
  		x2 = x1 + 5;
  		y1 = 5;
  		y2 = HAUTEUR_FENETRE - 5;
  		dessineRectangle(x1, y1, x2, y2, COULEUR_NOIR);
  	}

  	// affichage des barres horizontales de la grille
  	for (int i = 0; i < M->taille - 1; i++)
  	{
  		x1 = 5;
  		x2 = LARGEUR_FENETRE - 5;
  		y1 = (HAUTEUR_FENETRE / M->taille) * (i + 1);
  		y2 = y1 + 5;
  		dessineRectangle(x1, y1, x2, y2, COULEUR_NOIR);
  	}

  	// allocation des n*n surfaces des cases
  	nb_cases = M->taille * M->taille;
  	SDL_Surface * cases[nb_cases];
  	for (int i = 0; i < M->taille; i++) {
  		for (int j = 0; j < M->taille; j++) {
  			if ((i == M->taille - 1) && (j == M->taille - 1)) {
  				x1 = 10 + j * (LARGEUR_FENETRE / M->taille);
  				x2 = (j + 1) * (LARGEUR_FENETRE / M->taille) - 10;
  				y1 = 10 + i * (HAUTEUR_FENETRE / M->taille);
  				y2 = (i + 1) * (HAUTEUR_FENETRE / M->taille) - 10;
  			} else if (j == M->taille - 1) {
  				x1 = 10 + j * (LARGEUR_FENETRE / M->taille);
  				x2 = (j + 1) * (LARGEUR_FENETRE / M->taille) - 10;
  				y1 = 10 + i * (HAUTEUR_FENETRE / M->taille);
  				y2 = (i + 1) * (HAUTEUR_FENETRE / M->taille) - 5;
  			} else if (i == M->taille - 1) {
  				x1 = 10 + j * (LARGEUR_FENETRE / M->taille);
  				x2 = (j + 1) * (LARGEUR_FENETRE / M->taille) - 5;
  				y1 = 10 + i * (HAUTEUR_FENETRE / M->taille);
  				y2 = (i + 1) * (HAUTEUR_FENETRE / M->taille) - 10;
  			} else {
  				x1 = 10 + j * (LARGEUR_FENETRE / M->taille);
  				x2 = (j + 1) * (LARGEUR_FENETRE / M->taille) - 5;
  				y1 = 10 + i * (HAUTEUR_FENETRE / M->taille);
  				y2 = (i + 1) * (HAUTEUR_FENETRE / M->taille) - 5;
  			}
  			cases[i] = dessineRectangle(x1, y1, x2, y2, COULEUR_ROUGE);
  		}
  	}


	for (int i = 0; i<M->taille; i++) {
		for (int j = 0; j<M->taille; j++) {
			switch (M->grille[i][j]) {
				case -1 :
					// ne rien afficher
					break;
				case 0 :
					// afficher une croix
					break;
				case 1 :
					// afficher un rond
					break;
				default :
					// ne rien afficher
					break;
			}
		}
	}
}

/*
Demande à l'utilisateur en début de partie la taille de la grille du morpion.
Renvoie la taille de la grille
*/
int demandeTaille () {
  int taille, lecture;
  printf("Veuillez rentrer la taille de la grille (supérieur à 2) : ");
  lecture = scanf("%d", &taille);

  if (lecture == 0 || taille < 3)
    return -1;

  return taille;
}

/*
Demande une coordonnées au joueur pour savoir où il va jouer
Renvoie la coordonnées.
*/
int demandeCase(morpion * m) {
	int res;
	scanf("%d", &res);
	while((res < 0) || (res >= m->taille)) {
	printf("Entrée invalide, veuillez reessayez : ");
	scanf("%d", &res);
	}
	return res;
}

/*
Demande si le joueur veut jouer contre l'IA ou contre un autre joueur.
Renvoi un entier représentant le mode.
*/
int demandeMode() {
	int res;
	printf("Quel mode de jeu ?\n1. Joueur vs Joueur\n2. Joueur vs IA\n");
	scanf("%d", &res);
	while((res < 0) || (res > 2)) {
    	printf("Entrée invalide, veuillez reessayez : ");
    	scanf("%d", &res);
  	}
  	return res;
}

/*
Lance la fonction adéquate au mode sélectionné
*/
void jouePartie(morpion * m, int mode) {;
	if (mode == NORMAL_MODE) {
    joueJoueur (m);
  }
  else if (mode == IA_MODE) {
    joueIA (m);
  }
}

void initFenetre() {
	surface_ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, RES_COULEUR_FENETRE, SDL_HWSURFACE); // Ouverture de la fenêtre
    SDL_WM_SetCaption(NOM_FENETRE, NULL);
    printf("Ouverture de la fenetre..\n");

    // initialisation des couleurs
    COULEUR_BLANC = SDL_MapRGB(surface_ecran->format, 255, 255, 255);
    COULEUR_NOIR = SDL_MapRGB(surface_ecran->format, 0, 0, 0);
    COULEUR_ROUGE = SDL_MapRGB(surface_ecran->format, 255, 0, 0);
    SDL_FillRect(surface_ecran, NULL, COULEUR_BLANC);

    SDL_Flip(surface_ecran); /* Mise à jour de l'écran */
}

SDL_Surface * dessineRectangle(int x1, int y1, int x2, int y2, Uint32 couleur) {
	SDL_Rect position;
	position.x = x1;
	position.y = y1;
	SDL_Surface * rectangle = NULL;
	rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, abs(x2 - x1) , abs(y2 - y1), RES_COULEUR_FENETRE, 0, 0, 0, 0); /* alloue la surface */

	SDL_FillRect(rectangle, NULL, couleur); /* rempli la surface avec couleur */
	SDL_BlitSurface(rectangle, NULL, surface_ecran, &position); /* "colle" le rectangle créé sur la surface de fond */

	SDL_Flip(surface_ecran); /* Mise à jour de l'écran */
	return rectangle;
}

/*
Fonction pour le joueur contre joueur. Cette fonction va faire jouer chaque joueur
en regardant si quelqu'un à gagné.
*/
void joueJoueur (morpion * m) {
  int gagnant1, gagnant2;
  int i, j;
  int tour = 0;

  initFenetre();

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

/*
Fonction pour le joueur contre IA. Cett fonction va faire jouer le joueur puis l'IA
en boucle jusqu'à qu'il y ai un gagnant ou match nul.
*/
void joueIA (morpion *m) {
	int gagnant1, gagnant2;
	int i, j;
	int tour = 0;
	coordonnees c;

	initFenetre();

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

/*
Affiche un message en fonction de qui a gagné la partie.
*/
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