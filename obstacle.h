#ifndef OBSTACLE_H
#define OBSTACLE_H
//#include "hero.h"
#include <QWidget>
#define MAX 10

class obstacle : public QWidget
{
    Q_OBJECT
public:
    explicit obstacle(QWidget *parent = 0);


//    int sort[10];  //障碍物类型 1: 砖块 2: 金币 3：箱子
    int type;  //障碍物类型 1: 砖块 2: 金币 3：箱子
    int number;  //障碍物个数
    int obPosX[MAX];  //障碍物坐标
    int obPosY[MAX];
    int obWidth[MAX];  //障碍物的宽
    int obHeight[MAX];  //障碍物的高
    int showflag[MAX];  //障碍物是否显示 0: 不显示 1： 显示

    void InitLandData();  //初始化陆地的数据
    void InitBrickData();  //初始化砖块的数据
    void InitCoinData();  //初始化金币的数据
    void InitBoxData();  //初始化箱子的数据

    void ObstacleGoLeft();  //障碍物左移
signals:

public slots:
};

#endif // OBSTACLE_H
