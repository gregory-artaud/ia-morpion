#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "../core/morpion/morpion.h"
#include "affGraphic.h"

void pause();
 
int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL

    /*int n, mode;

    n = demandeTaille();
    if (n == -1) {
        printf("Valeur donnée non supérieur à 3.\n");
        exit(1);
    }

    mode = demandeMode();

    morpion * M = creerMorpion (n);
    jouePartie(M, mode);*/

    initFenetre();

    int n, mode;

    n = demandeTaille();
    if (n == -1) {
        printf("Valeur donnée non supérieur à 3.\n");
        exit(1);
    }

    mode = demandeMode();

    morpion * M = creerMorpion (n);

    affichageMorpion(M);

    pause();
 
    SDL_Quit(); // Arrêt de la SDL
 
    return EXIT_SUCCESS; // Fermeture du programme
}

void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}