#ifndef CASE_MUR_H
#define CASE_MUR_H

#include "case.h"
#include <QPainter>

class Case_mur : public Case
{
public:
    Case_mur();
    ~Case_mur();
    Case_mur(Coordonnee *m_p);
    Case_mur(Case_mur &c);
    int getType() const {return 1;};
    bool getMarquee() const {return false;};
    void afficher(QPainter *p) const;
    bool getLibre() const {return false;};
};

#endif // CASE_MUR_H
