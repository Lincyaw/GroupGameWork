#include "javacup.h"

javacup::javacup(QObject *parent,int postionx,int postiony,int RangeX,int RangeY,float horV,float verV):anemy(parent, postionx,postiony,RangeX,RangeY,horV,verV)
{
    setCursor(Qt::OpenHandCursor);
    PicWidth = 34;
    PicHeight = 64;
    color = QColor(qrand()%256,qrand()%256,qrand()%256);
    HorizontalDir = left;
    VerticalDir = down;
    HeroSkin = QPixmap(":/javacup/java.png");
    HeroNormalSkin = QPixmap(":/javacup/java.png");
    HeroBeAttackedSkin = QPixmap(":/javacup/javaBeAttacked.png");
    connect(MoveTimer,&QTimer::timeout,[=](){
        if(MoveFlat == 1)
        {
            switch (MoveMode)
            {
            case 1://左右横条
                if(heroPosX< BornPosX - m_RangeX)
                {
                    HorizontalDir = right;
                }
                if(heroPosX > BornPosX + m_RangeX)
                {
                    HorizontalDir = left;
                }
                if(HorizontalDir == left)
                {
                    heroPosX = heroPosX - HorizontalV;
                    //                moveBy(-HorizontalV,0);
                }
                else
                {
                    heroPosX = heroPosX + HorizontalV;
                    //                moveBy(HorizontalV,0);
                }
                break;

            case 2://上下起伏
                if(heroPosY< BornPosY - m_RangeY)
                {
                    VerticalDir = down;
                }
                if(heroPosY > BornPosY + m_RangeY)
                {
                    VerticalDir = up;
                }
                if(VerticalDir == up)
                {
                    heroPosY = heroPosY - VerticalV;
                    //                moveBy(-HorizontalV,0);
                }
                else
                {
                    heroPosY = heroPosY + VerticalV;
                    //                moveBy(HorizontalV,0);
                }
                break;

            case 3://六亲不认
                if(heroPosX< BornPosX - m_RangeX)
                {
                    HorizontalDir = right;
                }
                if(heroPosX > BornPosX + m_RangeX)
                {
                    HorizontalDir = left;
                }
                if(HorizontalDir == left)
                {
                    heroPosX = heroPosX - HorizontalV;
                    //                moveBy(-HorizontalV,0);
                }
                else
                {
                    heroPosX = heroPosX + HorizontalV;
                    //                moveBy(HorizontalV,0);
                }
                if(heroPosY< BornPosY - m_RangeY)
                {
                    VerticalDir = down;
                }
                if(heroPosY > BornPosY + m_RangeY)
                {
                    VerticalDir = up;
                }
                if(VerticalDir == up)
                {
                    heroPosY = heroPosY - VerticalV;
                    //                moveBy(-HorizontalV,0);
                }
                else
                {
                    heroPosY = heroPosY + VerticalV;
                    //                moveBy(HorizontalV,0);
                }
                break;

            case 4://孤儿不复还左右版本
                if(HorizontalDir == left)
                {
                    heroPosX = heroPosX - HorizontalV;
                    //                moveBy(-HorizontalV,0);
                }
                else
                {
                    heroPosX = heroPosX + HorizontalV;
                    //                moveBy(HorizontalV,0);
                }
                break;

            case 5://孤儿不复还上天
                if(VerticalDir == up)
                {
                    heroPosY = heroPosY - VerticalV;
                    //                moveBy(-HorizontalV,0);
                }
                else
                {
                    heroPosY = heroPosY + VerticalV;
                    //                moveBy(HorizontalV,0);
                }
                break;

            default:
                if(heroPosX< BornPosX - m_RangeX)
                {
                    HorizontalDir = right;
                }
                if(heroPosX > BornPosX + m_RangeX)
                {
                    HorizontalDir = left;
                }
                if(HorizontalDir == left)
                {
                    heroPosX = heroPosX - HorizontalV;
                    //                moveBy(-HorizontalV,0);
                }
                else
                {
                    heroPosX = heroPosX + HorizontalV;
                    //                moveBy(HorizontalV,0);
                }
                break;
            }

        }
//         update(heroPosX-50, heroPosY-50,46+100, 156);
    });
    MoveTimer->start(MoveInterval);
}

javacup::~javacup()
{

}
