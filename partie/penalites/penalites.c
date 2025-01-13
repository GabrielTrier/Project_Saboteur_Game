#include "penalites.h"

void clicDansCartePenalite(ALLEGRO_EVENT *event, Joueur *joueur, int *decalageX, int *decalageY, int *glisserDeposerPenalite,
                          int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6, int *partieCommencee) {
    if (*partieCommencee) {
        if (event->mouse.x >= 300 && event->mouse.x <= 370 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
            joueur->piocheJoueur[0].penalite == 1) {
            *glisserDeposerPenalite = 1;
            *decalageX = event->mouse.x - 300;
            *decalageY = event->mouse.y - 32;
            *carte1 = 1;
        } else if (event->mouse.x >= 400 && event->mouse.x <= 470 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[1].penalite == 1) {
            *glisserDeposerPenalite = 1;
            *decalageX = event->mouse.x - 400;
            *decalageY = event->mouse.y - 32;
            *carte2 = 1;
        } else if (event->mouse.x >= 500 && event->mouse.x <= 570 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[2].penalite == 1) {
            *glisserDeposerPenalite = 1;
            *decalageX = event->mouse.x - 500;
            *decalageY = event->mouse.y - 32;
            *carte3 = 1;
        } else if (event->mouse.x >= 600 && event->mouse.x <= 670 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[3].penalite == 1) {
            *glisserDeposerPenalite = 1;
            *decalageX = event->mouse.x - 600;
            *decalageY = event->mouse.y - 32;
            *carte4 = 1;
        } else if (event->mouse.x >= 700 && event->mouse.x <= 770 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[4].penalite == 1) {
            *glisserDeposerPenalite = 1;
            *decalageX = event->mouse.x - 700;
            *decalageY = event->mouse.y - 32;
            *carte5 = 1;
        } else if (event->mouse.x >= 800 && event->mouse.x <= 870 && event->mouse.y >= 32 && event->mouse.y <= 137 &&
                   joueur->piocheJoueur[5].penalite == 1) {
            *glisserDeposerPenalite = 1;
            *decalageX = event->mouse.x - 800;
            *decalageY = event->mouse.y - 32;
            *carte6 = 1;
        }
    }
}

