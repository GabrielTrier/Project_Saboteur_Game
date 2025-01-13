#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>

#include "menu/menu.h"
#include "source/aide/aide.h"
#include "source/ecranDefaite/ecranDefaite.h"
#include "source/ecranVictoire/ecranVictoire.h"

#include "partie/choix/choix.h"

#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 750
#define PLATEAU_COLONNES 7
#define PLATEAU_LIGNES 5

int main() {
    int isEnd = 1, i = 0, aide = 0, menu = 1, menu1 = 0, nbJoueurs = 0, indiceSaisie = 0, modeSaisie = 0,
            modificationPioche = 0, glisserDeposerGalerie = 0, glisserDeposerPenalite = 0, glisserDeposerReparation = 0,
            decalageX = 0, decalageY = 0, partieCommencee = 0, carteEboulement = 0, carteMap = 0, clicPiocheOuDefausse = 0,
            carte1 = 0, carte2 = 0, carte3 = 0, carte4 = 0, carte5 = 0, carte6 = 0, victoireSaboteur = 0;

    Rect r = {0}, k = {0}, j = {0}, g = {0}, f = {0}, h = {0}, p = {0};
    Action pioche[NB_CARTES] = {0};
    Plateau plateau[PLATEAU_LIGNES][PLATEAU_COLONNES] = {0};
    Pepite pepites[NB_PEPITES] = {0};
    Arrivee arrivee[NB_ARRIVEES] = {0};
    Joueur joueur1 = {0}, joueur2 = {0}, joueur3 = {0}, joueur4 = {0};
    Pierre pierre = {0};
    Image nainDefaite = {0};
    Image saboteurDefaite = {0};
    Or or[NB_MAX_OR] = {0};
    char saisie[100] = {0};

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_FONT *fontPartie = NULL;
    ALLEGRO_EVENT event = {0};
    ALLEGRO_BITMAP *dosPioche = NULL;
    ALLEGRO_BITMAP *galerieCarrefour = NULL;
    ALLEGRO_BITMAP *galerieChemin = NULL;
    ALLEGRO_BITMAP *galerieImpasse = NULL;
    ALLEGRO_BITMAP *galerieTCote = NULL;
    ALLEGRO_BITMAP *galerieTHaut = NULL;
    ALLEGRO_BITMAP *fond = NULL;
    ALLEGRO_BITMAP *saboteurEcran = NULL;
    ALLEGRO_BITMAP *nainEcran = NULL;
    ALLEGRO_BITMAP *fondMine = NULL;
    ALLEGRO_BITMAP *entree = NULL;
    ALLEGRO_BITMAP *regle1 = NULL;
    ALLEGRO_BITMAP *regle2 = NULL;
    ALLEGRO_BITMAP *regle3 = NULL;
    ALLEGRO_BITMAP *regle4 = NULL;
    ALLEGRO_BITMAP *regle5 = NULL;
    ALLEGRO_BITMAP *arriveeDos = NULL;
    ALLEGRO_BITMAP *eboulement = NULL;
    ALLEGRO_BITMAP *map = NULL;
    ALLEGRO_BITMAP *chariotD = NULL;
    ALLEGRO_BITMAP *lanterneD = NULL;
    ALLEGRO_BITMAP *piocheD = NULL;
    ALLEGRO_BITMAP *chariotR = NULL;
    ALLEGRO_BITMAP *lanterneR = NULL;
    ALLEGRO_BITMAP *piocheR = NULL;
    ALLEGRO_BITMAP *chariotLanterneR = NULL;
    ALLEGRO_BITMAP *chariotPiocheR = NULL;
    ALLEGRO_BITMAP *lanternePiocheR = NULL;
    ALLEGRO_BITMAP *nain = NULL;
    ALLEGRO_BITMAP *saboteur = NULL;
    ALLEGRO_BITMAP *pepite1 = NULL;
    ALLEGRO_BITMAP *pepite2 = NULL;
    ALLEGRO_BITMAP *pepite3 = NULL;
    ALLEGRO_BITMAP *arriveeGrotte = NULL;
    ALLEGRO_BITMAP *ecranVictoire = NULL;
    ALLEGRO_BITMAP *nainsVictoire = NULL;
    ALLEGRO_BITMAP *chariotsVictoire = NULL;
    ALLEGRO_MOUSE_STATE souris;

    assert(al_init());
    assert(al_init_primitives_addon());
    assert(al_install_keyboard());
    assert(al_install_mouse());
    al_init_font_addon();
    assert(al_init_ttf_addon());
    assert(al_init_image_addon());

    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (display == NULL) {
        printf("Display assertion failed.");
    }
    timer = al_create_timer(1.0 / 40.0);
    if (timer == NULL) {
        printf("Timer assertion failed.");
        al_destroy_display(display);
    }
    queue = al_create_event_queue();
    if (queue == NULL) {
        printf("Queue assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
    }
    font = al_load_ttf_font("../fonts/Starjout.ttf", 60, 0);
    if (font == NULL) {
        printf("Font assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
    }
    fond = al_load_bitmap("../images/starwars.jpeg");
    if (fond == NULL) {
        printf("Fond bitmap assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
    }
    entree = al_load_bitmap("../images/entree.png");
    if (entree == NULL) {
        printf("Entree bitmap assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
        al_destroy_bitmap(fond);
    }
    arriveeDos = al_load_bitmap("../images/arriveeDos.png");
    if (arriveeDos == NULL) {
        printf("ArriveeDos bitmap assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
        al_destroy_bitmap(fond);
        al_destroy_bitmap(entree);
    }
    regle1 = al_load_bitmap("../images/regle1.JPG");
    if (regle1 == NULL) {
        printf("Regle1 bitmap assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
        al_destroy_bitmap(fond);
        al_destroy_bitmap(entree);
        al_destroy_bitmap(arriveeDos);
    }
    regle2 = al_load_bitmap("../images/regle2.JPG");
    if (regle2 == NULL) {
        printf("Regle2 bitmap assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
        al_destroy_bitmap(fond);
        al_destroy_bitmap(entree);
        al_destroy_bitmap(arriveeDos);
        al_destroy_bitmap(regle1);
    }
    regle3 = al_load_bitmap("../images/regle3.JPG");
    if (regle3 == NULL) {
        printf("Regle3 bitmap assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
        al_destroy_bitmap(fond);
        al_destroy_bitmap(entree);
        al_destroy_bitmap(arriveeDos);
        al_destroy_bitmap(regle1);
        al_destroy_bitmap(regle2);
    }
    regle4 = al_load_bitmap("../images/regle4.JPG");
    if (regle4 == NULL) {
        printf("Regle4 bitmap assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
        al_destroy_bitmap(fond);
        al_destroy_bitmap(entree);
        al_destroy_bitmap(arriveeDos);
        al_destroy_bitmap(regle1);
        al_destroy_bitmap(regle2);
        al_destroy_bitmap(regle3);
    }
    regle5 = al_load_bitmap("../images/regle5.JPG");
    if (regle5 == NULL) {
        printf("Regle5 bitmap assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
        al_destroy_bitmap(fond);
        al_destroy_bitmap(entree);
        al_destroy_bitmap(arriveeDos);
        al_destroy_bitmap(regle1);
        al_destroy_bitmap(regle2);
        al_destroy_bitmap(regle3);
        al_destroy_bitmap(regle4);
    }
    fontPartie = al_load_font("../fonts/Starjout.ttf", 15, 0);
    if (fontPartie == NULL) {
        printf("FontPartie assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
        al_destroy_bitmap(fond);
        al_destroy_bitmap(entree);
        al_destroy_bitmap(arriveeDos);
        al_destroy_bitmap(regle1);
        al_destroy_bitmap(regle2);
        al_destroy_bitmap(regle3);
        al_destroy_bitmap(regle4);
        al_destroy_bitmap(regle5);
    }
    galerieCarrefour = al_load_bitmap("../images/galerieCarrefour.JPG");
    if (galerieCarrefour == NULL) {
        printf("GalerieCarrefour bitmap assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
        al_destroy_font(fontPartie);
        al_destroy_bitmap(fond);
        al_destroy_bitmap(entree);
        al_destroy_bitmap(arriveeDos);
        al_destroy_bitmap(regle1);
        al_destroy_bitmap(regle2);
        al_destroy_bitmap(regle3);
        al_destroy_bitmap(regle4);
        al_destroy_bitmap(regle5);
    }
    galerieChemin = al_load_bitmap("../images/galerieChemin.JPG");
    if (galerieChemin == NULL) {
        printf("GalerieChemin bitmap assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
        al_destroy_font(fontPartie);
        al_destroy_bitmap(fond);
        al_destroy_bitmap(entree);
        al_destroy_bitmap(arriveeDos);
        al_destroy_bitmap(regle1);
        al_destroy_bitmap(regle2);
        al_destroy_bitmap(regle3);
        al_destroy_bitmap(regle4);
        al_destroy_bitmap(regle5);
        al_destroy_bitmap(galerieCarrefour);
    }
    galerieImpasse = al_load_bitmap("../images/galerieImpasse.JPG");
    if (galerieImpasse == NULL) {
        printf("GalerieImpasse bitmap assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
        al_destroy_font(fontPartie);
        al_destroy_bitmap(fond);
        al_destroy_bitmap(entree);
        al_destroy_bitmap(arriveeDos);
        al_destroy_bitmap(regle1);
        al_destroy_bitmap(regle2);
        al_destroy_bitmap(regle3);
        al_destroy_bitmap(regle4);
        al_destroy_bitmap(regle5);
        al_destroy_bitmap(galerieCarrefour);
        al_destroy_bitmap(galerieChemin);
    }
    galerieTCote = al_load_bitmap("../images/galerieTCote.JPG");
    if (galerieTCote == NULL) {
        printf("Galerie TCote bitmap assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
        al_destroy_font(fontPartie);
        al_destroy_bitmap(fond);
        al_destroy_bitmap(entree);
        al_destroy_bitmap(arriveeDos);
        al_destroy_bitmap(regle1);
        al_destroy_bitmap(regle2);
        al_destroy_bitmap(regle3);
        al_destroy_bitmap(regle4);
        al_destroy_bitmap(regle5);
        al_destroy_bitmap(galerieCarrefour);
        al_destroy_bitmap(galerieChemin);
        al_destroy_bitmap(galerieImpasse);
    }
    galerieTHaut = al_load_bitmap("../images/galerieTHaut.JPG");
    if (galerieTHaut == NULL) {
        printf("GalerieTHaut bitmap assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
        al_destroy_font(fontPartie);
        al_destroy_bitmap(fond);
        al_destroy_bitmap(entree);
        al_destroy_bitmap(arriveeDos);
        al_destroy_bitmap(regle1);
        al_destroy_bitmap(regle2);
        al_destroy_bitmap(regle3);
        al_destroy_bitmap(regle4);
        al_destroy_bitmap(regle5);
        al_destroy_bitmap(galerieCarrefour);
        al_destroy_bitmap(galerieChemin);
        al_destroy_bitmap(galerieImpasse);
        al_destroy_bitmap(galerieTCote);
    }
    eboulement = al_load_bitmap("../images/eboulement.JPG");
    if (eboulement == NULL) {
        printf("Eboulement bitmap assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
        al_destroy_font(fontPartie);
        al_destroy_bitmap(fond);
        al_destroy_bitmap(entree);
        al_destroy_bitmap(arriveeDos);
        al_destroy_bitmap(regle1);
        al_destroy_bitmap(regle2);
        al_destroy_bitmap(regle3);
        al_destroy_bitmap(regle4);
        al_destroy_bitmap(regle5);
        al_destroy_bitmap(galerieCarrefour);
        al_destroy_bitmap(galerieChemin);
        al_destroy_bitmap(galerieImpasse);
        al_destroy_bitmap(galerieTCote);
        al_destroy_bitmap(galerieTHaut);
    }
    map = al_load_bitmap("../images/map.JPG");
    if (map == NULL) {
        printf("Map bitmap assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
        al_destroy_font(fontPartie);
        al_destroy_bitmap(fond);
        al_destroy_bitmap(entree);
        al_destroy_bitmap(arriveeDos);
        al_destroy_bitmap(regle1);
        al_destroy_bitmap(regle2);
        al_destroy_bitmap(regle3);
        al_destroy_bitmap(regle4);
        al_destroy_bitmap(regle5);
        al_destroy_bitmap(galerieCarrefour);
        al_destroy_bitmap(galerieChemin);
        al_destroy_bitmap(galerieImpasse);
        al_destroy_bitmap(galerieTCote);
        al_destroy_bitmap(galerieTHaut);
        al_destroy_bitmap(eboulement);
    }
    chariotD = al_load_bitmap("../images/destructionChariot.JPG");
    if (chariotD == NULL) {
        printf("ChariotD bitmap assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
        al_destroy_font(fontPartie);
        al_destroy_bitmap(fond);
        al_destroy_bitmap(entree);
        al_destroy_bitmap(arriveeDos);
        al_destroy_bitmap(regle1);
        al_destroy_bitmap(regle2);
        al_destroy_bitmap(regle3);
        al_destroy_bitmap(regle4);
        al_destroy_bitmap(regle5);
        al_destroy_bitmap(galerieCarrefour);
        al_destroy_bitmap(galerieChemin);
        al_destroy_bitmap(galerieImpasse);
        al_destroy_bitmap(galerieTCote);
        al_destroy_bitmap(galerieTHaut);
        al_destroy_bitmap(eboulement);
        al_destroy_bitmap(map);
    }
    lanterneD = al_load_bitmap("../images/destructionLanterne.JPG");
    if (lanterneD == NULL) {
        printf("LanterneD bitmap assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
        al_destroy_font(fontPartie);
        al_destroy_bitmap(fond);
        al_destroy_bitmap(entree);
        al_destroy_bitmap(arriveeDos);
        al_destroy_bitmap(regle1);
        al_destroy_bitmap(regle2);
        al_destroy_bitmap(regle3);
        al_destroy_bitmap(regle4);
        al_destroy_bitmap(regle5);
        al_destroy_bitmap(galerieCarrefour);
        al_destroy_bitmap(galerieChemin);
        al_destroy_bitmap(galerieImpasse);
        al_destroy_bitmap(galerieTCote);
        al_destroy_bitmap(galerieTHaut);
        al_destroy_bitmap(eboulement);
        al_destroy_bitmap(map);
        al_destroy_bitmap(chariotD);
    }
    piocheD = al_load_bitmap("../images/destructionPioche.JPG");
    if (piocheD == NULL) {
        printf("PiocheD bitmap assertion failed.");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        al_destroy_font(font);
        al_destroy_font(fontPartie);
        al_destroy_bitmap(fond);
        al_destroy_bitmap(entree);
        al_destroy_bitmap(arriveeDos);
        al_destroy_bitmap(regle1);
        al_destroy_bitmap(regle2);
        al_destroy_bitmap(regle3);
        al_destroy_bitmap(regle4);
        al_destroy_bitmap(regle5);
        al_destroy_bitmap(galerieCarrefour);
        al_destroy_bitmap(galerieChemin);
        al_destroy_bitmap(galerieImpasse);
        al_destroy_bitmap(galerieTCote);
        al_destroy_bitmap(galerieTHaut);
        al_destroy_bitmap(eboulement);
        al_destroy_bitmap(map);
        al_destroy_bitmap(chariotD);
        al_destroy_bitmap(lanterneD);
    }
    saboteurEcran = al_load_bitmap("../images/saboteurD.jpg");
    fondMine = al_load_bitmap("../images/fondmine.jpg");
    nainEcran = al_load_bitmap("../images/nainEcran.png");
    chariotR = al_load_bitmap("../images/reparationChariot.JPG");
    lanterneR = al_load_bitmap("../images/reparationLanterne.JPG");
    piocheR = al_load_bitmap("../images/reparationPioche.JPG");
    chariotLanterneR = al_load_bitmap("../images/reparationChariotLanterne.JPG");
    chariotPiocheR = al_load_bitmap("../images/reparationChariotPioche.JPG");
    lanternePiocheR = al_load_bitmap("../images/reparationLanternePioche.JPG");
    nain = al_load_bitmap("../images/nain.JPG");
    saboteur = al_load_bitmap("../images/saboteur.JPG");
    pepite1 = al_load_bitmap("../images/pepite1.JPG");
    pepite2 = al_load_bitmap("../images/pepite2.JPG");
    pepite3 = al_load_bitmap("../images/pepite3.JPG");
    dosPioche = al_load_bitmap("../images/dosPioche.JPG");
    arriveeGrotte = al_load_bitmap("../images/arriveeGrotte.PNG");
    ecranVictoire = al_load_bitmap("../images/ecranVictoire");
    nainsVictoire = al_load_bitmap("../images/nainsVictoire");
    chariotsVictoire = al_load_bitmap("../images/chariotsVictoire");

    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());

    al_set_window_title(display, "Saboteur");
    al_set_window_position(display, 20, 20);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_scaled_bitmap(fond, 0, 0, 1000, 500, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    al_set_target_backbuffer(display);
    srand(time(NULL));

    for (i = 0; i < 5; i++) {
        r = initRectangle(i);
        dessinerRectangle(r);
        ecrireTexte(font, r, i);
    }
    p = initRectanglePlateau();

    initCartesAction(galerieCarrefour, galerieChemin, galerieImpasse, galerieTCote, galerieTHaut,
                     eboulement, map, chariotD, lanterneD, piocheD, chariotR, lanterneR, piocheR,
                     chariotLanterneR, chariotPiocheR, lanternePiocheR, pioche);
    initCartesPepite(pepite1, pepite2, pepite3, pepites);
    initCartesArrivee(pepite1, arriveeGrotte, arrivee);

    al_start_timer(timer);
    al_flip_display();

    while (isEnd) {
        al_wait_for_event(queue, &event);
        al_get_mouse_state(&souris);

        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                isEnd = 0;
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE:
                        isEnd = 0;
                        break;
                    case ALLEGRO_KEY_BACKSPACE:
                        revenirMenu(&aide, &menu, fond);
                        break;
                    case ALLEGRO_KEY_LEFT:
                        passageSlidePrecedente(&aide, regle1, regle2, regle3, regle4);
                        break;
                    case ALLEGRO_KEY_RIGHT:
                        passageSlideSuivante(&aide, regle2, regle3, regle4, regle5);
                        break;
                    case ALLEGRO_KEY_A:
                        affichagePlateauJeu(k, j, g, f, h, p, i, fontPartie, arriveeDos, entree, dosPioche, pioche);
                        break;
                    case ALLEGRO_KEY_B:
                        al_draw_scaled_bitmap(fond, 0, 0, 1000, 500, 0, 0,
                                              SCREEN_WIDTH, SCREEN_HEIGHT, 0);
                        break;
                    case ALLEGRO_KEY_D:
                        affichage(fondMine, nainEcran, saboteurEcran, nainDefaite, saboteurDefaite);
                        victoireSaboteur = 1;
                        break;
                    case ALLEGRO_KEY_V:
                        menu = 0;
                        al_clear_to_color(al_map_rgb(0, 0, 0));
                        al_draw_scaled_bitmap(ecranVictoire, 0, 0, 1000, 500, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
                                              0);
                        al_draw_scaled_bitmap(chariotsVictoire, 0, 0, 1000, 500, 1150, 400, 600, 300,
                                              0);
                        al_draw_scaled_bitmap(nainsVictoire, 0, 0, 409, 500, 300, 460, 400, 300, 0);
                        initOr(or);
                        apparitionOr(or);
                        afficheOr(or);

                }
                break;
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                passageMenuAPartie(&event, font, fond, regle1, regle2, regle3, regle4, regle5, &aide, r, &menu, &menu1,
                                   &isEnd, nbJoueurs);
                passageNbJoueursAPartie(&event, font, fond, saboteur, nain, r, &menu1, &nbJoueurs,
                                        &modificationPioche, pioche, &joueur1, &joueur2, &joueur3, &joueur4,
                                        &partieCommencee);
                //determinerSiSaisie(&event, r, &modeSaisie, &indiceSaisie, saisie);
                //fct normalement utilisee pour inscrire les prenoms des joueurs
                //clicDansGalerie pour un seul joueur par manque de temps
                choixJoueurLorsDeSonTour(&event, pepite3, arriveeGrotte, arrivee, &joueur1, pioche, p, &partieCommencee,
                                         &decalageX, &decalageY, &glisserDeposerGalerie, &glisserDeposerPenalite,
                                         &glisserDeposerReparation, &carteEboulement, &carteMap, &clicPiocheOuDefausse,
                                         &modificationPioche, &carte1, &carte2, &carte3, &carte4, &carte5, &carte6);
                break;
            case ALLEGRO_EVENT_MOUSE_AXES: {
                deplacementCarte(&event, arriveeDos, entree, dosPioche, fontPartie, pioche, k, j, g, f, h, p, i,
                                 &joueur1,
                                 glisserDeposerGalerie, glisserDeposerPenalite, glisserDeposerReparation, decalageX,
                                 decalageY,
                                 carte1, carte2, carte3, carte4, carte5, carte6);
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP: {
                relachementCarte(&event, entree, dosPioche, arrivee, pioche, fontPartie, k, j, g, f, h, p, i, &joueur1,
                                 &joueur2, &joueur3, &modificationPioche, &glisserDeposerGalerie,
                                 &glisserDeposerPenalite,
                                 &glisserDeposerReparation, &decalageX, &decalageY,
                                 &carte1, &carte2, &carte3, &carte4, &carte5, &carte6);
                break;
            }
            case ALLEGRO_EVENT_TIMER:
                actualisationRectangles(r, i, menu, font, souris);
                actualisationRectanglesJoueurs(r, i, menu1, font, souris);
                affichageEcranSaboteur(fondMine, nainEcran, saboteurEcran, victoireSaboteur, &pierre,
                                       nainDefaite, saboteurDefaite);
                break;
        }
        al_flip_display();
    }

    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    al_destroy_font(font);
    al_destroy_font(fontPartie);
    al_destroy_bitmap(fond);
    al_destroy_bitmap(entree);
    al_destroy_bitmap(arriveeDos);
    al_destroy_bitmap(regle1);
    al_destroy_bitmap(regle2);
    al_destroy_bitmap(regle3);
    al_destroy_bitmap(regle4);
    al_destroy_bitmap(regle5);
    al_destroy_bitmap(galerieCarrefour);
    al_destroy_bitmap(galerieChemin);
    al_destroy_bitmap(galerieImpasse);
    al_destroy_bitmap(galerieTCote);
    al_destroy_bitmap(galerieTHaut);
    al_destroy_bitmap(eboulement);
    al_destroy_bitmap(map);
    al_destroy_bitmap(chariotD);
    al_destroy_bitmap(lanterneD);
    al_destroy_bitmap(piocheD);
    al_destroy_bitmap(chariotR);
    al_destroy_bitmap(lanterneR);
    al_destroy_bitmap(piocheR);
    al_destroy_bitmap(chariotLanterneR);
    al_destroy_bitmap(chariotPiocheR);
    al_destroy_bitmap(lanternePiocheR);
    al_destroy_bitmap(nain);
    al_destroy_bitmap(saboteur);
    al_destroy_bitmap(pepite1);
    al_destroy_bitmap(pepite2);
    al_destroy_bitmap(pepite3);
    al_destroy_bitmap(dosPioche);
    al_destroy_bitmap(arriveeGrotte);
    al_destroy_bitmap(fondMine);
    al_destroy_bitmap(nainEcran);
    al_destroy_bitmap(saboteurEcran);

    return 0;
}