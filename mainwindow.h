#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"player.h"
#include"obstacle.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);

    QGraphicsScene *pScene = new QGraphicsScene();
    QGraphicsView *pView = new QGraphicsView();
    void shootBullet();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
