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
Uint32 COULEUR_BLEU;
SDL_Surface * surface_ecran;
SDL_Surface ** cases;

// retourne le tableau de pointeur sur les surfaces des cases
SDL_Surface ** initGrille(morpion * M) {
	int x1, x2, y1, y2;
	int nb_cases = M->taille * M->taille;

	SDL_Surface ** casesRes = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * nb_cases);

	// affichage des barres verticales de la grille
  	for (int i = 0; i < M->taille - 1; i++)
  	{
  		x1 = (LARGEUR_FENETRE / M->taille) * (i + 1);
  		x2 = x1 + 5;
  		y1 = 5;
  		y2 = HAUTEUR_FENETRE - 5;
  		SDL_FreeSurface(dessineRectangle(x1, y1, x2, y2, COULEUR_NOIR));
  	}

  	// affichage des barres horizontales de la grille
  	for (int i = 0; i < M->taille - 1; i++)
  	{
  		x1 = 5;
  		x2 = LARGEUR_FENETRE - 5;
  		y1 = (HAUTEUR_FENETRE / M->taille) * (i + 1);
  		y2 = y1 + 5;
  		SDL_FreeSurface(dessineRectangle(x1, y1, x2, y2, COULEUR_NOIR));
  	}

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
  			casesRes[M->taille * i + j] = dessineRectangle(x1, y1, x2, y2, COULEUR_BLANC);
  			casesRes[M->taille * i + j]->clip_rect.x = x1;
  			casesRes[M->taille * i + j]->clip_rect.y = y1;
  		}
  	}
  	return casesRes;
}

void affichageMorpion (morpion * M) {
	int x1, x2, y1, y2;
	int nb_cases = M->taille * M->taille;

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

	for (int i = 0; i<M->taille; i++) {
		for (int j = 0; j<M->taille; j++) {
			switch (M->grille[i][j]) {
				case 0 :
					// afficher une croix
					dessineCroix(cases[M->taille * i + j]);
					break;
				case 1 :
					// afficher un rond
					dessineRond(cases[M->taille * i + j]);
					break;
				default :
					// ne rien afficher
					break;
			}

			// printf("MaJ de la case numero %d ..\n", M->taille * i + j);
		}
	}
}

/*
* Dessine une croix sur surface
*/
void dessineCroix(SDL_Surface * surface) {
	int x1, x2, y1, y2;

	x1 = surface->clip_rect.x;
	y1 = surface->clip_rect.y;
	x2 = surface->clip_rect.x + surface->clip_rect.w;
	y2 = surface->clip_rect.y + surface->clip_rect.h;
	SDL_FreeSurface(dessineRectangle(x1, y1, x2, y2, COULEUR_BLEU));
}

/*
* Dessine un rond sur surface
*/
void dessineRond(SDL_Surface * surface) {
	int x1, x2, y1, y2;

	x1 = surface->clip_rect.x;
	y1 = surface->clip_rect.y;
	x2 = surface->clip_rect.x + surface->clip_rect.w;
	y2 = surface->clip_rect.y + surface->clip_rect.h;
	SDL_FreeSurface(dessineRectangle(x1, y1, x2, y2, COULEUR_ROUGE));
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
	surface_ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, RES_COULEUR_FENETRE, SDL_HWSURFACE | SDL_DOUBLEBUF); // Ouverture de la fenêtre
    SDL_WM_SetCaption(NOM_FENETRE, NULL);
    printf("Ouverture de la fenetre..\n");

    // initialisation des couleurs
    COULEUR_BLANC = SDL_MapRGB(surface_ecran->format, 255, 255, 255);
    COULEUR_NOIR = SDL_MapRGB(surface_ecran->format, 0, 0, 0);
    COULEUR_ROUGE = SDL_MapRGB(surface_ecran->format, 255, 0, 0);
    COULEUR_BLEU = SDL_MapRGB(surface_ecran->format, 0, 0, 255);
    SDL_FillRect(surface_ecran, NULL, COULEUR_BLANC);

    SDL_Flip(surface_ecran); /* Mise à jour de l'écran */
}

