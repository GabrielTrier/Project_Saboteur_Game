#include "cartes.h"

void placerCarteEntreeMine(ALLEGRO_BITMAP* entree){
    al_draw_scaled_bitmap(entree, 0, 0, 106, 163, 200, 420, 100, 150,0);
}

void placerCartesArrivee(ALLEGRO_BITMAP* arrivee){
    al_draw_scaled_bitmap(arrivee, 0, 0, 98, 156, 1400, 250, 100, 150, 0);
    al_draw_scaled_bitmap(arrivee, 0, 0, 98, 156, 1400, 425, 100, 150, 0);
    al_draw_scaled_bitmap(arrivee, 0, 0, 98, 156, 1400, 600, 100, 150, 0);
}
void initCartesAction(ALLEGRO_BITMAP* galerieCarrefour, ALLEGRO_BITMAP* galerieChemin, ALLEGRO_BITMAP* galerieImpasse,
                      ALLEGRO_BITMAP* galerieTCote, ALLEGRO_BITMAP* galerieTHaut, ALLEGRO_BITMAP* eboulement,
                      ALLEGRO_BITMAP* map, ALLEGRO_BITMAP* chariotD, ALLEGRO_BITMAP* lanterneD, ALLEGRO_BITMAP* piocheD,
                      ALLEGRO_BITMAP* chariotR, ALLEGRO_BITMAP* lanterneR, ALLEGRO_BITMAP* piocheR,
                      ALLEGRO_BITMAP* chariotLanterneR, ALLEGRO_BITMAP* chariotPiocheR,
                      ALLEGRO_BITMAP* lanternePiocheR, Action pioche[NB_CARTES]){
    int i;
    for (i = 0; i < 9; i++) {
        pioche[i].image = galerieCarrefour;
        pioche[i].galerie = 1;
        pioche[i].droite = 1;
        pioche[i].gauche = 1;
        pioche[i].haut = 1;
        pioche[i].bas = 1;
        pioche[i].penalite = 0;
        pioche[i].reparation = 0;
        pioche[i].eboulement = 0;
        pioche[i].map = 0;
        pioche[i].lampe = 0;
        pioche[i].chariot = 0;
        pioche[i].pioche = 0;
        pioche[i].x = 0;
        pioche[i].y = 0;
    }
    for (i = 9; i < 18; i++) {
        pioche[i].image = galerieChemin;
        pioche[i].galerie = 1;
        pioche[i].droite = 1;
        pioche[i].gauche = 1;
        pioche[i].haut = 0;
        pioche[i].bas = 0;
        pioche[i].penalite = 0;
        pioche[i].reparation = 0;
        pioche[i].eboulement = 0;
        pioche[i].map = 0;
        pioche[i].lampe = 0;
        pioche[i].chariot = 0;
        pioche[i].pioche = 0;
        pioche[i].x = 0;
        pioche[i].y = 0;
    }
    for (i = 18; i < 27; i++) {
        pioche[i].image = galerieImpasse;
        pioche[i].galerie = 1;
        pioche[i].droite = 0;
        pioche[i].gauche = 1;
        pioche[i].haut = 0;
        pioche[i].bas = 0;
        pioche[i].penalite = 0;
        pioche[i].reparation = 0;
        pioche[i].eboulement = 0;
        pioche[i].map = 0;
        pioche[i].lampe = 0;
        pioche[i].chariot = 0;
        pioche[i].pioche = 0;
        pioche[i].x = 0;
        pioche[i].y = 0;
    }
    for (i = 27; i < 36; i++) {
        pioche[i].image = galerieTCote;
        pioche[i].galerie = 1;
        pioche[i].droite = 1;
        pioche[i].gauche = 0;
        pioche[i].haut = 1;
        pioche[i].bas = 1;
        pioche[i].penalite = 0;
        pioche[i].reparation = 0;
        pioche[i].eboulement = 0;
        pioche[i].map = 0;
        pioche[i].lampe = 0;
        pioche[i].chariot = 0;
        pioche[i].pioche = 0;
        pioche[i].x = 0;
        pioche[i].y = 0;
    }
    for (i = 36; i < 45; i++) {
        pioche[i].image = galerieTHaut;
        pioche[i].galerie = 1;
        pioche[i].droite = 1;
        pioche[i].gauche = 1;
        pioche[i].haut = 1;
        pioche[i].bas = 0;
        pioche[i].penalite = 0;
        pioche[i].reparation = 0;
        pioche[i].eboulement = 0;
        pioche[i].map = 0;
        pioche[i].lampe = 0;
        pioche[i].chariot = 0;
        pioche[i].pioche = 0;
        pioche[i].x = 0;
        pioche[i].y = 0;
    }
    for (i = 45; i < 47; i++) {
        pioche[i].image = eboulement;
        pioche[i].galerie = 0;
        pioche[i].droite = 0;
        pioche[i].gauche = 0;
        pioche[i].haut = 0;
        pioche[i].bas = 0;
        pioche[i].penalite = 0;
        pioche[i].reparation = 0;
        pioche[i].eboulement = 1;
        pioche[i].map = 0;
        pioche[i].lampe = 0;
        pioche[i].chariot = 0;
        pioche[i].pioche = 0;
        pioche[i].x = 0;
        pioche[i].y = 0;
    }
    for (i = 47; i < 49; i++) {
        pioche[i].image = map;
        pioche[i].galerie = 0;
        pioche[i].droite = 0;
        pioche[i].gauche = 0;
        pioche[i].haut = 0;
        pioche[i].bas = 0;
        pioche[i].penalite = 0;
        pioche[i].reparation = 0;
        pioche[i].eboulement = 0;
        pioche[i].map = 1;
        pioche[i].lampe = 0;
        pioche[i].chariot = 0;
        pioche[i].pioche = 0;
        pioche[i].x = 0;
        pioche[i].y = 0;
    }
    for (i = 49; i < 51; i++) {
        pioche[i].image = chariotD;
        pioche[i].galerie = 0;
        pioche[i].droite = 0;
        pioche[i].gauche = 0;
        pioche[i].haut = 0;
        pioche[i].bas = 0;
        pioche[i].penalite = 1;
        pioche[i].reparation = 0;
        pioche[i].eboulement = 0;
        pioche[i].map = 0;
        pioche[i].lampe = 0;
        pioche[i].chariot = 1;
        pioche[i].pioche = 0;
        pioche[i].x = 0;
        pioche[i].y = 0;
    }
    for (i = 51; i < 53; i++) {
        pioche[i].image = lanterneD;
        pioche[i].galerie = 0;
        pioche[i].droite = 0;
        pioche[i].gauche = 0;
        pioche[i].haut = 0;
        pioche[i].bas = 0;
        pioche[i].penalite = 1;
        pioche[i].reparation = 0;
        pioche[i].eboulement = 0;
        pioche[i].map = 0;
        pioche[i].lampe = 1;
        pioche[i].chariot = 0;
        pioche[i].pioche = 0;
        pioche[i].x = 0;
        pioche[i].y = 0;
    }
    for (i = 53; i < 55; i++) {
        pioche[i].image = piocheD;
        pioche[i].galerie = 0;
        pioche[i].droite = 0;
        pioche[i].gauche = 0;
        pioche[i].haut = 0;
        pioche[i].bas = 0;
        pioche[i].penalite = 1;
        pioche[i].reparation = 0;
        pioche[i].eboulement = 0;
        pioche[i].map = 0;
        pioche[i].lampe = 0;
        pioche[i].chariot = 0;
        pioche[i].pioche = 1;
        pioche[i].x = 0;
        pioche[i].y = 0;
    }
    for (i = 55; i < 57; i++) {
        pioche[i].image = chariotR;
        pioche[i].galerie = 0;
        pioche[i].droite = 0;
        pioche[i].gauche = 0;
        pioche[i].haut = 0;
        pioche[i].bas = 0;
        pioche[i].penalite = 0;
        pioche[i].reparation = 1;
        pioche[i].eboulement = 0;
        pioche[i].map = 0;
        pioche[i].lampe = 0;
        pioche[i].chariot = 1;
        pioche[i].pioche = 0;
        pioche[i].x = 0;
        pioche[i].y = 0;
    }
    for (i = 57; i < 59; i++) {
        pioche[i].image = lanterneR;
        pioche[i].galerie = 0;
        pioche[i].droite = 0;
        pioche[i].gauche = 0;
        pioche[i].haut = 0;
        pioche[i].bas = 0;
        pioche[i].penalite = 0;
        pioche[i].reparation = 1;
        pioche[i].eboulement = 0;
        pioche[i].map = 0;
        pioche[i].lampe = 1;
        pioche[i].chariot = 0;
        pioche[i].pioche = 0;
        pioche[i].x = 0;
        pioche[i].y = 0;
    }
    for (i = 59; i < 61; i++) {
        pioche[i].image = piocheR;
        pioche[i].galerie = 0;
        pioche[i].droite = 0;
        pioche[i].gauche = 0;
        pioche[i].haut = 0;
        pioche[i].bas = 0;
        pioche[i].penalite = 0;
        pioche[i].reparation = 1;
        pioche[i].eboulement = 0;
        pioche[i].map = 0;
        pioche[i].lampe = 0;
        pioche[i].chariot = 0;
        pioche[i].pioche = 1;
        pioche[i].x = 0;
        pioche[i].y = 0;
    }
    for (i = 61; i < 63; i++) {
        pioche[i].image = chariotLanterneR;
        pioche[i].galerie = 0;
        pioche[i].droite = 0;
        pioche[i].gauche = 0;
        pioche[i].haut = 0;
        pioche[i].bas = 0;
        pioche[i].penalite = 0;
        pioche[i].reparation = 1;
        pioche[i].eboulement = 0;
        pioche[i].map = 0;
        pioche[i].lampe = 1;
        pioche[i].chariot = 1;
        pioche[i].pioche = 0;
        pioche[i].x = 0;
        pioche[i].y = 0;
    }
    for (i = 63; i < 65; i++) {
        pioche[i].image = chariotPiocheR;
        pioche[i].galerie = 0;
        pioche[i].droite = 0;
        pioche[i].gauche = 0;
        pioche[i].haut = 0;
        pioche[i].bas = 0;
        pioche[i].penalite = 0;
        pioche[i].reparation = 1;
        pioche[i].eboulement = 0;
        pioche[i].map = 0;
        pioche[i].lampe = 0;
        pioche[i].chariot = 1;
        pioche[i].pioche = 1;
        pioche[i].x = 0;
        pioche[i].y = 0;
    }
    for (i = 65; i < 67; i++) {
        pioche[i].image = lanternePiocheR;
        pioche[i].galerie = 0;
        pioche[i].droite = 0;
        pioche[i].gauche = 0;
        pioche[i].haut = 0;
        pioche[i].bas = 0;
        pioche[i].penalite = 0;
        pioche[i].reparation = 1;
        pioche[i].eboulement = 0;
        pioche[i].map = 0;
        pioche[i].lampe = 1;
        pioche[i].chariot = 0;
        pioche[i].pioche = 1;
        pioche[i].x = 0;
        pioche[i].y = 0;
    }
    melangePioche(pioche);
}

