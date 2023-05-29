#include "tablero.h"
#include "ui_tablero.h"

Tablero::Tablero(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tablero)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1400,600);
    scene->setBackgroundBrush(QBrush(QImage(":/zximage/fondo.png")));
    ui->graphicsView->setScene(scene);

    pj=nullptr;
    connect(ui->bt_Iniciar, &QPushButton::clicked, this, &Tablero::onStart);


}

Tablero::~Tablero()
{
    delete ui;
}

void Tablero::onStart(void)
{
    scene->clear();
    tiempo = new QTimer();
    tiempo->start(15);
    connect(tiempo, &QTimer::timeout, this, &Tablero::onUpdate);

    gen = new QTimer();
    gen->start(2000);
    connect(gen, &QTimer::timeout, this, &Tablero::generarBloques);

    pj= new personaje();
    scene->addItem(pj);

    zom = new zombie();
    scene->addItem(zom);

    bloPj=nullptr;
    bloZom=nullptr;

    vxBloque=20;
    AumentarVxBloque = new QTimer();
    AumentarVxBloque->start(20000);
    connect(AumentarVxBloque, &QTimer::timeout, this, &Tablero::velocidadBloque);

    score = new Score();
    scene->addItem(score);
}
void Tablero::onUpdate(void)
{
    if(pj->getPx()>1400){
        for(auto it:Bloques){
            scene->removeItem(it);
        }
        Bloques.clear();
        pj->setPx(130);
        pj->setPy(510);
        zom->setPx(30);
        zom->setPy(520);
    }
    Colisiones = scene->collidingItems(pj);
    if(pj->getAccion()=='M'){
        reiniciarPartida();
    }
    if(pj->getAccion()=='D' || pj->getAccion()=='A' || pj->getAccion()!='W' || pj->getAccion()!='C'){
        score->increase();
        if(pj->getAccion()=='D'){
            if(!Colisiones.isEmpty()){
                for(auto c:Colisiones){
                    bloPj=dynamic_cast<Bloque *>(c);
                    morder=dynamic_cast<zombie *>(c);
                    if(bloPj){
                        if(bloPj->getTipo()==caja || bloPj->getTipo()==muro || bloPj->getTipo()==mesa){
                            pj->setVx(-20);
                            pj->setAccion('A');
                            pj->colisionado();
                        }
                    }else{
                        pj->setVx(20);
                        pj->setAccion('D');
                        pj->derecha();
                    }if(morder){
                        pj->setAccion('M');
                    }
                }
            }else{
                pj->setVx(20);
                pj->setAccion('D');
                pj->derecha();
            }
        }else if(pj->getAccion()=='A'){
            if(!Colisiones.isEmpty()){
                for(auto c:Colisiones){
                    bloPj = dynamic_cast<Bloque *>(c);
                    morder=dynamic_cast<zombie *>(c);
                    if(bloPj){
                        if(bloPj->getTipo()==caja || bloPj->getTipo()==muro || bloPj->getTipo()==mesa){
                            pj->setVx(20);
                            pj->setAccion('D');
                            pj->colisionado();
                        }
                    }else{
                        pj->setVx(-20);
                        pj->setAccion('A');
                        pj->izquierda();
                    }if(morder){
                        pj->setAccion('M');
                    }
                }
            }else{
                pj->setVx(-20);
                pj->setAccion('A');
                pj->izquierda();
            }
        }else if(pj->getAccion()=='W' ||  pj->getAccion()=='C'){              //pasar por encima de objetos
            /*if(!Colisiones.isEmpty()){
                for(auto c:Colisiones){
                    morder = dynamic_cast<Perro *>(c);
                    if(morder){
                        pj->setAccion('M');
                    }
                }
            }*/
             /*if(!Colisiones.isEmpty()){
                for(auto c:Colisiones){
                    bloPj = dynamic_cast<Bloque *>(c);
                    if(bloPj){
                        if(bloPj->getTipo()==caja || bloPj->getTipo()==muro || bloPj->getTipo()==mesa){
                            if(pj->getPy()+110>=bloPj->getBpy()){
                                pj->setPy(pj->getPy()-10);
                                qDebug()<<"jaja";
                                pj->sobreObjeto();
                                pj->setVy(0);
                                if(pj->getAccion()!='E'){
                                    pj->setAccion('E');
                                }
                                if(pj->getVx()>0){
                                    pj->setAccion('D');
                                }else{
                                    pj->setAccion('A');
                                }
                            }else{
                                if(pj->getVx()>0){
                                    pj->setVx(-20);
                                    pj->setAccion('A');
                                    pj->izquierda();
                                }else{
                                    pj->setVx(20);
                                    pj->setAccion('D');
                                    pj->derecha();
                                }
                            }
                        }
                    }
                }
            }
        }else if(pj->getAccion()=='E'){
            pj->iniciarCaida();*/
        }
    }

    zom->seguir(pj->getPx(), pj->getAccion());
    ColZom = scene->collidingItems(zom);
    if(!ColZom.isEmpty()){
        for(auto c:ColZom){
            bloZom = dynamic_cast<Bloque *>(c);
            if(bloZom){
                if(bloZom->getTipo()==caja || bloZom->getTipo()==muro){
                    zom->setAccion('D');
                    scene->removeItem(bloZom);
                }
            }
        }
    }else{
        if(zom->getVx()>0){
            zom->setAccion('0');
        }else{
            zom->setAccion('1');
        }
    }

    for(auto it:Bloques){
        if(it->getBpx()>-30){
            it->moverse();
        }else{
            if (it->getTipo()==mesa){
                scene->removeItem(it);
            }
            Bloques.pop_front();
        }
    }
}

void Tablero::keyPressEvent(QKeyEvent *event)
{
        if(event->key()==Qt::Key_A && pj->getAccion()!='W'){
            pj->setAccion('A');
        }else if(event->key()==Qt::Key_D && pj->getAccion()!='W' && pj->getAccion()!='C'){
            pj->setAccion('D');
        }else if(event->key()==Qt::Key_W && pj->getAccion()!='W' && pj->getAccion()!='C'){
            pj->setPxs(pj->getPx());
            pj->setPys(pj->getPy());
            pj->iniciarSalto();
        }else if(event->key()==Qt::Key_Shift){
            if(pj->getAccion()=='D'){
                pj->setAccion('0');
            }else{
                pj->setAccion('1');
            }
            pj->setVx(0);

        }else if(event->key()==Qt::Key_S){
            pj->setAccion('S');
        }
}

void Tablero::generarBloques(void)
{
    int nran=rand()%4;
    if(nran==0){
        Bloques.push_back(new Bloque(1600,530,caja,40,50,vxBloque));
        scene->addItem(Bloques.back());
    }else if(nran==1){
        Bloques.push_back(new Bloque(1600,490,muro,40,90,vxBloque));
        scene->addItem(Bloques.back());
    }else if(nran==2){
        Bloques.push_back(new Bloque(1600,480,mesa,80,90,vxBloque));
        scene->addItem(Bloques.back());
    }
}

void Tablero::velocidadBloque()
{
    vxBloque+=0.2;
}

void Tablero::reiniciarPartida()
{
    for(auto it:Bloques){
        scene->removeItem(it);
    }
    Bloques.clear();
    score->setScore(0);
    pj->setPx(130);
    pj->setPy(510);
    zom->setPx(30);
    zom->setPy(520);
    pj->setAccion('D');
}


