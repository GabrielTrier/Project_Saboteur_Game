#include "joueur.h"


void distributionRoles(int nbJoueurs, int* modificationPioche, Action pioche[NB_CARTES],
                       ALLEGRO_BITMAP* saboteur, ALLEGRO_BITMAP* nain, ALLEGRO_EVENT* event,
                       Joueur* joueur1, Joueur* joueur2, Joueur* joueur3, Joueur* joueur4) {
    switch (nbJoueurs) {
        case 2:
            joueur1->role = rand() % 1;
            if (joueur1->role == 1) {
                joueur2->role = 0;
                joueur1->image = saboteur;
                joueur2->image = nain;
            }
            else {
                joueur2->role = 1;
                joueur1->image = nain;
                joueur2->image = saboteur;
            }
            distributionCartesDebut(&joueur1, &modificationPioche, pioche);
            distributionCartesDebut(&joueur2, &modificationPioche, pioche);
            break;
        case 3:
            do {
                joueur3->role = rand() % 2;
                if (joueur3->role == 1) {
                    joueur2->role = 0;
                    joueur1->role = 0;
                    joueur1->image = nain;
                    joueur2->image = nain;
                    joueur3->image = saboteur;
                }
                joueur2->role = rand() % 2;
                if (joueur2->role == 1) {
                    joueur3->role = 0;
                    joueur1->role = 0;
                    joueur1->image = nain;
                    joueur2->image = saboteur;
                    joueur3->image = nain;
                }
                joueur1->role = rand() % 2;
                if (joueur1->role == 1) {
                    joueur2->role = 0;
                    joueur3->role = 0;
                    joueur1->image = saboteur;
                    joueur2->image = nain;
                    joueur3->image = nain;
                }
            } while ((joueur1->role != 1) || (joueur2->role != 1) || (joueur3->role != 1));
            distributionCartesDebut(&joueur1, &modificationPioche, pioche);
            distributionCartesDebut(&joueur2, &modificationPioche, pioche);
            distributionCartesDebut(&joueur3, &modificationPioche, pioche);
            break;
        case 4:
            do {
                joueur4->role= rand()%2;
                if(joueur4->role==1){
                    joueur3->role=0;
                    joueur2->role=0;
                    joueur1->role=0;
                    joueur1->image = nain;
                    joueur2->image = nain;
                    joueur3->image = nain;
                    joueur4->image = saboteur;
                }
                joueur3->role = rand() % 2;
                if (joueur3->role == 1) {
                    joueur4->role=0;
                    joueur2->role = 0;
                    joueur1->role = 0;
                    joueur1->image = nain;
                    joueur2->image = nain;
                    joueur3->image = saboteur;
                    joueur4->image = nain;
                }
                joueur2->role = rand() % 2;
                if (joueur2->role == 1) {
                    joueur4->role=0;
                    joueur3->role = 0;
                    joueur1->role = 0;
                    joueur1->image = nain;
                    joueur2->image = saboteur;
                    joueur3->image = nain;
                    joueur4->image = nain;
                }
                joueur1->role = rand() % 2;
                if (joueur1->role == 1) {
                    joueur2->role = 0;
                    joueur3->role = 0;
                    joueur4->role=0;
                    joueur1->image = saboteur;
                    joueur2->image = nain;
                    joueur3->image = nain;
                    joueur4->image = nain;
                }
            } while ((joueur1->role != 1) || (joueur2->role != 1) || (joueur3->role != 1)|| (joueur4->role !=1));
            distributionCartesDebut(&joueur1, &modificationPioche, pioche);
            distributionCartesDebut(&joueur2, &modificationPioche, pioche);
            distributionCartesDebut(&joueur3, &modificationPioche, pioche);
            distributionCartesDebut(&joueur4, &modificationPioche, pioche);
    }
}

