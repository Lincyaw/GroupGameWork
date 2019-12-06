#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include<QKeyEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->player = new hero(this);
    this->land = new obstacle(this);
    this->brick = new obstacle(this);
    this->coin = new obstacle(this);
    this->box = new obstacle(this);

    resize(WidgetWidth,WidgetHeight);


///////////////////////////////人物////////////////////////////////////////////////
    connect(player,&hero::UpDatePainter,[=](){
        updateHero;
    });
    connect(player,&hero::StartTimer,[=](){
        FallTimer->start(12);
    });
    connect(player,&hero::StopTimer,[=](){
        FallTimer->stop();
    });
    connect(JumpTimer,&QTimer::timeout,[=](){ //跳跃的函数, 降落到地面的时候停止定时器
        updateHero;
        bool k;
        k = player->HeroJump(brick);
        if(k)
        {
            JumpTimer->stop();
        }
    });
    connect(FallTimer,&QTimer::timeout,[=](){ //跳跃的函数, 降落到地面的时候停止定时器
        updateHero;

        if(player->HeroFallDown(brick))
        {
            FallTimer->stop();
        }
    });



////////////////////////////////背景///////////////////////////////////////////////

    land->InitLandData();
    brick->InitBrickData();
    coin->InitCoinData();
    connect(player,&hero::MeetCoin,[=](){
        coin->showflag[player->HeroMeetWhichObstacle] = 0;
        update(coin->obPosX[player->HeroMeetWhichObstacle],coin->obPosY[player->HeroMeetWhichObstacle],coin->obWidth[player->HeroMeetWhichObstacle],coin->obHeight[player->HeroMeetWhichObstacle]);
    });
    box->InitBoxData();


////////////////////////////////怪物//////////////////////////////////////////////
    this->monster = new anemy(this,400);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    int i;
    //实例化画家对象  this指定的是绘图设备
    QPainter painter(this);
    QPainter obPainter(this);


    //painter.drawRect(0,490,80,50);
    painter.drawRect(30,500,30,50);
    painter.drawRect(460,450,40,20);
    //画陆地

    //画地面

    obPainter.drawPixmap(land->obPosX[0],land->obPosY[0],land->obWidth[0],land->obHeight[0],QPixmap(":/background/background/brick01.png"));
    //画砖块
    for (i = 0; i < brick->number; i++)
    {
        obPainter.drawPixmap(brick->obPosX[i],brick->obPosY[i],brick->obWidth[i],brick->obHeight[i],QPixmap(":/background/background/brick01.png"));
    }
    //画金币
    for (i = 0; i < coin->number; i++)
    {
        if(coin->showflag[i])
        {
            obPainter.drawPixmap(coin->obPosX[i],coin->obPosY[i],coin->obWidth[i],coin->obHeight[i],QPixmap(":/background/background/coin.png"));
        }
    }

    //画箱子
    obPainter.drawPixmap(box->obPosX[0],box->obPosY[0],box->obWidth[0],box->obHeight[0],QPixmap(":/background/background/brick02.png"));

//    painter.drawLine(QPoint(0,GroundY),QPoint(WidgetWidth,GroundY));

    //画人
    //通过测试可以得到画出来的人物的 左上角点为(heroPosX,heroPosY),宽为23,高为28
    painter.drawPixmap(player->heroPosX,player->heroPosY,23,28,player->HeroSkin);

}
void MainWindow::timerEvent(QTimerEvent *ev)
{
    if(ev->timerId() == JumpTimer->timerId())
    {
        updateHero;
        //update();
        player->HeroJump(brick);

    }
    if(ev->timerId() == FallTimer->timerId())
    {
        updateHero;
        player->HeroFallDown(brick);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key_J) //跳跃
    {
        if(player->JumpOrNot==0)//如果在跳跃的过程中就不进行下面的进程, 即防止二段跳使人物一直在最高度
        {
             player->Jumpflag = 0;//把跳跃的方向置为向上
             JumpTimer->start(12);//每12ms更新一次人物的位置
        }
    }
    if(ev->key() == Qt::Key_A)//左移
    {

        player->RunSkinCounter--;
        switch(player->RunSkinCounter)
        {
            case 0:
                player->HeroSkin = player->HeroRunSkin1;
                player->RunSkinCounter = 30;
               // qDebug()<<"0001";
                break;
            case 5:
                player->HeroSkin = player->HeroRunSkin2;
               // qDebug()<<"0002";
                break;
            case 10:
                player->HeroSkin = player->HeroRunSkin3;
                //qDebug()<<"0003";
                break;
            case 15:
                player->HeroSkin = player->HeroRunSkin4;
               // qDebug()<<"0004";
                break;
            case 20:
                player->HeroSkin = player->HeroRunSkin5;
                //qDebug()<<"0005";
            case 25:
                player->HeroSkin = player->HeroRunSkin0;
                break;
        }

        player->HeroGoLeft(brick); //人向左运动
        player->HeroGoLeft(coin); //人向左运动
        updateHero;
    }
    if(ev->key() == Qt::Key_D)//右移
    {
        player->RunSkinCounter++;
        switch(player->RunSkinCounter)
        {
            case 0:
                player->HeroSkin = player->HeroRunSkin1;
               // qDebug()<<"0001";
                break;
            case 5:
                player->HeroSkin = player->HeroRunSkin2;
               // qDebug()<<"0002";
                break;
            case 10:
                player->HeroSkin = player->HeroRunSkin3;
                //qDebug()<<"0003";
                break;
            case 15:
                player->HeroSkin = player->HeroRunSkin4;
               // qDebug()<<"0004";
                break;
            case 20:
                player->HeroSkin = player->HeroRunSkin5;
                //qDebug()<<"0005";
                break;
            case 25:
                player->HeroSkin = player->HeroRunSkin0;
                break;
            case 30:
                player->RunSkinCounter=0;
              break;

        }
        if (player->heroPosX < 750)  //角色在屏幕左半部分时，角色右移
        {
            player->HeroGoRight(brick);//人向右运动
            player->HeroGoRight(coin); //人向右运动
            // qDebug()<<player->RunSkinCounter;
            update(player->heroPosX-18,player->heroPosY,80,50);
        }
        else  //角色在屏幕右半部分时，障碍物左移
        {
            player->JudgeWhatHeroMeets(brick);
            player->JudgeWhatHeroMeets(coin);
            update(player->heroPosX-18,player->heroPosY,80,50);

            brick->ObstacleGoLeft();
            for (int i = 0; i < brick->number; i++)
            {
                update(brick->obPosX[i],brick->obPosY[i],brick->obWidth[i] + 10,brick->obHeight[i]);
            }

            coin->ObstacleGoLeft();
            for (int i = 0; i < coin->number; i++)
            {
                update(coin->obPosX[i],coin->obPosY[i],coin->obWidth[i] + 10,coin->obHeight[i]);
            }

            box->ObstacleGoLeft();
            update(box->obPosX[0],box->obPosY[0],box->obWidth[0] + 10,box->obHeight[0]);
        }

        player->HeroGoRight(brick);//人向右运动
        player->HeroGoRight(coin); //人向右运动

       // qDebug()<<player->RunSkinCounter;
        updateHero;
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
