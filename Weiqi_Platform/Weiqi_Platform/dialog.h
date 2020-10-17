#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
#include "game.h"

extern int globalSize;       //����ȫ�ֱ���globalSize

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(int edges,QWidget *parent = nullptr);
    ~Dialog();
    int SIZE=globalSize;           //SIZEΪ���Ӹ���
    int WIDTH=65*8/globalSize;         //WIDTHΪÿ�����ӵĳ���
    const int x=20,y=20;        //x,yΪ����ԭ���λ��
    int player_color; //�����Ϸ��ÿһ�����Ӷ�Ҫ�޸�
    int chessX,chessY;
    Game* game;
    bool get_chess_location(int& row,int& col,int newX,int newY);
    void print_grid();//����������
    void print_chess();//������


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
