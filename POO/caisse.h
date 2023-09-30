#ifndef CAISSE_H
#define CAISSE_H

#include <QPainter>
#include "mobile.h"

class Caisse : public mobile
{
protected:
    bool coloree;
public:
    Caisse();
    ~Caisse();
    Caisse(Coordonnee &p,bool &m_coloree);
    Caisse(Caisse &c);
    void afficher(QPainter *p) const;
    void setColoree(bool m_coloree) {coloree = m_coloree;};
    bool getColoree() const {return coloree;};
    //bool getLibre() const;
};

#endif // CAISSE_H
