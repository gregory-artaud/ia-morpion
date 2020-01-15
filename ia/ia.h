#ifndef _IA_H_
#define _IA_H_

typedef struct {
    int i;
    int j;
}coordonnees;

int max (morpion *M);
int min (morpion *M);
coordonnees minmax (morpion *M);
int maxAB (morpion *M);
int minAB (morpion *M);
coordonnees minmaxAB (morpion *M);
#endif
