#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(400,400);
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
    //初始化地面
    for(int i = 0; i <  GROUNDNUM; i++)
    {
        ground[i] = new obstacle;
    }
    nGround(0,GROUNDNUM,-400,650);

    //初始化砖块
    for(int i = 0; i <  BRICKNUM; i++)
    {
        brick[i] = new obstacle;
    }
    nBrick(0,2,-200,570);
    nBrick(2,4,0,470);
    nBrick(4,5,200,370);
    nBrick(5,7,500,380);
    nBrick(7,8,600,580);
    nBrick(8,10,700,480);
    nBrick(10,11,900,370);
    nBrick(11,12,1100,470);
    nBrick(12,13,1300,570);
    nBrick(13,14,1500,470);
    nBrick(14,15,1700,570);
    nBrick(16,17,1900,470);
    nBrick(17,18,2100,370);

    //初始化金币
    for(int i = 0; i <  COINNUM; i++)
    {
        coin[i] = new obstacle;
    }
    nCoin(0,3,0,445);
    coin[0]->magic = 1;
    nCoin(3,4,800,345);

    //初始化书
    book = new obstacle;
    newOb(book,3,2500,550,180,200,4);

    //初始化云
    for(int i = 0; i < CLOUDNUM; i++)
    {
        cloud[i] = new obstacle;
        cloud[i]->setType(4);
        cloud[i]->setPos(-375 + 250 * i,300);
        cloud[i]->setWidthHeight(100,50);
        pScene->addItem(cloud[i]);
    }

    //初始化主楼
    h = new obstacle;
    newOb(h,5,2600,550,180,200,5);

    //初始化会动的砖
    for(int i = 0; i <  MBRICKNUM; i++)
    {
        mbrick[i] = new obstacle;
    }
    nmBrick(0,3,3000,550);

//    //初始化作业
//    homework = new obstacle;
//    newOb(homework,7,550,550,180,200,6);
	
    //初始化角色
    item = new player;
    item->setFlag(QGraphicsItem::ItemIsFocusable);  //鼠标选中这个item之后就是聚焦, 然后可以用键盘控制这个item
    item->setFlag(QGraphicsItem::ItemIsMovable);
    pScene->addItem(item);
    pScene->setFocusItem(item);


    ///初始化怪物*************************************************
    Cups[0] = new javacup(nullptr,-250,900,40,0,3,0);
    Cups[1] = new javacup(nullptr,0,800,40,0,3,0);
    Cups[2] = new javacup(nullptr,100,700,40,0,3,0);
    Cups[3] = new javacup(nullptr,400,600,40,0,3,0);
    Cups[4] = new javacup(nullptr,900,700,40,0,3,0);
    Cups[5] = new javacup(nullptr,1200,900,40,0,3,0);
    Cups[6] = new javacup(nullptr,1700,750,40,0,3,0);
    Cups[7] = new javacup(nullptr,1950,900,40,0,3,0);
    Cups[8] = new javacup(nullptr,2300,1000,40,0,3,0);
    Cups[9] = new javacup(nullptr,2500,800,40,0,3,0);
    for(int i = 0; i < 10; i++)
    {
        pScene->addItem(Cups[i]);
    }



    //连接攻击信号与怪物信号
    for(int i = 0; i < CupNum; i++)
    {
        connect(item,&player::Skill0,Cups[i],&javacup::AttackedByJ);
        connect(item,&player::Skill1,Cups[i],&javacup::AttackedByK);
        connect(item,&player::Skill2,Cups[i],&javacup::AttackedByL);
    }

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
            brick[i]->moveBy(-2,0);
//            if(brick[i]->pos().x()<-500)
//            {
//                pScene->removeItem(brick[i]);

//            }
        }

        for (int i = 0; i < 4; i++)
        {
            coin[i]->moveBy(-2,0);
        }

        book->moveBy(-2,0);
        h->moveBy(-2,0);
//        homework->moveBy(-2,0);

        for (int i = 0; i < 3; i++)
        {
            mbrick[i]->moveBy(-2,0);
        }

        for (int i = 0; i < 10; i++)
        {
            Cups[i]->moveBy(-3,0);
        }

    });

    connect(coin[0]->groundTimer,&QTimer::timeout,[=](){
        for(int i = 0;i<GROUNDNUM;i++)
        {
            if(count%2==0)
            {
                pScene->removeItem(ground[i]);
                pScene->update();
                qDebug()<<"showflag=2";
                ground[i]->setData(1,2);
            }
            else
            {
                pScene->addItem(ground[i]);
                ground[i]->setData(1,1);
                pScene->update();
               qDebug()<<"showflag=1";
            }

        }
         count++;
    });

    //胜利
    connect(item,&player::succeed,[=](){
        pView->close();
        QMessageBox::about(this,"Victory","你赢了!");
    });

    //失败
    connect(item,&player::failed,[=](){

        pView->close();
        QMessageBox::about(this,"Defeated","你输了!\n再来一次吧!奥利给!!!!");
        this->close();
    });
    connect(item,&player::failed,[=](){
        pView->close();
        this->close();
    });
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{


}

void MainWindow::newOb(obstacle *one, int type, int x, int y, int w, int h, int data)
{
    one->setType(type);
    one->setPos(x,y-300);
    one->setWidthHeight(w,h);
    one->setData(1,data);
    one->setPos(x,y);
    pScene->addItem(one);
}

void MainWindow::nGround(int begin, int end, int x, int y)
{
    for(int i = begin; i < end; i++)
    {
        newOb(ground[i],0,x + 150 * (i - begin),y,300,200,2);
    }
}

void MainWindow::nBrick(int begin, int end, int x, int y)
{
    for(int i = begin; i < end; i++)
    {
        newOb(brick[i],1,x + 50 * (i - begin),y,100,50,2);
    }
}

void MainWindow::nCoin(int begin, int end, int x, int y)
{
    for(int i = begin; i < end; i++)
    {
        newOb(coin[i],2,x + 25 * (i - begin),y,50,50,3);
    }
}

void MainWindow::nmBrick(int begin, int end, int x, int y)
{
    for(int i = begin; i < end; i++)
    {
        newOb(mbrick[i],6,x + 600 * (i - begin),y,50,50,2);
    }
}
