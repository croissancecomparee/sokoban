#ifndef GRILLE_H
#define GRILLE_H

#include "case.h"
#include "coordonnee.h"
//#include "niveau.h"
#include <iostream>
//#include <vector>

//#define N 50

using namespace std;

class Grille
{
public:
    Grille();
    Grille(int m_largeur, int m_longueur);
    Grille(Grille &g);
    void afficher(QPainter *p) const;
    Case* getCase(int m_x, int m_y) const;
    int getLargeur() const {return largeur;};
    int getLongueur() const {return longueur;};
    void setCase(int m_x, int m_y, Case *c);
public:
    int largeur;
    int longueur;
    //vector<vector<Case>>  grille;
    Case*** grille;
};

#endif // GRILLE_H
