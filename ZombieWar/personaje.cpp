#include "personaje.h"

personaje::personaje(QObject *parent)
    : QObject{parent}
{
    Qsprite = new QTimer();
    connect(Qsprite,&QTimer::timeout,this,&personaje::Actualizacion);
    Qsalto = new QTimer();
    connect(Qsalto,&QTimer::timeout,this,&personaje::saltar);
    Qcaida = new QTimer();
    connect(Qcaida,&QTimer::timeout,this,&personaje::caida);

    filas =0;
    columnas = 0;
    ancho=65;
    alto =100;
    pixmap = new QPixmap(":/zximage/policia.png");
    Qsprite->start(100);

    px=130;
    py=510;
    setPos(px,py);
    vx=0;
    vy=0;
    accion = 'R';
    pxs=px;
    pys=py;
    ts=0;
    tc=0;
}

QRectF personaje::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,filas,ancho,alto);
}

void personaje::Actualizacion()
{
    if(accion=='0'){
        filas=0;
    }else if(accion=='1'){
        filas=100;
    }else if(accion=='D'){
        filas=200;
    }else if(accion=='A'){
        filas=300;
    }else if(accion=='W'){
        if(vx>0){
            filas=400;
        }else{
            filas=500;
        }
    }else if(accion=='S'){
        if(vx==20){
            filas=600;
        }else{
            filas=700;
        }
    }else if(accion=='M'){
        filas=800;
    }
    columnas+=70;
    if(columnas >=420){
        columnas=0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

void personaje::derecha()
{
    px = px + vx*0.1;
    setPos(px,py);
}

void personaje::izquierda()
{
    if(px>30){
        px = px + vx*0.1;
        setPos(px,py);
    }else{
        setPos(px,py);
    }
}
void personaje::iniciarSalto()
{
    if(accion=='0' || accion=='1'){
        ts=0;
    }else{
        ts=-9.2;
    }
    tc=0;
    Qsalto->start(25);
}

void personaje::iniciarCaida()
{
    tc=0;
    Qcaida->start(25);
}


void personaje::saltar()
{
    if(accion!='0' && accion!='1'){
        accion='W';
        if(vx>0){
            vx=20*cos(30*(pi/180));
            vy=20*sin(30*(pi/180));
        }else if(vx<0){
            vx=-20*cos(30*(pi/180));
            vy=20*sin(30*(pi/180));
        }

        px=-1*(vx*(-9.2))+vx*ts+pxs;
        py=-1*(vy*(-9.2)-((G*((-9.2)*(-9.2)))*0.5))-((vy*ts-((G*(ts*ts))*0.5))+pys);
        setPos(px,py);
        ts+=0.1;

        if(py<=400){
            accion='C';
            Qsalto->stop();
            vy=0;
            if (vx>0){
                vx=20;
            }else{
                vx=-20;
            }
            Qcaida->start(25);
        }
    }else{
        py=py-(0.5*G*(ts*ts));
        setPos(px,py);
        ts+=0.1;
        if(py<=400){
            accion='C';
            Qsalto->stop();
            vy=0;
            vx=0;
            Qcaida->start(25);
        }
    }
}

void personaje::caida()
{
    px = px + vx*0.3;
    py=py+(0.5*G*(tc*tc));
    setPos(px,py);
    if(py>=510){
        Qcaida->stop();
        if(vx>0){
            accion='D';
        }else if(vx<0){
            accion='A';
        }else{
            accion='0';
        }
    }else{
        tc+=0.1;
    }
}

void personaje::colisionado()
{
    px+=vx*1.5;
    setPos(px,py);
}

void personaje::sobreObjeto()
{
    Qsalto->stop();
}

float personaje::getVx() const
{
    return vx;
}

void personaje::setVx(float newVx)
{
    vx = newVx;
}

float personaje::getVy() const
{
    return vy;
}

void personaje::setVy(float newVy)
{
    vy = newVy;
}

float personaje::getPx() const
{
    return px;
}

void personaje::setPx(float newPx)
{
    px = newPx;
}

float personaje::getPy() const
{
    return py;
}

void personaje::setPy(float newPy)
{
    py = newPy;
}

char personaje::getAccion() const
{
    return accion;
}

void personaje::setAccion(char newAccion)
{
    accion = newAccion;
}

float personaje::getPxs() const
{
    return pxs;
}

void personaje::setPxs(float newPxs)
{
    pxs = newPxs;
}

float personaje::getPys() const
{
    return pys;
}

void personaje::setPys(float newPys)
{
    pys = newPys;
}

float personaje::getTs() const
{
    return ts;
}

void personaje::setTs(float newTs)
{
    ts = newTs;
}
