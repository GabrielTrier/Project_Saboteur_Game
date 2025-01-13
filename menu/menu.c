#include "menu.h"
#include <stdio.h>

Rect initRectangle(int i) {
    Rect rectangle = {0};
    rectangle.largeur = 1000;
    rectangle.hauteur = 100;
    placerRectanglesDebutPartie(&rectangle, i);
    rectangle.color = al_map_rgb(255, 200, 150);
    return rectangle;
}

void placerRectanglesDebutPartie(Rect *r, int i) {
    r->x = SCREEN_WIDTH / 2 - r->largeur / 2;
    r->y = 50 + i * 135;
}

void dessinerRectangle(Rect r) {
    al_draw_filled_rectangle(r.x, r.y, r.largeur + r.x, r.hauteur + r.y, r.color);
}

void ecrireTexte(ALLEGRO_FONT *font, Rect r, int i) {
    switch (i) {
        case 0:
            al_draw_text(font, al_map_rgb(0, 0, 0), r.x + 200, r.y, 0, "Nouvelle partie");
            break;
        case 1:
            al_draw_text(font, al_map_rgb(0, 0, 0), r.x + 130, r.y, 0, "Partie sauvegardée");
            break;
        case 2:
            al_draw_text(font, al_map_rgb(0, 0, 0), r.x + 230, r.y, 0, "Afficher l'aide");
            break;
        case 3:
            al_draw_text(font, al_map_rgb(0, 0, 0), r.x + 140, r.y, 0, "Afficher les scores");
            break;
        case 4:
            al_draw_text(font, al_map_rgb(0, 0, 0), r.x + 360, r.y, 0, "Quitter");
            break;
    }
}

void actualisationRectangles(Rect r, int i, int menu, ALLEGRO_FONT *font, ALLEGRO_MOUSE_STATE souris) {
    if (menu) {
        for (i = 0; i < 5; i++) {
            r = initRectangle(i);
            if (souris.x >= r.x && souris.x <= r.x + r.largeur && souris.y >= r.y && souris.y <= r.y + r.hauteur) {
                r.color = al_map_rgb(205, 150, 100);
            }
            dessinerRectangle(r);
            ecrireTexte(font, r, i);
        }
    }
}

void actualisationRectanglesJoueurs(Rect r, int i, int menu1, ALLEGRO_FONT *font, ALLEGRO_MOUSE_STATE souris) {
    if (menu1) {
        if (souris.x >= SCREEN_WIDTH / 2 - r.largeur / 2 && souris.x <= SCREEN_WIDTH / 2 + r.largeur / 2
            && souris.y >= SCREEN_HEIGHT / 4 - r.hauteur && souris.y <= SCREEN_HEIGHT / 4 + r.hauteur / 2) {
        }
        if (souris.x >= SCREEN_WIDTH / 2 - r.largeur / 2 && souris.x <= SCREEN_WIDTH / 2 + r.largeur / 2
            && souris.y >= SCREEN_HEIGHT / 2 - r.hauteur && souris.y <= SCREEN_HEIGHT / 2 + r.hauteur / 2) {
        }
        if (souris.x >= SCREEN_WIDTH / 2 - r.largeur / 2 && souris.x <= SCREEN_WIDTH / 2 + r.largeur / 2
            && souris.y >= 3 * SCREEN_HEIGHT / 4 - r.hauteur && souris.y <= 3 * SCREEN_HEIGHT / 4 + r.hauteur / 2) {
        }
    }
}

