#include "player.h"
player::player(QObject *parent) : QObject(parent)
{
    setToolTip("憨憨!");//提示
    setCursor(Qt::OpenHandCursor);
    color = QColor(qrand()%256,qrand()%256,qrand()%256);
    connect(JumpTimer,&QTimer::timeout,[=](){
        FreeFalling();
         update(heroPosX-50, heroPosY-50,46+100, 156);
    });
    connect(KeyTimer,&QTimer::timeout,[=](){
        if(KeyPressed(Key_W))
        {
            qDebug()<<heroPosX<<"  "<<heroPosY;
            Direction = up;
            JumpOrnot = true;
            setVelocity(27);
        }
        if(KeyPressed(Key_A))
        {

             qDebug()<<pos();
             HorizontalDir = bullets::left;
             heroPosX-=HorizontalSpeed;
             RunSkinCounter--;

             switch(RunSkinCounter)
             {
                 case 0:
                     HeroSkin = HeroRunSkin1;
                     RunSkinCounter = 30;
                    // qDebug()<<"0001";
                     break;
                 case 5:
                     HeroSkin = HeroRunSkin2;
                    // qDebug()<<"0002";
                     break;
                 case 10:
                     HeroSkin = HeroRunSkin3;
                     //qDebug()<<"0003";
                     break;
                 case 15:
                     HeroSkin = HeroRunSkin4;
                    // qDebug()<<"0004";
                     break;
                 case 20:
                     HeroSkin = HeroRunSkin5;
                     //qDebug()<<"0005";
                 case 25:
                     HeroSkin = HeroRunSkin0;
                     break;
             }
             moveBy(-HorizontalSpeed,0);  //相对现在的位置移动
        }

        if(KeyPressed(Key_D))
        {
                     qDebug()<<pos();
            HorizontalDir = bullets::right;
            if(heroPosX<-430)
            {
              moveBy(HorizontalSpeed,0);  //相对现在的位置移动
               heroPosX+=HorizontalSpeed;
            }
            else
            {
                emit BackGroundMove();
            }

            RunSkinCounter++;
            switch(RunSkinCounter)
            {
                case 0:
                    HeroSkin = HeroRunSkin1;
                   // qDebug()<<"0001";
                    break;
                case 5:
                    HeroSkin = HeroRunSkin2;
                   // qDebug()<<"0002";
                    break;
                case 10:
                    HeroSkin = HeroRunSkin3;
                    //qDebug()<<"0003";
                    break;
                case 15:
                    HeroSkin = HeroRunSkin4;
                   // qDebug()<<"0004";
                    break;
                case 20:
                    HeroSkin = HeroRunSkin5;
                    //qDebug()<<"0005";
                    break;
                case 25:
                    HeroSkin = HeroRunSkin0;
                    break;
                case 30:
                    RunSkinCounter=0;
                  break;
            }

        }
        if(KeyPressed(Key_K))
        {
            emit shoot(heroPosX,heroPosY);
        }
    });
    JumpTimer->start(100);
    KeyTimer->start(10);
    setPosition(-700,0);
    setData(1,1);
    setVelocity(0);
}
QRectF player::boundingRect()const
{
    qreal penWidth = 1;
    return QRectF(heroPosX-penWidth / 2, heroPosY - penWidth/2,46+penWidth, 56+penWidth);
}
void player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(heroPosX,heroPosY,46,56,HeroSkin);

}
void player::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::ClosedHandCursor);
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
    if(event->key() == Qt::Key_K)
    {
      SaveKeyPressed(Key_K);
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
    if(event->key()==Qt::Key_K)
    {
        SaveKeyReleased(Key_K);
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
        Velocity-=Gravity;
    }
    if(!collidingItems().isEmpty())
    {
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
            Velocity-=Gravity;
        }
    }



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
int player::getPosX()
{
    return heroPosX;
}
int player::getPosY()
{
    return heroPosY;
}
