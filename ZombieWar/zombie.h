#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QObject>
#include "personaje.h"


class zombie : public personaje
{
    Q_OBJECT
public:
    explicit zombie(QObject *parent = nullptr);
    void seguir(float jx, char accion);

};

#endif // ZOMBIE_H
