#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem> //metodo virtual
#include <QPainter>
#include <QPixmap> //generar imagen
#include <QDebug>
#include <QTimer>
#include <cmath>

#define dt 0.1
#define G 9.8
#define pi 3.1416

class personaje : public QObject, public QGraphicsItem
{
    Q_OBJECT
protected:
    float px;
    float py;
    float vx;
    float vy;
    int score;
    char accion;
    float pxs;
    float pys;
    float filas;
    float columnas;
    float ancho;
    float alto;
    float ts;
    float tc;
public:

    explicit personaje(QObject *parent = nullptr);
    virtual QRectF boundingRect() const;//metodo virtual
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void derecha();
    void izquierda();
    void iniciarSalto();
    void iniciarCaida();
    void colisionado();
    void sobreObjeto();

    QTimer  *Qsprite;
    QTimer *Qsalto;
    QTimer *Qcaida;
    QPixmap *pixmap;

    float getVx() const;
    float getVy() const;
    float getPx() const;
    float getPy() const;
    char getAccion() const;
    float getPxs() const;
    float getPys() const;

    void setVx(float newVx);
    void setVy(float newVy);
    void setPx(float newPx);
    void setPy(float newPy);
    void setAccion(char newAccion);
    void setPxs(float newPxs);
    void setPys(float newPys);

    float getTs() const;
    void setTs(float newTs);

signals:
public slots:
    void Actualizacion();
    void saltar();
    void caida();
};

#endif // PERSONAJE_H
