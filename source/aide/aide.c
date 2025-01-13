//
// Created by kenza on 31-Mar-21.
//

#include "aide.h"


void passageSlideSuivante(int* aide, ALLEGRO_BITMAP* regle2, ALLEGRO_BITMAP* regle3, ALLEGRO_BITMAP* regle4, ALLEGRO_BITMAP* regle5){
    if(*aide==4){
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_scaled_bitmap(regle5,0,0,350,396,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
        *aide+=1;
    }
    if(*aide==3){
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_scaled_bitmap(regle4,0,0,700,500,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
        *aide+=1;
    }
    if(*aide==2){
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_scaled_bitmap(regle3,0,0,700,500,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
        *aide+=1;
    }
    if (*aide==1){
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_scaled_bitmap(regle2,0,0,700,500,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
        *aide+=1;
    }
}

void passageSlidePrecedente(int* aide, ALLEGRO_BITMAP* regle1, ALLEGRO_BITMAP* regle2, ALLEGRO_BITMAP* regle3, ALLEGRO_BITMAP* regle4){
    if(*aide==2){
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_scaled_bitmap(regle1,0,0,697,499,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
        *aide-=1;
    }
    if(*aide==3){
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_scaled_bitmap(regle2,0,0,697,499,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
        *aide-=1;
    }
    if(*aide==4){
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_scaled_bitmap(regle3,0,0,697,499,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
        *aide-=1;
    }
    if(*aide==5){
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_scaled_bitmap(regle4,0,0,697,499,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
        *aide-=1;
    }
}

void revenirMenu(int* aide, int* menu, ALLEGRO_BITMAP* fond){
    if (*aide<= 1 || *aide>=5){
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_scaled_bitmap(fond, 0, 0, 1000, 500, 0, 0,
                              SCREEN_WIDTH, SCREEN_HEIGHT,0);
        *menu=1;
    }
}