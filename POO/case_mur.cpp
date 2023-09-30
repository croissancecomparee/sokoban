#include "case_mur.h"

Case_mur::Case_mur()
{

}

/*
Case_mur::~Case_mur() {

}*/

Case_mur::Case_mur(Coordonnee *m_p) {
    point = *m_p;
}

Case_mur::Case_mur(Case_mur &c) {
    point = c.point;
}


void Case_mur::afficher(QPainter *p) const
{
    //QPainter painter;
    int m_p = point.getPixel();
    int m_x = point.getX();
    int m_y = point.getY();

    p->drawPixmap(m_x*m_p,m_y*m_p,m_p,m_p,QPixmap(":/images/images/WallRound_Brown.png"));
}
