#ifndef MAIN_C_CHOIX_H
#define MAIN_C_CHOIX_H

#include "../../source/joueur/joueur.h"
#include "../../source/cartes/cartes.h"
#include "../../source/tableau/tableau.h"
#include "../galerie/galerie.h"
#include "../penalites/penalites.h"
#include "../reparation/reparation.h"
#include "../eboulement/eboulement.h"
#include "../map/map.h"
#include "../pioche/pioche.h"

void choixJoueurLorsDeSonTour(ALLEGRO_EVENT *event, ALLEGRO_BITMAP *pepite3, ALLEGRO_BITMAP *arriveeGrotte,
                              ALLEGRO_BITMAP *arrivee, Joueur *joueur1, Action pioche[NB_CARTES], Rect p,
                              int *partieCommencee, int *decalageX, int *decalageY, int *glisserDeposerGalerie,
                              int *glisserDeposerPenalite, int *glisserDeposerReparation, int *carteEboulement,
                              int *carteMap, int *clicPiocheOuDefausse, int *modificationPioche,
                              int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6);

void deplacementCarte(ALLEGRO_EVENT* event, ALLEGRO_BITMAP* arriveeDos, ALLEGRO_BITMAP* entree, ALLEGRO_BITMAP* dosPioche,
                      ALLEGRO_FONT* fontPartie, Action pioche[NB_CARTES], Rect k, Rect j, Rect g, Rect f, Rect h, Rect p,
                      int i, Joueur* joueur1, int glisserDeposerGalerie, int glisserDeposerPenalite, int glisserDeposerReparation,
                      int decalageX, int decalageY, int carte1, int carte2, int carte3, int carte4, int carte5, int carte6);

void relachementCarte(ALLEGRO_EVENT* event, ALLEGRO_BITMAP* entree, ALLEGRO_BITMAP* dosPioche, Arrivee arrivee[NB_ARRIVEES],
                      Action pioche[NB_CARTES], ALLEGRO_FONT* fontPartie,  Rect k, Rect j, Rect g, Rect f, Rect h, Rect p,
                      int i, Joueur* joueur1, Joueur* joueur2, Joueur* joueur3, int* modificationPioche,
                      int* glisserDeposerGalerie, int* glisserDeposerPenalite, int* glisserDeposerReparation, int* decalageX,
                      int* decalageY, int* carte1, int* carte2, int* carte3, int* carte4, int* carte5, int* carte6);
#endif