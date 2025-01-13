//
// Created by kenza on 04-Apr-21.
//

#include "score.h"

/*void afficherScore(int nbJoueurs, Joueur joueur1, Joueur joueur2, Joueur joueur3, Joueur joueur4,
                   Rect r, ALLEGRO_FONT* font){
    switch (nbJoueurs) {
        case 2:
            dessinerRectangles2Joueurs(r);
            ecrireScore2Joueurs(font);
            break;
        case 3:
            dessinerRectangles3Joueurs(r);
            ecrireScore3Joueurs(font);
            break;
        case 4:
            dessinerRectangles4Joueurs(r);
            ecrireScore4Joueurs(font);
            break;
    }
}

void dessinerRectangles2Joueurs(Rect r){
    al_draw_filled_rectangle(SCREEN_WIDTH / 2 - r.largeur / 2, SCREEN_HEIGHT / 3 - r.hauteur,
                             SCREEN_WIDTH / 2 + r.largeur / 2, SCREEN_HEIGHT / 3 + r.hauteur / 2,
                             al_map_rgb(255, 200, 150));
    al_draw_filled_rectangle(SCREEN_WIDTH / 2 - r.largeur / 2, 2*SCREEN_HEIGHT / 3 - r.hauteur,
                             SCREEN_WIDTH / 2 + r.largeur / 2, 2*SCREEN_HEIGHT / 3 + r.hauteur / 2,
                             al_map_rgb(255, 200, 150));
}

void dessinerRectangles3Joueurs(Rect r){
    al_draw_filled_rectangle(SCREEN_WIDTH / 2 - r.largeur / 2, SCREEN_HEIGHT / 4 - r.hauteur,
                             SCREEN_WIDTH / 2 + r.largeur / 2,
                             SCREEN_HEIGHT / 4 + r.hauteur / 2, al_map_rgb(255, 200, 150));
    al_draw_filled_rectangle(SCREEN_WIDTH / 2 - r.largeur / 2, SCREEN_HEIGHT / 2 - r.hauteur,
                             SCREEN_WIDTH / 2 + r.largeur / 2,
                             SCREEN_HEIGHT / 2 + r.hauteur / 2, al_map_rgb(255, 200, 150));
    al_draw_filled_rectangle(SCREEN_WIDTH / 2 - r.largeur / 2, 3 * SCREEN_HEIGHT / 4 - r.hauteur,
                             SCREEN_WIDTH / 2 + r.largeur / 2,
                             3 * SCREEN_HEIGHT / 4 + r.hauteur / 2, al_map_rgb(255, 200, 150));
}

void dessinerRectangles4Joueurs(Rect r){
    al_draw_filled_rectangle(SCREEN_WIDTH / 2 - r.largeur / 2, SCREEN_HEIGHT / 5 - r.hauteur,
                             SCREEN_WIDTH / 2 + r.largeur / 2, SCREEN_HEIGHT / 5 + r.hauteur / 3,
                             al_map_rgb(255, 200, 150));
    al_draw_filled_rectangle(SCREEN_WIDTH / 2 - r.largeur / 2, 2*SCREEN_HEIGHT / 5 - r.hauteur,
                             SCREEN_WIDTH / 2 + r.largeur / 2, 2*SCREEN_HEIGHT / 5 + r.hauteur / 3,
                             al_map_rgb(255, 200, 150));
    al_draw_filled_rectangle(SCREEN_WIDTH / 2 - r.largeur / 2, 3*SCREEN_HEIGHT / 5 - r.hauteur,
                             SCREEN_WIDTH / 2 + r.largeur / 2, 3*SCREEN_HEIGHT / 5 + r.hauteur / 3,
                             al_map_rgb(255, 200, 150));
    al_draw_filled_rectangle(SCREEN_WIDTH / 2 - r.largeur / 2, 4*SCREEN_HEIGHT / 5 - r.hauteur,
                             SCREEN_WIDTH / 2 + r.largeur / 2, 4*SCREEN_HEIGHT / 5 + r.hauteur / 3,
                             al_map_rgb(255, 200, 150));
}

void ecrireScore2Joueurs(ALLEGRO_FONT* font){
    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_WIDTH / 2 - 175,
                 SCREEN_HEIGHT / 4 - 80, 0, "Score joueur 1: ");
    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_WIDTH / 2 - 175,
                 SCREEN_HEIGHT / 4 - 80, 0, "Score joueur 2: ");
}

void ecrireScore3Joueurs(ALLEGRO_FONT* font){
    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_WIDTH / 2 - 175,
                 SCREEN_HEIGHT / 4 - 80, 0, "Score joueur 1: ");
    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_WIDTH / 2 - 175,
                 SCREEN_HEIGHT / 4 - 80, 0, "Score joueur 2: ");
    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_WIDTH / 2 - 175,
                 SCREEN_HEIGHT / 4 - 80, 0, "Score joueur 3: ");
}

void ecrireScore4Joueurs(ALLEGRO_FONT* font){
    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_WIDTH / 2 - 175,
                 SCREEN_HEIGHT / 4 - 80, 0, "Score joueur 1: ");
    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_WIDTH / 2 - 175,
                 SCREEN_HEIGHT / 4 - 80, 0, "Score joueur 2: ");
    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_WIDTH / 2 - 175,
                 SCREEN_HEIGHT / 4 - 80, 0, "Score joueur 3: ");
    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_WIDTH / 2 - 175,
                 SCREEN_HEIGHT / 4 - 80, 0, "Score joueur 4: ");
}
 */