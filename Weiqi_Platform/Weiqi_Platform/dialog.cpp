#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>
#include <QPen>
#include <QMoveEvent>
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    chessX = -1;
    chessY = -1;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_backButton_clicked()
{
    MainWindow *fater = new MainWindow();
    this->close();
    fater->show();
}

void Dialog::paintEvent(QPaintEvent *)
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

  //在棋盘正中做一个黑棋子
  if(chessX != -1 && chessY != -1)
  {
      paint->setBrush(QBrush(Qt::black,Qt::SolidPattern));//毛刷：颜色，实图案
      paint->drawEllipse(chessX*WIDTH+5,chessY*WIDTH+5,WIDTH/2,WIDTH/2);//画椭圆：中心点X,Y,宽度，高度
  }
}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    //获取点击的坐标
    int newX = event->x();
    int newY = event->y();

    if( newX >= x && newY <= x + 8*WIDTH && newY >= y && newY <= y+8*WIDTH)
    {
        chessX = newX/WIDTH+0.5;
        chessY = newY/WIDTH+0.5;
    }

    update();

}
