#include "bloque.h"

float Bloque::getBpx() const
{
    return bpx;
}

void Bloque::setBpx(float newBpx)
{
    bpx = newBpx;
}

float Bloque::getBpy() const
{
    return bpy;
}

void Bloque::setBpy(float newBpy)
{
    bpy = newBpy;
}

int Bloque::getTipo() const
{
    return tipo;
}

void Bloque::setTipo(int newTipo)
{
    tipo = newTipo;
}

float Bloque::getLx() const
{
    return lx;
}

void Bloque::setLx(float newLx)
{
    lx = newLx;
}

float Bloque::getLy() const
{
    return ly;
}

void Bloque::setLy(float newLy)
{
    ly = newLy;
}

float Bloque::getVx() const
{
    return vx;
}

void Bloque::setVx(float newVx)
{
    vx = newVx;
}

Bloque::Bloque()
{

}
Bloque::~Bloque()
{

}

Bloque::Bloque(float px, float py, int tipo, float lx, float ly, float vx) : bpx(px), bpy(py), tipo(tipo), lx(lx), ly(ly), vx(vx)
{
    setPos(bpx,bpy);
}
QRectF Bloque::boundingRect() const
{
    return QRectF(0,0,lx,ly);
}

void Bloque::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(tipo==0){
        QPixmap pixman(":/zximage/obstaculo1.png");
        painter->drawPixmap(0,0,lx,ly,pixman);
    }else if(tipo==1){
        QPixmap pixman(":/zximage/obstaculo2.png");
        painter->drawPixmap(0,0,lx,ly,pixman);
    }else if(tipo==2){
        QPixmap pixman(":/zximage/obstaculo3.png");
        painter->drawPixmap(0,0,lx,ly,pixman);
    }else if(tipo==3){
        QPixmap pixman(":/zximage/obstaculo4.png");
        painter->drawPixmap(0,0,lx,ly,pixman);
    }
}

void Bloque::moverse()
{
    bpx+=-1*vx*0.1;
    setPos(bpx,bpy);
}

