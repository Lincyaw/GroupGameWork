#ifndef OBSTACLE_H
#define OBSTACLE_H
//#include "hero.h"
#include <QWidget>

class obstacle : public QWidget
{
    Q_OBJECT
public:
    explicit obstacle(QWidget *parent = 0);


//    int sort[10];  //障碍物类型 1: 砖块 2: 金币
    int type;  //障碍物类型 1: 砖块 2: 金币
    const static int number = 6;
    int obPosX[number];  //障碍物坐标
    int obPosY[number];
    int obWidth[number];  //障碍物的宽
    int obHeight[number];  //障碍物的高
    int showflag[number];  //障碍物是否显示 0: 不显示 1： 显示

    void InitLandData();  //初始化陆地的数据
    void InitBrickData();  //初始化砖块的数据
    void InitCoinData();  //初始化金币的数据

    void CoinDisappear(int i);
signals:

public slots:
};

#endif // OBSTACLE_H
