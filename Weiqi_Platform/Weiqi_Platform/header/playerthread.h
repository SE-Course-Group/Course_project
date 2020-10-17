#ifndef PLAYERTHREAD_H
#define PLAYERTHREAD_H

#include"backend.h"
#include<QObject>

class Playerthread:public QObject
{
public:
    Playerthread(int id,int color,Backend* b,QObject* parent=nullptr);
    int id()const{return player_id;}
    int color()const{return player_color;}
private:
    int player_id; //玩家id，1/2
    int player_color; //1(黑色)，-1（白色）
    Backend* back; //相关联的后端类
signals://信号
    void chooselocation();//选择落子的位置
};

#endif // PLAYERTHREAD_H
