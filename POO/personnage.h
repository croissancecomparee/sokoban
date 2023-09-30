#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <QPainter>
#include "mobile.h"

class Personnage : public mobile
{
public:
    Personnage();
    Personnage(Coordonnee *p);
    Personnage(Personnage &p);
    void afficher(QPainter *p) const;
};

#endif // PERSONNAGE_H
