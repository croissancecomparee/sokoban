#include "grille.h"


Grille::Grille(int m_largeur, int m_longueur)
    //:grille(m_longueur, vector<Case> (m_largeur))
{
    largeur = m_largeur;
    longueur = m_longueur;

    grille = new Case**[longueur];
    for (int i=0;i<longueur;i++) {
        grille[i] = new Case*[largeur];
    }
}

Grille::Grille(Grille &g)
{
    largeur = g.largeur;
    longueur = g.longueur;
    for (int i=0;i<longueur;i++) {
        for (int j=0;j<largeur;j++) {
            grille[i][j] = g.grille[i][j];
        }
    }
}

void Grille::afficher(QPainter *p) const
{
    for(int i=0;i<longueur;i++){
        for (int j=0;j<largeur;j++){
            grille[i][j]->afficher(p);
        }
    }
}

Case* Grille::getCase(int m_x, int m_y) const{
    return grille[m_x][m_y];
}

void Grille::setCase(int m_x, int m_y, Case* c) {
    grille[m_x][m_y] = c;
}
