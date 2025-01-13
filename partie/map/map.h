#ifndef MAIN_C_MAP_H
#define MAIN_C_MAP_H

#include "../../source/joueur/joueur.h"
#include "../../source/cartes/cartes.h"
#include "../../source/tableau/tableau.h"

void clicDansCarteMap(ALLEGRO_EVENT *event, Joueur *joueur, int *partieCommencee, int* carteMap,
                      int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6);
void clicSurArriveeAvecMap(ALLEGRO_EVENT *event, ALLEGRO_BITMAP* pepite, ALLEGRO_BITMAP* grotte,
                           Joueur* joueur, Action pioche[NB_CARTES], Arrivee arrivee[NB_ARRIVEES],
                           int *modificationPioche, int *carteMap,
                           int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6);

#endif