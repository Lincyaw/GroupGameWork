#include "hero.h"

hero::hero(QObject *parent) : QObject(parent)
{

}
void hero::HeroGoLeft(obstacle *ob)
{
     heroPosX-=HeroStep;
    JudgeWhatHeroMeets(ob);


}
void hero::HeroGoRight(obstacle *ob)
{
    heroPosX+=HeroStep;
    JudgeWhatHeroMeets(ob);

    //qDebug()<<"HeroPosx = "<<heroPosX<<"HeroposY = "<<heroPosY;
}
bool hero::HeroJump(obstacle *ob)
{
    //qDebug()<<heroPosX;
    JudgeWhatHeroMeets(ob);
    if(heroPosY>groundY-HeroJumpHeight-HeroHeight && Jumpflag == 0) //跳跃的上界
    {
        heroPosY -= JumpSpeed;
        JumpOrNot = 1;
        //qDebug()<<"向上";
    }
    if(heroPosY<=groundY-HeroJumpHeight-HeroHeight && Jumpflag == 0)
    {
        Jumpflag = 1;
        JumpOrNot = 1;
        // qDebug()<<"到顶了";
    }
    if(heroPosY<groundY-HeroHeight && Jumpflag == 1) //跳跃的下界
    {
        heroPosY += FallSpeed;
        JumpOrNot = 1;
        //qDebug()<<"向下";
    }
    if(heroPosY>=groundY-HeroHeight && Jumpflag == 1)
    {
        JumpOrNot = 0;
        return 1;
        //qDebug()<<"到底了";
    }
    return 0;
}
int hero::JudgeWhatHeroMeets(obstacle *ob)
{
    //左上角点为(heroPosX,heroPosY+10),宽为30,高为40
    //qDebug()<<"type是"<<ob->type;
    int i;
    if(ob->type==1)
    {
        //int tempflag = 0;
        for(i=0;i<ob->number;i++)
        {
            int BrickLeft = ob->obPosX[i],BrickRight = ob->obPosX[i]+ob->obWidth[i],BrickTop =ob->obPosY[i];//因为没有写好具体的砖块类, 因此砖块的大小暂时在这里用临时变量
             int BrickButtom = ob->obPosY[i]+ob->obHeight[i];

             //代替, 在砖块类写好后可以把这些量换成砖块的posXrange和posYrange
            if(heroPosX+HeroWidth>BrickLeft && heroPosX<BrickRight && heroPosY+HeroHeight-2<= BrickTop)//判断有没有跳到砖头的上面
            {
                //这里表示的是跳到了砖块的上方,则修改原来的groundY地平线为BrickTop
                groundY = BrickTop;
                HeroJumpHeight = HeroJumpHeightNormal;
                //qDebug()<<"跳到了上面"<<i;

                StandOnTheBrickflag = 1;
                HeroMeetWhichObstacle = i;
                break;

            }
            else
            {
                if((heroPosX+HeroWidth<=BrickLeft || heroPosX>=BrickRight) && JumpOrNot==0)
                {
                    StandOnTheBrickflag = 0;
                    //没有则回到原来的地平线;  注意,如果有其他的地形同理
                    groundY = 540;//MainWindow::GroundY是主窗口设定的地平线
                    HeroJumpHeight = HeroJumpHeightNormal;
                    //flag = 1;
                    //qDebug()<<"JumpOrNot="<<JumpOrNot;
                    //qDebug()<<"跳到底了吗?"<<i;

                }
    //            if(StandOnTheBrickflag)
    //                break;
                if(heroPosX+HeroWidth>=BrickLeft && heroPosX<=BrickRight && HeroPosY>= BrickButtom)
                {
                    HeroJumpHeight = groundY-HeroHeight-BrickButtom;
                   // qDebug()<<"上面是砖头";
                    StandOnTheBrickflag = 0;
                }

            }

        }
        if(!StandOnTheBrickflag && heroPosY<groundY-HeroHeight)
            StartTimer();
    }
    else if(ob->type==2)
    {
        //判断是否遇到金币
        for(i=0;i<ob->number;i++)
        {
            int BrickLeft = ob->obPosX[i],BrickRight = ob->obPosX[i]+ob->obWidth[i],BrickTop =ob->obPosY[i];//因为没有写好具体的砖块类, 因此砖块的大小暂时在这里用临时变量
             int BrickButtom = ob->obPosY[i]+ob->obHeight[i];

            if((heroPosX+HeroWidth>=BrickLeft && heroPosX+HeroWidth<= BrickRight) && heroPosY+14 >= BrickTop && heroPosY+14<=BrickButtom)//判断有没有跳到砖头的上面
            {
                HeroMeetWhichObstacle = i;
                emit MeetCoin();
                //qDebug()<<"遭遇金币"<<i;


            }
    }
    }
return 0;
}
bool hero::HeroFallDown(obstacle *ob)
{

    if(heroPosY<groundY-HeroHeight) //跳跃的下界
    {


        //qDebug()<<"groundY-HeroHeight = "<<groundY-HeroHeight <<"heroPosY="<<heroPosY;
        heroPosY += FallSpeed;
        return 0;
    }
    else
    {
        StopTimer();
         return 1;
    }
}
