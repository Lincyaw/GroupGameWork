#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //resize(1920,1080);

    player *item;
    obstacle *cloud[3];
    obstacle *ground;
    obstacle *brick[27];
    obstacle *coin[6];
    obstacle *book;

    item = new player;
    item->setFlag(QGraphicsItem::ItemIsFocusable);  //鼠标选中这个item之后就是聚焦, 然后可以用键盘控制这个item
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setPosition(-700,500);
    item->setData(1,1);

    //初始化云
    for(int i = 0; i < 3; i++)
    {
        cloud[i] = new obstacle;
        cloud[i]->setType(0);
        cloud[i]->setPosition(-500 + 530 * i,0);
        cloud[i]->setWidthHeight(100,50);
        pScene->addItem(cloud[i]);
    }
    //初始化地面
    ground = new obstacle;
    ground->setType(1);
    ground->setPosition(-750,650);
    ground->setWidthHeight(1980,200);
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
        brick[i+12]->setPosition(1500 + 250 * i,400 - 100 * i);
        brick[i+12]->setWidthHeight(50,50);
        brick[i+12]->setData(1,2);
        pScene->addItem(brick[i+12]);
    }
    for(int i = 0; i < 3; i++)
    {
        brick[i+15] = new obstacle;
        brick[i+15]->setType(1);
        brick[i+15]->setPosition(2500 + 250 * i,200 + 100 * i);
        brick[i+15]->setWidthHeight(50,50);
        brick[i+15]->setData(1,2);
        pScene->addItem(brick[i+15]);
    }
    for(int i = 0; i < 2; i++)
    {
        brick[i+18] = new obstacle;
        brick[i+18]->setType(1);
        brick[i+18]->setPosition(3500 + 50 * i,400);
        brick[i+18]->setWidthHeight(50,50);
        brick[i+18]->setData(1,2);
        pScene->addItem(brick[i+18]);
    }
    brick[20] = new obstacle;
    brick[20]->setType(1);
    brick[20]->setPosition(3750,200);
    brick[20]->setWidthHeight(50,50);
    brick[20]->setData(1,2);
    pScene->addItem(brick[20]);
    for(int i = 0; i < 3; i++)
    {
        brick[i+21] = new obstacle;
        brick[i+21]->setType(1);
        brick[i+21]->setPosition(4450 + 50 * i,250);
        brick[i+21]->setWidthHeight(50,50);
        brick[i+21]->setData(1,2);
        pScene->addItem(brick[i+21]);
    }
    for(int i = 0; i < 2; i++)
    {
        brick[i+24] = new obstacle;
        brick[i+24]->setType(1);
        brick[i+24]->setPosition(4800 + 50 * i,350);
        brick[i+24]->setWidthHeight(50,50);
        brick[i+24]->setData(1,2);
        pScene->addItem(brick[i+24]);
    }
    brick[26] = new obstacle;
    brick[26]->setType(1);
    brick[26]->setPosition(5150,200);
    brick[26]->setWidthHeight(50,50);
    brick[26]->setData(1,2);
    pScene->addItem(brick[26]);
    //初始化金币
    coin[0] = new obstacle;
    coin[0]->setType(2);
    coin[0]->setPosition(-100,300);
    coin[0]->setWidthHeight(50,50);
    coin[0]->setShowFlag(1);
    coin[0]->setData(1,3);
    pScene->addItem(coin[0]);

    coin[1] = new obstacle;
    coin[1]->setType(2);
    coin[1]->setPosition(170,150);
    coin[1]->setWidthHeight(50,50);
    coin[1]->setShowFlag(1);
    coin[1]->setData(1,3);
    pScene->addItem(coin[1]);

    coin[2] = new obstacle;
    coin[2]->setType(2);
    coin[2]->setPosition(400,350);
    coin[2]->setWidthHeight(50,50);
    coin[2]->setShowFlag(1);
    coin[2]->setData(1,3);
    pScene->addItem(coin[2]);

    coin[3] = new obstacle;
    coin[3]->setType(2);
    coin[3]->setPosition(1000,350);
    coin[3]->setWidthHeight(50,50);
    coin[3]->setShowFlag(1);
    coin[3]->setData(1,3);
    pScene->addItem(coin[3]);

    coin[4] = new obstacle;
    coin[4]->setType(2);
    coin[4]->setPosition(1750,250);
    coin[4]->setWidthHeight(50,50);
    coin[4]->setShowFlag(1);
    coin[4]->setData(1,3);
    pScene->addItem(coin[4]);

    coin[5] = new obstacle;
    coin[5]->setType(2);
    coin[5]->setPosition(2500,150);
    coin[5]->setWidthHeight(50,50);
    coin[5]->setShowFlag(1);
    coin[5]->setData(1,3);
    pScene->addItem(coin[5]);

    //初始化书
    book = new obstacle;
    book->setType(3);
    book->setPosition(6000,500);//边界630
    book->setWidthHeight(120,150);
    book->setData(1,4);
    pScene->addItem(book);

    //bullet *D1 = new bullet;
    // 将 item 添加至场景中

    connect(item,&player::BackGroundMove,[=](){
        for (int i = 0; i < 27; i++)
        {
            brick[i]->moveBy(-3,0);
            update(brick[i]->obPosX,brick[i]->obPosY,brick[i]->obWidth,brick[i]->obHeight);
        }
        for (int i = 0; i < 6; i++)
        {
            coin[i]->moveBy(-3,0);
            update(coin[i]->obPosX,coin[i]->obPosY,coin[i]->obWidth,coin[i]->obHeight);
        }
        book->moveBy(-3,0);
        update(book->obPosX,book->obPosY,book->obWidth,book->obHeight);
    });
    pScene->addItem(item);
    pScene->setFocusItem(item);



    // 为视图设置场景

    pView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    pView->resize(1980,1080);

    pView->setScene(pScene);
    pView->setStyleSheet("border:none; background:white;");
    pView->centerOn(0,0);
    pView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   // pView->setParent(this);
    //pView->setVisible(false);

}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_begin_clicked()
{
    pView->show();
    this->setVisible(false);
}
