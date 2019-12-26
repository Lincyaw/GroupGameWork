#include "obstacle.h"
#include<QDebug>
obstacle::obstacle(QObject *parent) : QObject(parent)
{
    setShowFlag(1);
    connect(cloudTimer,&QTimer::timeout,[=](){
        if(type == 4)
        {
            setPos(pos().x() - 5,pos().y());
            if(pos().x() < -475)
            {
                setPos(375,pos().y());;
            }
            update(pos().x(),pos().y(),obWidth,obHeight);
        }
    });
    cloudTimer->start(200);

    connect(brickTimer,&QTimer::timeout,[=](){
        if(type == 6)
        {
            if(moveFlag)
            {
                setPos(pos().x() + 5,pos().y());
            }
            else
            {
                setPos(pos().x() - 5,pos().y());
            }
            if(pos().x() < -100)
            {
                moveFlag = 1;
            }
            else if(pos().x() > 200)
            {
                moveFlag = 0;
            }
            update(pos().x(),pos().y(),obWidth,obHeight);
        }
    });
    brickTimer->start(200);
}

QRectF obstacle::boundingRect()const
{
    return QRectF(pos().x(),pos().y(),obWidth,obHeight);
}

void obstacle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    switch(type)
    {
    case 1://砖块
    {
        painter->drawPixmap(pos().x(),pos().y(),obWidth,obHeight,Ground);
        break;
    }
    case 2://金币
    {
        if(showflag)
        {
            painter->drawPixmap(pos().x(),pos().y(),obWidth,obHeight,Coin);
        }
        if(!collidingItems().isEmpty())
        {
            for(int i = 0; i < collidingItems().length(); i++)
            {
                if(collidingItems().at(i)->data(1).toInt()==1)
                {
                    setShowFlag(0);
                    update(pos().x(),pos().y(),obWidth,obHeight);
                    if(magic == 1)
                    {
                        GroundTimer->start(500);
                    }
                }
            }
        }
        break;
    }
    case 3://书
    {
        painter->drawPixmap(pos().x(),pos().y(),obWidth,obHeight,Book);
        break;
    }
    case 4://云
    {
        painter->drawPixmap(pos().x(),pos().y(),obWidth,obHeight,Cloud);
        break;
    }
    case 5://主楼
    {
        painter->drawPixmap(pos().x(),pos().y(),obWidth,obHeight,H);
        break;
    }
    case 6://会动的砖
    {
        painter->drawPixmap(pos().x(),pos().y(),obWidth,obHeight,Ground);
        break;
    }
    case 7://作业
    {
        painter->drawPixmap(pos().x(),pos().y(),obWidth,obHeight,Homework);
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
