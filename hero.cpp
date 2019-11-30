#include "hero.h"

hero::hero(QObject *parent) : QObject(parent)
{

}
void hero::HeroGoLeft()
{
    JudgeWhatHeroMeets(Brick);
    heroPosX-=HeroStep;

}
void hero::HeroGoRight()
{
    JudgeWhatHeroMeets(Brick);
    heroPosX+=HeroStep;
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
//    //左上角点为(heroPosX,heroPosY+10),宽为30,高为40

//    int BrickLeft = 460,BrickRight = 500,BrickTop = 450;//因为没有写好具体的砖块类, 因此砖块的大小暂时在这里用临时变量
//     int BrickButtom = 460;                                                //代替, 在砖块类写好后可以把这些量换成砖块的posXrange和posYrange

//    if(heroPosX>=BrickLeft && heroPosX<=BrickRight && heroPosY >= BrickButtom)
//    {
//        HeroJumpHeight = groundY-HeroHeight-BrickButtom;
//        qDebug()<<"上面是砖头";
//    }
//    if(heroPosX>=BrickLeft && heroPosX<=BrickRight && heroPosY < BrickTop)//判断有没有跳到砖头的上面
//    {
//        //这里表示的是跳到了砖块的上方,则修改原来的groundY地平线为BrickTop
//        groundY = BrickTop+HeroHeight;
//        HeroJumpHeight = HeroJumpHeightNormal;
//        qDebug()<<"跳到了上面";
//    }
//    if((heroPosX<BrickLeft || heroPosX>BrickRight) && JumpOrNot==0)
//    {
//        //没有则回到原来的地平线;  注意,如果有其他的地形同理
//        groundY = 540;//MainWindow::GroundY是主窗口设定的地平线
//        HeroJumpHeight = HeroJumpHeightNormal;
//        //flag = 1;
//        StartTimer();
//        //qDebug()<<"跳到底了吗?";

//    }

     ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     /// \brief type
     ///
     ///
     /// 下面是测试模块
     /// 如果要正常跑的话把上面的注释取消,再把下面的注释掉就可以了
int type[1500][800];

    if(type[heroPosX][HeroPosY-2]==Brick || type[heroPosX+HeroWidth][HeroPosY-2]==Brick)//减2是用来保留判断的区间,判断头顶是不是砖头,
                                                                                            //判断人物的最上面的两个顶点即可
    {
        HeroJumpHeight = groundY-HeroHeight-HeroPosY; //如果是的话调整人物跳跃的高度, 使人最高只能跳到砖块的下面

        /*
            问题:
                不知道具体的砖块在哪个位置, 需要根据人所在的位置去探测哪边是砖块, 导致下面改变相对地面的高度的时候会发生偏差
                像之前有BrickButtom, top这些参数的时候, 这些值是固定的, 因此相对地面的高度也是固定的
                但是如果用posY代替上面的参数的话, 因为posY本身就在改变, 导致相对地面也会不断改变
            解决方案:
                    ?
*/

        qDebug()<<"上面是砖头";
    }
    if(type[heroPosX][HeroPosY+HeroHeight+2]==Brick || type[heroPosX+HeroWidth][HeroPosY+HeroHeight+2]==Brick)//判断有没有跳到砖头的上面
    {
        //这里表示的是跳到了砖块的上方,则修改原来的groundY地平线为BrickTop
        groundY = BrickTop + HeroHeight;
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
