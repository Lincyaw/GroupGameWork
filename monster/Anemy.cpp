#include "Anemy.h"
#include <QDebug>
Anemy::Anemy(QObject *parent ,int mPosX ,int mPosY)
{
    PosX = mPosX;
    PosY = mPosY;
    MoveDir = 0;
    AnemyStandSkin = QPixmap();
    MaxLeftPosX = mPosX - MaxLeftPosX;
    MaxRightPosX = mPosX + MaxRightPosX;
}


void Anemy::MoveX()
{
    qDebug()<<MoveDir;
    if((MoveDir == 0)&&(PosX >= MaxLeftPosX))
    {
        PosX -= 1;
    }
    else if((MoveDir == 0)&&(PosX <= MaxLeftPosX))
    {
        MoveDir = 1;
    }
    else if((MoveDir == 1)&&(PosX <= MaxRightPosX))
    {
        PosX += 1;
    }
    else
    {
        MoveDir = 0;
    }
}
