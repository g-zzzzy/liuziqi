#ifndef MAN_MACHINE_H
#define MAN_MACHINE_H

#include <QWidget>
#include <QPushButton>
#include <QTime>

class man_machine : public QWidget
{
    Q_OBJECT
public:
    explicit man_machine(QWidget *parent = nullptr);
    QPushButton start;
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    int cellwidth;
    int cellheigt;
    int startx;
    int starty;
    int chessx, chessy;
    int chess[21][21];
    bool flag;       //黑/白棋
    bool right;     //鼠标选中的点是否可以下子
    QPushButton restart;
    QPushButton back;
    void Restart();
    void dealstart();
    void Goback();
    QTimer *my_time;

signals:
    void goback();

public slots:
    void handleTimeout();
};

#endif // MAN_MACHINE_H
