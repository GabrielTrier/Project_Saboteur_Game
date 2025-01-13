cmake_minimum_required(VERSION 3.10)
project(ProjetSaboteur C)

set(CMAKE_C_STANDARD 99)

add_executable(ProjetSaboteur main.c source/cartes/cartes.h source/cartes/cartes.c
        source/joueur/joueur.c source/joueur/joueur.h menu/menu.c menu/menu.h source/tableau/tableau.c
        source/tableau/tableau.h source/saisie/saisie.c source/saisie/saisie.h source/aide/aide.h source/aide/aide.c
        source/plateau/plateau.c source/plateau/plateau.h commentaires.h source/score/score.c source/score/score.h
        source/ecranDefaite/ecranDefaite.c source/ecranDefaite/ecranDefaite.h partie/galerie/galerie.c
        partie/galerie/galerie.h partie/penalites/penalites.c partie/penalites/penalites.h partie/reparation/reparation.c
        partie/reparation/reparation.h partie/map/map.c partie/map/map.h partie/eboulement/eboulement.c
        partie/eboulement/eboulement.h partie/pioche/pioche.c partie/pioche/pioche.h partie/choix/choix.c
        partie/choix/choix.h rectangle.h action.h pepite.h arrivee.h
        source/ecranVictoire/ecranVictoire.c source/ecranVictoire/ecranVictoire.h)

target_link_libraries(ProjetSaboteur -lmingw32 -lallegro-5.0.10-monolith-md-debug)