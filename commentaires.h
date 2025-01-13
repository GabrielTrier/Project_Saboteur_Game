//
// Created by kenza on 04-Apr-21.
//

#ifndef PROJETSABOTEUR_COMMENTAIRES_H
#define PROJETSABOTEUR_COMMENTAIRES_H

/*
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
if (entree == NULL) {
printf("ArriveeDos bitmap assertion failed.");
al_destroy_display(display);
al_destroy_timer(timer);
al_destroy_event_queue(queue);
al_destroy_font(font);
al_destroy_bitmap(fond);
al_destroy_bitmap(entree);
}
regle1 = al_load_bitmap("../images/regle1.JPG");
if (fond == NULL) {
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
if (fond == NULL) {
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
if (fond == NULL) {
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
if (fond == NULL) {
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
if (fond == NULL) {
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

chariotR = al_load_bitmap("../images/reparationChariot.JPG");
if (chariotR == NULL) {
printf("ChariotR bitmap assertion failed.");
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
}
lanterneR = al_load_bitmap("../images/reparationLanterne.JPG");
if (lanterneR == NULL) {
printf("LanterneR bitmap assertion failed.");
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
}
piocheR = al_load_bitmap("../images/reparationPioche.JPG");
if (piocheR == NULL) {
printf("PiocheR bitmap assertion failed.");
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
}
chariotLanterneR = al_load_bitmap("../images/reparationChariotLanterne.JPG");
if (chariotLanterneR == NULL) {
printf("ChariotLanterneR bitmap assertion failed.");
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
}
chariotPiocheR = al_load_bitmap("../images/reparationChariotPioche.JPG");
if (chariotPiocheR == NULL) {
printf("ChariotPiocheR bitmap assertion failed.");
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
}
lanternePiocheR = al_load_bitmap("../images/reparationLanternePioche.JPG");
if (lanternePiocheR == NULL) {
printf("LanternePiocheR bitmap assertion failed.");
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
}
nain = al_load_bitmap("../images/nain.JPG");
if (nain == NULL) {
printf("Nain bitmap assertion failed.");
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
}
saboteur = al_load_bitmap("../images/saboteur.JPG");
if (saboteur == NULL) {
printf("Saboteur bitmap assertion failed.");
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
}
pepite1 = al_load_bitmap("../images/pepite1.JPG");
if (pepite1 == NULL) {
printf("Pepite1 bitmap assertion failed.");
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
}
pepite2 = al_load_bitmap("../images/pepite2.JPG");
if (pepite2 == NULL) {
printf("Pepite2 bitmap assertion failed.");
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
}
pepite3 = al_load_bitmap("../images/pepite3.JPG");
if (pepite3 == NULL) {
printf("Pepite3 bitmap assertion failed.");
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
dosPioche = al_load_bitmap("../images/dosPioche.JPG");
if (dosPioche == NULL) {
printf("DosPioche bitmap assertion failed.");
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
}
arriveeGrotte = al_load_bitmap("../images/arriveeGrotte.PNG");
if (arriveeGrotte == NULL) {
printf("ArriveeGrotte bitmap assertion failed.");
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
}
}*/

#endif //PROJETSABOTEUR_COMMENTAIRES_H
