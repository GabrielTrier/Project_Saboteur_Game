//
// Created by gabri on 3/29/2021.
//
#include "tableau.h"

void affichagePlateauJeu(Rect k, Rect j, Rect g, Rect f, Rect h, Rect p, int i,ALLEGRO_FONT*fontPartie, ALLEGRO_BITMAP* arrivee,
                         ALLEGRO_BITMAP* entree, ALLEGRO_BITMAP* dosPioche, Joueur* joueur){
    al_clear_to_color(al_map_rgb(0, 0, 0));
    k = iniRectanglehaut(i);
    dessinerRectangleDuHaut(fontPartie,k);
    j= inirectangle_pannejoueur(i);
    dessinerRectangle_pannejoueur(fontPartie,&j);
    g= RectangleJoueur1(i);
    dessinerRectangleJoueur1(fontPartie,&g);
    f = RectangleJoueur2(i);
    dessinerRectangleJoueur2(fontPartie,&f);
    h = RectangleJoueur3(i);
    dessinerRectangleJoueur3(fontPartie,&h);
    placerCartesArrivee(arrivee);
    placerCarteEntreeMine(entree);
    affichagePlateauGalerie(p);
    dessinerPioche(dosPioche);
    dessinerDefausse(dosPioche);
    affichageCartesJoueur(&joueur);
}
void dessinerDefausse(ALLEGRO_BITMAP* dosPioche){
    al_draw_scaled_bitmap(dosPioche,0,0,110,167,1400,0,100,150,0);
}
void dessinerPioche(ALLEGRO_BITMAP* dosPioche){
    al_draw_scaled_bitmap(dosPioche,0,0,110,167,1300,0,100,150,0);
}
//rectangle haut
Rect iniRectanglehaut(int i){
    Rect rectangle = {0};
    rectangle.largeur = 1300;
    rectangle.hauteur = 150;
    placerRectanglehaut(&rectangle, i);
    rectangle.color = al_map_rgb(255, 200, 87);
    return rectangle;
}

void placerRectanglehaut(Rect* r, int i){
    r->x = 0;
    r->y = 0;
}
void dessinerRectangleDuHaut(ALLEGRO_FONT* fontPartie,Rect r){
        al_draw_filled_rectangle(r.x, r.y, r.largeur+r.x, r.hauteur+r.y, r.color);
        al_draw_text(fontPartie,al_map_rgb(0,0,0),0,0,0,"Joueur 1");
    al_draw_text(fontPartie,al_map_rgb(0,0,0),400,0,0,"score: ");
    al_draw_text(fontPartie,al_map_rgb(0,0,0),0,75,0,"Cartes de jeu");
    }
    //rectangle malus
Rect inirectangle_pannejoueur(int i){
    Rect rectangle = {0};
    rectangle.largeur = 1500;
    rectangle.hauteur = 100;
    placerRectanglepannejoueur(&rectangle, i);
    rectangle.color = al_map_rgb(125, 125, 125);
    return rectangle;
}
void placerRectanglepannejoueur(Rect* j, int i){
    j->x = 0;
    j->y = 150;
}

void dessinerRectangle_pannejoueur(ALLEGRO_FONT* fontPartie,Rect* j){
    al_draw_filled_rectangle(j->x, j->y, j->largeur+j->x, j->hauteur+j->y, j->color);
    al_draw_text(fontPartie,al_map_rgb(0,0,0),0,150,0,"Les joueurs en attente...");

}
//joueur 1
Rect RectangleJoueur1(int i){
    Rect rectangle = {0};
    rectangle.largeur = 200;
    rectangle.hauteur = 100;
    placerRectanglejoueur1(&rectangle, i);
    rectangle.color = al_map_rgb(50, 50, 250);
    return rectangle;
}
void placerRectanglejoueur1(Rect* g, int i){
    g->x = 0;
    g->y = 300;
}

void dessinerRectangleJoueur1(ALLEGRO_FONT*fontPartie,Rect* g){
    al_draw_filled_rectangle(g->x, g->y, g->largeur+g->x, g->hauteur+g->y, g->color);
    al_draw_text(fontPartie,al_map_rgb(0,0,0),0,300,0,"Joueur 1:");
}
//joueur 2
Rect RectangleJoueur2(int i){
    Rect rectangle = {0};
    rectangle.largeur = 200;
    rectangle.hauteur = 100;
    placerRectanglejoueur2(&rectangle, i);
    rectangle.color = al_map_rgb(50, 50, 250);
    return rectangle;
}
void placerRectanglejoueur2(Rect* g, int i){
    g->x = 0;
    g->y = 450;
}

void dessinerRectangleJoueur2(ALLEGRO_FONT* fontPartie,Rect* g){
    al_draw_filled_rectangle(g->x, g->y, g->largeur+g->x, g->hauteur+g->y, g->color);
    al_draw_text(fontPartie,al_map_rgb(0,0,0),0,450,0,"Joueur 2:");

}
//joueur 3
Rect RectangleJoueur3(int i){
    Rect rectangle = {0};
    rectangle.largeur = 200;
    rectangle.hauteur = 100;
    placerRectanglejoueur3(&rectangle, i);
    rectangle.color = al_map_rgb(50, 50, 250);
    return rectangle;
}
void placerRectanglejoueur3(Rect* g, int i){
    g->x = 0;
    g->y = 600;
}

void dessinerRectangleJoueur3(ALLEGRO_FONT* fontPartie,Rect* g){
    al_draw_filled_rectangle(g->x, g->y, g->largeur+g->x, g->hauteur+g->y, g->color);
    al_draw_text(fontPartie,al_map_rgb(0,0,0),0,600,0,"Joueur 3:");

}


/*    Rect r = {0};
    Rect j = {0};
    Rect g = {0};
    Rect f = {0};
    Rect h = {0};

     r = iniRectanglehaut(i);
        dessinerRectangleDuHaut(r);
        j= inirectangle_pannejoueur(i);
        dessinerRectangle_pannejoueur(&j);
        g= RectangleJoueur1(i);
        dessinerRectangleJoueur1(&g);
        f = RectangleJoueur2(i);
        dessinerRectangleJoueur2(&f);
        h = RectangleJoueur3(i);
        dessinerRectangleJoueur3(&h);*/