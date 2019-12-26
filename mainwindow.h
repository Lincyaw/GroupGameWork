#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"player.h"
#include"obstacle.h"
#include <QMainWindow>
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
#include<QPushButton>
#include"mypushbutton.h"
#define SCREENWIDTH 1500
#define SCREENHEIGHT 1080
#define CLOUDNUM 3
#define GROUNDNUM 6
#define CupNum 10
#define BRICKNUM 20
#define COINNUM 3
#define MBRICKNUM 5
#define TREENUM 5

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
    int count = 0;
    QGraphicsScene *pScene = new QGraphicsScene();
    QGraphicsView *pView = new QGraphicsView();
    player *item;
    obstacle *ground[GROUNDNUM];
    obstacle *brick[BRICKNUM];
    obstacle *coin[COINNUM];
    obstacle *book;
    obstacle *cloud[CLOUDNUM];
    obstacle *h;
    obstacle *mbrick[MBRICKNUM];
//    obstacle *homework;
    obstacle *tree[TREENUM];
    QGraphicsTextItem *text = new QGraphicsTextItem;
    void firstLevelIni();
    void newOb(obstacle *one, int type, int x, int y, int w, int h, int data);
    void nGround(int begin, int end, int x, int y);
    void nBrick(int begin, int end, int x, int y);
    void nCoin(int begin, int end, int x, int y);
    void nmBrick(int begin, int end, int x, int y);

    QList<int> generateUniqueRandomNumber();
 //  QSound *BGM = new QSound(":/m/back/BGM.wav");
    QMediaPlayer *myPlayer= new QMediaPlayer;
    //怪物
    javacup * Cups[CupNum];
    QPixmap knife = QPixmap(":/m/back/knife.png");
    QPixmap knife2 = QPixmap(":/m/back/knife2.png");
    QPixmap start = QPixmap(":/m/back/start.png");
    QPixmap hit = QPixmap(":/m/back/hit.png");
private slots:

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
