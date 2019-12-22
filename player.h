#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include<QCursor>
#include<QGraphicsSceneMouseEvent>
#include<QDrag>
#include<QWidget>
#include<QMimeData>
#include<QApplication>
#include<QGraphicsScene>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include<QGraphicsView>
#include<QTimer>
#include <QPixmap>
#include <QObject>
#include <QDebug>
#include<QKeyEvent>
#include<QList>
#include<QPainter>
#include "bullets.h"
#include"somedeclare.h"
class player : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit player(QObject *parent = 0);
    int heroPosX;//人物的x位置
    int heroPosY;//人物的y位置
    int Velocity;//人物跳跃时候的垂直的速度


    enum Dir{up,down,left,right};//人物的方向
    Dir Direction;
    bullets::Dir HorizontalDir;
    int RunSkinCounter = 0;//人物移动的时候皮肤切换计数器


    int HorizontalSpeed = 3;
    QTimer *JumpTimer = new QTimer;

    QPixmap HeroSkin = QPixmap(":/hero/adventurer-run-00.png");
    QPixmap HeroRunSkin0 = QPixmap(":/hero/adventurer-run-00.png");
    QPixmap HeroRunSkin1 = QPixmap(":/hero/adventurer-run-01.png");
    QPixmap HeroRunSkin2 = QPixmap(":/hero/adventurer-run-02.png");
    QPixmap HeroRunSkin3 = QPixmap(":/hero/adventurer-run-03.png");
    QPixmap HeroRunSkin4 = QPixmap(":/hero/adventurer-run-04.png");
    QPixmap HeroRunSkin5 = QPixmap(":/hero/adventurer-run-05.png");

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void advance(int phase) override;


    void setPosition(int x,int y);
    void setVelocity(int v);
    bool JumpOrnot;
    //////////////////////////////////////////////////////////////////////////////
private:
    QColor color;
    void keyPressEvent(QKeyEvent *event) override;
    int Gravity = 1; //重力值

signals:
    void shoot();
    void BackGroundMove();
public slots:
     void FreeFalling(void);
};

#endif // PLAYER_H
