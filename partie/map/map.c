#include "map.h"

void clicDansCarteMap(ALLEGRO_EVENT *event, Joueur *joueur, int *partieCommencee, int* carteMap,
                      int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6) {
    if (*partieCommencee) {
        if (event->mouse.x >= 300 && event->mouse.x <= 370 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
            joueur->piocheJoueur[0].map == 1) {
            *carteMap = 1;
            *carte1 = 1;
        } else if (event->mouse.x >= 400 && event->mouse.x <= 470 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[1].map == 1) {
            *carteMap = 1;
            *carte2 = 1;
        } else if (event->mouse.x >= 500 && event->mouse.x <= 570 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[2].map == 1) {
            *carteMap = 1;
            *carte3 = 1;
        } else if (event->mouse.x >= 600 && event->mouse.x <= 670 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[3].map == 1) {
            *carteMap = 1;
            *carte4 = 1;
        } else if (event->mouse.x >= 700 && event->mouse.x <= 770 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[4].map == 1) {
            *carteMap = 1;
            *carte5 = 1;
        } else if (event->mouse.x >= 800 && event->mouse.x <= 870 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[5].map == 1) {
            *carteMap = 1;
            *carte6 = 1;
        }
    }
}

void clicSurArriveeAvecMap(ALLEGRO_EVENT *event, ALLEGRO_BITMAP* pepite, ALLEGRO_BITMAP* grotte,
                           Joueur* joueur, Action pioche[NB_CARTES], Arrivee arrivee[NB_ARRIVEES],
                           int *modificationPioche, int *carteMap,
                           int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6){
    if (*carteMap) {
        int autre = 0;
        if (event->mouse.x >= 1400 && event->mouse.x <= 1500) {
            if (event->mouse.y >= 250 && event->mouse.y <= 350) {
                if(arrivee[0].reussite == 1){
                    al_draw_scaled_bitmap(pepite, 0, 0, 124, 196, 1400,250, 100, 150, 0);
                }
                else if(arrivee[0].reussite == 0){
                    al_draw_scaled_bitmap(grotte, 0, 0, 124, 196, 1400, 250, 100, 150, 0);
                }
            } else if (event->mouse.y >= 425 && event->mouse.y <= 525) {
                if(arrivee[1].reussite == 1){
                    al_draw_scaled_bitmap(pepite, 0, 0, 124, 196, 1400, 425, 100, 150, 0);
                }
                else if(arrivee[1].reussite == 1){
                    al_draw_scaled_bitmap(grotte, 0, 0, 124, 196, 1400, 425, 100, 150, 0);
                }
            } else if (event->mouse.y >= 600 && event->mouse.y <= 700) {
                if(arrivee[2].reussite == 1){
                    al_draw_scaled_bitmap(pepite, 0, 0, 124, 196, 1400, 600, 100, 150, 0);
                }
                else if(arrivee[2].reussite == 1){
                    al_draw_scaled_bitmap(grotte, 0, 0, 124, 196, 1400, 600, 100, 150, 0);
                }
            } else { autre = 1; }
        } else { autre = 1; }

        if (autre) {
            printf("Veuillez recommencer et appuyer sur une carte arrivee.");
            autre = 0;
        }
        else {
            carteUtilisee(pioche, &joueur, &modificationPioche, &carte1, &carte2, &carte3, &carte4, &carte5, &carte6);
            *carteMap = 0;
        }
    }
}