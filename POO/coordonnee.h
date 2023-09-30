#ifndef COORDONNEE_H
#define COORDONNEE_H


class Coordonnee
{
protected:
    int x;
    int y;
    bool libreDeplacement;
    int pixel = 64;
public:
    Coordonnee();
    Coordonnee(int m_x, int m_y, bool m_libreDeplacement);
    Coordonnee(Coordonnee &c);
    bool getLibre() const {return libreDeplacement;};
    //Coordonnee getCoordonnee() const;
    int getX() const {return x;};
    int getY() const {return y;};
    int getPixel() const {return pixel;};
    //void setX(int dx);
    inline void setX(int dx) {x = dx;};
    inline void setY(int dy) {y = dy;};
    inline void setLibre(bool lib) {libreDeplacement = lib;};
};

#endif // COORDONNEE_H
