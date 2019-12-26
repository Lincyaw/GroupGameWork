#ifndef OBSTACLE_H
#define OBSTACLE_H

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

class obstacle : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
     obstacle(QObject *parent = 0, int booktype = 0);

    int type;  //障碍物类型 0：地 1: 砖块 2: 金币 3：书 4：云 5：主楼 6：会动的砖 7：作业 8：树
    int obPosX;  //障碍物坐标
    int obPosY;
    int obWidth;  //障碍物的宽
    int obHeight;  //障碍物的高
    int showflag;  //障碍物是否显示 0: 不显示 1： 显示
    int magic = 0;
    int moveFlag;
    int bookType = 0;
    bool DeleteOrNot = false;
    QPixmap Ground = QPixmap(":/obstacle/obstacle/Grass.png");
    QPixmap Brick = QPixmap(":/obstacle/obstacle/brick01.png");
    QPixmap Coin = QPixmap(":/obstacle/obstacle/coin.png");
    QPixmap Book= QPixmap(":/obstacle/obstacle/book.jpg");
    QPixmap Book1 = QPixmap(":/obstacle/obstacle/book.jpg");
    QPixmap Book2 = QPixmap(":/obstacle/obstacle/book2.jpg");
    QPixmap Book3 = QPixmap(":/obstacle/obstacle/book3.jpg");
    QPixmap Cloud = QPixmap(":/obstacle/obstacle/cloud.png");
    QPixmap H = QPixmap(":/obstacle/obstacle/mainbuild.png");
    QPixmap Homework = QPixmap(":/obstacle/obstacle/homework.png");
    QPixmap Tree = QPixmap(":/obstacle/obstacle/trees.png");

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QTimer *cloudTimer = new QTimer;
    QTimer *brickTimer = new QTimer;
    QTimer *groundTimer = new QTimer;

    void setType(int num);
    void setPosition(int x,int y);
    void setWidthHeight(int width,int height);
    void setShowFlag(int num);


signals:
    void GroundTwinkcle();
public slots:
};

#endif // OBSTACLE_H
