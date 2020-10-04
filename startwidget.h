#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "man_machine.h"
#include "twoplayer.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QPushButton solo;
    void solopattern();
    QPushButton two;
    void twopattern();
    void paintEvent(QPaintEvent *);
    void getsolo();
    void gettwo();
    QPushButton in;
    void tellin();

private:
    Ui::Widget *ui;
    man_machine w;
    twoplayer t;
};

#endif // STARTWIDGET_H
