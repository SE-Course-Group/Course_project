#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    const int SIZE=8;                        //棋盘点数
    const int WIDTH=65;                      //棋盘大小
    const int x=20,y=20;                     //棋盘原点位置

private slots:
    void on_backButton_clicked();             //返回按钮槽

private:
    Ui::Dialog *ui;
    void paintEvent(QPaintEvent *);      //绘图函数声明
    QPainter *paint;
};

#endif // DIALOG_H
