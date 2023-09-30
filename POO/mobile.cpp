#include "mobile.h"

mobile::mobile()
{
    point.setX(0);
    point.setY(0);
    point.setLibre(false);
}

mobile::~mobile() {

}

void mobile::deplacer(char direction)
{
    if (direction == 'g') {
        int x = point.getX();
        x--;
        point.setX(x);
    }
    if (direction == 'h') {
        int y = point.getY();
        y++;
        point.setY(y);
    }
    if (direction == 'd') {
        int x = point.getX();
        x++;
        point.setX(x);
    }
    if (direction == 'b') {
        int y = point.getY();
        y--;
        point.setY(y);
    }
}

int mobile::getX() const {
    return point.getX();
}

int mobile::getY() const {
    return point.getY();
}

void mobile::setPoint(Coordonnee *m_point) {
    /*point.setX(1);
    point.setY(1);
    point.setLibre(true);*/
    point.setX(m_point->getX());
    point.setY(m_point->getY());
    point.setLibre(m_point->getLibre());
}
