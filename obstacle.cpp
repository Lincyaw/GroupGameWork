#include "obstacle.h"
#include<QDebug>
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
    case 0://云
    {
        painter->drawPixmap(obPosX,obPosY,obWidth,obHeight,Cloud);
        break;
    }
    case 1://砖块
    {
        painter->drawPixmap(obPosX,obPosY,obWidth,obHeight,Ground);
        break;
    }
    case 2://金币
    {
        if (showflag == 1)
        {
            painter->drawPixmap(obPosX,obPosY,obWidth,obHeight,Coin);
        }
        if(!collidingItems().isEmpty())
        {
            for(int i = 0; i < collidingItems().length(); i++)
            {
                if(collidingItems().at(i)->data(1).toInt()==1)
                {
                    setShowFlag(0);
                    update(obPosX,obPosY,obWidth,obHeight);
                }
            }
        }
        break;
    }
    case 3://书
    {
        painter->drawPixmap(obPosX,obPosY,obWidth,obHeight,Book);
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

void obstacle::setShowFlag(int num)
{
    showflag = num;
}
