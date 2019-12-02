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


    resize(WidgetWidth,WidgetHeight);


///////////////////////////////人物////////////////////////////////////////////////
    connect(player,&hero::UpDatePainter,[=](){
        update(player->heroPosX-5,player->heroPosY,80,50);
    });
    connect(player,&hero::StartTimer,[=](){
        FallTimer->start(12);
    });
    connect(player,&hero::StopTimer,[=](){
        FallTimer->stop();
    });
    connect(JumpTimer,&QTimer::timeout,[=](){ //跳跃的函数, 降落到地面的时候停止定时器
        update(player->heroPosX-5,player->heroPosY,80,50);
        if(player->HeroJump())
        {
            JumpTimer->stop();
        }
    });
    connect(FallTimer,&QTimer::timeout,[=](){ //跳跃的函数, 降落到地面的时候停止定时器
        update(player->heroPosX-5,player->heroPosY,80,50);
        if(player->HeroFallDown())
        {
            FallTimer->stop();
        }
    });



////////////////////////////////背景///////////////////////////////////////////////

    land->InitLandData();
    brick->InitBrickData();




////////////////////////////////怪物//////////////////////////////////////////////
}

void MainWindow::paintEvent(QPaintEvent *)
{
    int i;
    //实例化画家对象  this指定的是绘图设备
    QPainter painter(this);
    QPainter obPainter(this);

    //painter.drawRect(0,490,80,50);
    painter.drawRect(30,500,30,50);
    painter.drawRect(460,450,40,10);
    //画地面
    obPainter.drawPixmap(land->obPosX[0],land->obPosY[0],land->obWidth[0],land->obHeight[0],QPixmap(":/background/background/brick01.png"));
    for (i = 0; i < 3; i++)
    {
        obPainter.drawPixmap(brick->obPosX[i],brick->obPosY[i],brick->obWidth[i],brick->obHeight[i],QPixmap(":/background/background/brick01.png"));
    }
//    painter.drawLine(QPoint(0,GroundY),QPoint(WidgetWidth,GroundY));
    //画人
    //通过测试可以得到画出来的人物的 左上角点为(heroPosX,heroPosY+10),宽为30,高为40
    painter.drawPixmap(player->heroPosX-30,player->heroPosY,80,50,QPixmap(":/hero/adventurer-run-04.png"));

}
void MainWindow::timerEvent(QTimerEvent *ev)
{
    if(ev->timerId() == JumpTimer->timerId())
    {
        update(player->heroPosX-10,player->heroPosY,80,50);
        //update();
        player->HeroJump();

    }
    if(ev->timerId() == FallTimer->timerId())
    {
        update(player->heroPosX-10,player->heroPosY,80,50);
        player->HeroFallDown();
    }

}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key_J ) //跳跃
    {
        if(player->JumpOrNot==0)//如果在跳跃的过程中就不进行下面的进程, 即防止二段跳使人物一直在最高度
        {
             player->Jumpflag = 0;//把跳跃的方向置为向上
             JumpTimer->start(12);//每50ms更新一次人物的位置
        }
    }
    if(ev->key() == Qt::Key_A)//左移
    {
        player->HeroGoLeft(); //人向左运动
        update(player->heroPosX-10,player->heroPosY,80,50);
    }
    if(ev->key() == Qt::Key_D)//右移
    {
        player->HeroGoRight();//人向右运动
        update(player->heroPosX-10,player->heroPosY,80,50);
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
