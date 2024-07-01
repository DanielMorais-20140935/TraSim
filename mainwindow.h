#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void startGame();
    void stopGame();

private slots:

    void on_comecar_clicked();

    void on_parar_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Scene *s;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
