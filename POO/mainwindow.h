#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>
#include "personnage.h"
#include "caisse.h"
#include "grille.h"
#include "case_mur.h"
#include "case_vide.h"
#include "case_neant.h"
#include "niveau.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void setNiveau(Niveau &m_n);

private slots:

    void on_bRestart_clicked();
    void on_bUndo_clicked();



private:
    Ui::MainWindow *ui;
    Personnage *perso;
    Caisse *cai;
    Case_mur *cm;
    Case_Vide *cv;
    Case_neant *cn;
    Niveau *n;
    Niveau *n2;
    int numNiveau = 7;
    void paintEvent(QPaintEvent* e);
    void keyPressEvent (QKeyEvent * event);
    void gagner();
};
#endif // MAINWINDOW_H
