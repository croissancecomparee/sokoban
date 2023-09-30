#ifndef CASE_NEANT_H
#define CASE_NEANT_H

#include "case.h"
#include <QPainter>

class Case_neant : public Case
{
public:
    Case_neant();
    Case_neant(Coordonnee *p);
    Case_neant(Case_neant &c);
    int getType() const {return 3;};
    bool getMarquee() const {return false;};
    void afficher(QPainter *p) const;
    bool getLibre() const {return false;};
};

#endif // CASE_NEANT_H
