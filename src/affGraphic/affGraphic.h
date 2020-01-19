#ifndef _AFF_GRAPHIC_H_
#define _AFF_GRAPHIC_H_

#define HAUTEUR_FENETRE 480
#define LARGEUR_FENETRE 480
#define RES_COULEUR_FENETRE 32
#define NOM_FENETRE "Morpion"

#define NORMAL_MODE 1
#define IA_MODE 2

extern SDL_Surface ** cases;

SDL_Surface ** initGrille(morpion * M);
void affichageMorpion (morpion * M);
int demandeTaille ();
int demandeMode();
void jouePartie(morpion * m, int mode);
void initFenetre();
void joueJoueur (morpion * m);
void joueIA (morpion *m);
void finPartie (morpion * m, int gagnant1, int gagnant2);
SDL_Surface * dessineRectangle(int x1, int y1, int x2, int y2, Uint32 couleur);
void dessineCroix(SDL_Surface * surface);
void dessineRond(SDL_Surface * surface);
int clicJoueur(morpion * m);
int coordVersCase (morpion * m, int x, int y);
int estDansRect (SDL_Surface * surface, int x, int y);
void freeCases(morpion * m);
void ecranFinal(morpion * m);

#endif