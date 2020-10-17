#ifndef PLAYTHREAD_H
#define PLAYTHREAD_H

//ÕÊº“¿‡
#include<QObject>
#include "game.h"

class playerThread:public QObject
{
            Q_OBJECT
//public:
//    explicit playerThread(Backend* back, QObject* parent = nullptr);
//    playerThread(int id, Backend* b,QObject* parent = nullptr);
//    playerThread(int id, Backend* b,QString name, QObject* parent = nullptr);

//    QString getPlayerName() const;
//    void setPlayerName(QString playerName);

//    int getPlayerID() const;
//    int getType() const;
//protected:
//    QString playerName;
//    int playerID;
//    int type;
//    Backend* back;
//signals:
//    void chooseDraw();
//    void chooseUno();

};
#endif // PLAYTHREAD_H
