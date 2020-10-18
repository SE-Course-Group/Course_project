#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>
#include <QPen>
#include <QMoveEvent>
#include "mainwindow.h"
#include "game.h"

Dialog::Dialog(int edges,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    game=new Game(edges);
    move_sound=new QMediaPlayer();
    move_sound->setMedia(QUrl("qrc:/mp3/other_file/move_chess.mp3"));
    wait_move_sound=new QMediaPlaylist();
    wait_move_sound->addMedia(QUrl("qrc:/mp3/other_file/wait_move.mp3"));
    wait_move_sound->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop); //循环播放
    background_sound=new QMediaPlayer();
    background_sound->setPlaylist(wait_move_sound);
    transition_player=new QMediaPlayer();
    transition_player->setMedia(QUrl("qrc:/mp3/other_file/transition.mp3"));
    background_sound->play();
    player_color=1;
    chessX = -1;
    chessY = -1;
}

Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::get_chess_location(int &row, int &col, int newX, int newY)
{
    row = newX/WIDTH+0.5;
    col = newY/WIDTH+0.5;
    if(row<0||row>=game->EDGES||col<0||col>=game->EDGES)return false;
    return true;
}

void Dialog::print_grid()
{
    paint=new QPainter;
    paint->begin(this);                                          //主窗口

    paint->setPen(QPen(Qt::black,2,Qt::SolidLine));            //钢笔工具：颜色，线号，实线

    //画SIZE+1条横线
    for(int i=0;i<SIZE+1;i++)
    {
        paint->drawLine(x,y+WIDTH*i,x+WIDTH*(SIZE),y+WIDTH*i); //画线函数：x1,y1,x2,y2:画从(x1,y1)到(x2,y2)的线
    }

    //画SIZE+1条竖线
    for(int i=0;i<SIZE+1;i++)
    {
        paint->drawLine(x+WIDTH*i,y,x+WIDTH*i,y+WIDTH*(SIZE));
    }
}

void Dialog::print_chess()
{
    for(int i=0;i<game->EDGES;i++)
        for(int j=0;j<game->EDGES;j++){
            if(game->get_situation(i,j)==1){
             paint->setBrush(QBrush(Qt::black,Qt::SolidPattern));//毛刷：颜色，实图案
             paint->drawEllipse(y+j*WIDTH-WIDTH/4,x+i*WIDTH-WIDTH/4,WIDTH/2,WIDTH/2);//画椭圆：中心点X,Y,宽度，高度
             }
            else if(game->get_situation(i,j)==-1){
                paint->setBrush(QBrush(Qt::white,Qt::SolidPattern));//毛刷：颜色，实图案
                paint->drawEllipse(y+j*WIDTH-WIDTH/4,x+i*WIDTH-WIDTH/4,WIDTH/2,WIDTH/2);//画椭圆：中心点X,Y,宽度，高度
            }
        }
}

void Dialog::on_backButton_clicked()
{
    MainWindow *fater = new MainWindow();
    transition_player->play();
    background_sound->stop();
    this->close();
    fater->show();
}

void Dialog::paintEvent(QPaintEvent *)
{
    print_grid();
    print_chess();
}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    //获取点击的坐标
    int newX = event->x();
    int newY = event->y();
    int row,col;
    if(!get_chess_location(col,row,newX,newY))return;
    if(game->move(player_color,row,col)){
        move_sound->play(); //落子成功，放一遍声音
        game->update_board();
        if(player_color==1)player_color=-1;
        else player_color=1;
        update();
    }
}

