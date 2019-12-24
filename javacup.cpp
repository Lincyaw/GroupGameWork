#include "javacup.h"

javacup::javacup(QObject *parent,int postionx,int postiony,int RangeX,int RangeY,float horV,float verV):anemy(parent, postionx,postiony,RangeX,RangeY,horV,verV)
{
    setCursor(Qt::OpenHandCursor);
    PicWidth = 46;
    PicHeight = 56;
    color = QColor(qrand()%256,qrand()%256,qrand()%256);
    HorizontalDir = left;
    heroSkin = QPixmap(":/java/javacup.jpg");
    MoveTimer->start(MoveInterval);
    connect(MoveTimer,&QTimer::timeout,[=](){
        if(MoveFlat == 1)
        {
            if(heroPosX < BornPosX - m_RangeX)
            {
                HorizontalDir = right;
            }
            else if(heroPosX > BornPosX + m_RangeX)
            {
                HorizontalDir = left;
            }
            if(HorizontalDir == left)
            {
                heroPosX -= heroPosX - HorizontalV;
            }
            else
            {
                heroPosX += heroPosX + HorizontalV;
            }
        }
         update(heroPosX-50, heroPosY-50,46+100, 156);
    });
}

javacup::~javacup()
{

}
