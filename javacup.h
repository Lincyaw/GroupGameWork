#ifndef JAVACUP_H
#define JAVACUP_H
#include "anemy.h"

class javacup:public anemy
{
public:
    javacup(QObject *parent = nullptr,int postionx = 0,int postiony = 0,int RangeX = 0,int RangeY = 0,float horV = 0,float verV = 0);
    ~javacup();
};

#endif // JAVACUP_H
