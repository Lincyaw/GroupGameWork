#include "obstacle.h"
#include<QDebug>

obstacle::obstacle(QWidget *parent) : QWidget(parent)
{

}

void obstacle::InitLandData()
{
    obPosX[0] = 0;
//    obPosX[1] = 1000;

    obPosY[0] = 540;
//    obPosY[1] = 540;

    obWidth[0] = 1500;

    obHeight[0] = 260;
}

void obstacle::InitBrickData()
{
    int i;
    for (i = 0; i < 3; i++)
    {
        obPosY[i] = 470;
        obHeight[i] = 30;
        obWidth[i] = 40;
        obPosX[i] = 460 + i * obWidth[i];
    }
}

