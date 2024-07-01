#include "scene.h"
#include "carro.h"
# include <QRandomGenerator>
#include "semaforo.h"
#include <QGraphicsScene>



Scene::Scene(QObject *parent)
    : QGraphicsScene{parent}
{
    timerHorizonTal=new QTimer(this);
    timerVertical = new QTimer(this);

    setUpCarLhTimer();
    setUpCarRhTimer();
    setUpCarTvTimer();
    setUpCarBvTimer();

    setTimerVertical();
     s1=new Semaforo(QPixmap(":/imagens/semaforoRed.png"),0);
     s2=new Semaforo(QPixmap(":/imagens/semaforoRed.png"),0);
     s3=new Semaforo(QPixmap(":/imagens/semaforoRed.png"),0);
     s4=new Semaforo(QPixmap(":/imagens/semaforoRed.png"),0);


    s1->setPos(950 / 2 + 200, 800 / 2 - 200);
    s1->setZValue(3);
    s1->setScale(0.15);
    addItem(s1);

    s2->setPos(440/2-100, 180/2+100);
    s2->setZValue(3);
    s2->setRotation(90);
    s2->setScale(0.15);
    addItem(s2);

    s3->setPos(580 / 2 - 20, 350 / 2 + 20);
    s3->setZValue(3);
    s3->setScale(0.15);
    addItem(s3);

    s4->setPos(1250/2-100, 180/2+100);
    s4->setZValue(3);
    s4->setRotation(90);
    s4->setScale(0.15);
    addItem(s4);
}


void Scene::start()
{

    timerVertical->start(7000);



}
void Scene::stop(){

    carLhTimer->stop();
    carRhTimer->stop();
    carTvTimer->stop();
    carBvTimer->stop();
    timerVertical->stop();
    s1->setEstado(0);
    s2->setEstado(0);
    s3->setEstado(0);
    s4->setEstado(0);

}

void Scene::setTimerVertical(){

    if(timerHorizonTal->isActive())
        timerHorizonTal->stop();

    Scene::semaforo=1;

    connect(timerVertical,&QTimer::timeout,[=](){
        int randomNumber = QRandomGenerator::global()->bounded(1000, 6000);
        int randomNumber2 = QRandomGenerator::global()->bounded(1000, 6000);

        if(Scene::semaforo){
            s1->setEstado(1);
            s2->setEstado(0);
            s3->setEstado(1);
            s4->setEstado(0);

            carLhTimer->stop();
            carRhTimer->stop();
            carTvTimer->start(randomNumber);
            carBvTimer->start(randomNumber2);
         }else{
            s1->setEstado(0);
            s2->setEstado(1);
            s3->setEstado(0);
            s4->setEstado(1);
            carLhTimer->start(randomNumber);
            carRhTimer->start(randomNumber2);
            carTvTimer->stop();
            carBvTimer->stop();
        }

        Scene::semaforo=!Scene::semaforo;


    });


}


void Scene::setUpCarRhTimer()
{
    carRhTimer=new QTimer(this);


    connect(carRhTimer,&QTimer::timeout,[=](){

        Carro *c4= new Carro(QPixmap(":/imagens/carro4.png"),775,2-245,650/2-245,650/2-245);
        c4->setScale(0.3);
        c4->setRotation(90);
        addItem(c4);

    });



}

void Scene::setUpCarLhTimer()
{
    carLhTimer=new QTimer(this);


    connect(carLhTimer,&QTimer::timeout,[=](){
        Carro *c3= new Carro(QPixmap(":/imagens/carro3.png"),150,775,650/2-295,650/2-295);
        c3->setScale(0.3);
        c3->setRotation(90);
        addItem(c3);

    });


}

void Scene::setUpCarTvTimer()
{
    carTvTimer=new QTimer(this);


    connect(carTvTimer,&QTimer::timeout,[=](){

        Carro *c2 = new Carro(QPixmap(":/imagens/carro2.png"),775/2+260,775/2+260,650/2-130,600);
        c2->setScale(0.3);
        c2->setRotation(180);
        addItem(c2);

        Carro *c2_left = new Carro(QPixmap(":/imagens/carro2.png"),775/2-145,775/2-145,650/2-130,600);
        c2_left->setScale(0.3);
        c2_left->setRotation(180);
        addItem(c2_left);

    });

    //carTvTimer->start(300);

}

void Scene::setUpCarBvTimer()
{
    carBvTimer=new QTimer(this);


    connect(carBvTimer,&QTimer::timeout,[=](){
        Carro *c1 = new Carro(QPixmap(":/imagens/carro.png"), 775/2 + 200, 775/2 + 200, 650/2 + 135, 650/2 - 480);
        c1->setScale(0.11);
        addItem(c1);
\
        // Carro 1 - Movendo-se de baixo para cima na interseção da esquerda
        Carro *c1_left = new Carro(QPixmap(":/imagens/carro.png"), 775/2 - 200, 775/2 - 200, 650/2 + 135, 650/2 - 480);
        c1_left->setScale(0.11);
        addItem(c1_left);
    });

    //carBvTimer->start(1000);

}
