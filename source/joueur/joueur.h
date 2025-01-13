#ifndef PROJETSABOTEUR_JOUEUR_H
#define PROJETSABOTEUR_JOUEUR_H
#include <stdio.h>
#include <allegro5/allegro.h>
#include <assert.h>
#include "../saisie/saisie.h"
#include "../cartes/cartes.h"
#include "../../menu/menu.h"
#include "../../rectangle.h"
#define NB_CARTES_JOUEUR 6

struct Action;
struct Pepite;
struct Arrivee;

typedef struct {
    char nom;
    int score, role, penalite, lampe, chariot, pioche;
    ALLEGRO_BITMAP* logo;
    ALLEGRO_BITMAP* image;
    Action piocheJoueur[NB_CARTES_JOUEUR];
}Joueur;

void distributionRoles(int nbJoueurs, int* modificationPioche, Action pioche[NB_CARTES],
                       ALLEGRO_BITMAP* saboteur, ALLEGRO_BITMAP* nain, ALLEGRO_EVENT* event,
                       Joueur* joueur1, Joueur* joueur2, Joueur* joueur3, Joueur* joueur4);
void affichageRectangleRoleJoueur(ALLEGRO_BITMAP* fond, Rect r);
void affichageCarteRole(Joueur joueur, ALLEGRO_BITMAP* nain, ALLEGRO_BITMAP* saboteur);
void affichageRoleJoueur1(ALLEGRO_FONT* font, Rect r, Joueur joueur, ALLEGRO_BITMAP* nain, ALLEGRO_BITMAP* saboteur,
                          ALLEGRO_BITMAP* fond);
void affichageRoleJoueur2(ALLEGRO_FONT* font, Rect r, Joueur joueur, ALLEGRO_BITMAP* nain, ALLEGRO_BITMAP* saboteur,
                          ALLEGRO_BITMAP* fond;
void affichageRoleJoueur3(ALLEGRO_FONT* font, Rect r, Joueur joueur, ALLEGRO_BITMAP* nain, ALLEGRO_BITMAP* saboteur,
                          ALLEGRO_BITMAP* fond);
void affichageRoleJoueur4(ALLEGRO_FONT* font, Rect r, Joueur joueur, ALLEGRO_BITMAP* nain, ALLEGRO_BITMAP* saboteur,
                          ALLEGRO_BITMAP* fond);
void affichageRoles(ALLEGRO_FONT* font, ALLEGRO_EVENT* event, ALLEGRO_BITMAP* saboteur, ALLEGRO_BITMAP* nain,
                    ALLEGRO_BITMAP* fond, Joueur* joueur1, Joueur* joueur2, Joueur* joueur3, Joueur* joueur4,
                    Rect r, int nbJoueurs, int* partieCommencee);
#endif