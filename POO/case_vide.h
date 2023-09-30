#ifndef CASE_VIDE_H
#define CASE_VIDE_H

#include "case.h"
#include <QPainter>

class Case_Vide : public Case
{
private:
    bool marquee;
public:
    Case_Vide();
    ~Case_Vide();
    Case_Vide(Coordonnee *p, bool m_marquee);
    Case_Vide(Case_Vide &c);
    int getType() const {return 2;};
    void afficher(QPainter *p) const;
    bool getLibre() const {return true;};
    bool getMarquee() const {return marquee;};
    void setMarquee(bool m_marquee) {marquee = m_marquee;};
    //bool getCaisse() const;
};

#endif // CASE_VIDE_H
