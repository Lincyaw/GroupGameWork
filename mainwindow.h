#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "hero.h"
#include <QTimer>
#include "obstacle.h"
#include "anemy.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    hero *player;
    anemy *monster;
    obstacle *land;
    obstacle *brick;
    obstacle *coin;
    obstacle *box;

    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    QTimer *JumpTimer = new QTimer(this);
    QTimer *FallTimer = new QTimer(this);
    void keyPressEvent(QKeyEvent *);
    const static int GroundY = 540;
    int WidgetWidth = 1500;
    int WidgetHeight = 800;


private:
    Ui::MainWindow *ui;

signals:

public slots:

};

#endif // MAINWINDOW_H
