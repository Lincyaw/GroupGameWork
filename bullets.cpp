#include "bullets.h"

bullets::bullets(int x,int y)
{
    qDebug()<<"一个子弹";
        setSpeed(10);
        setDirection(right);
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


        });
      shootTimer->start(100);
}
QRectF bullets::boundingRect()const
{
    qreal penWidth = 1;
    return QRectF(bulletPosX-penWidth / 2, bulletPosY - penWidth/2,5+penWidth, 5+penWidth);
}
void bullets::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawEllipse(bulletPosX,bulletPosY,5,5);

}
void bullets::setPosition(int x,int y)
{
    bulletPosX = x;
    bulletPosY = y;
}

void bullets::setSpeed(int v)
{
    speed = v;
}
void bullets::setDirection(Dir dir)
{
    direction = dir;
}
