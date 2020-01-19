#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "../core/morpion/morpion.h"
#include "affGraphic.h"

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL

    int n, mode;

    n = demandeTaille();
    if (n == -1) {
        printf("Valeur donnée non supérieur à 3.\n");
        exit(1);
    }

    mode = demandeMode();

    morpion * M = creerMorpion (n);

    initFenetre();
    cases = initGrille(M);

    jouePartie(M, mode);
 
    SDL_Quit(); // Arrêt de la SDL
 
    return EXIT_SUCCESS; // Fermeture du programme
}