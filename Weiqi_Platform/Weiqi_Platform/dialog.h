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
    const int SIZE=8;
    const int WIDTH=65;
    const int x=20,y=20;

    int chessX,chessY;

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
