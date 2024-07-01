#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    s = new Scene(this);

    // cenário
    QGraphicsPixmapItem *cenarioImg = new QGraphicsPixmapItem(QPixmap(":/imagens/cross.jpg")
                                                                  .scaled(800, 800, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->horizontalSlider->setRange(1, 5);

    s->addItem(cenarioImg);

    // configurar cenário
    ui->graphicsView->setSceneRect(0, 0, 800, 800);  // Adjusted to fit new image
    ui->graphicsView->setScene(s);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(800, 800);  // Adjusted to fit new image

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comecar_clicked()
{
    s->start();
    qDebug()<<"ol";
}

void MainWindow::on_parar_clicked()
{
    s->stop();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    QString numberString = QString::number(value);
    ui->ncars->setText(numberString);
}
