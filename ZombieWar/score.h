#ifndef SCORE_H
#define SCORE_H


#include <QGraphicsTextItem>
#include <QFont>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem *parent=0);
    void increase();
    int getscore();
    float getPx() const;
    void setPx(float newPx);

    float getPy() const;
    void setPy(float newPy);

    const QString &getTexto() const;
    void setTexto(const QString &newTexto);

    void setScore(int newScore);

private:
    int score;
    float px;
    float py;
};

#endif // SCORE_H
