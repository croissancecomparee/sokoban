#include "case_vide.h"

Case_Vide::Case_Vide()
{
    marquee = false;
}

Case_Vide::~Case_Vide() {

}

Case_Vide::Case_Vide(Coordonnee *p, bool m_marquee) {
    point = *p;
    marquee = m_marquee;
}

Case_Vide::Case_Vide(Case_Vide &c) {
    marquee = c.marquee;
    point = c.point;
}

void Case_Vide::afficher(QPainter *p) const
{
    //QPainter painter;
    int m_p = point.getPixel();
    int m_x = point.getX();
    int m_y = point.getY();
    p->drawPixmap(m_x*m_p,m_y*m_p,m_p,m_p,QPixmap(":/images/images/GroundGravel_Sand.png"));

    if (marquee == true) {
        //QPainter painter2;
        p->drawPixmap(m_x*m_p+m_p/4,m_y*m_p+m_p/4,QPixmap(":/images/images/EndPoint_Blue.png"));
    }
}

