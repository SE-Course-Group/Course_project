#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent * )
{
    paint = new QPainter;
    paint->begin(this);     //主窗口

    paint->setPen(QPen(Qt::black,2,Qt::SolidLine));   //钢笔工具：颜色，线号

    //画SIZE+1条横线
    for(int i = 0;i < SIZE + 1;i++)
    {
        paint->drawLine(x,y+WIDTH*i,x+WIDTH*(SIZE),y+WIDTH*i);
    }

    //画SIZE+1条竖线
    for(int i = 0;i < SIZE + 1;i++)
    {
        paint->drawLine(x+WIDTH*i,y,x+WIDTH*i,y+WIDTH*(SIZE));
    }

    //在棋盘正中画个棋子
    paint->setBrush(QBrush(Qt::black,Qt::SolidPattern));
    paint->drawEllipse((SIZE+0.2)*WIDTH/2,(SIZE+0.2)*WIDTH/2,WIDTH/2,WIDTH/2);
    paint->end();

}

void Dialog::on_backButton_clicked()
{
    this->show();
}
