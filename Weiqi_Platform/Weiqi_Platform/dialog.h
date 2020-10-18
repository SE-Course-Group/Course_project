#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "game.h"

extern int globalSize;       //声明全局变量globalSize

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(int edges,QWidget *parent = nullptr);
    ~Dialog();
    int SIZE=globalSize;           //SIZE为格子个数
    int WIDTH=65*8/globalSize;         //WIDTH为每个格子的长宽
    const int x=20,y=20;        //x,y为棋盘原点的位置
    int player_color; //玩家游戏，每一次落子都要修改
    int chessX,chessY;
    QMediaPlayer* move_sound; //指向下棋的音频
    QMediaPlaylist* wait_move_sound; //等待下棋的音乐列表
    QMediaPlayer* background_sound; //背景音乐
    QMediaPlayer *transition_player; //转场音效
    Game* game;
    bool get_chess_location(int& row,int& col,int newX,int newY);
    void print_grid();//画棋盘线条
    void print_chess();//画棋子


private slots:
    void on_backButton_clicked();


protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::Dialog *ui;
    QPainter *paint;
};

#endif // DIALOG_H
