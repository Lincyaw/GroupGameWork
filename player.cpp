#include "player.h"
player::player(QObject *parent) : QObject(parent)
{
    setToolTip("憨憨!");//提示
    setCursor(Qt::OpenHandCursor);
    PicWidth = 46;
    PicHeight = 56;
    color = QColor(qrand()%256,qrand()%256,qrand()%256);
    connect(JumpTimer,&QTimer::timeout,[=](){
        FreeFalling();
        if(collidingItems().isEmpty())
        {
         update(heroPosX-50, heroPosY-50,46+100, 156);
        }
    });

    connect(KeyTimer,&QTimer::timeout,[=](){
        if(KeyPressed(Key_W))
        {
            Direction = up;
            JumpOrnot = true;
            setVelocity(8);
        }
        if(KeyPressed(Key_A))
        {
             HorizontalDir = left;
             heroPosX-=HorizontalSpeed;
             moveBy(-HorizontalSpeed,0);  //相对现在的位置移动
             if(!SkillTimer1->isActive()&&!SkillTimer0->isActive()&&!SkillTimer2->isActive())
             {
                 PicWidth = 46;
                 PicHeight = 56;
                 RunSkinCounter--;
                 switch(RunSkinCounter)
                 {
                     case 0:
                         HeroSkin = HeroRunSkin1;
                         RunSkinCounter = 60;
                        // qDebug()<<"0001";
                         break;
                     case 10:
                         HeroSkin = HeroRunSkin2;
                        // qDebug()<<"0002";
                         break;
                     case 20:
                         HeroSkin = HeroRunSkin3;
                         //qDebug()<<"0003";
                         break;
                     case 30:
                         HeroSkin = HeroRunSkin4;
                        // qDebug()<<"0004";
                         break;
                     case 40:
                         HeroSkin = HeroRunSkin5;
                         //qDebug()<<"0005";
                     case 50:
                         HeroSkin = HeroRunSkin0;
                         break;
                 default:
                     break;
                 }
             }
        }
        if(KeyPressed(Key_D))
        {
            HorizontalDir = right;
            if(heroPosX<-500)
            {
              moveBy(HorizontalSpeed,0);  //相对现在的位置移动
               heroPosX+=HorizontalSpeed;
            }
            else
            {
                emit BackGroundMove();
            }
            if(!SkillTimer1->isActive()&&!SkillTimer0->isActive()&&!SkillTimer2->isActive())
            {
                PicWidth = 46;
                PicHeight = 56;
                RunSkinCounter++;
                switch(RunSkinCounter)
                {
                    case 0:
                        HeroSkin = HeroRunSkin1;
                       // qDebug()<<"0001";
                        break;
                    case 10:
                        HeroSkin = HeroRunSkin2;
                       // qDebug()<<"0002";
                        break;
                    case 20:
                        HeroSkin = HeroRunSkin3;
                        //qDebug()<<"0003";
                        break;
                    case 30:
                        HeroSkin = HeroRunSkin4;
                       // qDebug()<<"0004";
                        break;
                    case 40:
                        HeroSkin = HeroRunSkin5;
                        //qDebug()<<"0005";
                        break;
                    case 50:
                        HeroSkin = HeroRunSkin0;
                        break;
                    case 60:
                        RunSkinCounter=-10;
                      break;
                default:
                    break;
                }
            }
        }
        if(KeyPressed(Key_K)&&!SkillTimer0->isActive()&&!SkillTimer2->isActive())
        {
            SkillCounter = 0;
            SkillTimer1->start(100);
        }
        if(KeyPressed(Key_J)&&!SkillTimer1->isActive()&&!SkillTimer2->isActive())
        {
            SkillCounter = 0;
            SkillTimer0->start(100);
        }
        if(KeyPressed(Key_L)&&!SkillTimer1->isActive()&&!SkillTimer0->isActive())
        {
            SkillCounter = 0;
            SkillTimer2->start(100);
        }
    });
    connect(SkillTimer0,&QTimer::timeout,[=](){
        if(!SkillTimer1->isActive()&&!SkillTimer2->isActive())
        {
            emit Skill0();
            PicWidth = 100;
            PicHeight = 90;
            heroPosY-=5;
            switch (SkillCounter) {
            case 0:
                HeroSkin = Attack30;
                break;
            case 1:
                HeroSkin = Attack31;
                break;
            case 2:
                HeroSkin = Attack32;
                break;
            case 3:
                HeroSkin = Attack33;
                break;
            case 4:
                HeroSkin = Attack34;
                break;
            case 5:
                HeroSkin = Attack35;
                break;
            case 6:
                SkillTimer0->stop();
                 break;
            default:
                break;
            }
            SkillCounter++;
        }

    });
    connect(SkillTimer1,&QTimer::timeout,[=](){
        if(!SkillTimer0->isActive()&&!SkillTimer2->isActive())
        {
        emit Skill1();
        PicWidth = 100;
        PicHeight = 90;
        heroPosY-=5;
        switch (SkillCounter) {
        case 0:
            HeroSkin = Attack40;
            break;
        case 1:
            HeroSkin = Attack41;
            break;
        case 2:
            HeroSkin = Attack42;
            break;
        case 3:
            HeroSkin = Attack43;
            break;
        case 4:
            HeroSkin = Attack44;
            break;
        case 5:
            HeroSkin = Attack45;
            break;
        case 6:
            SkillTimer1->stop();
            break;
        default:
            break;
        }
        SkillCounter++;
        }
    });
    connect(SkillTimer2,&QTimer::timeout,[=](){
        if(!SkillTimer0->isActive()&&!SkillTimer1->isActive())
        {
        emit Skill2();
        PicWidth = 100;
        PicHeight = 90;
        heroPosY-=5;
        switch (SkillCounter) {
        case 0:
            HeroSkin = Attack00;
            break;
        case 1:
            HeroSkin = Attack01;
            break;
        case 2:
            HeroSkin = Attack02;
            break;
        case 3:
            HeroSkin = Attack03;
            break;
        case 4:
            HeroSkin = Attack10;
            break;
        case 5:
            HeroSkin = Attack11;
            break;
        case 6:
            HeroSkin = Attack12;
            break;
        case 7:
            HeroSkin = Attack50;
            break;
        case 8:
            HeroSkin = Attack51;
            break;
        case 9:
            HeroSkin = Attack50;
            break;
        case 10:
            HeroSkin = Attack51;
            break;
        case 11:
            SkillTimer2->stop();
            break;
        default:
            break;
        }
        SkillCounter++;
        }
    });
    JumpTimer->start(15);
    KeyTimer->start(10);
    setPosition(-700,0);
    setData(1,1);
    setVelocity(0);
}
QRectF player::boundingRect()const
{
    qreal penWidth = 1;
    return QRectF(heroPosX-penWidth / 2, heroPosY - penWidth/2,PicWidth+penWidth, PicHeight+penWidth);
}
void player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    //painter->setBrush(!collidingItems().isEmpty()? Qt::red : Qt::green);
   // painter->drawRect(0,0,20,20);
   // painter->drawRect(0,50,30,20);
    //如果与其他图形项碰撞则显示红色，否则显示绿色

    painter->drawPixmap(heroPosX,heroPosY,PicWidth,PicHeight,HeroSkin);

}
void player::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::ClosedHandCursor);
    //moveBy(10,0);

}
void player::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
}
void player::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
}
void player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W && !JumpOrnot)
    {
        SaveKeyPressed(Key_W);
    }
    if(event->key() == Qt::Key_A)
    {
        SaveKeyPressed(Key_A);
    }
    if(event->key() == Qt::Key_D)
    {
        SaveKeyPressed(Key_D);
    }
    if(event->key() == Qt::Key_S)
    {
        heroPosY+=HorizontalSpeed;
        moveBy(0,HorizontalSpeed);  //相对现在的位置移动
    }
    if(event->key() == Qt::Key_J)
    {
        SaveKeyPressed(Key_J);
    }
    if(event->key() == Qt::Key_K)
    {
        SaveKeyPressed(Key_K);
    }
    if(event->key() == Qt::Key_L)
    {
        SaveKeyPressed(Key_L);
    }
}
void player::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A)
    {
        SaveKeyReleased(Key_A);
    }
    if(event->key()==Qt::Key_W)
    {
        SaveKeyReleased(Key_W);
    }
    if(event->key()==Qt::Key_D)
    {
        SaveKeyReleased(Key_D);
    }
    if(event->key()==Qt::Key_J)
    {
        SaveKeyReleased(Key_J);
    }
    if(event->key()==Qt::Key_K)
    {
        SaveKeyReleased(Key_K);
    }
    if(event->key()==Qt::Key_L)
    {
        SaveKeyReleased(Key_L);
    }


}
void player::FreeFalling(void)
{
    int i;
    if(Velocity<=0)
    {
        Direction = down;
    }
    else if(Velocity>0)
    {
        Direction = up;
    }
    if(Direction == up || collidingItems().isEmpty())
    {
        heroPosY-=Velocity;
        Velocity=0.7*Velocity-Gravity;
    }
    if(!collidingItems().isEmpty())
    {
        collided();
        for(i = 0;i < collidingItems().length(); i++)
        {
            if(collidingItems().at(i)->data(1).toInt()==2 && Direction == down)
            {
                heroPosY-=1;
                JumpOrnot = false;
                UnderBrick = false;
                Velocity=0;
            }
            else if(collidingItems().at(i)->data(1).toInt()==2 && (Direction == up))
            {
                heroPosY+=Velocity;
                UnderBrick = true;
            }
            else
            {
                JumpOrnot = true;
                UnderBrick = false;
            }
        }
        if(JumpOrnot)
        {
            heroPosY-=Velocity;
            Velocity-=Gravity;
        }
        if(UnderBrick)//如果向上跳跃的时候碰到了砖头
        {
            if(Velocity>0)
            {
                Velocity =  0 - Velocity;
            }
            heroPosY-=Velocity;//让人往下掉
            Velocity=(0.8*Velocity-Gravity);
        }
    }
    else
    {
        notcollided();
    }

//    if(collidingItems().at(i)->data(2).toInt()==0&&!SkillTimer1->isActive()&&!SkillTimer0->isActive()&&!SkillTimer2->isActive())
//    {//遭遇怪兽并且人物没有在放技能
//        heroBlood-=1;
//        //if(heroBlood==0)
//        //{
//        //   gameover
//        //}
//    }

    return;
}
void player::setPosition(int x,int y)
{
    heroPosX = x;
    heroPosY = y;
}
void player::setVelocity(int v)
{
    Velocity = v;
}
void player::advance(int phase)
{
}

