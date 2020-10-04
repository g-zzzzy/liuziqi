#include "startwidget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(900,1200);

    setWindowTitle("游戏模式");
    //人机对战
    solo.setParent(this);
    solo.setText("人机对战");
    solo.move(400, 300);
    connect(&solo, &QPushButton::pressed, this, &Widget::solopattern);

    //双人对战
    two.setParent(this);
    two.setText("双人模式");
    two.move(400,400);

    //游戏规则
    in.setParent(this);
    in.setText("游戏规则");
    in.move(400,500);

    connect(&in, &QPushButton::pressed, this, &Widget::tellin);
    connect(&two, &QPushButton::pressed, this, &Widget::twopattern);
    connect(&w, &man_machine::goback, this, &Widget::getsolo);
    connect(&t, &twoplayer::bback, this, &Widget::gettwo);

}


void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    //设置背景图片
    p.drawPixmap(0,0,900,1200,QPixmap("../picture/start.jpg"));
}

void Widget::tellin()
{
    QMessageBox::about(this, "游戏规则","1.人机对战模式——执黑棋\n2.双人模式——两人轮流落子\n3.六子连成一条直线即为获胜");

}

void Widget::solopattern()
{
    w.show();
    this->hide();
}

void Widget::twopattern()
{
    t.show();
    this->hide();
}

void Widget::getsolo()
{
    w.hide();
    this->show();
}

void Widget::gettwo()
{
    t.hide();
    this->show();
}


Widget::~Widget()
{
    delete ui;
}
