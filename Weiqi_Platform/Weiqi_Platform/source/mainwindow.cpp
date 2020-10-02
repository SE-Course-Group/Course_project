#include "header/mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"

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
    this->close();

    dialog = new Dialog(this);

    dialog->setModal(false);
    dialog->show();
}


void MainWindow::on_helpButton_clicked()
{
    Form *fater = new Form();
    this->close();
    fater->show();
}
