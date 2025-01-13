#ifndef MAIN_C_ECRANVICTOIRE_H
#define MAIN_C_ECRANVICTOIRE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 750

#define NB_MAX_OR 50

typedef struct {
    int x, y, vitesse, width, height, actif;
} Or;

void initOr(Or or[NB_MAX_OR]);
void afficheOr(Or or[NB_MAX_OR]);
void apparitionOr(Or or[NB_MAX_OR]);

#endif