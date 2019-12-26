#include "anemy.h"
#include "player.h"
anemy::anemy(QObject *parent ,int postionx ,int postiony ,int RangeX,int RangeY,float horV ,float verV ) : QObject(parent)
{
    setHorizontalV(horV);
    setVerticalV(verV);
    setData(1,11);
    setRangeXY(RangeX,RangeY);
    BornPosX = postionx;
    BornPosY = postiony;
    setPos(BornPosX,BornPosY);
    MoveFlat = 1;//初始化可移动
    MoveTimer = new QTimer ;
    RecoveryTimer = new QTimer;
    heroBlood = 10;
    connect(this,&anemy::Behurt,[=]{
        HeroSkin = HeroBeAttackedSkin;
    });
    connect(RecoveryTimer,&QTimer::timeout,[=](){
       HeroSkin = HeroNormalSkin;
       MoveFlat = 1;
       RecoveryTimer->stop();
    });
}
QRectF anemy::boundingRect()const
{
    qreal penWidth = 1;
    return QRectF(pos().x()-penWidth / 2, pos().y()- penWidth/2,PicWidth+penWidth, PicHeight+penWidth);
}
void anemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
//    painter->setBrush(!collidingItems().isEmpty()? Qt::red : Qt::green);
   // painter->drawRect(0,0,20,20);
   // painter->drawRect(0,50,30,20);
    //如果与其他图形项碰撞则显示红色，否则显示绿色
    painter->drawPixmap(pos().x(),pos().y(),PicWidth,PicHeight,HeroSkin);

}


void anemy::setPosition(int x,int y)
{
    heroPosX = x;
    heroPosY = y;
}
void anemy::setHorizontalV(float v)
{
    HorizontalV = v;
}
void anemy::setVerticalV(float v)
{
    VerticalV = v;
}
void anemy::setRangeXY(int x,int y)
{
    m_RangeX = x;
    m_RangeY = y;
}
//被攻击时不能移动，掉血，图片变红
void anemy::AttackedByJ()
{
    if(!collidingItems().isEmpty())
    {
        for(int i = 0; i < collidingItems().length(); i++)
        {
            if(collidingItems().at(i)->data(1).toInt()== 1)//与人物碰撞
            {
                MoveFlat = 0;//进入僵直
                RecoveryTimer->start(RecoveryInterval);//若干秒后恢复
                heroBlood--;//怪物扣血
                if(heroBlood == 0)
                {
                    delete this;
                }
            }
        }
    }
}
void anemy::AttackedByK()
{
    if(!collidingItems().isEmpty())
    {
        for(int i = 0; i < collidingItems().length(); i++)
        {
            if(collidingItems().at(i)->data(1).toInt()== 1)//与人物碰撞
            {
                MoveFlat = 0;//进入僵直
                RecoveryTimer->start(RecoveryInterval);//若干秒后恢复
                heroBlood--;//怪物扣血
                if(heroBlood == 0)
                {
                    delete this;
                }
            }
        }
    }
}
void anemy::AttackedByL()
{
    if(!collidingItems().isEmpty())
    {
        for(int i = 0; i < collidingItems().length(); i++)
        {
            if(collidingItems().at(i)->data(1).toInt()== 1)//与人物碰撞
            {
                MoveFlat = 0;//进入僵直
                RecoveryTimer->start(RecoveryInterval);//若干秒后恢复
                heroBlood--;//怪物扣血
                if(heroBlood == 0)
                {
                    delete this;
                }
            }
        }
    }
}
