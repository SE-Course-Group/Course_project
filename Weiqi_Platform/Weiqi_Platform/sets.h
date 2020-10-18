#ifndef SETS_H
#define SETS_H

#include <QDialog>

namespace Ui {
class sets;
}

class sets : public QDialog
{
    Q_OBJECT

public:
    explicit sets(QWidget *parent = nullptr);
    ~sets();

private slots:
    void on_setbackButton_clicked();

private:
    Ui::sets *ui;
};

#endif // SETS_H
