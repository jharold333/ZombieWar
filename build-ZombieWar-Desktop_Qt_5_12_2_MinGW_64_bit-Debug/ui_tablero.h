/********************************************************************************
** Form generated from reading UI file 'tablero.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLERO_H
#define UI_TABLERO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tablero
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *bt_Iniciar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Tablero)
    {
        if (Tablero->objectName().isEmpty())
            Tablero->setObjectName(QString::fromUtf8("Tablero"));
        Tablero->resize(1418, 697);
        centralwidget = new QWidget(Tablero);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 20, 1400, 600));
        bt_Iniciar = new QPushButton(centralwidget);
        bt_Iniciar->setObjectName(QString::fromUtf8("bt_Iniciar"));
        bt_Iniciar->setGeometry(QRect(660, 630, 75, 24));
        Tablero->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Tablero);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1418, 22));
        Tablero->setMenuBar(menubar);
        statusbar = new QStatusBar(Tablero);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Tablero->setStatusBar(statusbar);

        retranslateUi(Tablero);

        QMetaObject::connectSlotsByName(Tablero);
    } // setupUi

    void retranslateUi(QMainWindow *Tablero)
    {
        Tablero->setWindowTitle(QApplication::translate("Tablero", "tablero", nullptr));
        bt_Iniciar->setText(QApplication::translate("Tablero", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tablero: public Ui_Tablero {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLERO_H
