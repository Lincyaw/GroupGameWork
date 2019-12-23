#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include <QList>
#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include<QCursor>
#include<QGraphicsSceneMouseEvent>
#include<QDrag>
#include<QWidget>
#include<QMimeData>
#include<QApplication>
#include<QGraphicsScene>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include<QGraphicsView>
#include<QTimer>
#include <QPixmap>
#include <QObject>
#include <QDebug>
#include<QKeyEvent>
#include<QList>
#include<QPainter>
#include"somedeclare.h"
class player : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit player(QObject *parent = 0);
    int heroPosX;//人物的x位置
    int heroPosY;//人物的y位置
    float Velocity;//人物跳跃时候的垂直的速度


    enum Dir{up,down,left,right};//人物的方向
    Dir Direction;
    Dir HorizontalDir;
    int RunSkinCounter = 0;//人物移动的时候皮肤切换计数器
    int SkillCounter = 0;


    int HorizontalSpeed = 1;
    QTimer *JumpTimer = new QTimer;
    QTimer *KeyTimer = new QTimer;
    QTimer *SkillTimer0 = new QTimer;
    QTimer *SkillTimer1 = new QTimer;
    QTimer *SkillTimer2 = new QTimer;
    QTimer *SkillTimer3 = new QTimer;

    QPixmap HeroSkin = QPixmap(":/hero/adventurer-run-00.png");
    QPixmap HeroRunSkin0 = QPixmap(":/hero/adventurer-run-00.png");
    QPixmap HeroRunSkin1 = QPixmap(":/hero/adventurer-run-01.png");
    QPixmap HeroRunSkin2 = QPixmap(":/hero/adventurer-run-02.png");
    QPixmap HeroRunSkin3 = QPixmap(":/hero/adventurer-run-03.png");
    QPixmap HeroRunSkin4 = QPixmap(":/hero/adventurer-run-04.png");
    QPixmap HeroRunSkin5 = QPixmap(":/hero/adventurer-run-05.png");
    QPixmap Attack00 = QPixmap(":/hero/adventurer-air-attack1-00.png");
    QPixmap Attack01 = QPixmap(":/hero/adventurer-air-attack1-01.png");
    QPixmap Attack02 = QPixmap(":/hero/adventurer-air-attack1-02.png");
    QPixmap Attack03 = QPixmap(":/hero/adventurer-air-attack1-03.png");
    QPixmap Attack10 = QPixmap(":/hero/adventurer-air-attack2-00.png");
    QPixmap Attack11 = QPixmap(":/hero/adventurer-air-attack2-01.png");
    QPixmap Attack12 = QPixmap(":/hero/adventurer-air-attack2-02.png");
    QPixmap Attack20 = QPixmap(":/hero/adventurer-attack1-00.png");
    QPixmap Attack21 = QPixmap(":/hero/adventurer-attack1-01.png");
    QPixmap Attack22 = QPixmap(":/hero/adventurer-attack1-02.png");
    QPixmap Attack23 = QPixmap(":/hero/adventurer-attack1-03.png");
    QPixmap Attack24 = QPixmap(":/hero/adventurer-attack1-04.png");
    QPixmap Attack30 = QPixmap(":/hero/adventurer-attack2-00.png");
    QPixmap Attack31 = QPixmap(":/hero/adventurer-attack2-01.png");
    QPixmap Attack32 = QPixmap(":/hero/adventurer-attack2-02.png");
    QPixmap Attack33 = QPixmap(":/hero/adventurer-attack2-03.png");
    QPixmap Attack34 = QPixmap(":/hero/adventurer-attack2-04.png");
    QPixmap Attack35 = QPixmap(":/hero/adventurer-attack2-05.png");
    QPixmap Attack40 = QPixmap(":/hero/adventurer-attack3-00.png");
    QPixmap Attack41 = QPixmap(":/hero/adventurer-attack3-01.png");
    QPixmap Attack42 = QPixmap(":/hero/adventurer-attack3-02.png");
    QPixmap Attack43 = QPixmap(":/hero/adventurer-attack3-03.png");
    QPixmap Attack44 = QPixmap(":/hero/adventurer-attack3-04.png");
    QPixmap Attack45 = QPixmap(":/hero/adventurer-attack3-05.png");
    QPixmap Attack50 = QPixmap(":/hero/adventurer-air-attack3-loop-00.png");
    QPixmap Attack51 = QPixmap(":/hero/adventurer-air-attack3-loop-01.png");
    QPixmap Attack52 = QPixmap(":/hero/adventurer-air-attack3-rdy-00.png");

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void advance(int phase) override;


    void setPosition(int x,int y);
    void setVelocity(int v);
    bool JumpOrnot;
    bool UnderBrick;
    //////////////////////////////////////////////////////////////////////////////
private:
    QColor color;
    int PicWidth;
    int PicHeight;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    int Gravity = 4; //重力值
    inline void SaveKeyPressed( int key )
    {
        m_PressedKeys |= ( 1 << key );
    }
    inline void SaveKeyReleased( int key )
    {
        m_PressedKeys &= ~( 1 << key );
    }
    inline bool KeyPressed( int key )
    {
        return m_PressedKeys & ( 1 << key );
    }
    enum Interested_Keys
    {
        Key_A = 1,
        Key_W,
        Key_D,
        Key_K,
        Key_J,
        Key_L
    };
        quint32  m_PressedKeys=0;

signals:
    void shoot();
    void BackGroundMove();
    void Skill0();
    void Skill1();
    void Skill2();
    void Skill3();
    void Skill4();
    void collided();
    void notcollided();
public slots:
     void FreeFalling(void);
};

#endif // PLAYER_H
