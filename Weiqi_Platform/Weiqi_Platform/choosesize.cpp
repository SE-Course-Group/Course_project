#include "choosesize.h"
#include "ui_choosesize.h"
#include "dialog.h"
#include "mainwindow.h"

int globalSize;            //将Size声明为一个全局变量，用于窗体间传值

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
    Dialog *dialog = new Dialog;
    this->close();
    dialog->show();
    globalSize=9;
}

void choosesize::on_play13Button_clicked()
{
    Dialog *dialog = new Dialog;
    this->close();
    dialog->show();
    globalSize=19;
}

void choosesize::on_play19Button_clicked()
{
    Dialog *dialog = new Dialog;
    this->close();
    dialog->show();
    globalSize=19;
}

void choosesize::on_back2Button_clicked()
{
    MainWindow *fater = new MainWindow();
    this->close();
    fater->show();
}