void cartePenaliteAJoueur(ALLEGRO_EVENT *event, Rect p, Rect k, Rect j, Rect g, Rect f, Rect h, int i,
                          ALLEGRO_FONT *fontPartie, ALLEGRO_BITMAP *arrivee, ALLEGRO_BITMAP *entree,
                          ALLEGRO_BITMAP *dosPioche, Joueur* joueur, Action pioche[NB_CARTES],
                          int *modificationPioche, int *glisserDeposerPenalite,
                          int *carte1, int *carte2, int *carte3, int *carte4, int *carte5, int *carte6,
                          Joueur* joueur1, Joueur* joueur2, Joueur* joueur3) {
    if (*glisserDeposerPenalite) {
        if(event->mouse.x >= 0 && event->mouse.x <= 200 && event->mouse.y >= 300 && event->mouse.y <= 400) {
            if (*carte1) {
                if (joueur->piocheJoueur[0].lampe == 1) {
                    joueur1->lampe = 1;
                    joueur1->penalite++;
                }
                if (joueur->piocheJoueur[0].chariot == 1) {
                    joueur1->chariot = 1;
                    joueur1->penalite++;
                }
                if (joueur->piocheJoueur[0].pioche == 1) {
                    joueur1->pioche = 1;
                    joueur1->penalite++;
                }
                al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, 50 * (joueur1->penalite),
                                      350, 30, 40, 0);
            } else if (*carte2) {
                if (joueur->piocheJoueur[1].lampe == 1) {
                    joueur1->lampe = 1;
                    joueur1->penalite++;
                }
                if (joueur->piocheJoueur[1].chariot == 1) {
                    joueur1->chariot = 1;
                    joueur1->penalite++;
                }
                if (joueur->piocheJoueur[1].pioche == 1) {
                    joueur1->pioche = 1;
                    joueur1->penalite++;
                }
                al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, 50 * (joueur1->penalite),
                                      350,30, 40, 0);
            } else if (*carte3) {
                if (joueur->piocheJoueur[2].lampe == 1) {
                    joueur1->lampe = 1;
                    joueur1->penalite++;
                }
                if (joueur->piocheJoueur[2].chariot == 1) {
                    joueur1->chariot = 1;
                    joueur1->penalite++;
                }
                if (joueur->piocheJoueur[2].pioche == 1) {
                    joueur1->pioche = 1;
                    joueur1->penalite++;
                }
                al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, 50 * (joueur1->penalite),
                                      350, 30, 40, 0);
            } else if (*carte4) {
                if (joueur->piocheJoueur[3].lampe == 1) {
                    joueur1->lampe = 1;
                    joueur1->penalite++;
                }
                if (joueur->piocheJoueur[3].chariot == 1) {
                    joueur1->chariot = 1;
                    joueur1->penalite++;
                }
                if (joueur->piocheJoueur[3].pioche == 1) {
                    joueur1->pioche = 1;
                    joueur1->penalite++;
                }
                al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, 50 * (joueur1->penalite),
                                      350,30, 40, 0);
            } else if (*carte5) {
                if (joueur->piocheJoueur[4].lampe == 1) {
                    joueur1->lampe = 1;
                    joueur1->penalite++;
                }
                if (joueur->piocheJoueur[4].chariot == 1) {
                    joueur1->chariot = 1;
                    joueur1->penalite++;
                }
                if (joueur->piocheJoueur[4].pioche == 1) {
                    joueur1->pioche = 1;
                    joueur1->penalite++;
                }
                al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, 50 * (joueur1->penalite),
                                      350, 30, 40, 0);
            } else if (*carte6) {
                if (joueur->piocheJoueur[5].lampe == 1) {
                    joueur1->lampe = 1;
                    joueur1->penalite++;
                }
                if (joueur->piocheJoueur[5].chariot == 1) {
                    joueur1->chariot = 1;
                    joueur1->penalite++;
                }
                if (joueur->piocheJoueur[5].pioche == 1) {
                    joueur1->pioche = 1;
                    joueur1->penalite++;
                }
                al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, 50 * (joueur1->penalite),
                                      350,30, 40, 0);
            }
        }
        else if(event->mouse.x >= 0 && event->mouse.x <= 200 && event->mouse.y >= 450 && event->mouse.y <= 550) {
                joueur2->penalite++;
                if (*carte1) {
                    if (joueur->piocheJoueur[0].lampe == 1) {
                        joueur2->lampe = 1;
                        joueur2->penalite++;
                    }
                    if (joueur->piocheJoueur[0].chariot == 1) {
                        joueur2->chariot = 1;
                        joueur2->penalite++;
                    }
                    if (joueur->piocheJoueur[0].pioche == 1) {
                        joueur2->pioche = 1;
                        joueur2->penalite++;
                    }
                    al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, 50 * (joueur2->penalite),
                                          500,30, 40, 0);
                } else if (*carte2) {
                    if (joueur->piocheJoueur[1].lampe == 1) {
                        joueur2->lampe = 1;
                        joueur2->penalite++;
                    }
                    if (joueur->piocheJoueur[1].chariot == 1) {
                        joueur2->chariot = 1;
                        joueur2->penalite++;
                    }
                    if (joueur->piocheJoueur[1].pioche == 1) {
                        joueur2->pioche = 1;
                        joueur2->penalite++;
                    }
                    al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, 50 * (joueur2->penalite),
                                          500,30, 40, 0);
                } else if (*carte3) {
                    if (joueur->piocheJoueur[2].lampe == 1) {
                        joueur2->lampe = 1;
                        joueur2->penalite++;
                    }
                    if (joueur->piocheJoueur[2].chariot == 1) {
                        joueur2->chariot = 1;
                        joueur2->penalite++;
                    }
                    if (joueur->piocheJoueur[2].pioche == 1) {
                        joueur2->pioche = 1;
                        joueur2->penalite++;
                    }
                    al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, 50 * (joueur2->penalite),
                                          500,30, 40, 0);
                } else if (*carte4) {
                    if (joueur->piocheJoueur[3].lampe == 1) {
                        joueur2->lampe = 1;
                        joueur2->penalite++;
                    }
                    if (joueur->piocheJoueur[3].chariot == 1) {
                        joueur2->chariot = 1;
                        joueur2->penalite++;
                    }
                    if (joueur->piocheJoueur[3].pioche == 1) {
                        joueur2->pioche = 1;
                        joueur2->penalite++;
                    }
                    al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, 50 * (joueur2->penalite),
                                          500,30, 40, 0);
                } else if (*carte5) {
                    if (joueur->piocheJoueur[4].lampe == 1) {
                        joueur2->lampe = 1;
                        joueur2->penalite++;
                    }
                    if (joueur->piocheJoueur[4].chariot == 1) {
                        joueur2->chariot = 1;
                        joueur2->penalite++;
                    }
                    if (joueur->piocheJoueur[4].pioche == 1) {
                        joueur2->pioche = 1;
                        joueur2->penalite++;
                    }
                    al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, 50 * (joueur2->penalite),
                                          500,30, 40, 0);
                } else if (*carte6) {
                    if (joueur->piocheJoueur[5].lampe == 1) {
                        joueur2->lampe = 1;
                        joueur2->penalite++;
                    }
                    if (joueur->piocheJoueur[5].chariot == 1) {
                        joueur2->chariot = 1;
                        joueur2->penalite++;
                    }
                    if (joueur->piocheJoueur[5].pioche == 1) {
                        joueur2->pioche = 1;
                        joueur2->penalite++;
                    }
                    al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, 50 * (joueur2->penalite),
                                          500,30, 40, 0);
                }
            }
        else if(event->mouse.x >= 0 && event->mouse.x <= 200 && event->mouse.y >= 600 && event->mouse.y <= 700) {
                    joueur3->penalite++;
                    if (*carte1) {
                        if (joueur->piocheJoueur[0].lampe == 1) {
                            joueur3->lampe = 1;
                            joueur3->penalite++;
                        }
                        if (joueur->piocheJoueur[0].chariot == 1) {
                            joueur3->chariot = 1;
                            joueur3->penalite++;
                        }
                        if (joueur->piocheJoueur[0].pioche == 1) {
                            joueur3->pioche = 1;
                            joueur3->penalite++;
                        }
                        al_draw_scaled_bitmap(joueur->piocheJoueur[0].image, 0, 0, 106, 162, 50 * (joueur3->penalite),
                                              650,30, 40, 0);
                    } else if (*carte2) {
                        if (joueur->piocheJoueur[1].lampe == 1) {
                            joueur3->lampe = 1;
                            joueur3->penalite++;
                        }
                        if (joueur->piocheJoueur[1].chariot == 1) {
                            joueur3->chariot = 1;
                            joueur3->penalite++;
                        }
                        if (joueur->piocheJoueur[1].pioche == 1) {
                            joueur3->pioche = 1;
                            joueur3->penalite++;
                        }
                        al_draw_scaled_bitmap(joueur->piocheJoueur[1].image, 0, 0, 106, 162, 50 * (joueur3->penalite),
                                              650,30, 40, 0);
                    } else if (*carte3) {
                        if (joueur->piocheJoueur[2].lampe == 1) {
                            joueur3->lampe = 1;
                            joueur3->penalite++;
                        }
                        if (joueur->piocheJoueur[2].chariot == 1) {
                            joueur3->chariot = 1;
                            joueur3->penalite++;
                        }
                        if (joueur->piocheJoueur[2].pioche == 1) {
                            joueur3->pioche = 1;
                            joueur3->penalite++;
                        }
                        al_draw_scaled_bitmap(joueur->piocheJoueur[2].image, 0, 0, 106, 162, 50 * (joueur3->penalite),
                                              650,30, 40, 0);
                    } else if (*carte4) {
                        if (joueur->piocheJoueur[3].lampe == 1) {
                            joueur3->lampe = 1;
                            joueur3->penalite++;
                        }
                        if (joueur->piocheJoueur[3].chariot == 1) {
                            joueur3->chariot = 1;
                            joueur3->penalite++;
                        }
                        if (joueur->piocheJoueur[3].pioche == 1) {
                            joueur3->pioche = 1;
                            joueur3->penalite++;
                        }
                        al_draw_scaled_bitmap(joueur->piocheJoueur[3].image, 0, 0, 106, 162, 50 * (joueur3->penalite),
                                              650,30, 40, 0);
                    } else if (*carte5) {
                        if (joueur->piocheJoueur[4].lampe == 1) {
                            joueur3->lampe = 1;
                            joueur3->penalite++;
                        }
                        if (joueur->piocheJoueur[4].chariot == 1) {
                            joueur3->chariot = 1;
                            joueur3->penalite++;
                        }
                        if (joueur->piocheJoueur[4].pioche == 1) {
                            joueur3->pioche = 1;
                            joueur3->penalite++;
                        }
                        al_draw_scaled_bitmap(joueur->piocheJoueur[4].image, 0, 0, 106, 162, 50 * (joueur3->penalite),
                                              650, 30, 40, 0);
                    } else if (*carte6) {
                        if (joueur->piocheJoueur[5].lampe == 1) {
                            joueur3->lampe = 1;
                            joueur3->penalite++;
                        }
                        if (joueur->piocheJoueur[5].chariot == 1) {
                            joueur3->chariot = 1;
                            joueur3->penalite++;
                        }
                        if (joueur->piocheJoueur[5].pioche == 1) {
                            joueur3->pioche = 1;
                            joueur3->penalite++;
                        }
                        al_draw_scaled_bitmap(joueur->piocheJoueur[5].image, 0, 0, 106, 162, 50 * (joueur3->penalite),
                                              650,30, 40, 0);
                    }
                }
        else{
            affichagePlateauJeu(k, j, g, f, h, p, i, fontPartie, arrivee, entree, dosPioche, &joueur);
        }

        carteUtilisee(pioche, &joueur, &modificationPioche, &carte1, &carte2, &carte3, &carte4, &carte5, &carte6);
        *glisserDeposerPenalite = 0;
    }
}