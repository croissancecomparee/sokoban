#include "niveau.h"

Niveau::Niveau()
{
    //nbCaisses = 0;
    //numNiveau = 0;
    //largeur = 0;
    //longueur = 0;
    //enCours = false;
    //resultat = false;
    //grille = new Grille();
    perso = new Personnage;
    /*
    caisses = new Caisse*[nbCaisses];
    for (int i=0;i<nbCaisses;i++) {
        caisses[i] = new Caisse();
    }
    */
}

Niveau::Niveau(int m_nbCaisses, int m_numNiveau, bool m_enCours, Grille &m_grille, Personnage &m_perso, Caisse** m_caisses) {
    nbCaisses = m_nbCaisses;
    numNiveau = m_numNiveau;
    enCours = m_enCours;
    //resultat = m_resultat;
    //grilleDeb = m_grilleDeb;
    grille = new Grille(m_grille);
    perso = new Personnage(m_perso);
    caisses = new Caisse*[nbCaisses];
    for (int i=0;i<nbCaisses;i++) {
        caisses[i] = m_caisses[i];
    }
}

Niveau::Niveau(Niveau &n) {
    nbCaisses = n.nbCaisses;
    numNiveau = n.numNiveau;
    enCours = n.enCours;
    largeur = n.largeur;
    longueur = n.longueur;
    //resultat = n.resultat;
    grille = n.grille;
    perso = n.perso;
    for (int i=0; i<nbCaisses;i++) {
        caisses[i] = n.caisses[i];
    }
}

bool Niveau::getCaisse(int x, int y) const {
    for (int i=0;i<nbCaisses;i++) {
        if ((caisses[i]->getX() == x)&&(caisses[i]->getY() == y)) {
            return true;
        }
    }
    return false;
}
/*
void Niveau::setFichier(string m_nomFichier) {
    nomFichier = m_nomFichier;
}*/


void Niveau::afficher(QPainter *p) const {
    grille->afficher(p);
    perso->afficher(p);
    for (int i=0;i<nbCaisses;i++) {
        caisses[i]->afficher(p);
    }
}

void Niveau::importerGrille(QString nomFichier) {
    //ifstream fichier(nomFichier.c_str(), ios::in);
    QString curseur;
    Coordonnee p;
    QFile fichier(nomFichier);
    int k=0; // compteur de caisse

    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream flux(&fichier);

        numNiveau = flux.readLine().toInt();
        nbCaisses = flux.readLine().toInt();
        largeur= flux.readLine().toInt();
        longueur= flux.readLine().toInt();
        grille = new Grille(largeur,longueur);
        caisses = new Caisse*[nbCaisses];
        //perso = new Personnage(new Coordonnee());
        for (int i=0;i<nbCaisses;i++) {
            caisses[i] = new Caisse();
        }

        //grille->grille[0][0] = new Case_mur();
        grille->setCase(0,0, new Case_mur());
        //fichier >> numNiveau >> nbCaisses >> largeur >> longueur; // >> codeNiveau;
        while (!flux.atEnd()) {
            for (int j=0; j<largeur;j++) {
                curseur = flux.readLine();
                for (int i=0; i<longueur; i++) {
                     // on lis le caractere
                    // on change les coordonnes du point
                    //p.setX(i);
                    //p.setY(j);
                    // selon le caractere du curseur, on ajoute dans la grille
                    switch(curseur.at(i).toLatin1())  {
                        case '-': { // case vide non marquee
                            grille->setCase(i,j, new Case_Vide(new Coordonnee(i,j,true), false));
                            break;
                        }
                        case 'O': { // case vide marquee
                            grille->setCase(i,j, new Case_Vide(new Coordonnee(i,j,true), true));
                            break;
                        }
                        case 'P': { // case joueur, donc vide non marquee
                            grille->setCase(i,j, new Case_Vide(new Coordonnee(i,j,true), false));
                            perso->setPoint(new Coordonnee(i,j,true));
                            break;
                        }
                        case 'C': {// case caisse, non marquee
                            grille->setCase(i,j, new Case_Vide(new Coordonnee(i,j,true), false));
                            caisses[k]->setPoint(new Coordonnee(i,j,true));
                            k++;
                            break;
                        }
                        case 'M':{ // case caisse, coloree, donc marquee
                            grille->setCase(i,j, new Case_Vide(new Coordonnee(i,j,true), true));
                            caisses[k]->setPoint(new Coordonnee(i,j,true));
                            caisses[k]->setColoree(true);
                            k++;
                            break;
                            }
                        case '_': {// case neant
                            grille->setCase(i,j, new Case_neant(new Coordonnee(i,j,false)));
                            break;
                            }
                        case '#': {// case mur
                            grille->setCase(i,j, new Case_mur(new Coordonnee(i,j,false)));
                            break;
                        }
                         default: {
                            grille->setCase(i,j, new Case_neant(new Coordonnee(i,j,false)));
                            break;
                        }

                    }
                }
            }
        }
        //fichier.close();
    }
    else {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}


int Niveau::isCaisse(int x, int y) const {
    int res = -1;
    for (int k=0;k<nbCaisses;k++){
        if (((caisses[k]->getX()==x)&&(caisses[k]->getY()==y))) {
            res = k;
        }
    }
    return res;
}

bool Niveau::testerSiGagner() const {
    int k = 0;
    bool gagne = true;
    while (gagne == true && k<nbCaisses) {
        gagne = caisses[k]->getColoree();
        k++;
    }
    return (gagne);
}
/*
void deplacer(char direction) {

}
*/
