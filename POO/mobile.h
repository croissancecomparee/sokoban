#ifndef MOBILE_H
#define MOBILE_H

#import "coordonnee.h"
#include <QPainter>

class mobile //:Coordonnee //relation de composition semble plus appropriee plutot qu'un heritage
{
protected:
    Coordonnee point;
public:
    mobile();
    virtual ~mobile();
    void deplacer(char direction);
    virtual void afficher(QPainter *p) const =0;
    //void getVoisine(); //utilite ?
    bool getLibre();
    int getX() const;
    int getY() const;
    void setPoint(Coordonnee *m_point);
};

#endif // MOBILE_H
