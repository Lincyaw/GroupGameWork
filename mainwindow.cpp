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
//    connect(coin[0]->groundTimer,&QTimer::timeout,[=](){
//        for(int i = 0;i<1;i++)
//        {
//            if(count%2)
//            {
//                ground[i]->showflag = 1;
//            }
//            else
//            {
//                ground[i]->showflag = 0;
//            }

//        }
//       // count++;
//    });
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

    coin[0] = new obstacle;
    nCoin(0,1,200,345);
    coin[0]->magic = 1;
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
        //qDebug()<<brick[1]->pos();
        for (int i = 0; i < BRICKNUM; i++)
        {
            brick[i]->moveBy(-2,0);
        }
        coin[0]->moveBy(-2,0);
    });

    //胜利
    connect(item,&player::succeed,[=](){
        pView->close();
        QMessageBox::about(this,"Victory","你赢了!");
    });
    connect(item,&player::failed,[=](){

        pView->close();
        QMessageBox::about(this,"Defeated","你输了!\n再来一次吧!奥利给!!!!");
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
