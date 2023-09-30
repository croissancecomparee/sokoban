QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    caisse.cpp \
    case.cpp \
    case_mur.cpp \
    case_neant.cpp \
    case_vide.cpp \
    coordonnee.cpp \
    grille.cpp \
    immobile.cpp \
    main.cpp \
    mainwindow.cpp \
    mobile.cpp \
    niveau.cpp \
    personnage.cpp

HEADERS += \
    caisse.h \
    case.h \
    case_mur.h \
    case_neant.h \
    case_vide.h \
    coordonnee.h \
    grille.h \
    immobile.h \
    mainwindow.h \
    mobile.h \
    niveau.h \
    personnage.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc

DISTFILES += \
    PNG/Character4.png \
    PNG/PNG/WallRound_Gray.png
