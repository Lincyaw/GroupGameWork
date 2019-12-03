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
    type = 1;
    int i;
    for (i = 0; i < 3; i++)
    {
        obPosY[i] = 400;
        obHeight[i] = 30;
        obWidth[i] = 40;
        obPosX[i] = 460 + i * obWidth[i];
    }
    for (i = 0; i < 3; i++)
    {
        obPosY[i+3] = 300;
        obHeight[i+3] = 30;
        obWidth[i+3] = 40;
        obPosX[i+3] = 680 + i * obWidth[i+3];
    }
}

void obstacle::InitCoinData()
{
    int i;
    type = 2;
    for (i = 0; i < 3; i++)
    {
        showflag[i] = 1;
        obPosY[i] = 370;
        obHeight[i] = 30;
        obWidth[i] = 40;
        obPosX[i] = 460 + i * obWidth[i];
    }
    for (i = 0; i < 3; i++)
    {
        showflag[i+3] = 1;
        obPosY[i+3] = 270;
        obHeight[i+3] = 30;
        obWidth[i+3] = 40;
        obPosX[i+3] = 680 + i * obWidth[i+3];
    }
}

//void obstacle::CoinDisappear(hero *player)
//{
//    int i;
//    for (i = 0; i < number; i++)
//    {
//        if((player->heroPosX + player->HeroWidth >= obPosX[i] && player->heroPosX <= obPosX[i]) && (player->HeroPosY + player->HeroHeight >= obPosY && player->HeroPosY <= obPosY + obHeight))
//        {
//            showflag[i] = 0;
//        }
//    }
//}

