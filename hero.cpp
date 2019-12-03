#include "hero.h"

hero::hero(QObject *parent) : QObject(parent)
{
    Brick =  1; // 定义砖块类型为1;
    heroPosX = 0;
    heroPosY = 490;
    HeroPosY = heroPosY+10; //修正后的人的左上角, 因为用heroPosY的话上方还有一点点空白
    HeroWidth = 30;
    HeroStep = 12;
    JumpSpeed = 6;
    FallSpeed = 4;
    Jumpflag = 0; //判断跳跃的时候是往下还是往上
    StandOnTheBrickflag = 0;
    JumpOrNot = 0;
    HeroJumpHeightNormal = 200;
    HeroJumpHeight = 100;

    HeroSkin= QPixmap(":/hero/adventurer-run-01.png");
    HeroRunSkin1 = QPixmap(":/hero/adventurer-run-01.png");
    HeroRunSkin2 = QPixmap(":/hero/adventurer-run-02.png");
    HeroRunSkin3 = QPixmap(":/hero/adventurer-run-03.png");
    HeroRunSkin4 = QPixmap(":/hero/adventurer-run-04.png");
    HeroRunSkin5 = QPixmap(":/hero/adventurer-run-05.png");


    groundY = 540;
    HeroHeight = 50;//人物这张图片画图是从左上角开始的, 因此要在想绘制的地方
                        //减去整张照片的高度才能画在想画的位置.
            //通过测试可以得到画出来的人物的 左上角点为(heroPosX,heroPosY+10),宽为30,高为40
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
        heroPosY -= JumpSpeed+2;
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
    if(ob->type==1)
    {
        for(i=0;i<ob->number;i++)
        {
            int BrickLeft = ob->obPosX[i],BrickRight = ob->obPosX[i]+ob->obWidth[i],BrickTop =ob->obPosY[i];//因为没有写好具体的砖块类, 因此砖块的大小暂时在这里用临时变量
             int BrickButtom = ob->obPosY[i]+ob->obHeight[i];

             //代替, 在砖块类写好后可以把这些量换成砖块的posXrange和posYrange
            if(heroPosX+HeroWidth>=BrickLeft && heroPosX<=BrickRight && heroPosY+HeroHeight-5 <= BrickTop)//判断有没有跳到砖头的上面
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
                   // qDebug()<<"跳到底了吗?";

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

    }
    else if(ob->type==2)
    {
        //判断是否遇到金币
        for(i=0;i<ob->number;i++)
        {
            int BrickLeft = ob->obPosX[i],BrickRight = ob->obPosX[i]+ob->obWidth[i],BrickTop =ob->obPosY[i];//因为没有写好具体的砖块类, 因此砖块的大小暂时在这里用临时变量
             int BrickButtom = ob->obPosY[i]+ob->obHeight[i];

            if(heroPosX+HeroWidth>=BrickLeft && heroPosX<=BrickRight && heroPosY+10 >= BrickTop && heroPosY+10<=BrickButtom)//判断有没有跳到砖头的上面
            {
                emit MeetCoin();
            }
    }
    }
return 0;
}
bool hero::HeroFallDown(obstacle *ob)
{
    if(heroPosY<groundY-HeroHeight) //跳跃的下界
    {
        heroPosY += 3;
        return 0;
    }
    else
    {
       return 1;
    }
}
