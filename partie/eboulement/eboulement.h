#ifndef MAIN_C_EBOULEMENT_H
#define MAIN_C_EBOULEMENT_H

#include "../../source/joueur/joueur.h"
#include "../../source/cartes/cartes.h"
#include "../../source/tableau/tableau.h"

void clicDansCarteEboulement(ALLEGRO_EVENT *event, Joueur *joueur, int *partieCommencee, int* carteEboulement,
                             int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6);
void clicDansGalerieAvecEboulement(ALLEGRO_EVENT *event, Rect p, Joueur* joueur, Action pioche[NB_CARTES],
                                   int *modificationPioche, int *carteEboulement,
                                   int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6);

#endif