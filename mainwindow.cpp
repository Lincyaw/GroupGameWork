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
    obstacle *brick[18];
    obstacle *coin[12];
    obstacle *book;

    item = new player;
    item->setFlag(QGraphicsItem::ItemIsFocusable);  //鼠标选中这个item之后就是聚焦, 然后可以用键盘控制这个item
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setPosition(-700,50);
    item->setData(1,1);

    //初始化地面
    ground = new obstacle;
    ground->setType(1);
    ground->setPosition(-750,540);
    ground->setWidthHeight(1500,250);
    ground->setData(1,2);
    pScene->addItem(ground);
    //初始化砖块
    for(int i = 0; i < 3; i++)
    {
        brick[i] = new obstacle;
        brick[i]->setType(1);
        brick[i]->setPosition(-200 + 50 * i,350);
        brick[i]->setWidthHeight(50,50);
        brick[i]->setData(1,2);
        pScene->addItem(brick[i]);
    }
    for(int i = 0; i < 3; i++)
    {
        brick[i+3] = new obstacle;
        brick[i+3]->setType(1);
        brick[i+3]->setPosition(70 + 50 * i,200);
        brick[i+3]->setWidthHeight(50,50);
        brick[i+3]->setData(1,2);
        pScene->addItem(brick[i+3]);
    }
    for(int i = 0; i < 3; i++)
    {
        brick[i+6] = new obstacle;
        brick[i+6]->setType(1);
        brick[i+6]->setPosition(400 + 50 * i,400);
        brick[i+6]->setWidthHeight(50,50);
        brick[i+6]->setData(1,2);
        pScene->addItem(brick[i+6]);
    }
    for(int i = 0; i < 3; i++)
    {
        brick[i+9] = new obstacle;
        brick[i+9]->setType(1);
        brick[i+9]->setPosition(950 + 50 * i,400);
        brick[i+9]->setWidthHeight(50,50);
        brick[i+9]->setData(1,2);
        pScene->addItem(brick[i+9]);
    }
    for(int i = 0; i < 3; i++)
    {
        brick[i+12] = new obstacle;
        brick[i+12]->setType(1);
        brick[i+12]->setPosition(1500 + 100 * i,400 - 100 * i);
        brick[i+12]->setWidthHeight(50,50);
        brick[i+12]->setData(1,2);
        pScene->addItem(brick[i+12]);
    }
    for(int i = 0; i < 3; i++)
    {
        brick[i+15] = new obstacle;
        brick[i+15]->setType(1);
        brick[i+15]->setPosition(1850 + 100 * i,200 + 100 * i);
        brick[i+15]->setWidthHeight(50,50);
        brick[i+15]->setData(1,2);
        pScene->addItem(brick[i+15]);
    }
    //初始化金币
    for(int i = 0; i < 3; i++)
    {
        coin[i] = new obstacle;
        coin[i]->setType(2);
        coin[i]->setPosition(-200 + 50 * i,300);
        coin[i]->setWidthHeight(50,50);
        coin[i]->setShowFlag(1);
        coin[i]->setData(1,3);
        pScene->addItem(coin[i]);
    }
    for(int i = 0; i < 3; i++)
    {
        coin[i+3] = new obstacle;
        coin[i+3]->setType(2);
        coin[i+3]->setPosition(70 + 50 * i,150);
        coin[i+3]->setWidthHeight(50,50);
        coin[i+3]->setShowFlag(1);
        coin[i+3]->setData(1,3);
        pScene->addItem(coin[i+3]);
    }
    for(int i = 0; i < 3; i++)
    {
        coin[i+6] = new obstacle;
        coin[i+6]->setType(2);
        coin[i+6]->setPosition(400 + 50 * i,350);
        coin[i+6]->setWidthHeight(50,50);
        coin[i+6]->setShowFlag(1);
        coin[i+6]->setData(1,3);
        pScene->addItem(coin[i+6]);
    }
    for(int i = 0; i < 3; i++)
    {
        coin[i+9] = new obstacle;
        coin[i+9]->setType(2);
        coin[i+9]->setPosition(950 + 50 * i,350);
        coin[i+9]->setWidthHeight(50,50);
        coin[i+9]->setShowFlag(1);
        coin[i+9]->setData(1,3);
        pScene->addItem(coin[i+9]);
    }
    //初始化书
    book = new obstacle;
    book->setType(3);
    book->setPosition(2500,390);//边界630
    book->setWidthHeight(120,150);
    book->setData(1,4);
    pScene->addItem(book);

    //bullet *D1 = new bullet;
    // 将 item 添加至场景中
    connect(item,&player::shoot,[=](){
        shootBullet(item->heroPosX,item->heroPosY);
    });
    connect(item,&player::BackGroundMove,[=](){
        for (int i = 0; i < 18; i++)
        {
            brick[i]->moveBy(-3,0);
            update(brick[i]->obPosX,brick[i]->obPosY,brick[i]->obWidth,brick[i]->obHeight);
        }
        for (int i = 0; i < 12; i++)
        {
            coin[i]->moveBy(-3,0);
            update(coin[i]->obPosX,coin[i]->obPosY,coin[i]->obWidth,coin[i]->obHeight);
        }
        book->moveBy(-3,0);
        update(book->obPosX,book->obPosY,book->obWidth,book->obHeight);
    });
    pScene->addItem(item);
    pScene->setFocusItem(item);


//    //新建一个直线项
//    QGraphicsLineItem *line = new QGraphicsLineItem(-750, 50, 750, 50);
//    line->setData(1,2);
//    QGraphicsRectItem *reg = new QGraphicsRectItem(0,-10,50,50);
//    reg->setData(1,3);
//    pScene->addItem(line);
//    pScene->addItem(reg);
//    qDebug() << item->shape();   //输出item的shape信息
//    qDebug() << item->boundingRect();  //输出item的boundingRect信息


//    新建一个直线项
//    QGraphicsLineItem *line = new QGraphicsLineItem(-750, 50, 750, 50);
//    line->setData(1,4);
//    QGraphicsRectItem *reg = new QGraphicsRectItem(0,-10,50,50);
//    reg->setData(1,4);

//    QGraphicsRectItem *reg2 = new QGraphicsRectItem(200,-10,50,50);
//    reg->setData(1,3);


//    pScene->addItem(line);
//    pScene->addItem(reg);
//    pScene->addItem(reg2);
//    qDebug() << item->shape();   //输出item的shape信息
//    qDebug() << item->boundingRect();  //输出item的boundingRect信息




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



void MainWindow::shootBullet(int p,int q)
{
    int i;
    bullets *D1 = new bullets(p,q);
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
