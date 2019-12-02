#ifndef HERO_H
#define HERO_H

#include <QObject>
#include<QTimer>
#include <QDebug>
#include "obstacle.h"
class hero : public QObject
{
    Q_OBJECT
public:

    explicit hero(QObject *parent = 0);
    const static int Brick =  1; // 定义砖块类型为1;
    int heroPosX = 0;
    int heroPosY = 490;
    int HeroPosY = 500; //修正后的人的左上角, 因为用heroPosY的话上方还有一点点空白
    int HeroWidth = 30;

    int HeroStep = 4;
    int Jumpflag = 0; //判断跳跃的时候是往下还是往上
    int JumpOrNot = 0;
    const static int HeroJumpHeightNormal = 200;
    int HeroJumpHeight = 200;
    int groundY = 540;
    int HeroHeight = 50;//人物这张图片画图是从左上角开始的, 因此要在想绘制的地方
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
