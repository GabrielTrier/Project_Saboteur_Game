//
// Created by kenza on 31-Mar-21.
//

#ifndef PROJETSABOTEUR_AIDE_H
#define PROJETSABOTEUR_AIDE_H

#include <allegro5/allegro.h>

#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 750

void passageSlideSuivante(int* aide, ALLEGRO_BITMAP* regle2, ALLEGRO_BITMAP* regle3,
                          ALLEGRO_BITMAP* regle4, ALLEGRO_BITMAP* regle5);
void passageSlidePrecedente(int* aide, ALLEGRO_BITMAP* regle1, ALLEGRO_BITMAP* regle2,
                            ALLEGRO_BITMAP* regle3, ALLEGRO_BITMAP* regle4);
void revenirMenu(int* aide, int* menu, ALLEGRO_BITMAP* fond);

#endif //PROJETSABOTEUR_AIDE_H
