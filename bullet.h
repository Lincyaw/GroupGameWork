#ifndef BULLET_H
#define BULLET_H
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
#include"somedeclare.h"
class bullet : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    enum Dir{up,down,left,right};
    bullet(Dir dir1,int x, int y);
    explicit bullet(QObject *parent = 0);
    ~bullet();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QTimer *shootTimer = new QTimer;
    int bulletPosX;//人物的x位置
    int bulletPosY;//人物的y位置
    int speed;

    Dir direction;
    void setPosition(int x,int y);
    void setSpeed(int v);
    void setDirection(Dir dir);
    void killSelf();
};

#endif // BULLET_H
