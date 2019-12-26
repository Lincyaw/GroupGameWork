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
#include "javacup.h"
#include<QGraphicsTextItem>
#include<QFont>
#include<QTime>
#define SCREENWIDTH 1500
#define SCREENHEIGHT 1080
#define CLOUDNUM 3
#define GROUNDNUM 6
#define CupNum 10
#define BRICKNUM 45
#define COINNUM 8
#define MBRICKNUM 15

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
    int k=0;
    int count = 0;
    QGraphicsScene *pScene = new QGraphicsScene();
    QGraphicsView *pView = new QGraphicsView();
    player *item;
    obstacle *cloud[CLOUDNUM];
    obstacle *ground[GROUNDNUM];
    obstacle *brick[BRICKNUM];
    obstacle *coin[COINNUM];
    obstacle *book;
    obstacle *h;
    obstacle *mbrick[3];
    obstacle *homework;
    QGraphicsTextItem *text = new QGraphicsTextItem;
    void firstLevelIni();
    void newOb(obstacle *one, int type, int x, int y, int w, int h, int data);
    void nBrick(int begin, int end, int x, int y);
    void nCoin(int begin, int end, int x, int y);
    QList<int> generateUniqueRandomNumber();
 //  QSound *BGM = new QSound(":/m/back/BGM.wav");
    QMediaPlayer *myPlayer= new QMediaPlayer;
    //怪物
    javacup * Cups[CupNum];
private slots:
    void on_begin_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
