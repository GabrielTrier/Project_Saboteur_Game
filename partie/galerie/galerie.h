#ifndef MAIN_C_GALERIE_H
#define MAIN_C_GALERIE_H

#include "../../source/joueur/joueur.h"
#include "../../source/tableau/tableau.h"
#include "../../action.h"

#define PLATEAU_COLONNES 7
#define PLATEAU_LIGNES 5

typedef struct{
    int x, y, largeur, hauteur;
    ALLEGRO_BITMAP* image;
}Plateau;

void clicDansCarteGalerie(ALLEGRO_EVENT* event, Joueur* joueur, int* decalageX, int* decalageY, int* glisserDeposer,
                          int* carte1, int* carte2, int* carte3, int* carte4, int* carte5, int* carte6, int* partieCommencee);
void replacerSiDebordement(Joueur* joueur, int largeur, int hauteur);
void actualisationCartes(ALLEGRO_EVENT* event, Joueur* joueur, int decalageX, int decalageY,
                        int carte1, int carte2, int carte3, int carte4, int carte5, int carte6);
void carteUtilisee(Action pioche[NB_CARTES], Joueur *joueur, int* modificationPioche, int* carte1, int* carte2,
                   int* carte3, int* carte4, int* carte5, int* carte6);
void carteGalerieDansPlateau(ALLEGRO_EVENT *event, Rect p, Rect k, Rect j, Rect g, Rect f, Rect h, int i,
                             ALLEGRO_FONT *fontPartie, ALLEGRO_BITMAP *arrivee, ALLEGRO_BITMAP *entree,
                             ALLEGRO_BITMAP *dosPioche, Joueur *joueur, Action pioche[NB_CARTES],
                             int *modificationPioche, int *glisserDeposerGalerie,
                             int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6);

#endif