#include "plateau.h"

Rect initRectanglePlateau(){
    Rect plateau = {0};
    plateau.x = 300;
    plateau.y = 250;
    plateau.largeur = 1099;
    plateau.hauteur = 500;
    plateau.color = al_map_rgb(200, 200, 200);
    return plateau;
}

void affichagePlateauGalerie(Rect p){
    al_draw_filled_rectangle(p.x, p.y, p.x+p.largeur, p.y+p.hauteur, p.color);
    affichageLignes(p);
    affichageColonnes(p);
}

void affichageLignes(Rect p){
    ALLEGRO_COLOR noir = al_map_rgb(0, 0, 0);
    al_draw_line(p.x, p.y+(p.hauteur/5), p.x+p.largeur, p.y+(p.hauteur/5), noir, 1);
    al_draw_line(p.x, p.y+(2*p.hauteur/5), p.x+p.largeur, p.y+(2*p.hauteur/5), noir, 1);
    al_draw_line(p.x, p.y+(3*p.hauteur/5), p.x+p.largeur, p.y+(3*p.hauteur/5), noir, 1);
    al_draw_line(p.x, p.y+(4*p.hauteur/5), p.x+p.largeur, p.y+(4*p.hauteur/5), noir, 1);
}

void affichageColonnes(Rect p){
    ALLEGRO_COLOR noir = al_map_rgb(0, 0, 0);
    al_draw_line(p.x+(p.largeur/7), p.y, p.x+(p.largeur/7), p.y+p.hauteur, noir, 1);
    al_draw_line(p.x+(2*p.largeur/7), p.y, p.x+(2*p.largeur/7), p.y+p.hauteur, noir, 1);
    al_draw_line(p.x+(3*p.largeur/7), p.y, p.x+(3*p.largeur/7), p.y+p.hauteur, noir, 1);
    al_draw_line(p.x+(4*p.largeur/7), p.y, p.x+(4*p.largeur/7), p.y+p.hauteur, noir, 1);
    al_draw_line(p.x+(5*p.largeur/7), p.y, p.x+(5*p.largeur/7), p.y+p.hauteur, noir, 1);
    al_draw_line(p.x+(6*p.largeur/7), p.y, p.x+(6*p.largeur/7), p.y+p.hauteur, noir, 1);
}