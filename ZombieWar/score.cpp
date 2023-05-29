#include "score.h"


Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    //inicializa el score en 0
           score = 0;
// dibujar texto
           setPlainText(QString("score: ")+ QString::number(score)); //score 0
           setDefaultTextColor(Qt::black);
           setFont(QFont("Castellar",16));
           px=615;
           py=20;
           setPos(px,py);

}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ")+QString::number(score));
}

int Score::getscore(){
    return score;
}

float Score::getPx() const
{
    return px;
}

void Score::setPx(float newPx)
{
    px = newPx;
}

float Score::getPy() const
{
    return py;
}

void Score::setPy(float newPy)
{
    py = newPy;
}

void Score::setScore(int newScore)
{
    score = newScore;
}


