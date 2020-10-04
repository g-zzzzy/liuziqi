#ifndef TWOPLAYER_H
#define TWOPLAYER_H

#include <QWidget>
#include <QPushButton>

class twoplayer : public QWidget
{
    Q_OBJECT
public:
    explicit twoplayer(QWidget *parent = nullptr);
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
    void dealback();


signals:
    void bback();

public slots:
};

#endif // TWOPLAYER_H
