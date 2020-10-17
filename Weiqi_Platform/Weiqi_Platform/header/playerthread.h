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
    int player_id; //���id��1/2
    int player_color; //1(��ɫ)��-1����ɫ��
    Backend* back; //������ĺ����
signals://�ź�
    void chooselocation();//ѡ�����ӵ�λ��
};

#endif // PLAYERTHREAD_H
