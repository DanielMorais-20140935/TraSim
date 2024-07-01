#include "semaforo.h"
#include <QGraphicsScene>

Semaforo::Semaforo(QPixmap pixmap, bool estado)
:QGraphicsPixmapItem{pixmap}

{

    setEstado(estado);

}


bool Semaforo::getEstado() const
{
    return estado;
}

void Semaforo::setEstado(bool newEstado)
{
    estado = newEstado;
    if(estado==0){
        setPixmap(QPixmap(":/imagens/semaforoRed.png"));
    }else{
        setPixmap(QPixmap(":/imagens/semaforoGreen.png"));
    }
}
