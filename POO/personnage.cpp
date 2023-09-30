#include "personnage.h"


Personnage::Personnage()
{

}

Personnage::Personnage(Coordonnee *p) {
    point = *p;
}

Personnage::Personnage(Personnage &p) {

}

void Personnage::afficher(QPainter *p) const
{
    //QPainter painter;
    int m_p = point.getPixel();
    int m_x = point.getX();
    int m_y = point.getY();
    //p->drawPixmap(m_x*m_p,m_y*m_p,QPixmap(":/images/images/Character4.png"));
    p->drawPixmap(m_x*m_p+m_p/4,m_y*m_p,QPixmap(":/images/images/Character4.png"));
}

