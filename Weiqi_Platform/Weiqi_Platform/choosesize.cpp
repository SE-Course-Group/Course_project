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
}

choosesize::~choosesize()
{
    delete ui;
}

void choosesize::on_play9Button_clicked()
{
    globalSize=8;                  //设置全局变量，传递参数
    Dialog *dialog = new Dialog;
    this->close();
    dialog->show();

}

void choosesize::on_play13Button_clicked()
{
    globalSize=12;
    Dialog *dialog = new Dialog;
    this->close();
    dialog->show();
}

void choosesize::on_play19Button_clicked()
{
    globalSize=18;
    Dialog *dialog = new Dialog;
    this->close();
    dialog->show();
}

void choosesize::on_back2Button_clicked()
{
    MainWindow *fater = new MainWindow();
    this->close();
    fater->show();
}