/*
Dessine un rectangle et lui alloue une surface
*/
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

int estDansRect (SDL_Surface * surface, int x, int y) {
	int x1, x2, y1, y2;
	int res = 0;

	x1 = surface->clip_rect.x;
	y1 = surface->clip_rect.y;
	x2 = surface->clip_rect.x + surface->clip_rect.w;
	y2 = surface->clip_rect.y + surface->clip_rect.h;
	if ((x >= x1) && (x <= x2) && (y >= y1) && (y <= y2)) {
		res = 1;
	}

	return res;
}

int coordVersCase (morpion * m, int x, int y) {
	int i = 0;
	int nb_cases = m->taille * m->taille;
	int res = -1;

	while ((i < nb_cases) && !estDansRect(cases[i], x, y)) {
		i++;
	}

	if (i != nb_cases) res = i;

	return res;
}

int clicJoueur (morpion * m) {
	int x, y, caseRes, continuer;
	SDL_Event event;
	
	continuer = 1;
	caseRes = -1;
	while (continuer) {
	    SDL_WaitEvent(&event);
	    switch(event.type) {
	        case SDL_QUIT:
	            continuer = 0;
	            break;
	        case SDL_MOUSEBUTTONUP:
	        	if (event.button.button == SDL_BUTTON_LEFT) {
	        		x = event.button.x;
	            	y = event.button.y;
	            	
	        	}
	        	caseRes = coordVersCase(m, x, y);
	        	if (caseRes != -1) continuer = 0;
	            break;
	    }
	}

	return caseRes;
}

void freeCases(morpion * m) {
	int nb_cases = m->taille * m->taille;
	for (int i = 0; i < nb_cases; i++) {
		SDL_FreeSurface(cases[i]);
	}

	free(cases);
}

/*
Fonction pour le joueur contre joueur. Cette fonction va faire jouer chaque joueur
en regardant si quelqu'un à gagné.
*/
void joueJoueur (morpion * m) {
  int gagnant1, gagnant2;
  int numeroCase;
  int i, j;
  int tour = 0;

  gagnant1 = gagnant(m, JOUEUR1);
  gagnant2 = gagnant(m, JOUEUR2);
  while ((gagnant1 == 0) && (gagnant2 == 0)) {
    affichageMorpion(m);
    printf("C'est au tour de Joueur %d\n", tour % 2 + 1);
    do {
    	numeroCase = clicJoueur(m);
		i = numeroCase / m->taille;
		j = numeroCase % m->taille;
    } while (jouer(m, i, j, tour % 2) != 0);
    printf("Joueur %d a joué en %d,%d\n", tour % 2 + 1, i, j);
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
	int numeroCase;
	int i, j;
	int tour = 0;
	coordonnees c;

  	gagnant1 = gagnant(m, JOUEUR1);
  	gagnant2 = gagnant(m, JOUEUR2);
  	while ((gagnant1 == 0) && (gagnant2 == 0)) {
    	affichageMorpion(m);
    	printf("C'est au tour de Joueur %d\n", tour % 2 + 1);
    	if (tour % 2 == 1) {
      		c = minmaxAB(m);
      		jouer(m, c.i, c.j, JOUEUR2);
    	} else {
    		do {
        		numeroCase = clicJoueur(m);
				i = numeroCase / m->taille;
				j = numeroCase % m->taille;
      		} while (jouer(m, i, j, tour % 2) != 0);
    	}
    	gagnant1 = gagnant(m, JOUEUR1);
    	gagnant2 = gagnant(m, JOUEUR2);
    	tour++;
  	}
  	finPartie (m, gagnant1, gagnant2);
}

void ecranFinal(morpion * m) {
	int continuer = 1;
	SDL_Event event;

	while (continuer) {
		SDL_WaitEvent(&event);
		switch(event.type) {
			case SDL_QUIT:
				freeCases(m);
				freeMorpion(m);
				continuer = 0;
				break;
		}
	}
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

	ecranFinal(m);
}