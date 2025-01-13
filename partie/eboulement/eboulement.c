#include "eboulement.h"

void clicDansCarteEboulement(ALLEGRO_EVENT *event, Joueur *joueur, int *partieCommencee, int* carteEboulement,
                             int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6) {
    if (*partieCommencee) {
        if (event->mouse.x >= 300 && event->mouse.x <= 370 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
            joueur->piocheJoueur[0].eboulement == 1) {
            *carteEboulement = 1;
            *carte1 = 1;
        } else if (event->mouse.x >= 400 && event->mouse.x <= 470 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[1].eboulement == 1) {
            *carte2 = 1;
        } else if (event->mouse.x >= 500 && event->mouse.x <= 570 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[2].eboulement == 1) {
            *carteEboulement = 1;
            *carte3 = 1;
        } else if (event->mouse.x >= 600 && event->mouse.x <= 670 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[3].eboulement == 1) {
            *carteEboulement = 1;
            *carte4 = 1;
        } else if (event->mouse.x >= 700 && event->mouse.x <= 770 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[4].eboulement == 1) {
            *carteEboulement = 1;
            *carte5 = 1;
        } else if (event->mouse.x >= 800 && event->mouse.x <= 870 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[5].eboulement == 1) {
            *carteEboulement = 1;
            *carte6 = 1;
        }
    }
}

