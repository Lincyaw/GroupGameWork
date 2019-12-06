#ifndef ANEMY_H
#define ANEMY_H
#include <QObject>
#include <QPainter>

class Anemy : public QObject
{
    Q_OBJECT
public:
    explicit Anemy(QObject *parent = nullptr,int mPosX = 0,int mPosY = 490);

    //出生位置
    int PosX;
    int PosY;

    //可活动最大范围
    int MaxLeftPosX = 100;
    int MaxRightPosX = 100;

    //属性
    int Width;
    int Height;
    int Hp;
    int Step;
    int MoveDir;//MoveDir为0时向左移动，为1时向右移动

    //模型皮肤
    QPixmap AnemyCurrentSkin;
    QPixmap AnemyStandSkin;
    QPixmap AnemyRunningSkin1;
    QPixmap AnemyRunningSkin2;
    QPixmap AnemyRunningSkin3;
    QPixmap AnemyRunningSkin4;
    QPixmap AnemyRunningSkin5;


    //移动函数
    void MoveX();
    
signals:

public slots:
};

#endif // ANEMY_H
