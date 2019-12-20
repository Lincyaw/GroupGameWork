#ifndef HERO2_H
#define HERO2_H

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
class hero2 : public QObject,QGraphicsItem
{
    Q_OBJECT
public:
    explicit hero2(QObject *parent = nullptr);
    qreal heroPosX;//人物的x位置
    qreal heroPosY;//人物的y位置
    int Velocity;//人物跳跃时候的垂直的速度


    enum Dir{up,down,left,right};//人物的方向
    Dir Direction = right;



    int HorizontalSpeed = 10;
   // QTimer *JumpTimer;

    QPixmap HeroSkin = QPixmap(":/hero/adventurer-run-00.png");
    QPixmap HeroRunSkin0 = QPixmap(":/hero/adventurer-run-00.png");
    QPixmap HeroRunSkin1 = QPixmap(":/hero/adventurer-run-01.png");
    QPixmap HeroRunSkin2 = QPixmap(":/hero/adventurer-run-02.png");
    QPixmap HeroRunSkin3 = QPixmap(":/hero/adventurer-run-03.png");
    QPixmap HeroRunSkin4 = QPixmap(":/hero/adventurer-run-04.png");
    QPixmap HeroRunSkin5 = QPixmap(":/hero/adventurer-run-05.png");

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);



    void setPosition(qreal x,qreal y);
    void setVelocity(int v);
    //////////////////////////////////////////////////////////////////////////////
private:
    QColor color;
    void keyPressEvent(QKeyEvent *event);
    qreal Gravity = 0.5; //重力值
signals:

public slots:
};

#endif // HERO2_H
