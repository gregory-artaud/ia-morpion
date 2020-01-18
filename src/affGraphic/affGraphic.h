#ifndef _AFF_GRAPHIC_H_
#define _AFF_GRAPHIC_H_

#define HAUTEUR_FENETRE 480
#define LARGEUR_FENETRE 640
#define RES_COULEUR_FENETRE 32
#define NOM_FENETRE "Morpion"

#define NORMAL_MODE 1
#define IA_MODE 2

extern Uint32 COULEUR_BLANC;
extern Uint32 COULEUR_NOIR;
extern SDL_Surface * surface_ecran;

void affichageMorpion (morpion * M);
int demandeTaille ();
int demandeCase(morpion * m);
int demandeMode();
void jouePartie(morpion * m, int mode);
void initFenetre();
void joueJoueur (morpion * m);
void joueIA (morpion *m);
void finPartie (morpion * m, int gagnant1, int gagnant2);
SDL_Surface * dessineRectangle(int x1, int y1, int x2, int y2, Uint32 couleur);

#endif