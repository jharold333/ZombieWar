#ifndef BLOQUE_H
#define BLOQUE_H


#include <QGraphicsItem> //metodo virtual
#include <QPainter>
#include <QPixmap> //generar imagen
enum misBloques{ caja=0, muro=1 , mesa=2};
class Bloque : public QGraphicsItem
{
private:
    float bpx;
    float bpy;
    int tipo;
    float lx;
    float ly;
    float vx;
public:
    Bloque();
    ~Bloque();
    Bloque(float px, float py, int tipo, float lx, float ly, float vx);

    virtual QRectF boundingRect() const;//metodo virtual
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);//metodo virtual
    void moverse(void);

    float getBpx() const;
    float getBpy() const;
    int getTipo() const;
    float getLx() const;
    float getLy() const;

    void setBpx(float newBpx);
    void setBpy(float newBpy);
    void setTipo(int newTipo);
    void setLx(float newLx);
    void setLy(float newLy);

    float getVx() const;
    void setVx(float newVx);
};

#endif // BLOQUE_H
