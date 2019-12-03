#ifndef HERO_H
#define HERO_H
#include <QPixmap>
#include <QObject>
#include<QTimer>
#include <QDebug>
#include "obstacle.h"
class hero : public QObject
{
    Q_OBJECT
public:

    explicit hero(QObject *parent = 0);
    int Brick; // 定义砖块类型为1;
    int heroPosX;
    int heroPosY;
    int HeroPosY; //修正后的人的左上角, 因为用heroPosY的话上方还有一点点空白
    int HeroWidth;
    int HeroStep;
    int JumpSpeed;
    int FallSpeed;
    int Jumpflag; //判断跳跃的时候是往下还是往上
    int StandOnTheBrickflag;
    int JumpOrNot;
    int HeroJumpHeightNormal;
    int HeroJumpHeight;

    QPixmap HeroSkin;
    QPixmap HeroSkin1;
    QPixmap HeroSkin2;
    QPixmap HeroSkin3;
    QPixmap HeroSkin4;
    QPixmap HeroSkin5;


    int groundY;
    int HeroHeight;//人物这张图片画图是从左上角开始的, 因此要在想绘制的地方
                        //减去整张照片的高度才能画在想画的位置.
            //通过测试可以得到画出来的人物的 左上角点为(heroPosX,heroPosY+10),宽为30,高为40

    void HeroGoLeft(obstacle *ob);
    void HeroGoRight(obstacle *ob);
    bool HeroFallDown(obstacle *ob);
    bool HeroJump(obstacle *ob);
   // int JudgeWhatHeroMeets(int Type[1500][800]);//暂定比如砖头是1, 石头是2,怪物是3等等
    int JudgeWhatHeroMeets(obstacle *ob);

signals:
    void StopTimer();//关闭定时器信号
    void StartTimer();//打开定时器信号
    void UpDatePainter();
public slots:
};

#endif // HERO_H
