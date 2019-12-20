#include "bullet.h"

bullet::bullet(Dir dir1,int x, int y)
{
    qDebug()<<"一个子弹";
    setSpeed(10);
    setDirection(dir1);
    setPosition(x,y);
    connect(shootTimer,&QTimer::timeout,[=](){
            if(direction == right)
            {
                bulletPosX += speed;
                update();
            }
            if(direction == left)
            {
                bulletPosY -= speed;
                update();
            }
//        }


    });
  shootTimer->start(100);
}
bullet::~bullet()
{
    qDebug()<<"析构";
}

QRectF bullet::boundingRect()const
{
    qreal penWidth = 1;
    return QRectF(bulletPosX-penWidth / 2, bulletPosY - penWidth/2,5+penWidth, 5+penWidth);
}
void bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    //painter->setBrush(!collidingItems().isEmpty()? Qt::red : Qt::green);
   // painter->drawRect(0,0,20,20);
   // painter->drawRect(0,50,30,20);
    //如果与其他图形项碰撞则显示红色，否则显示绿色

   // painter->drawPixmap(bulletPosX,bulletPosY,46,56,HeroSkin);
    painter->drawEllipse(bulletPosX,bulletPosY,5,5);

}
void bullet::setPosition(int x,int y)
{
    bulletPosX = x;
    bulletPosY = y;
}

void bullet::setSpeed(int v)
{
    speed = v;
}
void bullet::setDirection(Dir dir)
{
    direction = dir;
}
