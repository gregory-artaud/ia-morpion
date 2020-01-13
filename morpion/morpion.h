#ifndef _MORPION_H_
#define _MORPION_H_

#define VIDE -1
#define JOUEUR1 0
#define JOUEUR2 1

const int tailleGrille;
typedef char morpion[tailleGrille][tailleGrille];

// initialise morpion avec la valeur VIDE
void initMorpion();

// renvoie 1 si m[i][j] est non vide et 0 sinon
int jouer(morpion m, int i, int j, int joueur);

// renvoie 1 si joueur a gagné
// si m est plein et que personne n'a gagné renvoie -1
// renvoie 0 sinon
int gagnant(morpion m, int joueur);

#endif