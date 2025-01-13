#ifndef PROJETSABOTEUR_MENU_H
#define PROJETSABOTEUR_MENU_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <assert.h>
#include <stdio.h>
#include "../source/joueur/joueur.h"
#include "../source/score/score.h"
#include "../source/cartes/cartes.h"
#include "../rectangle.h"
#include "../action.h"
#include "../pepite.h"
#include "../arrivee.h"

#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 750

Rect initRectangle(int i);
void placerRectanglesDebutPartie(Rect* r, int i);
void dessinerRectangle(Rect r);
void ecrireTexte(ALLEGRO_FONT* font, Rect r, int i);
void actualisationRectangles(Rect r, int i, int menu, ALLEGRO_FONT* font, ALLEGRO_MOUSE_STATE souris);
void passageMenuAPartie(ALLEGRO_EVENT* event, ALLEGRO_FONT* font, ALLEGRO_BITMAP* fond,ALLEGRO_BITMAP* regle1,
                        ALLEGRO_BITMAP* regle2,ALLEGRO_BITMAP* regle3,ALLEGRO_BITMAP* regle4,ALLEGRO_BITMAP* regle5,int* aide,
                        Rect r, int* menu, int* menu1, int* isEnd, int nbJoueurs);
void demanderNombreJoueurs(ALLEGRO_FONT* font, Rect r);
void passageNbJoueursAPartie(ALLEGRO_EVENT* event, ALLEGRO_FONT* font, ALLEGRO_BITMAP* fond,
                             ALLEGRO_BITMAP* saboteur, ALLEGRO_BITMAP* nain, Rect r,
                             int *menu1, int *nbJoueurs, int* modificationPioche, Action pioche[NB_CARTES],
                             Joueur* joueur1, Joueur* joueur2, Joueur* joueur3, Joueur* joueur4, int* partieCommencee);
void actualisationRectanglesJoueurs(Rect r, int i, int menu1, ALLEGRO_FONT* font, ALLEGRO_MOUSE_STATE souris);
void texte2Joueurs(ALLEGRO_FONT* font);
void texte3Joueurs(ALLEGRO_FONT* font);
void texte4Joueurs(ALLEGRO_FONT* font);
void dessinerRectanglesJoueurs(Rect r);

#endif