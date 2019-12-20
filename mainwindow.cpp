#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(1500,800);
    player *item;
    obstacle *ground;
    obstacle *coin[3];


    item = new player;
    item->setFlag(QGraphicsItem::ItemIsFocusable);  //鼠标选中这个item之后就是聚焦, 然后可以用键盘控制这个item
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setPosition(-700,0);
    //初始化地面
    ground = new obstacle;
    ground->setType(1);
    ground->setPosition(-750,250);
    ground->setWidthHeight(1500,250);
    ground->setData(1,2);
    pScene->addItem(ground);
    //初始化金币
    for(int i = 0; i < 3; i++)
    {
        coin[i] = new obstacle;
        coin[i]->setType(2);
        coin[i]->setPosition(0 + 30 * i,0);
        coin[i]->setWidthHeight(30,30);
        coin[i]->setData(1,3);
        pScene->addItem(coin[i]);
    }



    //bullet *D1 = new bullet;
    // 将 item 添加至场景中
    connect(item,&player::shoot,[=](){
        shootBullet();
    });
    pScene->addItem(item);
    pScene->setFocusItem(item);


    //新建一个直线项
    QGraphicsLineItem *line = new QGraphicsLineItem(-750, 50, 750, 50);
    line->setData(1,2);
    QGraphicsRectItem *reg = new QGraphicsRectItem(0,-10,50,50);
    reg->setData(1,3);
    //pScene->addItem(line);
    pScene->addItem(reg);
   // qDebug() << item->shape();   //输出item的shape信息
   // qDebug() << item->boundingRect();  //输出item的boundingRect信息


    //新建一个直线项
   // QGraphicsLineItem *line = new QGraphicsLineItem(-750, 50, 750, 50);
   // line->setData(1,4);
 //   QGraphicsRectItem *reg = new QGraphicsRectItem(0,-10,50,50);
   // reg->setData(1,4);

//    QGraphicsRectItem *reg2 = new QGraphicsRectItem(200,-10,50,50);
//    reg->setData(1,3);


    //pScene->addItem(line);
    pScene->addItem(reg);
    //pScene->addItem(reg2);
   // qDebug() << item->shape();   //输出item的shape信息
   // qDebug() << item->boundingRect();  //输出item的boundingRect信息




    // 为视图设置场景

    pView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    pView->resize(1500,800);
    pView->setScene(pScene);
    pView->setStyleSheet("border:none; background:white;");
    pView->centerOn(0,0);
    pView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pView->setParent(this);


}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
}



void MainWindow::shootBullet()
{
    int i;
    bullets *D1 = new bullets;
    pScene->addItem(D1);
    for(i=0;i<D1->collidingItems().length();i++)
    {
        if(D1->collidingItems().at(i)->data(1).toInt() == 2)
        {
            pScene->removeItem(D1);
        }
    }

//    connect(D1->shootTimer,&QTimer::timeout,[=](){

//                if(D1->bulletPosX >500 || D1->bulletPosX <-750)
//                {
//                    qDebug()<<"一个子弹析构";
//                   // D1->deleteLater();
//                    pScene->removeItem(D1);
//                }
//    });
}


MainWindow::~MainWindow()
{
    delete ui;
}
