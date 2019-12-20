#include "obstacle.h"

obstacle::obstacle(QObject *parent) : QObject(parent)
{

}
QRectF obstacle::boundingRect()const
{
    return QRectF(obPosX,obPosY,obWidth,obHeight);
}

void obstacle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    switch(type)
    {
    case 1:
    {
        painter->drawPixmap(obPosX,obPosY,obWidth,obHeight,Ground);
        break;
    }
    case 2:
    {
        painter->drawPixmap(obPosX,obPosY,obWidth,obHeight,Coin);
        break;
    }
    }


}

void obstacle::setType(int num)
{
    type = num;
}

void obstacle::setPosition(int x,int y)
{
    obPosX = x;
    obPosY = y;
}

void obstacle::setWidthHeight(int width,int height)
{
    obWidth = width;
    obHeight = height;
}
