#ifndef MAIN_C_ACTION_H
#define MAIN_C_ACTION_H

typedef struct{
    ALLEGRO_BITMAP* image;
    int galerie, penalite, reparation, eboulement, map;
    int gauche, droite, haut, bas;
    int lampe, chariot, pioche;
    int x, y;
}Action;

//utilisation de l'enum ci-dessous si on savait les utiliser correctement dans un code

enum{
    CARREFOUR, CHEMIN, IMPASSE, T_COTE, T_HAUT, PENALITE_CHARIOT, PENALITE_LAMPE, PENALITE_PIOCHE, REPARATION_CHARIOT,
    REPARATION_LAMPE, REPARATION_PIOCHE, REPARATION_CHARIOT_LAMPE, REPARATION_LAMPE_PIOCHE, REPARATION_CHARIOT_PIOCHE,
    NB_TYPES_PRECIS_CARTES};

#endif