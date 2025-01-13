#include "galerie.h"

void clicDansCarteGalerie(ALLEGRO_EVENT *event, Joueur *joueur, int *decalageX, int *decalageY, int *glisserDeposerGalerie,
                     int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6, int *partieCommencee) {
    if (*partieCommencee) {
        if (event->mouse.x >= 300 && event->mouse.x <= 370 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
            joueur->piocheJoueur[0].galerie == 1) {
            *glisserDeposerGalerie = 1;
            *decalageX = event->mouse.x - 300;
            *decalageY = event->mouse.y - 32;
            *carte1 = 1;
        } else if (event->mouse.x >= 400 && event->mouse.x <= 470 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[1].galerie == 1) {
            *glisserDeposerGalerie = 1;
            *decalageX = event->mouse.x - 400;
            *decalageY = event->mouse.y - 32;
            *carte2 = 1;
        } else if (event->mouse.x >= 500 && event->mouse.x <= 570 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[2].galerie == 1) {
            *glisserDeposerGalerie = 1;
            *decalageX = event->mouse.x - 500;
            *decalageY = event->mouse.y - 32;
            *carte3 = 1;
        } else if (event->mouse.x >= 600 && event->mouse.x <= 670 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[3].galerie == 1) {
            *glisserDeposerGalerie = 1;
            *decalageX = event->mouse.x - 600;
            *decalageY = event->mouse.y - 32;
            *carte4 = 1;
        } else if (event->mouse.x >= 700 && event->mouse.x <= 770 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[4].galerie == 1) {
            *glisserDeposerGalerie = 1;
            *decalageX = event->mouse.x - 700;
            *decalageY = event->mouse.y - 32;
            *carte5 = 1;
        } else if (event->mouse.x >= 800 && event->mouse.x <= 870 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[5].galerie == 1) {
            *glisserDeposerGalerie = 1;
            *decalageX = event->mouse.x - 800;
            *decalageY = event->mouse.y - 32;
            *carte6 = 1;
        }
    }
}

void replacerSiDebordement(Joueur* joueur, int largeur, int hauteur) {
    int i;
    for (i = 0; i < NB_CARTES_JOUEUR; i++) {
        if (joueur->piocheJoueur[i].x < 0) {
            joueur->piocheJoueur[i].x = 0;
        }
        if (joueur->piocheJoueur[i].x + largeur > SCREEN_WIDTH) {
            joueur->piocheJoueur[i].x = SCREEN_WIDTH - largeur;
        }
        if (joueur->piocheJoueur[i].y < 0) {
            joueur->piocheJoueur[i].y = 0;
        }
        if (joueur->piocheJoueur[i].y + hauteur > SCREEN_HEIGHT) {
            joueur->piocheJoueur[i].y = SCREEN_HEIGHT - hauteur;
        }
    }
}

void actualisationCartes(ALLEGRO_EVENT* event, Joueur* joueur, int decalageX, int decalageY,
                         int carte1, int carte2, int carte3, int carte4, int carte5, int carte6){
    int i;
    if(carte1){
        joueur->piocheJoueur[0].x = event->mouse.x - decalageX;
        joueur->piocheJoueur[0].y = event->mouse.y - decalageY;
    }
    if(carte2){
        joueur->piocheJoueur[1].x = event->mouse.x - decalageX;
        joueur->piocheJoueur[1].y = event->mouse.y - decalageY;
    }
    if(carte3){
        joueur->piocheJoueur[2].x = event->mouse.x - decalageX;
        joueur->piocheJoueur[2].y = event->mouse.y - decalageY;
    }
    if(carte4){
        joueur->piocheJoueur[3].x = event->mouse.x - decalageX;
        joueur->piocheJoueur[3].y = event->mouse.y - decalageY;
    }
    if(carte5){
        joueur->piocheJoueur[4].x = event->mouse.x - decalageX;
        joueur->piocheJoueur[4].y = event->mouse.y - decalageY;
    }
    if(carte6){
        joueur->piocheJoueur[5].x = event->mouse.x - decalageX;
        joueur->piocheJoueur[5].y = event->mouse.y - decalageY;
    }
    replacerSiDebordement(joueur, 70, 105);
    for(i = 0; i<NB_CARTES_JOUEUR; i++) {
        al_draw_scaled_bitmap(joueur->piocheJoueur[i].image, 0, 0, 110, 167, joueur->piocheJoueur[i].x,
                              joueur->piocheJoueur[i].y, 70, 105, 0);
    }
}

