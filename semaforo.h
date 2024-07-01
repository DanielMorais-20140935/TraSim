#ifndef SEMAFORO_H
#define SEMAFORO_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Semaforo :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Semaforo(QPixmap pixmap , bool estado);
    bool getEstado() const;
    void setEstado(bool newEstado);

private:
    bool estado;

signals:


};

#endif // SEMAFORO_H
