#ifndef CHOOSESIZE_H
#define CHOOSESIZE_H

#include <QDialog>

namespace Ui {
class choosesize;
}

class choosesize : public QDialog
{
    Q_OBJECT

public:
    explicit choosesize(QWidget *parent = nullptr);
    ~choosesize();

private slots:
    void on_play9Button_clicked();      //选择9*9棋盘

    void on_play13Button_clicked();     //选择13*13棋盘

    void on_play19Button_clicked();     //选择19*19棋盘

    void on_back2Button_clicked();      //返回主界面


private:
    Ui::choosesize *ui;
};

#endif // CHOOSESIZE_H
