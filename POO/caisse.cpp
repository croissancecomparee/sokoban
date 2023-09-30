#include "caisse.h"

Caisse::Caisse():mobile()
{
    coloree = false;
}

Caisse::~Caisse() {

}

Caisse::Caisse(Coordonnee &p, bool &m_coloree) {
    point = p;
    coloree = m_coloree;
}

Caisse::Caisse(Caisse &c):mobile() {
    coloree = c.coloree;
}


void Caisse::afficher(QPainter *p) const {
    //QPainter painter;

    int m_p = point.getPixel();
    int m_x = point.getX();
    int m_y = point.getY();

    if (coloree) {
        p->drawPixmap(m_x*m_p,m_y*m_p,m_p,m_p,QPixmap(":/images/images/Crate_Blue.png"));
    }
    else {
        p->drawPixmap(m_x*m_p,m_y*m_p,m_p,m_p,QPixmap(":/images/images/Crate_Brown.png"));
    }
}
