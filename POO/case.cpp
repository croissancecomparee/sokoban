#include "case.h"

Case::Case()
{
    point.setX(0);
    point.setY(0);
    point.setLibre(false);
}

Case::~Case() {

}

Case::Case(int m_x, int m_y, bool m_libreDeplacement)
{
    point.setX(m_x);
    point.setY(m_y);
    point.setLibre(m_libreDeplacement);
}
/*
void Case::afficher() const // methode abstraite
{
    QPainter painter;
    painter.drawPixmap(10,100,100,100,QPixmap(":/PNG/images2/images/GroundGravel_Concrete.png"));
}*/

int Case::getVoisineX(char direction) {
    if (direction == 'g') {
        return (point.getX()-1);
    }
    if (direction == 'h') {
        return (point.getX());
    }
    if (direction == 'd') {
        return (point.getX()+1);
    }
    if (direction == 'b') {
        return (point.getX());
    }
    else {
        return 0;
    }
}

int Case::getVoisineY(char direction) {
    if (direction == 'g') {
        return (point.getY());
    }
    if (direction == 'h') {
        return (point.getY()+1);
    }
    if (direction == 'd') {
        return (point.getY());
    }
    if (direction == 'b') {
        return (point.getY()-1);
    }
    else {
        return 0;
    }
}

void Case::setPoint(Coordonnee m_p) {
    point.setX(m_p.getX());
    point.setY(m_p.getY());
    point.setLibre(m_p.getLibre());
}
