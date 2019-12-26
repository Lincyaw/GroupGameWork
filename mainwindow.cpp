#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(700,700);
    setWindowIcon(QIcon(":/m/back/hit.png"));
    setWindowTitle("SuperHiter");
    MyPushButton * startBtn = new MyPushButton(":/m/back/knife.png");
    startBtn->setParent(this);
    startBtn->move(this->width() * 0.5 - 80 * 0.5 ,this->height() * 0.6 );

    connect(startBtn,&MyPushButton::clicked,[=](){
        //qDebug() << "点击了开始";
        //做弹起特效
        startBtn->zoom1();
        startBtn->zoom2();

        //显示选择关卡场景
        // pView->show();

        QMessageBox::information(this,"游戏提示",
                                 "WAD控制角色左右移动和上下移动\nJKL释放技能\n打败怪兽有大量积分哦!!!"
                                 );
        if(clickedTimes==0)
        {
            //BGM->play();

            myPlayer->setMedia(QUrl("qrc:/m/back/bgm.mp3"));
            myPlayer->setVolume(80);
            myPlayer->play();
            firstLevelIni();
            this->hide();
            pView->show();
            clickedTimes++;
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
//    for(int i = 0; i <  COINNUM; i++)
//    {
        coin[0] = new obstacle(nullptr,0);
        coin[1] = new obstacle(nullptr,1);
        coin[2] = new obstacle(nullptr,2);
        coin[3] = new obstacle(nullptr,0);
        coin[4] = new obstacle(nullptr,1);
        coin[5] = new obstacle(nullptr,2);
//    }
    nCoin(0,2,0,410);
    coin[0]->magic = 1;
    nCoin(2,3,600,310);
    nCoin(3,4,900,310);
    nCoin(4,5,1300,510);
    nCoin(5,6,1700,510);
    for(int i = 0; i <  COINNUM; i++)
    {
        connect(coin[i],&obstacle::GetCoin,[=](){
            item->Score+=20;
            if(item->Score>100)
            {
                item->Score-=100;
                item->heroBlood+=5;
            }
            emit item->DecBlood();
        });
    }

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

    //初始化树
    for(int i = 0; i < TREENUM; i++)
    {
        tree[i] = new obstacle;
        tree[i]->setType(8);
        tree[i]->setPos(-375 + 150 * i,600);
        tree[i]->setWidthHeight(100,100);
        pScene->addItem(tree[i]);
    }


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
    Cups[5] = new javacup(nullptr,1200,900,20,0,3,0);
    Cups[6] = new javacup(nullptr,1700,750,60,0,3,0);
    Cups[7] = new javacup(nullptr,1950,900,50,0,3,0);
    Cups[8] = new javacup(nullptr,2300,1000,40,0,3,0);
    Cups[9] = new javacup(nullptr,2500,800,30,0,3,0);
    Cups[10] = new javacup(nullptr,900,700,40,0,3,0);
    Cups[11] = new javacup(nullptr,1200,850,40,0,3,0);
    Cups[12] = new javacup(nullptr,2600,1000,40,0,3,0);
    Cups[13] = new javacup(nullptr,2700,1300,40,0,3,0);

    Cups[14] = new javacup(nullptr,800,1400,40,0,3,0);
    Cups[15] = new javacup(nullptr,900,1400,40,0,3,0);
    Cups[16] = new javacup(nullptr,1000,1400,40,0,3,0);
    Cups[17] = new javacup(nullptr,1200,1400,40,0,3,0);
    Cups[18] = new javacup(nullptr,1700,1400,40,0,3,0);
    Cups[19] = new javacup(nullptr,1400,1400,40,0,3,0);
    Cups[20] = new javacup(nullptr,2300,1400,40,0,3,0);
    Cups[21] = new javacup(nullptr,1900,1400,40,0,3,0);
    Cups[22] = new javacup(nullptr,2400,1400,40,0,3,0);
    Cups[23] = new javacup(nullptr,1600,1400,40,0,3,0);
    Cups[24] = new javacup(nullptr,2700,1400,40,0,3,0);

    for(int i = 0; i < CupNum; i++)
    {
//        Cups[i] = new javacup;
        pScene->addItem(Cups[i]);
        Cups[i]->setPosition(Cups[i]->BornPosX,(i%5)+800);
        Cups[i]->setRangeXY(40+10*(i%4),40+10*(i%4));
        Cups[i]->setVerticalV(2+i%3);
        Cups[i]->setHorizontalV(2+i%3);
        Cups[i]->MoveMode = (i+2)%5+1;
        if(i>13)
        {
            Cups[i]->HeroSkin = QPixmap(":/C++/C++.png");
            Cups[i]->HeroNormalSkin = QPixmap(":/C++/C++.png");
            Cups[i]->HeroBeAttackedSkin = QPixmap(":/C++/CBeAttacked.png");
            Cups[i]->PicWidth = 48;
            Cups[i]->PicHeight = 54;
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
        connect(Cups[i],&javacup::BeKilled,[=](){
            item->Score+=50;
            if(item->Score>100)
            {
                item->Score-=100;
                item->heroBlood+=5;
            }
            emit item->DecBlood();
        });
    }
    // 将 item 添加至场景中
    // 为视图设置场景


    QFont font;
    font.setKerning(true);
    font.setBold(true);
    text->setPlainText("血量:"+QString::number(item->heroBlood)+"\n积分:"+QString::number(item->Score));
    text->setPos(-700,500);
    text->setFont(font);
    pScene->addItem(text);
    connect(item,&player::DecBlood,[=](){
        text->setPlainText("血量:"+QString::number(item->heroBlood)+"\n积分:"+QString::number(item->Score));
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
        for (int i = 0; i < BRICKNUM; i++)
        {
            brick[i]->moveBy(-2,0);
//            if(brick[i]->pos().x()<-500)
//            {
//                pScene->removeItem(brick[i]);

//            }
        }

        for (int i = 0; i < COINNUM; i++)
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

        for (int i = 0; i < CupNum; i++)
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
        newOb(coin[i],2,x + 40 * (i - begin),y,80,120,3);
    }
}


void MainWindow::nmBrick(int begin, int end, int x, int y)
{
    for(int i = begin; i < end; i++)
    {
        newOb(mbrick[i],6,x + 600 * (i - begin),y,50,50,2);
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
    }
        for(i=0;i<8;i++)
        {
            qDebug()<<numbersList[i];
        }
        return numbersList;
}
