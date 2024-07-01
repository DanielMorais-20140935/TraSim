#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include<QTimer>
#include "semaforo.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    void start();
    void stop();
private:
    QTimer * carLhTimer;
    QTimer * carRhTimer;
    QTimer * carTvTimer;
    QTimer * carBvTimer;
    QTimer *timerVertical;
    QTimer *timerHorizonTal;
    bool semaforo;
    Semaforo *s1, *s2, *s3, *s4;

    void setUpCarLhTimer();
    void setUpCarRhTimer();
    void setUpCarTvTimer();
    void setUpCarBvTimer();
    void setTimerVertical();
    void setTimerHorizontal();

signals:

};

#endif // SCENE_H
