#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QWidget>

class obstacle : public QWidget
{
    Q_OBJECT
public:
    explicit obstacle(QWidget *parent = 0);

//    int sort[10];  //障碍物类型 0: 天空 1: 陆地 2：砖
    int type;  //障碍物类型 0: 天空 1: 陆地 2：砖
    int obPosX[10];  //障碍物坐标
    int obPosY[10];
    int obWidth[10];  //障碍物的宽
    int obHeight[10];  //障碍物的高

    void InitLandData();  //初始化陆地的数据
    void InitBrickData();  //初始化砖块的数据
    void InitCoinData();  //初始化金币的数据
signals:

public slots:
};

#endif // OBSTACLE_H
