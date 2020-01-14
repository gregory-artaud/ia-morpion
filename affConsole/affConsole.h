#ifndef _AFF_CONSOLE_H_
#define _AFF_CONSOLE_H_

#define NORMAL_MODE 1
#define IA_MODE 2

void affichageMorpion (morpion * M);
int demandeTaille ();
int demandeCase(morpion * m);
void jouePartie(morpion * m, int mode);
void joueJoueur (morpion * m);
void joueIA (morpion * m);
void finPartie (morpion * m, int gagnant1, int gagnant2);
int demandeMode();
#endif
