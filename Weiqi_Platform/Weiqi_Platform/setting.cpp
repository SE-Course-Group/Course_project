#include "setting.h"
#include "ui_setting.h"
#include "mainwindow.h"
setting::setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);
}

setting::~setting()
{
    delete ui;
}

void setting::on_pushButton_clicked()
{
    MainWindow *fater = new MainWindow();
    this->close();
    fater->show();
}
