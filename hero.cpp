#include "hero.h"

hero::hero(QObject *parent) : QObject(parent)
{

}
void hero::HeroGoLeft()
{
    JudgeWhatHeroMeets(Brick);
    heroPosX-=3;

}
void hero::HeroGoRight()
{
    JudgeWhatHeroMeets(Brick);
    heroPosX+=3;
}
bool hero::HeroJump()
{
    JudgeWhatHeroMeets(Brick);
    if(heroPosY>groundY-HeroJumpHeight-HeroHeight && Jumpflag == 0) //跳跃的上界
    {
        heroPosY -= 1;
        JumpOrNot = 1;
       // qDebug()<<"向上";
    }
    else
    {
        Jumpflag = 1;
        JumpOrNot = 1;
         //qDebug()<<"到顶了";
    }
    if(heroPosY<groundY-HeroHeight && Jumpflag == 1) //跳跃的下界
    {
        heroPosY += 1;
        JumpOrNot = 1;
        //qDebug()<<"向下";
    }
    if(heroPosY>=groundY-HeroHeight && Jumpflag == 1)
    {
        JumpOrNot = 0;
        return 1;
        //qDebug()<<"到底了";

    }
    else
    {
        JumpOrNot = 1;
       //qDebug()<<"没到底";
        return 0;
    }
}
int hero::JudgeWhatHeroMeets(int Type)
{
    int BrickLeft = 460,BrickRight = 500,BrickTop = 470;//因为没有写好具体的砖块类, 因此砖块的大小暂时在这里用临时变量
     int BrickButtom = 480;                                                //代替, 在砖块类写好后可以把这些量换成砖块的posXrange和posYrange
    switch(Type)
    {
        case Brick:
            if(heroPosX>=BrickLeft && heroPosX<=BrickRight && heroPosY >= BrickButtom)
            {
                HeroJumpHeight = groundY-HeroHeight-BrickButtom;
                qDebug()<<"上面是砖头";
            }
            if(heroPosX>=BrickLeft && heroPosX<=BrickRight && heroPosY < BrickTop)//判断有没有跳到砖头的上面
            {
                //这里表示的是跳到了砖块的上方,则修改原来的groundY地平线为BrickTop
                groundY = BrickTop+HeroHeight;
                HeroJumpHeight = HeroJumpHeightNormal;
                qDebug()<<"跳到了上面";
            }
            if((heroPosX<BrickLeft || heroPosX>BrickRight) && JumpOrNot==0)
            {
                //没有则回到原来的地平线;  注意,如果有其他的地形同理
                groundY = 540;//MainWindow::GroundY是主窗口设定的地平线
                HeroJumpHeight = HeroJumpHeightNormal;
                //flag = 1;
                StartTimer();
                //qDebug()<<"跳到底了吗?";

            }
        break;
    }



return 0;
}
bool hero::HeroFallDown()
{
    if(heroPosY<groundY-HeroHeight) //跳跃的下界
    {
        heroPosY += 2;
        return 0;
    }
    else
    {
       return 1;
    }
}
