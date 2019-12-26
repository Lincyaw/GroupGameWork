#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"player.h"
#include"obstacle.h"
#include <QMainWindow>
#include "hello.h"
#include<QPushButton>
#include<QMessageBox>
#include<QFileDialog>
#include<QSound>//多媒体模块下的音效头文件
#include <QFileInfo>
#include<QMediaPlayer>
#include<QAction>
#include<QLabel>
#include<QGraphicsItemGroup>
#define SCREENWIDTH 1500
#define SCREENHEIGHT 1080
#define GROUNDNUM 8
#define BRICKNUM 27
#define COINNUM 7
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);


    void shootBullet(int p,int q);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    int clickedTimes=0;
    QGraphicsScene *pScene = new QGraphicsScene();
    QGraphicsView *pView = new QGraphicsView();
    player *item;
    obstacle *cloud[3];
    obstacle *ground[GROUNDNUM];
    obstacle *brick[BRICKNUM];
    obstacle *coin[COINNUM];
    obstacle *book;
    obstacle *h;
    void firstLevelIni();
    void newOb(obstacle *one, int type, int x, int y, int w, int h, int data);
    void deleteOb();
    void nBrick(int begin, int end, int x, int y);
 //  QSound *BGM = new QSound(":/m/back/BGM.wav");
QMediaPlayer *myPlayer= new QMediaPlayer;

private slots:
    void on_begin_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