void melangePioche(Action pioche[NB_CARTES]){
    int i, carteADeplacer1 = 0, carteADeplacer2 = 0;
    Action echange1, echange2;
    for(i = 0 ; i < NB_CARTES ; i++){
        carteADeplacer1 = rand() % (NB_CARTES)+1;
        carteADeplacer2 = rand() % (NB_CARTES)+1;
        echange1 = pioche[carteADeplacer1];
        echange2 = pioche[carteADeplacer2];
        pioche[carteADeplacer2] = echange1;
        pioche[carteADeplacer1] = echange2;
    }
}

Action piocheCarte(Action pioche[NB_CARTES], int* modificationPioche){
    int nbAleatoire = 0;
    Action cartePiochee, echange;
    nbAleatoire = rand() % (NB_CARTES - *modificationPioche);
    cartePiochee = pioche[nbAleatoire];
    echange = pioche[NB_CARTES - *modificationPioche - 1];
    pioche[NB_CARTES - *modificationPioche - 1] = cartePiochee;
    pioche[nbAleatoire] = echange;
    (*modificationPioche)++;
    return cartePiochee;
}

void distributionCartesDebut(Joueur* joueur, int* modificationPioche, Action pioche[NB_CARTES]){
    int i;
    for(i = 0; i<NB_CARTES_JOUEUR; i++){
        joueur->piocheJoueur[i] = piocheCarte(pioche, modificationPioche);
    }
}

