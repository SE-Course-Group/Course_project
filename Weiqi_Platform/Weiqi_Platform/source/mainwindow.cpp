#include "header/mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"
#include "choosesize.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_playButton_clicked()    //关闭开始界面，打开游戏界面
{
    choosesize *chooseSize = new choosesize;
    this->close();
    chooseSize->show();
}


void MainWindow::on_helpButton_clicked()
{
    Form *fater = new Form();
    this->close();
    fater->show();
}
