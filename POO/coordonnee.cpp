#include "coordonnee.h"

Coordonnee::Coordonnee()
{
    x = 0;
    y = 0;
    libreDeplacement = false;
}

Coordonnee::Coordonnee(int m_x, int m_y, bool m_libreDeplacement)
{
    x = m_x;
    y = m_y;
    libreDeplacement = m_libreDeplacement;
}

Coordonnee::Coordonnee(Coordonnee &c)
{
    x = c.x;
    y = c.y;
    libreDeplacement = c.libreDeplacement;
}

/*
void Coordonnee::setX(int dx) {
    x = dx;
}*/
