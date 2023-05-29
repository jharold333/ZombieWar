#ifndef TABLERO_H
#define TABLERO_H

#include "bloque.h"
#include "personaje.h"
#include "zombie.h"
#include "score.h"
//librerias
#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QList>
#include <cstdlib>

QT_BEGIN_NAMESPACE
namespace Ui { class Tablero; }
QT_END_NAMESPACE

class Tablero : public QMainWindow
{
    Q_OBJECT

public:
    Tablero(QWidget *parent = nullptr);
    ~Tablero();
    void keyPressEvent(QKeyEvent *event);

public slots:
    void onStart(void);
    void onUpdate(void);
    void generarBloques(void);
    void velocidadBloque(void);
    void reiniciarPartida(void);

private:
    Ui::Tablero *ui;
    QGraphicsScene *scene;//atributo tipo escena

    QList <Bloque *> Bloques;
    QTimer *tiempo;
    QTimer *gen;
    QTimer *AumentarVxBloque;
    personaje *pj;
    zombie *zom;
    QList<QGraphicsItem* >Colisiones;
    QList<QGraphicsItem* >ColZom;
    Bloque *bloPj;
    Bloque *bloZom;
    zombie *morder;
    Score *score;
    float vxBloque;
};
#endif // TABLERO_H
