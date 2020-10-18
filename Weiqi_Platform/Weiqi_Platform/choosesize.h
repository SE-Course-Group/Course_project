#ifndef CHOOSESIZE_H
#define CHOOSESIZE_H

#include <QDialog>
#include <QMediaPlayer>
#include <QMediaPlaylist>

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
    QMediaPlaylist *background_playlist; //背景音效播放列表
    QMediaPlayer *background_player; //背景音效播放器
    QMediaPlayer *transition_player; //转场音效
};

#endif // CHOOSESIZE_H