void passageMenuAPartie(ALLEGRO_EVENT *event, ALLEGRO_FONT *font, ALLEGRO_BITMAP *fond, ALLEGRO_BITMAP *regle1,
                        ALLEGRO_BITMAP *regle2, ALLEGRO_BITMAP *regle3, ALLEGRO_BITMAP *regle4, ALLEGRO_BITMAP *regle5,
                        int *aide, Rect r, int *menu, int *menu1, int *isEnd, int nbJoueurs) {
    if (*menu) {
        if (event->mouse.x >= r.x && event->mouse.x <= r.x + r.largeur && event->mouse.y >= 50
            && event->mouse.y <= 50 + r.hauteur) {
            *menu = 0;
            *menu1 = 1;
            al_draw_scaled_bitmap(fond, 0, 0, 1000, 500, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
            demanderNombreJoueurs(font, r);
            //suite d'affichage du plateau a mettre ici
        } else if (event->mouse.x >= r.x && event->mouse.x <= r.x + r.largeur && event->mouse.y >= 185
                   && event->mouse.y <= 185 + r.hauteur) {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            *menu = 0;
        } else if (event->mouse.x >= r.x && event->mouse.x <= r.x + r.largeur && event->mouse.y >= 320
                   && event->mouse.y <= 320 + r.hauteur) {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_scaled_bitmap(regle1, 0, 0, 697, 499, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
            *aide = 1;
            *menu = 0;
        } else if (event->mouse.x >= r.x && event->mouse.x <= r.x + r.largeur && event->mouse.y >= 455
                   && event->mouse.y <= 455 + r.hauteur) {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            /*afficherScore(nbJoueurs, joueur1, joueur2, joueur3, joueur4, r, font);*/
            *menu = 0;
        } else if (event->mouse.x >= r.x && event->mouse.x <= r.x + r.largeur && event->mouse.y >= 590
                   && event->mouse.y <= 590 + r.hauteur) {
            *isEnd = 0;
        }
    }
}

void demanderNombreJoueurs(ALLEGRO_FONT *font, Rect r) {
    dessinerRectanglesJoueurs(r);
    texte2Joueurs(font);
    texte3Joueurs(font);
    texte4Joueurs(font);
}

void dessinerRectanglesJoueurs(Rect r) {
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

void texte2Joueurs(ALLEGRO_FONT *font) {
    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_WIDTH / 2 - 175, SCREEN_HEIGHT / 4 - 80, 0, "2 joueurs");
}

void texte3Joueurs(ALLEGRO_FONT *font) {
    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_WIDTH / 2 - 175, SCREEN_HEIGHT / 2 - 80, 0, "3 joueurs");
}

void texte4Joueurs(ALLEGRO_FONT *font) {
    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_WIDTH / 2 - 175, 3 * SCREEN_HEIGHT / 4 - 80, 0, "4 joueurs");
}

void passageNbJoueursAPartie(ALLEGRO_EVENT* event, ALLEGRO_FONT* font, ALLEGRO_BITMAP* fond,
                             ALLEGRO_BITMAP* saboteur, ALLEGRO_BITMAP* nain, Rect r,
                             int *menu1, int *nbJoueurs, int* modificationPioche, Action pioche[NB_CARTES],
                             Joueur* joueur1, Joueur* joueur2, Joueur* joueur3, Joueur* joueur4, int* partieCommencee) {
    if (*menu1) {
        if (event->mouse.x >= SCREEN_WIDTH / 2 - r.largeur / 2 && event->mouse.x <= SCREEN_WIDTH / 2 + r.largeur / 2
            && event->mouse.y >= SCREEN_HEIGHT / 4 - r.hauteur && event->mouse.y <= SCREEN_HEIGHT / 4 + r.hauteur / 2) {
            *nbJoueurs = 2;
        } else if (event->mouse.x >= SCREEN_WIDTH / 2 - r.largeur / 2 &&
                   event->mouse.x <= SCREEN_WIDTH / 2 + r.largeur / 2
                   && event->mouse.y >= SCREEN_HEIGHT / 2 - r.hauteur &&
                   event->mouse.y <= SCREEN_HEIGHT / 2 + r.hauteur / 2) {
            *nbJoueurs = 3;
        } else if (event->mouse.x >= SCREEN_WIDTH / 2 - r.largeur / 2 &&
                   event->mouse.x <= SCREEN_WIDTH / 2 + r.largeur / 2
                   && event->mouse.y >= 3 * SCREEN_HEIGHT / 4 - r.hauteur &&
                   event->mouse.y <= 3 * SCREEN_HEIGHT / 4 + r.hauteur / 2) {
            *nbJoueurs = 4;
        }
        *menu1 = 0;
        distributionRoles(nbJoueurs, &modificationPioche, pioche, saboteur, nain, &event, joueur1, joueur2, joueur3,
                          joueur4);
        affichageRoles(font, &event, saboteur, nain, fond, &joueur1, &joueur2, &joueur3, &joueur4, r, nbJoueurs,
                       &partieCommencee);
    }
}