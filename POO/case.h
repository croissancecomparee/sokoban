#ifndef CASE_H
#define CASE_H

//#include "immobile.h"
#include "coordonnee.h"
#include <QPainter>

class Case//Immobile
{
protected:
    Coordonnee  point;
public:
    Case();
    ~Case();
    Case(int m_x, int m_y, bool m_libreDeplacement);
    Case(Case &c);
    //virtual int getType() const =0;
    virtual void afficher(QPainter *p) const =0;
    virtual bool getLibre() const = 0;
    virtual bool getMarquee() const = 0;
    int getVoisineX(char direction);
    int getVoisineY(char direction);
    bool getCaisse() const;
    void setPoint(Coordonnee m_p);
};

#endif // CASE_H