void clicDansGalerieAvecEboulement(ALLEGRO_EVENT *event, Rect p, Joueur* joueur, Action pioche[NB_CARTES],
                                   int *modificationPioche, int *carteEboulement,
                                   int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6){
    if (*carteEboulement) {
        int autre = 0;
        if (event->mouse.x >= p.x && event->mouse.x <= p.x + (p.largeur / 7)) {
            if (event->mouse.y >= p.y && event->mouse.y <= p.y + (p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x, p.y, p.x + (p.largeur / 7), p.y + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (p.hauteur / 5) && event->mouse.y <= p.y + (2 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x, p.y + 100, p.x + (p.largeur / 7), p.y + 100 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (2 * p.hauteur / 5) && event->mouse.y <= p.y + (3 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x, p.y + 200, p.x + (p.largeur / 7), p.y + 200 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (3 * p.hauteur / 5) && event->mouse.y <= p.y + (4 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x, p.y + 300, p.x + (p.largeur / 7), p.y + 300 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (4 * p.hauteur / 5) && event->mouse.y <= p.y + p.hauteur) {
                al_draw_filled_rectangle(p.x, p.y + 400, p.x + (p.largeur / 7), p.y + 400 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else { autre = 1; }
        } else if (event->mouse.x >= p.x + (p.largeur / 7) && event->mouse.x <= p.x + (2 * p.largeur / 7)) {
            if (event->mouse.y >= p.y && event->mouse.y <= p.y + (p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 157, p.y, p.x + 157 + (p.largeur / 7), p.y + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (p.hauteur / 5) && event->mouse.y <= p.y + (2 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 157, p.y + 100, p.x + 157 + (p.largeur / 7), p.y + 100 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (2 * p.hauteur / 5) && event->mouse.y <= p.y + (3 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 157, p.y + 200, p.x + 157 + (p.largeur / 7), p.y + 200 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (3 * p.hauteur / 5) && event->mouse.y <= p.y + (4 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 157, p.y + 300, p.x + 157 + (p.largeur / 7), p.y + 300 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (4 * p.hauteur / 5) && event->mouse.y <= p.y + p.hauteur) {
                al_draw_filled_rectangle(p.x + 157, p.y + 400, p.x + 157 + (p.largeur / 7), p.y + 400 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else { autre = 1; }
        } else if (event->mouse.x >= p.x + (2 * p.largeur / 7) && event->mouse.x <= p.x + (3 * p.largeur / 7)) {
            if (event->mouse.y >= p.y && event->mouse.y <= p.y + (p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 314, p.y, p.x + 314 + (p.largeur / 7), p.y + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (p.hauteur / 5) && event->mouse.y <= p.y + (2 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 314, p.y + 100, p.x + 314 + (p.largeur / 7), p.y + 100 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (2 * p.hauteur / 5) && event->mouse.y <= p.y + (3 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 314, p.y + 200, p.x + 314 + (p.largeur / 7), p.y + 200 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (3 * p.hauteur / 5) && event->mouse.y <= p.y + (4 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 314, p.y + 300, p.x + 314 + (p.largeur / 7), p.y + 300 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (4 * p.hauteur / 5) && event->mouse.y <= p.y + p.hauteur) {
                al_draw_filled_rectangle(p.x + 314, p.y + 400, p.x + 314 + (p.largeur / 7), p.y + 400 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else { autre = 1; }
        } else if (event->mouse.x >= p.x + (3 * p.largeur / 7) && event->mouse.x <= p.x + (4 * p.largeur / 7)) {
            if (event->mouse.y >= p.y && event->mouse.y <= p.y + (p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 471, p.y, p.x + 471 + (p.largeur / 7), p.y + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (p.hauteur / 5) && event->mouse.y <= p.y + (2 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 471, p.y + 100, p.x + 471 + (p.largeur / 7), p.y + 100 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (2 * p.hauteur / 5) && event->mouse.y <= p.y + (3 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 471, p.y + 200, p.x + 471 + (p.largeur / 7), p.y + 200 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (3 * p.hauteur / 5) && event->mouse.y <= p.y + (4 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 471, p.y + 300, p.x + 471 + (p.largeur / 7), p.y + 300 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (4 * p.hauteur / 5) && event->mouse.y <= p.y + p.hauteur) {
                al_draw_filled_rectangle(p.x + 471, p.y + 400, p.x + 471 + (p.largeur / 7), p.y + 400 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else { autre = 1; }
        } else if (event->mouse.x >= p.x + (4 * p.largeur / 7) && event->mouse.x <= p.x + (5 * p.largeur / 7)) {
            if (event->mouse.y >= p.y && event->mouse.y <= p.y + (p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 628, p.y, p.x + 628 + (p.largeur / 7), p.y + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (p.hauteur / 5) && event->mouse.y <= p.y + (2 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 628, p.y + 100, p.x + 628 + (p.largeur / 7), p.y + 100 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (2 * p.hauteur / 5) && event->mouse.y <= p.y + (3 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 628, p.y + 200, p.x + 628 + (p.largeur / 7), p.y + 200 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (3 * p.hauteur / 5) && event->mouse.y <= p.y + (4 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 628, p.y + 300, p.x + 628 + (p.largeur / 7), p.y + 300 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (4 * p.hauteur / 5) && event->mouse.y <= p.y + p.hauteur) {
                al_draw_filled_rectangle(p.x + 628, p.y + 400, p.x + 628 + (p.largeur / 7), p.y + 400 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else { autre = 1; }
        } else if (event->mouse.x >= p.x + (5 * p.largeur / 7) && event->mouse.x <= p.x + (6 * p.largeur / 7)) {
            if (event->mouse.y >= p.y && event->mouse.y <= p.y + (p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 785, p.y, p.x + 785 + (p.largeur / 7), p.y + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (p.hauteur / 5) && event->mouse.y <= p.y + (2 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 785, p.y + 100, p.x + 785 + (p.largeur / 7), p.y + 100 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (2 * p.hauteur / 5) && event->mouse.y <= p.y + (3 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 785, p.y + 200, p.x + 785 + (p.largeur / 7), p.y + 200 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (3 * p.hauteur / 5) && event->mouse.y <= p.y + (4 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 785, p.y + 300, p.x + 785 + (p.largeur / 7), p.y + 300 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (4 * p.hauteur / 5) && event->mouse.y <= p.y + p.hauteur) {
                al_draw_filled_rectangle(p.x + 785, p.y + 400, p.x + 785 + (p.largeur / 7), p.y + 400 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else { autre = 1; }
        } else if (event->mouse.x >= p.x + (6 * p.largeur / 7) && event->mouse.x <= p.x + p.largeur) {
            if (event->mouse.y >= p.y && event->mouse.y <= p.y + (p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 942, p.y, p.x + 942 + (p.largeur / 7), p.y + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (p.hauteur / 5) && event->mouse.y <= p.y + (2 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 942, p.y + 100, p.x + 942 + (p.largeur / 7), p.y + 100 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (2 * p.hauteur / 5) && event->mouse.y <= p.y + (3 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 942, p.y + 200, p.x + 942 + (p.largeur / 7), p.y + 200 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (3 * p.hauteur / 5) && event->mouse.y <= p.y + (4 * p.hauteur / 5)) {
                al_draw_filled_rectangle(p.x + 942, p.y + 300, p.x + 942 + (p.largeur / 7), p.y + 300 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else if (event->mouse.y >= p.y + (4 * p.hauteur / 5) && event->mouse.y <= p.y + p.hauteur) {
                al_draw_filled_rectangle(p.x + 942, p.y + 400, p.x + 942 + (p.largeur / 7), p.y + 400 + (p.hauteur / 5),
                                         al_map_rgb(200, 200, 200));
            } else { autre = 1; }
        } else { autre = 1; }

        if (autre) {
            printf("Veuillez recommencer et appuyer sur une carte du plateau.");
            autre = 0;
        }
        else {
            carteUtilisee(pioche, &joueur, &modificationPioche, &carte1, &carte2, &carte3, &carte4, &carte5, &carte6);
            *carteEboulement = 0;
        }
    }
}