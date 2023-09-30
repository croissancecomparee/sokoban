#include "case_neant.h"

Case_neant::Case_neant()
{

}

Case_neant::Case_neant(Coordonnee *p) {
    point = *p;
}

Case_neant::Case_neant(Case_neant &c) {
    point = c.point;
}

void Case_neant::afficher(QPainter *p) const {
    //QPainter painter;
    int m_p = point.getPixel();
    int m_x = point.getX();
    int m_y = point.getY();

    p->drawPixmap(m_x*m_p,m_y*m_p,m_p,m_p,QPixmap(":/images/images/Ground_Concrete.png"));
}
