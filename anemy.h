#ifndef ANEMY_H
#define ANEMY_H
#include <QString>
#include <QList>
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
#include <QObject>


class anemy : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit anemy(QObject *parent = nullptr,int postionx = 0,int RangeX = 0,int RangeY = 0,int postiony = 0,float horV = 0,float verV = 0);
    int heroPosX;//人物的x位置
    int heroPosY;//人物的y位置
    int BornPosX;//出生位置
    int BornPosY;
    int m_RangeX;//x-range<x<x+range
    int m_RangeY;//
    float HorizontalV;//水平
    float VerticalV;//人物跳跃时候的垂直的速度
    int heroBlood;
    QColor color;
    int PicWidth;
    int PicHeight;
    int MoveFlat;//1为可移动，2为不可移动
    static const int MoveInterval = 30; //移动间隔
    static const int RecoveryInterval = 30;//硬直恢复

    enum Dir{up,down,left,right};//人物的方向
    Dir VerticalDir;
    Dir HorizontalDir;
    int RunSkinCounter = 0;//人物移动的时候皮肤切换计数器
    int SkillCounter = 0;

    QTimer *MoveTimer ;
    QTimer *RecoveryTimer;//从被攻击硬直到恢复移动
    QPixmap heroSkin;
    QPixmap BeAttackedSkin;


    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setPosition(int x,int y);
    void setHorizontalV(float v);
    void setVerticalV(float v);
    void setRangeXY(int x,int y);
    void attackJudge();
    //////////////////////////////////////////////////////////////////////////////
private:

signals:
    void shoot();
    void BackGroundMove();
    void Skill0();
    void Skill1();
    void Skill2();
    void Skill3();
    void Skill4();
    void collided();
    void notcollided();
public slots:
    void AttackedByJ();
    void AttackedByK();
    void AttackedByL();
};

#endif // ANEMY_H
