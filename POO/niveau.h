#ifndef NIVEAU_H
#define NIVEAU_H

#include <QPainter>
#include <QFile>
#include <QTextStream>
#include <QString>
#include "personnage.h"
#include "caisse.h"
#include "grille.h"
#include <iostream>
#include <string>
#include <fstream>
#include "case_mur.h"
#include "case_neant.h"
#include "case_vide.h"
#include <QDebug>

using namespace std;


class Niveau
{
protected:
    //string codeNiveau;
    int nbCaisses;
    int numNiveau;
    bool enCours;
    int largeur;
    int longueur;
    int nbMove = 0;
    //bool resultat; //utilite ?
    //string nomFichier;
    Grille* grille;
    Personnage* perso;
    Caisse** caisses;
public:
    Niveau();
    Niveau(int m_nbCaisses, int m_numNiveau, bool m_enCours, Grille &m_grille, Personnage &m_perso, Caisse** m_caisses);
    Niveau(Niveau &n);
    bool getEncours() const {return enCours;};
    bool getCaisse(int x, int y) const; // parcours le tableau de caisses et compare les coordonnees passees en entree, renvoit true si il y a une ciasse correspondante, false sinon
    //void setFichier(string m_nomFichier);
    // void restartNiveau();
    //void quitterNiveau();
    bool testerSiGagner() const;
    void importerGrille(QString nomFichier); //Grille
    void afficher(QPainter *p) const;
    Personnage* getPerso() const {return perso;};
    Grille* getGrille() const {return grille;};
    Caisse* getCaisses(int k) const {return caisses[k];};
    int isCaisse(int x, int y) const; //fonction parcours la liste des caisses et retournant si les coordonnées de la case passées en paramètre correspondent à une caisse
    int getNumNiveau() const { return numNiveau;};
    int getNbMove() const {return nbMove;};
    void incrNbMove() {nbMove++;};
    void resetNbMove() {nbMove = 0;};
    //void deplacer(char direction);
};

#endif // NIVEAU_H
