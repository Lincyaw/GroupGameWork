#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(700,700);
    setWindowIcon(QIcon(":/obstacle/obstacle/coin.png"));
    setWindowTitle("游戏");

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/m/back/welcome.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_begin_clicked()
{
    QMessageBox::information(this,"游戏提示",
                             "WAD控制角色左右移动和上下移动\nJKL释放技能\n打败怪兽有大量积分哦"
                                         );
    if(clickedTimes==0)
    {
        //BGM->play();

        myPlayer->setMedia(QUrl("qrc:/m/back/bgm.mp3"));
        myPlayer->setVolume(80);
        myPlayer->play();
        firstLevelIni();
        pView->show();
        clickedTimes++;
    }
}

void MainWindow::on_pushButton_clicked()
{
    pView->close();
    myPlayer->stop();
}

void MainWindow::firstLevelIni()
{
    for(int i = 0; i< BRICKNUM;i++)
    {
        brick[i] = new obstacle;
    }
    //初始化地面
    for(int i = 0; i < GROUNDNUM; i++)
    {
        ground[i] = new obstacle;
        ground[i]->setType(1);
        ground[i]->setPosition(-700 + 200 * i,650);
        ground[i]->setWidthHeight(200,200);
        ground[i]->setData(1,2);
        pScene->addItem(ground[i]);
    }

    //初始化砖块
    nBrick(0,3,-200,370);
    nBrick(3,6,70,200);

    for(int i = 0; i < 3; i++)
    {
        newOb(brick[i+6],1,400 + 50 * i,400,50,50,2);
    }
    for(int i = 0; i < 3; i++)
    {
        newOb(brick[i+9],1,950 + 50 * i,400,50,50,2);
    }
    for(int i = 0; i < 3; i++)
    {
        newOb(brick[i+12],1,1500 + 300 * i,400 - 100 * i,50,50,2);
    }
    for(int i = 0; i < 3; i++)
    {
        newOb(brick[i+15],1,2500 + 300 * i,200 + 100 * i,50,50,2);
    }
    for(int i = 0; i < 2; i++)
    {
        newOb(brick[i+18],1,3500 + 50 * i,400,50,50,2);
    }
    newOb(brick[20],1,3750,200,50,50,2);
    for(int i = 0; i < 3; i++)
    {
        newOb(brick[i+21],1,4450 + 50 * i,270,50,50,2);
    }
    for(int i = 0; i < 2; i++)
    {
        newOb(brick[i+24],1,4800 + 50 * i,400,50,50,2);
    }
    newOb(brick[26],1,5150,200,50,50,2);

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
    coin[4]->setPosition(1800,250);
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

    coin[6] = new obstacle;
    coin[6]->setType(2);
    coin[6]->setPosition(4450,220);
    coin[6]->setWidthHeight(50,50);
    coin[6]->setShowFlag(1);
    coin[6]->setData(1,3);
    pScene->addItem(coin[6]);

    //初始化书
    book = new obstacle;
    book->setType(3);
    book->setPosition(6000,450);
    book->setWidthHeight(160,200);
    book->setData(1,4);
    pScene->addItem(book);

    //初始化云
    for(int i = 0; i < 3; i++)
    {
        cloud[i] = new obstacle;
        cloud[i]->setType(4);
        cloud[i]->setPosition(-700 + (SCREENWIDTH / 3) * i,0);
        cloud[i]->setWidthHeight(100,50);
        pScene->addItem(cloud[i]);
    }

    //初始化主楼
    h = new obstacle;
    h->setType(5);
    h->setPosition(0,450);
    h->setWidthHeight(200,200);
    h->setData(1,5);
    pScene->addItem(h);

    //初始化角色
    item = new player;
    item->setFlag(QGraphicsItem::ItemIsFocusable);  //鼠标选中这个item之后就是聚焦, 然后可以用键盘控制这个item
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setPosition(-700,500);
    pScene->addItem(item);
    pScene->setFocusItem(item);

    // 将 item 添加至场景中
    // 为视图设置场景


    pView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    pView->resize(SCREENWIDTH,SCREENHEIGHT);
    pView->setScene(pScene);
    pView->setStyleSheet("border:none; background:black;");
    pView->centerOn(0,0);
    pView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //背景移动
    connect(item,&player::BackGroundMove,[=](){
        for (int i = 0; i < BRICKNUM; i++)
        {

            brick[i]->obPosX-=3;
            brick[i]->update(brick[i]->obPosX,brick[i]->obPosY,brick[i]->obWidth,brick[i]->obHeight);

        }
        for (int i = 0; i < COINNUM; i++)
        {
            //coin[i]->moveBy(-3,0);
            coin[i]->obPosX-=3;
            coin[i]->update(coin[i]->obPosX,coin[i]->obPosY,coin[i]->obWidth,coin[i]->obHeight);
        }
        book->obPosX-=3;
        book->update(book->obPosX,book->obPosY,book->obWidth,book->obHeight);

    });

    //胜利
    connect(item,&player::succeed,[=](){
        pView->close();
         QMessageBox::about(this,"Victory","你赢了!");
        this->close();
    });
    connect(item,&player::failed,[=](){
        pView->close();
         QMessageBox::about(this,"Defeated","你输了!");
        this->close();
    }
    );
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{


}
void MainWindow::newOb(obstacle *one, int type, int x, int y, int w, int h, int data)
{
    //one = new obstacle;
    one->setType(type);
    one->setPosition(x,y);
    one->setWidthHeight(w,h);
    one->setData(1,data);
    pScene->addItem(one);
}
void MainWindow::deleteOb()
{
    //获得指定矩形区域内的元素的指针列表
    QList<QGraphicsItem *> item_list_p = pView->scene()->items(QRectF(-1000,0,200,800), Qt::IntersectsItemShape);
    //删除元素
    for(int i=0; i<item_list_p.size(); i++)
    {
        pView->scene()->removeItem(item_list_p[i]);  //从scene移除
        delete item_list_p[i];  //释放内存
    }
}
void MainWindow::nBrick(int begin,int end,int x,int y)
{
    for(int i = begin; i < end; i++)
    {
        newOb(brick[i],1,x+50*i,y,50,50,2);
    }
}

