//
// Created by gabri on 3/29/2021.
//

#ifndef PROJETSABOTEUR_TABLEAU_H
#define PROJETSABOTEUR_TABLEAU_H
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <assert.h>
#include "../../menu/menu.h"
#include "../cartes/cartes.h"
#include "../plateau/plateau.h"
#include "../../rectangle.h"
#include "../joueur/joueur.h"
#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 750

void affichagePlateauJeu(Rect k, Rect j, Rect g, Rect f, Rect h, Rect p, int i,ALLEGRO_FONT*fontPartie, ALLEGRO_BITMAP* arrivee,
                         ALLEGRO_BITMAP* entree, ALLEGRO_BITMAP* dosPioche, Joueur* joueur);
Rect iniRectanglehaut(int i);
void dessinerDefausse(ALLEGRO_BITMAP* dosPioche);
void dessinerPioche(ALLEGRO_BITMAP* dosPioche);
void placerRectanglehaut(Rect* r, int i);
void dessinerRectangleDuHaut(ALLEGRO_FONT* fontPartie,Rect r);
Rect inirectangle_pannejoueur(int i);
void dessinerRectangle_pannejoueur(ALLEGRO_FONT*fontPartie,Rect* j);
void placerRectanglepannejoueur(Rect* rectangle, int i);
Rect RectangleJoueur1(int i);
void placerRectanglejoueur1(Rect* j, int i);
void dessinerRectangleJoueur1(ALLEGRO_FONT*fontPartie,Rect* j);
Rect RectangleJoueur2(int i);
void placerRectanglejoueur2(Rect* j, int i);
void dessinerRectangleJoueur2(ALLEGRO_FONT*fontPartie,Rect* j);
Rect RectangleJoueur3(int i);
void placerRectanglejoueur3(Rect* j, int i);
void dessinerRectangleJoueur3(ALLEGRO_FONT*fontPartie,Rect* j);
#endif //PROJETSABOTEUR_TABLEAU_H