void affichageCartesJoueur(Joueur* joueur){
    int i;
    for(i = 0; i < NB_CARTES_JOUEUR; i++) {
        joueur->piocheJoueur[i].x = 300+i*100;
        joueur->piocheJoueur[i].y = 32;
        al_draw_scaled_bitmap(joueur->piocheJoueur[i].image, 0, 0, 110, 167, joueur->piocheJoueur[i].x,
                              joueur->piocheJoueur[i].y, 70, 105, 0);
    }
}

void initCartesPepite(ALLEGRO_BITMAP* pepite1, ALLEGRO_BITMAP* pepite2, ALLEGRO_BITMAP* pepite3,
                      Pepite pepites[NB_PEPITES]){
    pepites[0].image = pepite1;
    pepites[0].valeur = 1;
    pepites[1].image = pepite2;
    pepites[1].valeur = 2;
    pepites[2].image = pepite3;
    pepites[2].valeur = 3;
    melangePepites(pepites);
}

void melangePepites(Pepite pepites[NB_PEPITES]){
    int i, nombrePepitesADeplacer1 = 0, nombrePepitesADeplacer2 = 0;
    Pepite echange1, echange2;
    for(i = 0 ; i < NB_PEPITES ; i++){
        nombrePepitesADeplacer1 = rand() % (NB_CARTES)+1;
        nombrePepitesADeplacer2 = rand() % (NB_CARTES)+1;
        echange1 = pepites[nombrePepitesADeplacer1];
        echange2 = pepites[nombrePepitesADeplacer2];
        pepites[nombrePepitesADeplacer1] = echange1;
        pepites[nombrePepitesADeplacer2] = echange2;
    }
}

void initCartesArrivee(ALLEGRO_BITMAP* pepite3, ALLEGRO_BITMAP* grotte, Arrivee arrivee[NB_ARRIVEES]){
    arrivee[0].image = pepite3;
    arrivee[0].reussite = 1;
    arrivee[0].y = 250;
    arrivee[1].image = grotte;
    arrivee[1].reussite = 0;
    arrivee[1].y = 425;
    arrivee[2].image = grotte;
    arrivee[2].reussite = 0;
    arrivee[2].y = 600;
    melangeCartesArrivee(arrivee);
}

void melangeCartesArrivee(Arrivee arrivee[NB_ARRIVEES]){
    int i, carteADeplacer1 = 0, carteADeplacer2 = 0;
    Arrivee echange1, echange2;
    for(i = 0 ; i < NB_PEPITES ; i++){
        carteADeplacer1 = rand() % (NB_CARTES)+1;
        carteADeplacer2 = rand() % (NB_CARTES)+1;
        echange1 = arrivee[carteADeplacer1];
        echange2 = arrivee[carteADeplacer2];
        arrivee[carteADeplacer1] = echange1;
        arrivee[carteADeplacer2] = echange2;
    }
}