void carteUtilisee(Action pioche[NB_CARTES], Joueur *joueur, int* modificationPioche, int* carte1, int* carte2,
                   int* carte3, int* carte4, int* carte5, int* carte6){
    if(*carte1) {
        joueur->piocheJoueur[0] = piocheCarte(pioche, *modificationPioche);
        *carte1 = 0;
    }
    if(*carte2) {
        joueur->piocheJoueur[1] = piocheCarte(pioche, *modificationPioche);
        *carte2 = 0;
    }
    if(*carte3) {
        joueur->piocheJoueur[2] = piocheCarte(pioche, *modificationPioche);
        *carte3 = 0;
    }
    if(*carte4) {
        joueur->piocheJoueur[3] = piocheCarte(pioche, *modificationPioche);
        *carte4 = 0;
    }
    if(*carte5) {
        joueur->piocheJoueur[4] = piocheCarte(pioche, *modificationPioche);
        *carte5 = 0;
    }
    if(*carte6) {
        joueur->piocheJoueur[5] = piocheCarte(pioche, *modificationPioche);
        *carte6 = 0;
    }
}

/*fonction avec une boucle for pour assigner les cartes galerie au plateau (tableau 2 dimensions)
void carteDansPlateau(ALLEGRO_EVENT *event, Rect p, Rect k, Rect j, Rect g, Rect f, Rect h, int i,
                      ALLEGRO_FONT *fontPartie, ALLEGRO_BITMAP *arrivee, ALLEGRO_BITMAP *entree,
                      ALLEGRO_BITMAP *dosPioche, Joueur *joueur, Action pioche[NB_CARTES],
                      int *modificationPioche, int *glisserDeposerGalerie,
                      int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6){
    int autre = 0, a, b;
    if(*glisserDeposerGalerie){
        if (*carte1) {
            for(a = 0; a < PLATEAU_COLONNES; a++){
                for(b = 0; b < PLATEAU_LIGNES; b++){
                    plateau[a][b].image = joueur->piocheJoueur[0].image;
            }

        } else if (*carte2) {
            al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x,
                                  p.y, p.largeur / 7, p.hauteur / 5, 0);
        } else if (*carte3) {
            al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x,
                                  p.y, p.largeur / 7, p.hauteur / 5, 0);
        } else if (*carte4) {
            al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x,
                                  p.y, p.largeur / 7, p.hauteur / 5, 0);
        } else if (*carte5) {
            al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x,
                                  p.y, p.largeur / 7, p.hauteur / 5, 0);
        } else if (*carte6) {
            al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x,
                                  p.y, p.largeur / 7, p.hauteur / 5, 0);
        }
    }
}*/

