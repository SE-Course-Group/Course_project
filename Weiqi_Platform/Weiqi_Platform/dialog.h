#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
#include "game.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    const int SIZE=8;
    const int WIDTH=65;
    const int x=20,y=20;
    int player_color; //玩家游戏，每一次落子都要修改
    int chessX,chessY;
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
