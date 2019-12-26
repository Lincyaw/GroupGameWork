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
    int count = 0;
    connect(coin[0]->GroundTimer,&QTimer::timeout,[=](){
        count++;
        if(count%2)
        {
            for(int i = 0;i < GROUNDNUM; i++)
            {
                ground[i]->type = 3;
                ground[i]->showflag = 0;
            }
        }
    });

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
    for(int i = 0; i <  BRICKNUM; i++)
    {
        brick[i] = new obstacle;
    }
    //初始化地面
    for(int i = 0; i < GROUNDNUM; i++)
    {
        ground[i] = new obstacle;
        ground[i]->setType(1);
       // ground[i]->setPosition(-700 + 200 * i,650);
        ground[i]->setPos(-700 + 200 * i,650);
        ground[i]->setWidthHeight(400,200);
        ground[i]->setData(1,2);
        pScene->addItem(ground[i]);
    }


    //初始化砖块
    nBrick(0,2,-200,570);
    nBrick(2,4,0,470);
    nBrick(4,6,200,370);
    nCoin(0,1,200,320);
    coin[0]->magic = 1;
 //   nBrick(4,6,200,370);

//    //初始化书
//    book = new obstacle;
//    book->setType(3);
//    //book->setPosition(10000,450);
//    book->setPos(10000,450);
//    book->setWidthHeight(160,200);
//    book->setData(1,4);
//    pScene->addItem(book);

//    //初始化云
//    for(int i = 0; i < CLOUDNUM; i++)
//    {
//        cloud[i] = new obstacle;
//        cloud[i]->setType(4);
//        //cloud[i]->setPosition(-700 + (SCREENWIDTH / 3) * i,0);
//        cloud[i]->setPos(-700 + (SCREENWIDTH / 3) * i,0);
//        cloud[i]->setWidthHeight(100,50);
//        pScene->addItem(cloud[i]);
//    }

//    //初始化主楼
//    h = new obstacle;
//    h->setType(5);
//  //  h->setPosition(50,450);
//    h->setPos(50,450);
//    h->setWidthHeight(200,200);
//    h->setData(1,5);
//    pScene->addItem(h);

//    //初始化会动的砖
//    for(int i = 0; i < 3; i++)
//    {
//        mbrick[i] = new obstacle;
//        mbrick[i]->setType(6);
//        mbrick[i]->setPosition(9300 + 600 * i,200);
//        mbrick[i]->setWidthHeight(50,50);
//        mbrick[i]->setData(1,2);
//        pScene->addItem(mbrick[i]);
//    }

//    for(int i = 0; i < 3; i++)
//    {
//        mbrick[i+3] = new obstacle;
//        mbrick[i+3]->setType(6);
//        mbrick[i+3]->setPosition(9600 + 600 * i,400);
//        mbrick[i+3]->setWidthHeight(50,50);
//        mbrick[i+3]->setData(1,2);
//        pScene->addItem(mbrick[i+3]);
//    }

//    for(int i = 0; i < 3; i++)
//    {
//        mbrick[i+6] = new obstacle;
//        mbrick[i+6]->setType(6);
//        mbrick[i+6]->setPosition(10900 + 1200 * i,300);
//        mbrick[i+6]->setWidthHeight(50,50);
//        mbrick[i+6]->setData(1,2);
//        pScene->addItem(mbrick[i+6]);
//    }

//    for(int i = 0; i < 3; i++)
//    {
//        mbrick[i+9] = new obstacle;
//        mbrick[i+9]->setType(6);
//        mbrick[i+9]->setPosition(11200 + 600 * i,380);
//        mbrick[i+9]->setWidthHeight(50,50);
//        mbrick[i+9]->setData(1,2);
//        pScene->addItem(mbrick[i+9]);
//    }

//    for(int i = 0; i < 3; i++)
//    {
//        mbrick[i+12] = new obstacle;
//        mbrick[i+12]->setType(6);
//        mbrick[i+12]->setPosition(11500 + 900 * i,180);
//        mbrick[i+12]->setWidthHeight(50,50);
//        mbrick[i+12]->setData(1,2);
//        pScene->addItem(mbrick[i+12]);
//    }

    //初始化作业
//    homework = new obstacle;
//    homework->setType(7);
//    homework->setPosition(5500,450);
//    homework->setWidthHeight(200,200);
//    homework->setData(1,6);
//    pScene->addItem(homework);

    //初始化角色
    item = new player;
    item->setFlag(QGraphicsItem::ItemIsFocusable);  //鼠标选中这个item之后就是聚焦, 然后可以用键盘控制这个item
    item->setFlag(QGraphicsItem::ItemIsMovable);
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
        qDebug()<<brick[1]->pos();
        for (int i = 0; i < BRICKNUM; i++)
        {
            brick[i]->moveBy(-3,0);
          //  brick[i]->obPosX-=3;
           // update(brick[i]->obPosX,brick[i]->obPosY,brick[i]->obWidth,brick[i]->obHeight);
        }
//        for (int i = 0; i < COINNUM; i++)
//        {
//            coin[i]->moveBy(-3,0);
           // coin[i]->obPosX-=3;
           // update(coin[i]->obPosX,coin[i]->obPosY,coin[i]->obWidth,coin[i]->obHeight);
//        }
//        book->obPosX-=3;
//        book->moveBy(-3,0);
        //update(book->obPosX,book->obPosY,book->obWidth,book->obHeight);
//        for (int i = 0; i < 3; i++)
//        {
//            mbrick[i]->obPosX-=3;
//            update(mbrick[i]->obPosX,mbrick[i]->obPosY,mbrick[i]->obWidth,mbrick[i]->obHeight);
//        }
       // homework->obPosX-=3;
//        homework->moveBy(-3,0);
        //update(homework->obPosX,homework->obPosY,homework->obWidth,homework->obHeight);
    });

    //胜利
    connect(item,&player::succeed,[=](){
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
//    one->setPosition(x,y-300);
    one->setPos(x,y-300);
    one->setWidthHeight(w,h);
    one->setData(1,data);
    one->setPos(x,y);
    pScene->addItem(one);
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
        newOb(coin[i],2,x + 50 * (i - begin),y,50,50,3);
    }
}
