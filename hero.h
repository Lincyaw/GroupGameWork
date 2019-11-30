#ifndef HERO_H
#define HERO_H

#include <QObject>
#include<QTimer>
#include <QDebug>
class hero : public QObject
{
    Q_OBJECT
public:

    explicit hero(QObject *parent = 0);
    const static int Brick =  1; // 定义砖块类型为1;
    int heroPosX = 0;
    int heroPosY = 510;
    int Jumpflag = 0; //判断跳跃的时候是往下还是往上
    int JumpOrNot = 0;
    const static int HeroJumpHeightNormal = 60;
    int HeroJumpHeight = 60;
    int groundY = 540;
    int HeroHeight = 30;//人物这张图片画图是从左上角开始的, 因此要在想绘制的地方
                        //减去整张照片的高度才能画在想画的位置.

    void HeroGoLeft();
    void HeroGoRight();
    bool HeroFallDown();
    bool HeroJump();
    int JudgeWhatHeroMeets(int Type);//暂定比如砖头是1, 石头是2,怪物是3等等


signals:
    void StopTimer();//关闭定时器信号
    void StartTimer();//打开定时器信号
    void UpDatePainter();
public slots:
};

#endif // HERO_H
