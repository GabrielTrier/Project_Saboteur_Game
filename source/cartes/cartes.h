#ifndef PROJETSABOTEUR_CARTES_H
#define PROJETSABOTEUR_CARTES_H
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <assert.h>
#include <stdlib.h>

#include "../joueur/joueur.h"
#include "../../partie/galerie/galerie.h"
#include "../../action.h"
#include "../../pepite.h"
#include "../../arrivee.h"

#define NB_CARTES 67
#define NB_PEPITES 3
#define NB_ARRIVEES 3

struct Joueur;

void placerCarteEntreeMine(ALLEGRO_BITMAP* entree);
void placerCartesArrivee(ALLEGRO_BITMAP* arrivee);
void initCartesAction(ALLEGRO_BITMAP* galerieCarrefour, ALLEGRO_BITMAP* galerieChemin, ALLEGRO_BITMAP* galerieImpasse,
                      ALLEGRO_BITMAP* galerieTCote, ALLEGRO_BITMAP* galerieTHaut, ALLEGRO_BITMAP* eboulement,
                      ALLEGRO_BITMAP* map, ALLEGRO_BITMAP* chariotD, ALLEGRO_BITMAP* lanterneD, ALLEGRO_BITMAP* piocheD,
                      ALLEGRO_BITMAP* chariotR, ALLEGRO_BITMAP* lanterneR, ALLEGRO_BITMAP* piocheR,
                      ALLEGRO_BITMAP* chariotLanterneR, ALLEGRO_BITMAP* chariotPiocheR,
                      ALLEGRO_BITMAP* lanternePiocheR, Action pioche[NB_CARTES]);
void melangePioche(Action pioche[NB_CARTES]);
Action piocheCarte(Action pioche[NB_CARTES], int* modificationPioche);
void distributionCartesDebut(Joueur* joueur, int* modificationPioche, Action pioche[NB_CARTES]);
void melangePepites(Pepite pepites[NB_PEPITES]);
void initCartesPepite(ALLEGRO_BITMAP* pepite1, ALLEGRO_BITMAP* pepite2, ALLEGRO_BITMAP* pepite3, Pepite pepites[NB_PEPITES]);
void affichageCartesJoueur(Joueur* joueur);
void initCartesArrivee(ALLEGRO_BITMAP* pepite3, ALLEGRO_BITMAP* grotte, Arrivee arrivee[NB_ARRIVEES]);
void melangeCartesArrivee(Arrivee arrivee[NB_ARRIVEES]);

#endif
