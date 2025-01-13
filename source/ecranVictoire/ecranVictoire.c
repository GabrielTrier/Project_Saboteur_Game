#include "ecranVictoire.h"

void afficheOr(Or or[NB_MAX_OR]) {
    int i = 0;
    for (i = 0; i < NB_MAX_OR ; i++) {
        if (or[i].actif) {
            al_draw_filled_ellipse(or[i].x, or[i].y, or[i].width, or[i].height,
                                   al_map_rgb(255, 200, 0));
        }
    }
}

void initOr(Or or[NB_MAX_OR]) {
    int i = 0;
    for (i = 0; i < NB_MAX_OR; i++) {
        or[i].vitesse = 1;
        or[i].actif = 1;
        or[i].x = or[i].width + rand() % (1500-1100)+1100;
        or[i].y = or[i].height + rand() % (500);
        or[i].width = 6;
        or[i].height = or[i].width;
    }
}

void apparitionOr(Or or[NB_MAX_OR]) {
    int i = 0;
    for (i = 0; i < NB_MAX_OR; i++) {
        if (!or[i].actif && rand() % 1000 < 2) {
            or[i].x = SCREEN_WIDTH - or[i].width;
            or[i].y = or[i].height + rand() % (SCREEN_HEIGHT - (or[i].height * 2));
            or[i].actif = 1;
        }
    }
}