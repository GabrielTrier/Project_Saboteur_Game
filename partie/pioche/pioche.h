#ifndef MAIN_C_PIOCHE_H
#define MAIN_C_PIOCHE_H

#include "../../source/joueur/joueur.h"
#include "../../source/cartes/cartes.h"
#include "../../source/tableau/tableau.h"

void clicPiocheOuDefaussePuisCarte(ALLEGRO_EVENT *event, int *partieCommencee, int* clicPiocheOuDefausse);
void clicDansCarteApresPiocheouDefausse(ALLEGRO_EVENT* event, Joueur* joueur, Action pioche[NB_CARTES],
                                        int* clicPiocheOuDefausse, int* modificationPioche);

#endif