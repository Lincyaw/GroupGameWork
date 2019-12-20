#ifndef ATTACK_H
#define ATTACK_H

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
class attack : public QGraphicsItem
{
public:
    attack();
    //~attack();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QTimer *shootTimer = new QTimer;
    int bulletPosX;//人物的x位置
    int bulletPosY;//人物的y位置
    int speed;

    void setPosition(int x,int y);
    void setSpeed(int v);
    void setDirection();
};

#endif // ATTACK_H
