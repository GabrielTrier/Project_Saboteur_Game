#ifndef PROJETSABOTEUR_SAISIE_H
#define PROJETSABOTEUR_SAISIE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>

#include "../../menu/menu.h"
#include "../../rectangle.h"

void saisirnom(int indiceSaisie, char* saisie, int* modeSaisie, ALLEGRO_EVENT* event, Rect r);
void determinerSiSaisie(ALLEGRO_EVENT* event, Rect r, int* modeSaisie, int* indiceSaisie, char saisie[100]);

#endif