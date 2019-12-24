#include "anemy.h"
anemy::anemy(QObject *parent ,int postionx ,int postiony ,int RangeX,int RangeY,float horV ,float verV ) : QObject(parent)
{
    setPosition(postionx,postiony);
    setHorizontalV(horV);
    setVerticalV(verV);
    setData(1,6);
    BornPosX = postionx;
    BornPosY = postiony;
    MoveFlat = 1;//初始化可移动
    MoveTimer = new QTimer ;
    RecoveryTimer = new QTimer;
}
QRectF anemy::boundingRect()const
{
    qreal penWidth = 1;
    return QRectF(heroPosX-penWidth / 2, heroPosY - penWidth/2,PicWidth+penWidth, PicHeight+penWidth);
}
void anemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    //painter->setBrush(!collidingItems().isEmpty()? Qt::red : Qt::green);
   // painter->drawRect(0,0,20,20);
   // painter->drawRect(0,50,30,20);
    //如果与其他图形项碰撞则显示红色，否则显示绿色

    painter->drawPixmap(heroPosX,heroPosY,PicWidth,PicHeight,heroSkin);

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
    MoveFlat = 0;
    RecoveryTimer->start(RecoveryInterval);
}
void anemy::AttackedByK()
{
    MoveFlat = 0;
    RecoveryTimer->start(RecoveryInterval);
}
void anemy::AttackedByL()
{
    MoveFlat = 0;
    RecoveryTimer->start(RecoveryInterval);
}
