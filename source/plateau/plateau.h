#ifndef PROJETSABOTEUR_PLATEAU_H
#define PROJETSABOTEUR_PLATEAU_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include "../../menu/menu.h"

#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 750

struct Rect;

Rect initRectanglePlateau();
void affichagePlateauGalerie(Rect p);
void affichageLignes(Rect p);
void affichageColonnes(Rect p);

#endif