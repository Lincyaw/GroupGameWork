#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"player.h"
#include"obstacle.h"
#include <QMainWindow>
#include "hello.h"
//#include "javacup.h"
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
    void shootBullet(int p,int q);
    ~MainWindow();

private slots:
    void on_begin_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
