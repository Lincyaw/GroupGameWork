#include "hero.h"

hero::hero(QObject *parent) : QObject(parent)
{

}
void hero::HeroGoLeft(obstacle *ob)
{
    JudgeWhatHeroMeets(ob);
    heroPosX-=HeroStep;

}
void hero::HeroGoRight(obstacle *ob)
{
    JudgeWhatHeroMeets(ob);
    heroPosX+=HeroStep;
}
bool hero::HeroJump(obstacle *ob)
{
    JudgeWhatHeroMeets(ob);
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
int hero::JudgeWhatHeroMeets(obstacle *ob)
{
    //左上角点为(heroPosX,heroPosY+10),宽为30,高为40
    int i;

    for(i=0;i<ob->number;i++)
    {
        int BrickLeft = ob->obPosX[i],BrickRight = ob->obPosX[i]+ob->obWidth[i],BrickTop =ob->obPosY[i];//因为没有写好具体的砖块类, 因此砖块的大小暂时在这里用临时变量
         int BrickButtom = ob->obPosY[i]+ob->obHeight[i];

         //代替, 在砖块类写好后可以把这些量换成砖块的posXrange和posYrange

//         int BrickLeft =460,BrickRight = 580,BrickTop =400;//因为没有写好具体的砖块类, 因此砖块的大小暂时在这里用临时变量
//          int BrickButtom = 430;


//qDebug()<<"BrickLeft="<<BrickLeft<<"\n"<<"BrickRight="<<BrickRight<<"\n"<<"BrickTop="<<BrickTop<<"\n"<<"BrickButtom="<<BrickButtom<<"\n-----------";

        if(heroPosX+HeroWidth>=BrickLeft && heroPosX<=BrickRight && heroPosY+HeroHeight <= BrickTop)//判断有没有跳到砖头的上面
        {
            //这里表示的是跳到了砖块的上方,则修改原来的groundY地平线为BrickTop
            groundY = BrickTop;
            HeroJumpHeight = HeroJumpHeightNormal;
            qDebug()<<"跳到了上面";
            StandOnTheBrickflag = 1;
            break;
        }
        else
        {
            if((heroPosX+HeroWidth<BrickLeft || heroPosX>BrickRight) && JumpOrNot==0)
            {
                StandOnTheBrickflag = 0;
                //没有则回到原来的地平线;  注意,如果有其他的地形同理
                groundY = 540;//MainWindow::GroundY是主窗口设定的地平线
                HeroJumpHeight = HeroJumpHeightNormal;
                //flag = 1;
                StartTimer();
                qDebug()<<"跳到底了吗?";

            }
//            if(StandOnTheBrickflag)
//                break;
            if(heroPosX+HeroWidth>=BrickLeft && heroPosX<=BrickRight && HeroPosY >= BrickButtom)
            {
                HeroJumpHeight = groundY-HeroHeight-BrickButtom;
                qDebug()<<"上面是砖头";
                StandOnTheBrickflag = 0;
            }
        }


    }





//    if(Type[heroPosX][HeroPosY-2]==Brick || Type[heroPosX+HeroWidth][HeroPosY-2]==Brick)//减2是用来保留判断的区间,判断头顶是不是砖头,
//                                                                                            //判断人物的最上面的两个顶点即可
//    {
//        HeroJumpHeight = groundY-HeroHeight-HeroPosY; //如果是的话调整人物跳跃的高度, 使人最高只能跳到砖块的下面
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



return 0;
}
bool hero::HeroFallDown(obstacle *ob)
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
