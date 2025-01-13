#include "pioche.h"

void clicPiocheOuDefaussePuisCarte(ALLEGRO_EVENT *event, int *partieCommencee, int* clicPiocheOuDefausse){
    if(*partieCommencee){
        if (event->mouse.x >= 1300 && event->mouse.x <= 1500 && event->mouse.y >= 0 && event->mouse.y <= 150){
            *clicPiocheOuDefausse = 1;
        }
    }
}

void clicDansCarteApresPiocheouDefausse(ALLEGRO_EVENT* event, Joueur* joueur, Action pioche[NB_CARTES],
                                        int* clicPiocheOuDefausse, int* modificationPioche){
    if(*clicPiocheOuDefausse) {
        if (event->mouse.x >= 300 && event->mouse.x <= 370 && event->mouse.y >= 32 && event->mouse.y <= 137) {
            joueur->piocheJoueur[0] = piocheCarte(pioche, *modificationPioche);
        } else if (event->mouse.x >= 400 && event->mouse.x <= 470 && event->mouse.y >= 32 && event->mouse.y <= 137) {
            joueur->piocheJoueur[1] = piocheCarte(pioche, *modificationPioche);
        } else if (event->mouse.x >= 500 && event->mouse.x <= 570 && event->mouse.y >= 32 && event->mouse.y <= 137) {
            joueur->piocheJoueur[2] = piocheCarte(pioche, *modificationPioche);
        } else if (event->mouse.x >= 600 && event->mouse.x <= 670 && event->mouse.y >= 32 && event->mouse.y <= 137) {
            joueur->piocheJoueur[3] = piocheCarte(pioche, *modificationPioche);
        } else if (event->mouse.x >= 700 && event->mouse.x <= 770 && event->mouse.y >= 32 && event->mouse.y <= 137) {
            joueur->piocheJoueur[4] = piocheCarte(pioche, *modificationPioche);
        } else if (event->mouse.x >= 800 && event->mouse.x <= 870 && event->mouse.y >= 32 && event->mouse.y <= 137) {
            joueur->piocheJoueur[5] = piocheCarte(pioche, *modificationPioche);
        } else {
            printf("Veuillez recommencer et appuyer sur l'une de vos cartes.");
        }
    }
    *clicPiocheOuDefausse = 0;
}