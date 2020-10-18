#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_playButton_clicked();
    void on_helpButton_clicked();
    void on_settingButton_clicked();

    void on_setButton_clicked();

private:
    Ui::MainWindow *ui;
    Dialog *dialog;
    QMediaPlayer *background_player;
    QMediaPlaylist *background_playlist;
};
#endif // MAINWINDOW_H
