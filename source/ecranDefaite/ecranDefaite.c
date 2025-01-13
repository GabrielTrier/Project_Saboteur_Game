//
// Created by gabri on 4/4/2021.
//

#include "ecranDefaite.h"

void affichage(ALLEGRO_BITMAP* fondMine,ALLEGRO_BITMAP* nainEcran,ALLEGRO_BITMAP* saboteurEcran,Image nain,Image saboteur) {
    saboteur.x = 300;
    saboteur.y = 300;
    nain.x = 800;
    nain.y = 200;
    al_draw_scaled_bitmap(fondMine, 0, 0, 736, 323, 0, 0, 1500, 750, 0);
    al_draw_scaled_bitmap(nainEcran, 0, 0, 500,500,nain.x,nain.y,300,300,0);
    al_draw_scaled_bitmap(saboteurEcran,0,0,235,400,saboteur.x,saboteur.y,235,300,0);
}

void actualisation(ALLEGRO_BITMAP* fondMine,ALLEGRO_BITMAP* nainEcran,ALLEGRO_BITMAP* saboteurEcran,Image nain,Image saboteur){
    int i=0;
    saboteur.x = 300;
    saboteur.y = 300;
    saboteur.largeur = 235;
    saboteur.hauteur = 300;
    nain.x = 800;
    nain.y = 200;
    nain.largeur = 300;
    nain.hauteur = 300;
    for(i=0;i<2000;i++) {
        al_draw_scaled_bitmap(fondMine, 0, 0, 736, 323, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        al_draw_scaled_bitmap(nainEcran, 0, 0, 500, 500, (nain.x+ rand()%100 -rand()% 100), (nain.y+ rand()%100 -rand()% 50), nain.largeur, nain.hauteur, 0);
        al_draw_scaled_bitmap(saboteurEcran, 0, 0, 235, 400, saboteur.x+ rand()%100 -rand()% 50, saboteur.y+ rand()%100 -rand()% 50, saboteur.largeur, saboteur.hauteur, 0);
    }
}

void replacementImage(ALLEGRO_BITMAP* fondMine,ALLEGRO_BITMAP* nainEcran,ALLEGRO_BITMAP* saboteurEcran,Image nain,Image saboteur){
    if (nain.x <SCREEN_WIDTH/2 ) { nain.x = SCREEN_WIDTH/2; }
    if (nain.x + nain.largeur > (SCREEN_WIDTH/2)) { nain.x = (SCREEN_WIDTH/2)-nain.largeur; }
    if (nain.y < 0) { nain.y = 0; }
    if (nain.y + nain.hauteur > SCREEN_HEIGHT) { nain.y = SCREEN_HEIGHT-nain.hauteur; }
    if (saboteur.x < 0) { saboteur.x = 0; }
    if (saboteur.x + saboteur.largeur > SCREEN_WIDTH) { saboteur.x = SCREEN_WIDTH-saboteur.largeur; }
    if (saboteur.y < 0) { saboteur.y = 0; }
    if (saboteur.y + saboteur.hauteur > SCREEN_HEIGHT) { saboteur.y = SCREEN_HEIGHT-saboteur.hauteur; }
}

void initPierre(Pierre pierre[]) {
    int i = 0;
    for (i = 0; i < NB_MAX_PIERRE; i++) {
        pierre[i].vitesse = 1;
        pierre[i].actif = 1;
        pierre[i].x = pierre[i].width + rand() % (SCREEN_WIDTH - (pierre[i].width * 4));
        pierre[i].y = pierre[i].height + rand() % (SCREEN_HEIGHT - (pierre[i].height * 4));
        pierre[i].width = 1 + rand() % 20;
        pierre[i].height = pierre[i].width;
    }
}

void affichePierre(Pierre pierre[]) {
    int i = 0;
    for (i = 0; i < NB_MAX_PIERRE; i++) {
        if (pierre[i].actif) {
            al_draw_filled_ellipse(pierre[i].x, pierre[i].y, pierre[i].width, pierre[i].height,
                                   al_map_rgb(200, 200, 200));
        }
    }
}

void mouvementPierre(Pierre pierre[]) {
    int i = 0;
    for (i = 0; i < NB_MAX_PIERRE; i++) {
        if (pierre[i].actif) {
            pierre[i].x -= pierre[i].vitesse;
            if (pierre[i].x - pierre[i].width < 0) {
                pierre[i].actif = 0;
            }
        }
    }
}

void apparitionPierre(Pierre pierre[]){
    int i = 0;
    for (i = 0; i < NB_MAX_PIERRE; i++) {
        if (!pierre[i].actif && rand() % 1000 < 2) {
            pierre[i].x = SCREEN_WIDTH - pierre[i].width;
            pierre[i].y = pierre[i].height + rand() % (SCREEN_HEIGHT - (pierre[i].height * 4));
            pierre[i].actif = 1;
        }
    }
}

void affichageEcranSaboteur(ALLEGRO_BITMAP* fondMine, ALLEGRO_BITMAP* nainEcran, ALLEGRO_BITMAP* saboteurEcran,
                            int victoireSaboteur, Pierre* pierre, Image nainDefaite, Image saboteurDefaite){
    if (victoireSaboteur){
        replacementImage(fondMine,nainEcran,saboteurEcran,nainDefaite,saboteurDefaite);
        actualisation(fondMine,nainEcran,saboteurEcran,saboteurDefaite,nainDefaite);
        init_pierre(&pierre);
        affichePierre(&pierre);
        apparitionPierre(&pierre);
        mouvementPierre(&pierre);
    }
}