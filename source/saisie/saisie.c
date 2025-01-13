#include "saisie.h"

void saisirnom(int indiceSaisie, char* saisie, int* modeSaisie, ALLEGRO_EVENT* event, Rect r){
    if(*modeSaisie = 1 && (event->keyboard.keycode >= ALLEGRO_KEY_A && event->keyboard.keycode <=ALLEGRO_KEY_Z || ALLEGRO_KEY_SPACE)){
        saisie[indiceSaisie]= event->keyboard.keycode +('A' - 1);
        indiceSaisie++;
    }
}

void determinerSiSaisie(ALLEGRO_EVENT* event, Rect r, int* modeSaisie, int* indiceSaisie, char saisie[100]){
    if (event->mouse.x >= SCREEN_WIDTH / 2 - r.largeur / 2 && event->mouse.x <= SCREEN_WIDTH / 2 + r.largeur / 2
        && event->mouse.y >= SCREEN_HEIGHT / 4 - r.hauteur && event->mouse.y <= SCREEN_HEIGHT / 4 + r.hauteur / 2) {
        *modeSaisie = 1;
        saisirnom(&indiceSaisie, saisie, modeSaisie, &event, r);
    }
}