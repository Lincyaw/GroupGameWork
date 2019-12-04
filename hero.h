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
    int Brick = 1; // 定义砖块类型为1;
    int heroPosX = 0;//人物图片的横坐标
    int heroPosY = 490;//人物图片的纵坐标
    int HeroPosY = heroPosY+10; //修正后的人的左上角, 因为用heroPosY的话上方还有一点点空白
    int HeroWidth = 30;//人物的宽度
    int HeroHeight = 50;//人物这张图片画图是从左上角开始的, 因此要在想绘制的地方
                        //减去整张照片的高度才能画在想画的位置.
            //通过测试可以得到画出来的人物的 左上角点为(heroPosX,heroPosY+10),宽为30,高为40
    int HeroStep = 5;//人物平移的时候的步子
    int JumpSpeed = 6;//人物跳跃的速度
    int FallSpeed = 6;//人物坠落的速度
    int Jumpflag = 0; //判断跳跃的时候是往下还是往上
    int StandOnTheBrickflag = 0;//判断有没有站在砖头上
    int JumpOrNot = 0;//判断人物有没有在跳跃的标志位
    const static int HeroJumpHeightNormal = 150;//人物正常的跳跃高度
    int HeroJumpHeight = 150;//人物在任何情况下的可改变的跳跃高度
    int HeroMeetWhichObstacle = 0;//人物遇到什么障碍物标志位

    QPixmap HeroSkin = QPixmap(":/hero/adventurer-run-01.png");
    QPixmap HeroRunSkin1 = QPixmap(":/hero/adventurer-run-01.png");
    QPixmap HeroRunSkin2 = QPixmap(":/hero/adventurer-run-02.png");
    QPixmap HeroRunSkin3 = QPixmap(":/hero/adventurer-run-03.png");
    QPixmap HeroRunSkin4 = QPixmap(":/hero/adventurer-run-04.png");
    QPixmap HeroRunSkin5 = QPixmap(":/hero/adventurer-run-05.png");

    int RunSkinCounter = 0;//人物移动的时候皮肤切换计数器
    int groundY = 540;//人物的相对地面
    const static int GroundY = 540;//绝对地面

    void HeroGoLeft(obstacle *ob);//人向左移动
    void HeroGoRight(obstacle *ob);//人向右移动
    bool HeroFallDown(obstacle *ob);//人物坠落,(没有在跳跃的情况下
    bool HeroJump(obstacle *ob);//人物跳跃
    int JudgeWhatHeroMeets(obstacle *ob);//判断人物遇到了什么的互动函数

    ////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////
    //测试区域
    int tempcounter = 0;

    //////////////////////////////////////////////////////////////////////////////

signals:
    void StopTimer();//关闭定时器信号
    void StartTimer();//打开定时器信号
    void UpDatePainter();
    void MeetCoin();//人物遇到金币后发射的信号
public slots:
};

#endif // HERO_H
