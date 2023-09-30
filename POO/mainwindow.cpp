#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);/*
    Coordonnee p(5,5, false);
    perso = new Personnage(p);
    perso->setPoint(&p);
    p = Coordonnee(6,6,false);
    cai = new Caisse(p, false);
    cai->setPoint(&p);
    p = Coordonnee(7,7,false);
    cm = new Case_mur(p);
    p = Coordonnee(8,8,true);
    cv = new Case_Vide(&p,false);
    p = Coordonnee(9, 9, false);
    cn = new Case_neant(&p);*/

    n = new Niveau();
    n2 = new Niveau();

    n->importerGrille(":/niveaux/niveau" + QString::number(numNiveau));

    *n2 = *n;

    //r = new CRectangle(10,50,70,30);
    //im = new CImagePPM("/mini-monster-crawler-game-character.jpg");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete n;
    delete n2;
    //delete r;
    //delete im;
}

/*
void MainWindow::setNiveau(Niveau &m_n) {
    n = &m_n;
}*/

void MainWindow::paintEvent(QPaintEvent* e) {
    QWidget::paintEvent(e);
    QPainter painter(this);
    //painter.setPen( QPen(Qt::red, 1) );
    //painter.setFont(QFont("Arial",16));
    //painter.drawText(10,30,QString("Exemple de tracés 2D"));

    /*perso->afficher(&painter);
    //painter.drawPixmap(500,100,QPixmap(":/images/images/Character4.png"));
    cai->afficher(&painter);
    cm->afficher(&painter);
    cv->afficher(&painter);
    cn->afficher(&painter);
*/
    painter.setPen( QPen(Qt::black, 1) );painter.setFont(QFont("Arial",200));painter.drawText(500,500,QString(QString::number(n->getNbMove())));
    n->afficher(&painter);
}
/*
void MainWindow::mousePressEvent(QMouseEvent *e) {
    if(e->button() == Qt::LeftButton)
    {
        perso->deplacer(e->x(),e->y());
        this->repaint();
    }
}*/

