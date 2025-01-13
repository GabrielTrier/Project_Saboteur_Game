#ifndef MAIN_C_PENALITES_H
#define MAIN_C_PENALITES_H

#include "../../source/tableau/tableau.h"

void clicDansCartePenalite(ALLEGRO_EVENT *event, Joueur *joueur, int *decalageX, int *decalageY, int *glisserDeposerPenalite,
                           int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6, int *partieCommencee);
void cartePenaliteAJoueur(ALLEGRO_EVENT *event, Rect p, Rect k, Rect j, Rect g, Rect f, Rect h, int i,
                          ALLEGRO_FONT *fontPartie, ALLEGRO_BITMAP *arrivee, ALLEGRO_BITMAP *entree,
                          ALLEGRO_BITMAP *dosPioche, Joueur* joueur, Action pioche[NB_CARTES],
                          int *modificationPioche, int *glisserDeposerPenalite,
                          int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6,
                          Joueur* joueur1, Joueur* joueur2, Joueur* joueur3);

#endif