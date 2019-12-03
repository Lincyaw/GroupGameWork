#ifndef ANEMY_H
#define ANEMY_H
#include "hero.h"
#include <QObject>

class anemy : public hero
{
    Q_OBJECT
public:
    explicit anemy(QObject *parent = nullptr,int pos_x = 0,int pos_y = 490);

signals:

public slots:
};

#endif // ANEMY_H