void MainWindow::keyPressEvent ( QKeyEvent * event ) {
    int px = n->getPerso()->getX();
    int py = n->getPerso()->getY();
    int vx = 0;
    int vy = 0;
    int vvx = 0;
    int vvy = 0;
    int k = -1;
    int l = -1;
    switch(event->key()){
        case Qt::Key_Z :
        // coordonnees voisins
            vx = (n->getGrille()->getCase(px, py))->getVoisineX('b');
            vy = (n->getGrille()->getCase(px, py))->getVoisineY('b');
            // si la case voisine est libre
            if (n->getGrille()->getCase(vx, vy)->getLibre()==true) {
                // on prend la numero de la caisse si c'est une caisse
                l = n->isCaisse(vx,vy);
                // c'est une caisse
                if (n->isCaisse(vx,vy)!=(-1)) {
                    // on prend les coordonnees de la case voisine de la case voisine
                    vvx = (n->getGrille()->getCase(vx, vy))->getVoisineX('b');
                    vvy = (n->getGrille()->getCase(vx, vy))->getVoisineY('b');
                    // on regarde si elle est libre
                    if ((n->getGrille()->getCase(vvx, vvy)->getLibre()==true)) {
                        // on prend a nouveau le numero de la caisse
                            k = (n->isCaisse(vvx,vvy));
                            // la case n'est pas une caisse
                            if (k == (-1)) {
                                // on enregistre etat precedent
                                *n2 = *n;
                                // on deplace le perso et la caisse
                                n->getPerso()->deplacer('b');
                                n->incrNbMove();
                                n->getCaisses(l)->deplacer('b');
                                // si la case est une case marquee
                                if (n->getGrille()->getCase(vvx, vvy)->getMarquee()) {
                                    // on colorie la caisse
                                    n->getCaisses(l)->setColoree(true);
                                    // on verifie si on a gagne ou non
                                    if (n->testerSiGagner()) {
                                        // on a gagne...
                                        this->gagner();/*
                                        numNiveau++;
                                        n->importerGrille(":/niveaux/niveau" + QString::number(numNiveau));*/
                                    }
                                }
                                // la case suivante n'est pas coloree, on regarde si la caisse l'est
                                else if (n->getCaisses(l)->getColoree()) {
                                    // elle l'est, donc on la decolorie
                                    n->getCaisses(l)->setColoree(false);
                                }
                            }
                    }
                }
                // la case voisin n'est pas une caisse
                else {
                    // on enregistre etat precedent
                    *n2 = *n;
                    // on peut se déplacer
                    n->getPerso()->deplacer('b');
                    n->incrNbMove();
                    }
            }
            break;
        case Qt::Key_Q :
            vx = (n->getGrille()->getCase(px, py))->getVoisineX('g');
            vy = (n->getGrille()->getCase(px, py))->getVoisineY('g');
            if (n->getGrille()->getCase(vx, vy)->getLibre()==true) {
                l = n->isCaisse(vx,vy);
                if (n->isCaisse(vx,vy)!=(-1)) {
                    vvx = (n->getGrille()->getCase(vx, vy))->getVoisineX('g');
                    vvy = (n->getGrille()->getCase(vx, vy))->getVoisineY('g');
                    if ((n->getGrille()->getCase(vvx, vvy)->getLibre()==true)) {
                            k = (n->isCaisse(vvx,vvy));
                            if (k == (-1)) {
                                // on enregistre etat precedent
                                *n2 = *n;
                                n->getPerso()->deplacer('g');
                                n->incrNbMove();
                                n->getCaisses(l)->deplacer('g');
                                if (n->getGrille()->getCase(vvx, vvy)->getMarquee()) {
                                    n->getCaisses(l)->setColoree(true);
                                    if (n->testerSiGagner()) {
                                        this->gagner();/*
                                        numNiveau++;
                                        n->importerGrille(":/niveaux/niveau" + QString::number(numNiveau));*/
                                    }
                                }
                                else if (n->getCaisses(l)->getColoree()) {
                                    n->getCaisses(l)->setColoree(false);
                                }
                            }
                    }
                }
                else {
                    // on enregistre etat precedent
                    *n2 = *n;
                    n->getPerso()->deplacer('g');
                    n->incrNbMove();
                }
            }
            break;
        case Qt::Key_S :
            vx = (n->getGrille()->getCase(px, py))->getVoisineX('h');
            vy = (n->getGrille()->getCase(px, py))->getVoisineY('h');
            if (n->getGrille()->getCase(vx, vy)->getLibre()==true) {
                l = n->isCaisse(vx,vy);
                if (n->isCaisse(vx,vy)!=(-1)) {
                    vvx = (n->getGrille()->getCase(vx, vy))->getVoisineX('h');
                    vvy = (n->getGrille()->getCase(vx, vy))->getVoisineY('h');
                    if ((n->getGrille()->getCase(vvx, vvy)->getLibre()==true)) {
                            k = (n->isCaisse(vvx,vvy));
                            if (k == (-1)) {
                                // on enregistre etat precedent
                                *n2 = *n;
                                n->getPerso()->deplacer('h');
                                n->incrNbMove();
                                n->getCaisses(l)->deplacer('h');
                                if (n->getGrille()->getCase(vvx, vvy)->getMarquee()) {
                                    n->getCaisses(l)->setColoree(true);
                                    if (n->testerSiGagner()) {
                                        this->gagner();/*
                                        numNiveau++;
                                        n->importerGrille(":/niveaux/niveau" + QString::number(numNiveau));*/
                                    }
                                }
                                else if (n->getCaisses(l)->getColoree()) {
                                    n->getCaisses(l)->setColoree(false);
                                }
                            }
                    }
                }
                else {
                    // on enregistre etat precedent
                    *n2 = *n;
                    n->getPerso()->deplacer('h');
                    n->incrNbMove();
                }
            }
            break;
        case Qt::Key_D :
            vx = (n->getGrille()->getCase(px, py))->getVoisineX('d');
            vy = (n->getGrille()->getCase(px, py))->getVoisineY('d');
            if (n->getGrille()->getCase(vx, vy)->getLibre()==true) {
                l = n->isCaisse(vx,vy);
                if (n->isCaisse(vx,vy)!=(-1)) {
                    vvx = (n->getGrille()->getCase(vx, vy))->getVoisineX('d');
                    vvy = (n->getGrille()->getCase(vx, vy))->getVoisineY('d');
                    if ((n->getGrille()->getCase(vvx, vvy)->getLibre()==true)) {
                            k = (n->isCaisse(vvx,vvy));
                            if (k == (-1)) {
                                // on enregistre etat precedent
                                *n2 = *n;
                                n->getPerso()->deplacer('d');
                                n->incrNbMove();
                                n->getCaisses(l)->deplacer('d');
                                if (n->getGrille()->getCase(vvx, vvy)->getMarquee()) {
                                    n->getCaisses(l)->setColoree(true);
                                    if (n->testerSiGagner()) {
                                        this->gagner();/*
                                        numNiveau++;
                                        n->importerGrille(":/niveaux/niveau" + QString::number(numNiveau));*/
                                    }
                                }
                                else if (n->getCaisses(l)->getColoree()) {
                                    n->getCaisses(l)->setColoree(false);
                                }
                            }
                    }
                }
                else {
                    // on enregistre etat precedent
                    *n2 = *n;
                    n->getPerso()->deplacer('d');
                    n->incrNbMove();
                }
            }
        /*case Qt::Key_Up :
            vx = (n->getGrille()->getCase(px, py))->getVoisineX('b');
            vy = (n->getGrille()->getCase(px, py))->getVoisineY('b');
            if (n->getGrille()->getCase(vx, vy)->getLibre()==true) {
                n->getPerso()->deplacer('b');
                }
            break;
        case Qt::Key_Left :
            vx = (n->getGrille()->getCase(px, py))->getVoisineX('g');
            vy = (n->getGrille()->getCase(px, py))->getVoisineY('g');
            if (n->getGrille()->getCase(vx, vy)->getLibre()==true) {
                n->getPerso()->deplacer('g');
            }
            break;
        case Qt::Key_Down :
            vx = (n->getGrille()->getCase(px, py))->getVoisineX('h');
            vy = (n->getGrille()->getCase(px, py))->getVoisineY('h');
            if (n->getGrille()->getCase(vx, vy)->getLibre()==true) {
                n->getPerso()->deplacer('h');
            }
            break;
        case Qt::Key_Right :vx = (n->getGrille()->getCase(px, py))->getVoisineX('d');
            vy = (n->getGrille()->getCase(px, py))->getVoisineY('d');
            if (n->getGrille()->getCase(vx, vy)->getLibre()==true) {
                n->getPerso()->deplacer('d');
            }*/
        }
    this->repaint();
}

void MainWindow::gagner() {
    numNiveau++;
    n->importerGrille(":/niveaux/niveau" + QString::number(numNiveau));
    n->resetNbMove();
}

void MainWindow::on_bRestart_clicked()
{
    n->importerGrille(":/niveaux/niveau" + QString::number(numNiveau));
    n->resetNbMove();
    this->repaint();
}

void MainWindow::on_bUndo_clicked()
{
    *n = *n2;
    this->repaint();
}
