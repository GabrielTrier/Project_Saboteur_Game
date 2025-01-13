#include "choix.h"

void choixJoueurLorsDeSonTour(ALLEGRO_EVENT *event, ALLEGRO_BITMAP *pepite3, ALLEGRO_BITMAP *arriveeGrotte,
                              ALLEGRO_BITMAP *arrivee, Joueur *joueur1, Action pioche[NB_CARTES], Rect p,
                              int *partieCommencee, int *decalageX, int *decalageY, int *glisserDeposerGalerie,
                              int *glisserDeposerPenalite, int *glisserDeposerReparation, int *carteEboulement,
                              int *carteMap, int *clicPiocheOuDefausse, int *modificationPioche,
                              int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6){
    clicDansCarteGalerie(&event, &joueur1, &decalageX, &decalageY, &glisserDeposerGalerie,
                         &carte1, &carte2, &carte3, &carte4, &carte5, &carte6, &partieCommencee);
    clicDansCartePenalite(&event, &joueur1, &decalageX, &decalageY, &glisserDeposerPenalite,
                          &carte1, &carte2, &carte3, &carte4, &carte5, &carte6, &partieCommencee);
    clicDansCarteReparation(&event, &joueur1, &decalageX, &decalageY, &glisserDeposerReparation,
                            &carte1, &carte2, &carte3, &carte4, &carte5, &carte6, &partieCommencee);
    clicDansCarteEboulement(&event, &joueur1, &partieCommencee, &carteEboulement,
                            &carte1, &carte2, &carte3, &carte4, &carte5, &carte6);
    clicDansGalerieAvecEboulement(&event, p, &joueur1, pioche, &modificationPioche, &carteEboulement,
                                  &carte1, &carte2, &carte3, &carte4, &carte5, &carte6);
    clicDansCarteMap(&event, &joueur1, &partieCommencee, &carteMap, &carte1, &carte2, &carte3, &carte4,
                     &carte5, &carte6);
    clicSurArriveeAvecMap(&event, pepite3, arriveeGrotte, &joueur1, pioche, arrivee, &modificationPioche,
                           &carteMap, &carte1, &carte2, &carte3, &carte4, &carte5, &carte6);
    clicPiocheOuDefaussePuisCarte(&event, &partieCommencee, &clicPiocheOuDefausse);
    clicDansCarteApresPiocheouDefausse(&event, &joueur1, pioche, &clicPiocheOuDefausse, &modificationPioche);
}

void deplacementCarte(ALLEGRO_EVENT* event, ALLEGRO_BITMAP* arriveeDos, ALLEGRO_BITMAP* entree, ALLEGRO_BITMAP* dosPioche,
                      ALLEGRO_FONT* fontPartie, Action pioche[NB_CARTES], Rect k, Rect j, Rect g, Rect f, Rect h, Rect p,
                      int i, Joueur* joueur1, int glisserDeposerGalerie, int glisserDeposerPenalite, int glisserDeposerReparation,
                      int decalageX, int decalageY, int carte1, int carte2, int carte3, int carte4, int carte5, int carte6){
    if ((glisserDeposerGalerie == 1) || (glisserDeposerPenalite == 1) || (glisserDeposerReparation == 1)) {
        affichagePlateauJeu(k, j, g, f, h, p, i, fontPartie, arriveeDos, entree, dosPioche, pioche);
        actualisationCartes(&event, &joueur1, decalageX, decalageY, carte1, carte2, carte3, carte4, carte5, carte6);
    }
}

void relachementCarte(ALLEGRO_EVENT* event, ALLEGRO_BITMAP* entree, ALLEGRO_BITMAP* dosPioche, Arrivee arrivee[NB_ARRIVEES],
                      Action pioche[NB_CARTES], ALLEGRO_FONT* fontPartie,  Rect k, Rect j, Rect g, Rect f, Rect h, Rect p,
                      int i, Joueur* joueur1, Joueur* joueur2, Joueur* joueur3, int* modificationPioche,
                      int* glisserDeposerGalerie, int* glisserDeposerPenalite, int* glisserDeposerReparation, int* decalageX,
                      int* decalageY, int* carte1, int* carte2, int* carte3, int* carte4, int* carte5, int* carte6){
    *decalageX = 0;
    *decalageY = 0;
    carteGalerieDansPlateau(&event, p, k, j, g, f, h, i, fontPartie, arrivee, entree, dosPioche, pioche,
                            &modificationPioche, &glisserDeposerGalerie, &carte1, &carte2, &carte3, &carte4,
                            &carte5, &carte6);
    cartePenaliteAJoueur(&event, p, k, j, g, f, h, i, fontPartie, arrivee, entree, dosPioche, &joueur1, pioche,
                         &modificationPioche, &glisserDeposerPenalite, &carte1, &carte2, &carte3, &carte4,
                         &carte5, &carte6, &joueur1, &joueur2, &joueur3);
    carteReparationAJoueur(&event, p, k, j, g, f, h, i, fontPartie, arrivee, entree, dosPioche, &joueur1, pioche,
                           &modificationPioche, &glisserDeposerReparation, &carte1, &carte2, &carte3, &carte4,
                           &carte5, &carte6,&joueur1, &joueur2, &joueur3);
}