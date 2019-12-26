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
    for(int i = 0; i < GROUNDNUM; i++)
    {
        ground[i] = new obstacle;
        ground[i]->setType(1);
       // ground[i]->setPosition(-700 + 200 * i,650);
        ground[i]->setPos(-400+i*150,650);
        ground[i]->setWidthHeight(300,200);
        ground[i]->setData(1,2);
        pScene->addItem(ground[i]);
    }


    for(int i = 0; i <  BRICKNUM; i++)
    {
        brick[i] = new obstacle;
    }
    //初始化砖块
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

    //初始化云
    for(int i = 0; i < CLOUDNUM; i++)
    {
        cloud[i] = new obstacle;
        cloud[i]->setType(4);
        cloud[i]->setPos(-375 + 250 * i,300);
        cloud[i]->setWidthHeight(100,50);
        pScene->addItem(cloud[i]);
    }

    //初始化会动的砖
    for(int i = 0; i < 3; i++)
    {
        mbrick[i] = new obstacle;
        mbrick[i]->setType(6);
        mbrick[i]->setPos(3000 + 600 * i,550);
        mbrick[i]->setWidthHeight(50,50);
        mbrick[i]->setData(1,2);
        mbrick[i]->moveFlag = 0;
        pScene->addItem(mbrick[i]);
    }



    //初始化金币w
    for(int i = 0; i <  COINNUM; i++)
    {
        coin[i] = new obstacle;
    }
    nCoin(0,3,0,445);
    coin[0]->magic = 1;
	
	
	
	
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
    Cups[5] = new javacup(nullptr,1200,900,20,0,3,0);
    Cups[6] = new javacup(nullptr,1700,750,60,0,3,0);
    Cups[7] = new javacup(nullptr,1950,900,50,0,3,0);
    Cups[8] = new javacup(nullptr,2300,1000,40,0,3,0);
    Cups[9] = new javacup(nullptr,2500,800,30,0,3,0);

    Cups[10] = new javacup(nullptr,900,700,40,0,3,0);
    Cups[11] = new javacup(nullptr,1200,850,40,0,3,0);
    Cups[12] = new javacup(nullptr,400,1000,40,0,3,0);
    Cups[13] = new javacup(nullptr,900,1300,40,0,3,0);
    Cups[14] = new javacup(nullptr,100,1400,40,0,3,0);

    for(int i = 0; i < CupNum; i++)
    {
        pScene->addItem(Cups[i]);
        Cups[i]->setRangeXY(40,40);
        Cups[i]->setVerticalV(2+i%3);
        Cups[i]->setHorizontalV(2+i%3);
        Cups[i]->MoveMode = (i+2)%5+1;
        if(i>9)
        {
            Cups[i]->HeroSkin = QPixmap(":/C++/C++.png");
            Cups[i]->HeroNormalSkin = QPixmap(":/C++/C++.png");
            Cups[i]->HeroBeAttackedSkin = QPixmap(":/C++/CBeAttacked.png");
            Cups[i]->PicWidth = 48;
            Cups[i]->PicHeight = 54;
            Cups[i]->setRangeXY(70,70);

        }
    }
//    for(int i = 0; i < PlusNum; i++)
//    {
//        pScene->addItem(plus[i]);
//        plus[i]->setRangeXY(40,40);
//        plus[i]->setVerticalV(4+(i%4));
//        plus[i]->setHorizontalV(5+(i%4));
//        plus[i]->MoveMode = i%3 + 1;
//    }


    //连接攻击信号与怪物信号
    for(int i = 0; i < CupNum; i++)
    {
        connect(item,&player::Skill0,Cups[i],&javacup::AttackedByJ);
        connect(item,&player::Skill1,Cups[i],&javacup::AttackedByK);
        connect(item,&player::Skill2,Cups[i],&javacup::AttackedByL);
    }
//    for(int i = 0; i < PlusNum; i++)
//    {
//        connect(item,&player::Skill0,plus[i],&Cpp::AttackedByJ);
//        connect(item,&player::Skill1,plus[i],&Cpp::AttackedByK);
//        connect(item,&player::Skill2,plus[i],&Cpp::AttackedByL);
//    }
    // 将 item 添加至场景中
    // 为视图设置场景

    QFont font;
    font.setKerning(true);
    font.setBold(true);
    text->setPlainText("血量:"+QString::number(item->heroBlood));
    text->setPos(-700,500);
    text->setFont(font);
    pScene->addItem(text);
    connect(item,&player::DecBlood,[=](){
        text->setPlainText("血量:"+QString::number(item->heroBlood));
        text->update();
    });
    pView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    pView->resize(SCREENWIDTH,SCREENHEIGHT);
    pView->setScene(pScene);
    pView->setStyleSheet("border:none; background:white;");
    pView->centerOn(0,0);
    pView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //背景移动
    connect(item,&player::BackGroundMove,[=](){
        //qDebug()<<brick[1]->pos();

        for (int i = 0; i < BRICKNUM; i++)
        {
            brick[i]->moveBy(-2,0);
            if(brick[i]->pos().x()<-500)
            {
                pScene->removeItem(brick[i]);

            }
        }

        for (int i = 0; i < 3; i++)
        {
            coin[i]->moveBy(-2,0);
        }

        for (int i = 0; i < 3; i++)
        {
            mbrick[i]->moveBy(-2,0);
        }

        for (int i = 0; i < CupNum; i++)
        {
            Cups[i]->moveBy(-3,0);
        }



    });
    connect(coin[0]->groundTimer,&QTimer::timeout,[=](){

        k++;
        if(k==3)
        {
            k=0;
        }
        for(int i = 0;i<GROUNDNUM;i++)
        {
            if(count%2==0&&(i+1)%2==k)
            {
                pScene->removeItem(ground[i]);
                pScene->update();
            }
            else
            {
                pScene->addItem(ground[i]);
                pScene->update();
            }

        }
         count++;
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
        newOb(coin[i],2,x + 25 * (i - begin),y,50,50,3);
    }
}
QList<int> MainWindow::generateUniqueRandomNumber()
{
    int i,j;
    QList<int> numbersList;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for(i=0;i<8;i++)
    {
        numbersList.append(qrand()%8);
        bool flag = true;
        while(flag)
        {
            for(j=0;j<i;j++)
            {
                if(numbersList[i]==numbersList[j])
                {
                    break;
                }
                if(j<i)
                {
                    numbersList[i]=rand()%8;
                }
                if(j==i)
                {
                    flag=!flag;
                }
            }
        }
        for(i=0;i<8;i++)
        {
            qDebug()<<numbersList[i];
        }
        return numbersList;
    }
}