void affichageRectangleRoleJoueur(ALLEGRO_BITMAP* fond, Rect r){
    al_draw_scaled_bitmap(fond, 0, 0, 1000, 500, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    al_draw_filled_rectangle(SCREEN_WIDTH / 2 - r.largeur / 2, SCREEN_HEIGHT / 4 - r.hauteur,
                             SCREEN_WIDTH / 2 + r.largeur / 2, SCREEN_HEIGHT / 4 + r.hauteur / 2,
                             al_map_rgb(255, 200, 150));
}

void affichageCarteRole(Joueur joueur, ALLEGRO_BITMAP* nain, ALLEGRO_BITMAP* saboteur){
    if(joueur.role == 1){
        al_draw_scaled_bitmap(saboteur, 0, 0, 154, 237, SCREEN_WIDTH / 2 - 100 / 2,
                              SCREEN_HEIGHT / 2 + 100 / 2, 100, 150, 0);
    }
    else{
        al_draw_scaled_bitmap(saboteur, 0, 0, 154, 237, SCREEN_WIDTH / 2 - 100 / 2,
                              SCREEN_HEIGHT / 2 + 100 / 2, 100, 150, 0);
    }
}

void affichageRoleJoueur1(ALLEGRO_FONT* font, Rect r, Joueur joueur, ALLEGRO_BITMAP* nain, ALLEGRO_BITMAP* saboteur,
                          ALLEGRO_BITMAP* fond){
    affichageRectangleRoleJoueur(fond, r);
    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_WIDTH / 2 - 175, SCREEN_HEIGHT / 4 - 80,
                 0, "Role joueur 1:");
    affichageCarteRole(joueur, nain, saboteur);
}

void affichageRoleJoueur2(ALLEGRO_FONT* font, Rect r, Joueur joueur, ALLEGRO_BITMAP* nain, ALLEGRO_BITMAP* saboteur,
                          ALLEGRO_BITMAP* fond){
    affichageRectangleRoleJoueur(fond, r);
    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_WIDTH / 2 - 175, SCREEN_HEIGHT / 4 - 80,
                 0, "Role joueur 2:");
    affichageCarteRole(joueur, nain, saboteur);
}

void affichageRoleJoueur3(ALLEGRO_FONT* font, Rect r, Joueur joueur, ALLEGRO_BITMAP* nain, ALLEGRO_BITMAP* saboteur,
                          ALLEGRO_BITMAP* fond){
    affichageRectangleRoleJoueur(fond, r);
    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_WIDTH / 2 - 175, SCREEN_HEIGHT / 4 - 80,
                 0, "Role joueur 3:");
    affichageCarteRole(joueur, nain, saboteur);
}

void affichageRoleJoueur4(ALLEGRO_FONT* font, Rect r, Joueur joueur, ALLEGRO_BITMAP* nain, ALLEGRO_BITMAP* saboteur,
                          ALLEGRO_BITMAP* fond){
    affichageRectangleRoleJoueur(fond, r);
    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_WIDTH / 2 - 175, SCREEN_HEIGHT / 4 - 80,
                 0, "Role joueur 4:");
    affichageCarteRole(joueur, nain, saboteur);
}

void affichageRoles(ALLEGRO_FONT* font, ALLEGRO_EVENT* event, ALLEGRO_BITMAP* saboteur, ALLEGRO_BITMAP* nain,
                    ALLEGRO_BITMAP* fond, Joueur* joueur1, Joueur* joueur2, Joueur* joueur3, Joueur* joueur4,
                    Rect r, int nbJoueurs, int* partieCommencee){
    affichageRoleJoueur1(font, r, *joueur1, nain, saboteur, fond);
    if(event->mouse.x >= 0 && event->mouse.x <= SCREEN_WIDTH && event->mouse.y >= 0 &&
       event->mouse.y <= SCREEN_HEIGHT){
        affichageRoleJoueur2(font, r, *joueur2, nain, saboteur, fond);
        if(event->mouse.x >= 0 && event->mouse.x <= SCREEN_WIDTH && event->mouse.y >= 0 &&
           event->mouse.y <= SCREEN_HEIGHT && (nbJoueurs >= 3)){
            affichageRoleJoueur3(font, r, *joueur3, nain, saboteur, fond);
            if(event->mouse.x >= 0 && event->mouse.x <= SCREEN_WIDTH && event->mouse.y >= 0 &&
               event->mouse.y <= SCREEN_HEIGHT && (nbJoueurs == 4)){
                affichageRoleJoueur4(font, r, *joueur4, nain, saboteur, fond);
            }
        }
        *partieCommencee = 1;
    }
}