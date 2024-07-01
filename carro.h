#ifndef CARRO_H
#define CARRO_H

#include <QObject>
#include <QGraphicsPixMapItem>
#include <QPropertyAnimation>

class Carro : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal y READ y WRITE setY)
    Q_PROPERTY(qreal x READ x WRITE setX)

public:

    explicit Carro(QPixmap pixmap, qreal xi, qreal xf , qreal yi, qreal yf);
    qreal y() const;
    qreal x() const;
    void setY(qreal newY);
    void setX(qreal newX);
    ~Carro();


signals:

private:
    qreal m_x;
    qreal m_y;
    int yPos, xPos;
    QPropertyAnimation *xanimation;
    QPropertyAnimation *yanimation;
    void animarX(int xi, int xf);
    void animarY(int yi, int yf);


};

#endif // CARRO_H
