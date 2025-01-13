#ifndef PROJETSABOTEUR_ECRANDEFAITE_H
#define PROJETSABOTEUR_ECRANDEFAITE_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <assert.h>
#include "../joueur/joueur.h"
#include "../score/score.h"
#include <stdio.h>
#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 750
#define NB_MAX_PIERRE 5

typedef struct {
    int x, y;
    int vitesse;
    int width, height;
    int actif;
} Pierre;

typedef struct{
    ALLEGRO_BITMAP* image;
    int x, y, largeur, hauteur;
}Image;

void affichage(ALLEGRO_BITMAP* fondMine,ALLEGRO_BITMAP* nainEcran,ALLEGRO_BITMAP* saboteurEcran,Image nain,Image saboteur);
void actualisation(ALLEGRO_BITMAP* fondMine,ALLEGRO_BITMAP* nainEcran,ALLEGRO_BITMAP* saboteurEcran,Image nain,Image saboteur);
void replacementImage(ALLEGRO_BITMAP* fondMine,ALLEGRO_BITMAP* nainEcran,ALLEGRO_BITMAP* saboteurEcran,Image nain,Image saboteur);
void init_pierre(Pierre pierre[]);
void affichePierre(Pierre pierre[]);
void mouvementPierre(Pierre pierre[]);
void apparitionPierre(Pierre pierre[]);
void affichageEcranSaboteur(ALLEGRO_BITMAP* fondMine, ALLEGRO_BITMAP* nainEcran, ALLEGRO_BITMAP* saboteurEcran,
                            int victoireSaboteur, Pierre* pierre, Image nainDefaite, Image saboteurDefaite);

#endif