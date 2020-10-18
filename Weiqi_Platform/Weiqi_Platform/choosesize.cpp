#include "choosesize.h"
#include "ui_choosesize.h"
#include "dialog.h"
#include "mainwindow.h"

int globalSize=8;

choosesize::choosesize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choosesize)
{
    ui->setupUi(this);
    background_playlist=new QMediaPlaylist();
    background_playlist->addMedia(QUrl("qrc:/mp3/other_file/wait_move.mp3"));
    background_playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    background_player=new QMediaPlayer(); //背景音效播放器
    background_player->setPlaylist(background_playlist);
    transition_player=new QMediaPlayer();
    transition_player->setMedia(QUrl("qrc:/mp3/other_file/transition.mp3"));
    background_player->play();
}

choosesize::~choosesize()
{
    delete ui;
}

void choosesize::on_play9Button_clicked()
{
    globalSize=8;                  //设置全局变量，传递参数
    Dialog *dialog = new Dialog(9);
    background_player->stop();
    transition_player->play();
    this->close();
    dialog->show();

}

void choosesize::on_play13Button_clicked()
{
    globalSize=12;
    Dialog *dialog = new Dialog(13);
    background_player->stop();
    transition_player->play();
    this->close();
    dialog->show();
}

void choosesize::on_play19Button_clicked()
{
    globalSize=18;
    Dialog *dialog = new Dialog(19);
    background_player->stop();
    transition_player->play();
    this->close();
    dialog->show();
}

void choosesize::on_back2Button_clicked()
{
    MainWindow *fater = new MainWindow();
    background_player->stop();
    transition_player->play();
    this->close();
    fater->show();
}