void carteGalerieDansPlateau(ALLEGRO_EVENT *event, Rect p, Rect k, Rect j, Rect g, Rect f, Rect h, int i,
                             ALLEGRO_FONT *fontPartie, ALLEGRO_BITMAP *arrivee, ALLEGRO_BITMAP *entree,
                             ALLEGRO_BITMAP *dosPioche, Joueur *joueur, Action pioche[NB_CARTES],
                             int *modificationPioche, int *glisserDeposerGalerie,
                             int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6) {
    int autre = 0;
    if (*glisserDeposerGalerie) {
        if (event->mouse.x >= p.x && event->mouse.x <= p.x + (p.largeur / 7)) {
            if (event->mouse.y >= p.y && event->mouse.y <= p.y + (p.hauteur / 5)) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else if (event->mouse.y >= p.y + (p.hauteur / 5) && event->mouse.y <= p.y + (2 * p.hauteur / 5)) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else if (event->mouse.y >= p.y + (2 * p.hauteur / 5) && event->mouse.y <= p.y + (3 * p.hauteur / 5)) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else if (event->mouse.y >= p.y + (3 * p.hauteur / 5) && event->mouse.y <= p.y + (4 * p.hauteur / 5)) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else if (event->mouse.y >= p.y + (4 * p.hauteur / 5) && event->mouse.y <= p.y + p.hauteur) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else {autre = 1;}
        } else if (event->mouse.x >= p.x + (p.largeur / 7) && event->mouse.x <= p.x + (2 * p.largeur / 7)) {
            if (event->mouse.y >= p.y && event->mouse.y <= p.y + (p.hauteur / 5)) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 157,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 157,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 157,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 157,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 157,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 157,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else if (event->mouse.y >= p.y + (p.hauteur / 5) && event->mouse.y <= p.y + (2 * p.hauteur / 5)) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else if (event->mouse.y >= p.y + (2 * p.hauteur / 5) && event->mouse.y <= p.y + (3 * p.hauteur / 5)) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else if (event->mouse.y >= p.y + (3 * p.hauteur / 5) && event->mouse.y <= p.y + (4 * p.hauteur / 5)) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else if (event->mouse.y >= p.y + (4 * p.hauteur / 5) && event->mouse.y <= p.y + p.hauteur) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 157,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else {autre = 1;}
        } else if (event->mouse.x >= p.x + (2 * p.largeur / 7) && event->mouse.x <= p.x + (3 * p.largeur / 7)) {
            if (event->mouse.y >= p.y && event->mouse.y <= p.y + (p.hauteur / 5)) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 314,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 314,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 314,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 314,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 314,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 314,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else if (event->mouse.y >= p.y + (p.hauteur / 5) && event->mouse.y <= p.y + (2 * p.hauteur / 5)) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else if (event->mouse.y >= p.y + (2 * p.hauteur / 5) && event->mouse.y <= p.y + (3 * p.hauteur / 5)) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else if (event->mouse.y >= p.y + (3 * p.hauteur / 5) && event->mouse.y <= p.y + (4 * p.hauteur / 5)) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else if (event->mouse.y >= p.y + (4 * p.hauteur / 5) && event->mouse.y <= p.y + p.hauteur) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 314,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else {autre = 1;}
        } else if (event->mouse.x >= p.x + (3 * p.largeur / 7) && event->mouse.x <= p.x + (4 * p.largeur / 7)) {
            if (event->mouse.y >= p.y && event->mouse.y <= p.y + (p.hauteur / 5)) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 471,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 471,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 471,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 471,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 471,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 471,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else if (event->mouse.y >= p.y + (p.hauteur / 5) && event->mouse.y <= p.y + (2 * p.hauteur / 5)) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else if (event->mouse.y >= p.y + (2 * p.hauteur / 5) && event->mouse.y <= p.y + (3 * p.hauteur / 5)) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else if (event->mouse.y >= p.y + (3 * p.hauteur / 5) && event->mouse.y <= p.y + (4 * p.hauteur / 5)) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else if (event->mouse.y >= p.y + (4 * p.hauteur / 5) && event->mouse.y <= p.y + p.hauteur) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 471,
                                          p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else {autre = 1;}
        } else if (event->mouse.x >= p.x + (4 * p.largeur / 7) && event->mouse.x <= p.x + (5 * p.largeur / 7)) {
            if (event->mouse.y >= p.y && event->mouse.y <= p.y + (p.hauteur / 5)) {
                if (*carte1) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 628,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte2) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 628,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte3) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 628,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte4) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 628,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte5) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 628,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                } else if (*carte6) {
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 628,
                                          p.y, p.largeur / 7, p.hauteur / 5, 0);
                }
            } else if (event->mouse.y >= p.y + (p.hauteur / 5) && event->mouse.y <= p.y + (2 * p.hauteur / 5)) {
                    if (*carte1) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte2) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte3) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte4) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte5) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte6) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                    }
                } else if (event->mouse.y >= p.y + (2 * p.hauteur / 5) && event->mouse.y <= p.y + (3 * p.hauteur / 5)) {
                    if (*carte1) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte2) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte3) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte4) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte5) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte6) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                    }
                } else if (event->mouse.y >= p.y + (3 * p.hauteur / 5) && event->mouse.y <= p.y + (4 * p.hauteur / 5)) {
                    if (*carte1) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte2) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte3) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte4) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte5) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte6) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                    }
                } else if (event->mouse.y >= p.y + (4 * p.hauteur / 5) && event->mouse.y <= p.y + p.hauteur) {
                    if (*carte1) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte2) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte3) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte4) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte5) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte6) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 628,
                                              p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                    }
                } else {autre = 1;}
            } else if (event->mouse.x >= p.x + (5 * p.largeur / 7) && event->mouse.x <= p.x + (6 * p.largeur / 7)) {
                if (event->mouse.y >= p.y && event->mouse.y <= p.y + (p.hauteur / 5)) {
                    if (*carte1) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 785,
                                              p.y, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte2) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 785,
                                              p.y, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte3) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 785,
                                              p.y, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte4) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 785,
                                              p.y, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte5) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 785,
                                              p.y, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte6) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 785,
                                              p.y, p.largeur / 7, p.hauteur / 5, 0);
                    }
                } else if (event->mouse.y >= p.y + (p.hauteur / 5) && event->mouse.y <= p.y + (2 * p.hauteur / 5)) {
                    if (*carte1) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte2) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte3) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte4) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte5) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte6) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                    }
                } else if (event->mouse.y >= p.y + (2 * p.hauteur / 5) && event->mouse.y <= p.y + (3 * p.hauteur / 5)) {
                    if (*carte1) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte2) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte3) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte4) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte5) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte6) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                    }
                } else if (event->mouse.y >= p.y + (3 * p.hauteur / 5) && event->mouse.y <= p.y + (4 * p.hauteur / 5)) {
                    if (*carte1) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte2) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte3) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte4) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte5) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte6) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                    }
                } else if (event->mouse.y >= p.y + (4 * p.hauteur / 5) && event->mouse.y <= p.y + p.hauteur) {
                    if (*carte1) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte2) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte3) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte4) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte5) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte6) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 785,
                                              p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                    }
                } else {autre = 1;}
            } else if (event->mouse.x >= p.x + (6 * p.largeur / 7) && event->mouse.x <= p.x + p.largeur) {
                if (event->mouse.y >= p.y && event->mouse.y <= p.y + (p.hauteur / 5)) {
                    if (*carte1) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 942,
                                              p.y, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte2) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 942,
                                              p.y, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte3) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 942,
                                              p.y, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte4) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 942,
                                              p.y, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte5) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 942,
                                              p.y, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte6) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 942,
                                              p.y, p.largeur / 7, p.hauteur / 5, 0);
                    }
                } else if (event->mouse.y >= p.y + (p.hauteur / 5) && event->mouse.y <= p.y + (2 * p.hauteur / 5)) {
                    if (*carte1) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte2) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte3) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte4) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte5) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte6) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 100, p.largeur / 7, p.hauteur / 5, 0);
                    }
                } else if (event->mouse.y >= p.y + (2 * p.hauteur / 5) && event->mouse.y <= p.y + (3 * p.hauteur / 5)) {
                    if (*carte1) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte2) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte3) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte4) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte5) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte6) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 200, p.largeur / 7, p.hauteur / 5, 0);
                    }
                } else if (event->mouse.y >= p.y + (3 * p.hauteur / 5) && event->mouse.y <= p.y + (4 * p.hauteur / 5)) {
                    if (*carte1) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte2) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte3) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte4) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte5) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte6) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 300, p.largeur / 7, p.hauteur / 5, 0);
                    }
                } else if (event->mouse.y >= p.y + (4 * p.hauteur / 5) && event->mouse.y <= p.y + p.hauteur) {
                    if (*carte1) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte2) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte3) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte4) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte5) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                    } else if (*carte6) {
                        al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, p.x + 942,
                                              p.y + 400, p.largeur / 7, p.hauteur / 5, 0);
                    }
                } else {autre = 1;}
            } else {autre = 1;}
        }

    carteUtilisee(pioche, &joueur, &modificationPioche, &carte1, &carte2, &carte3, &carte4, &carte5, &carte6);
    *glisserDeposerGalerie = 0;

    if(autre){
        affichagePlateauJeu(k, j, g, f, h, p, i, fontPartie, arrivee, entree, dosPioche, &joueur);
        autre = 0;
    }
}