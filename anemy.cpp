#include "anemy.h"

anemy::anemy(QObject *parent, int pos_x,int pos_y) : hero(parent)
{
    heroPosX = pos_x;
    heroPosY = pos_y;

    HeroSkin= QPixmap(":/monster/hell-beast-breath.png");
    HeroSkin1 = QPixmap(":/hero/adventurer-run-01.png");
    HeroSkin2 = QPixmap(":/hero/adventurer-run-02.png");
    HeroSkin3 = QPixmap(":/hero/adventurer-run-03.png");
    HeroSkin4 = QPixmap(":/hero/adventurer-run-04.png");
    HeroSkin5 = QPixmap(":/hero/adventurer-run-05.png");
}
