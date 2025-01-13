#ifndef MAIN_C_REPARATION_H
#define MAIN_C_REPARATION_H

#include "../galerie/galerie.h"

void clicDansCarteReparation(ALLEGRO_EVENT *event, Joueur *joueur, int *decalageX, int *decalageY, int *glisserDeposerReparation,
                           int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6, int *partieCommencee);
void carteReparationAJoueur(ALLEGRO_EVENT *event, Rect p, Rect k, Rect j, Rect g, Rect f, Rect h, int i, ALLEGRO_FONT *fontPartie,
                            ALLEGRO_BITMAP *arrivee, ALLEGRO_BITMAP *entree, ALLEGRO_BITMAP *dosPioche,
                            Joueur* joueur, Action pioche[NB_CARTES_JOUEUR],
                            int *modificationPioche, int *glisserDeposerReparation,
                            int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6,
                            Joueur* joueur1, Joueur* joueur2, Joueur* joueur3);

#endif