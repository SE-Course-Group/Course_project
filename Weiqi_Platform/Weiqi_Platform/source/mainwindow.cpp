#include "header/mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"
#include "choosesize.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    background_playlist=new QMediaPlaylist();
    background_playlist->addMedia(QUrl("qrc:/mp3/other_file/home_background.mp3"));
    background_playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    background_player=new QMediaPlayer();
    background_player->setPlaylist(background_playlist);
    background_player->play(); //开始播放背景音效，当进入其他页面时停止播放
}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_playButton_clicked()    //关闭开始界面，打开游戏界面
{
    choosesize *chooseSize = new choosesize;
    this->close();
    background_player->stop(); //停止播放背景音效
    chooseSize->show();
}

void MainWindow::on_helpButton_clicked()    //打开帮助界面
{
    Form *fater = new Form();
    this->close();
    background_player->stop(); //停止播放背景音效
    fater->show();
}

void MainWindow::on_settingButton_clicked(){
    return;
}
