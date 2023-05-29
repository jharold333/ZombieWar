#include "zombie.h"

zombie::zombie(QObject *parent)
    : personaje{parent}
{
    Qsprite = new QTimer();
    connect(Qsprite,&QTimer::timeout,this,&zombie::Actualizacion);

    filas =0;
    columnas = 0;
    ancho=70;
    alto =110;
    pixmap = new QPixmap(":/zximage/zombie.png");
    Qsprite->start(150);

    px=30;
    py=520;
    setPos(px,py);
    vx=15;
    vy=0;
    accion = 'R';
}

void zombie::seguir(float jx, char ac)
{
    if(ac!='W' && ac!='C'){
        if(px<jx+70){
            vx=15;
            accion = '0';
            px = px + vx*0.06;
            setPos(px,py);
        }else if(px>jx-70){
            vx=-15;
            accion = '1';
            px = px + vx*0.06;
            setPos(px,py);
        }
    }else{
        px = px + vx*0.06;
        setPos(px,py);
    }

}
