#include "carro.h"
#include<QGraphicsScene>

Carro::Carro(QPixmap pixmap, qreal xi, qreal xf , qreal yi, qreal yf)
    :QGraphicsPixmapItem{pixmap}

{

    xanimation=new QPropertyAnimation(this,"x",this);
    yanimation=new QPropertyAnimation(this,"y",this);

    setPos(xi,yi);
    yPos=yf;
    xPos=xf;

    if(yi==yf)
        animarX(xi,xf);
    else
        animarY(yi,yf);


}



void Carro:: animarX(int xi, int xf){
    xanimation->setStartValue(xi);
    xanimation->setEndValue(xf);
    xanimation->setDuration(2000);
    xanimation->setEasingCurve(QEasingCurve::Linear);


    connect(xanimation, &QPropertyAnimation::finished, [=](){
        qDebug() << "Animation Finished";
        scene()->removeItem(this);
        delete this;
    });

    xanimation->start();

}

void Carro:: animarY(int yi, int yf){
    yanimation->setStartValue(yi);
    yanimation->setEndValue(yf);
    yanimation->setDuration(2000);
    yanimation->setEasingCurve(QEasingCurve::Linear);


    connect(yanimation, &QPropertyAnimation::finished, [=](){
        qDebug() << "Animation Finished";
        scene()->removeItem(this);
        delete this;
    });

    yanimation->start();
}

qreal Carro::y() const
{
    return m_y;

}

qreal Carro::x() const
{
    return m_x;
}

void Carro::setY(qreal newY)
{
    m_y=newY;
    setPos(QPoint(0,0)+ QPoint(xPos,newY));

}

void Carro::setX(qreal newX)
{
    m_x=newX;
    setPos(QPoint(0,0) + QPoint(newX,yPos));
}


Carro::~Carro()
{

}
