#include "man_machine.h"
#include <QPainter>
#include <QPen>
#include <QMessageBox>
#include <QMouseEvent>
#include <QTimer>


man_machine::man_machine(QWidget *parent) : QWidget(parent)
{
    my_time=new QTimer(this);
    connect(my_time, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    this->setWindowTitle("六子棋——人机模式");
    this->setFixedSize(1150,1250);
    for(int i=0;i<=20;i++)
    {
        for(int j=0;j<=20;j++)
        {
            chess[i][j]=0;
        }
    }
    chessx=-1;
    chessy=-1;
    flag=false;  //true下黑棋；false下白棋
    right=false;

    back.setParent(this);
    back.setText("返回");
    back.move(600,1120);

    restart.setParent(this);    //重新开始游戏

    restart.setText("重新开始");
    restart.move(400,1120);

    connect(&back, &QPushButton::pressed, this, &man_machine::Goback);

    connect(&restart, &QPushButton::pressed, this, &man_machine::Restart);
}


void man_machine::paintEvent(QPaintEvent *)
{
    startx=75;
    starty=75;
    cellwidth=50;
    cellheigt=50;
    QPainter p(this);
    //设置背景图片
    p.drawPixmap(0,0,1150,1250,QPixmap("../picture/backgroud.jpg"));
    QPen pen;

    pen.setWidth(4);//设置线宽
    p.setPen(pen);
    //画棋盘
    for(int i=0;i<=20;i++)
    {
        //横线
        p.drawLine(startx, starty+i*cellwidth, startx+20*cellwidth, starty+i*cellwidth);
        //竖线
        p.drawLine(startx+i*cellwidth, starty, startx+i*cellwidth, starty+20*cellwidth);
    }


    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    pen.setWidth(1);

    //画之前的棋子
    for(int i=0;i<=20;i++)
    {
        for(int j=0;j<=20;j++)
        {
            if(chess[i][j]!=0)
            {
                if(chess[i][j]==1)
                {
                    pen.setColor(Qt::black);
                    brush.setColor(Qt::black);
                }
                else if(chess[i][j]==2)
                {
                    pen.setColor(Qt::white);
                    brush.setColor(Qt::white);
                }
                p.setPen(pen);
                p.setBrush(brush);
                p.drawEllipse(QPoint(i*50+75, j*50+75), 20, 20);
            }
        }
    }


    if(right)
    {
        //机器落子
        if(flag)
        {
            int max=0;     //记录最大值
            int max_i=-1;
            int max_j=-1;   //记录最大值的位置
           for(int i=0;i<=20;i++)
           {
               for(int j=0;j<=20;j++)
               {
                   if(!chess[i][j])
                   {
                       int s=0;     //s算分
                       if(chess[i-1][j]==1)
                       {
                           s+=2;
                           if(chess[i-2][j]==1)
                           {
                               s+=2;
                               if(chess[i-3][j]==1)
                               {
                                   s+=2;
                                   if(chess[i-4][j]==1)
                                   {
                                       s+=20;
                                       if(chess[i-5][j]==1)
                                       {
                                           s+=2;
                                           if(chess[i-6][j]==2)
                                               s+=30;
                                       }
                                       else if(chess[i-5][j]==2)
                                           s+=2;
                                   }
                               }
                           }
                       }
                       if(chess[i+1][j]==1)
                       {
                           s+=2;
                           if(chess[i+2][j]==1)
                           {
                               s+=2;
                               if(chess[i+3][j]==1)
                               {
                                   s+=2;
                                   if(chess[i+4][j]==1)
                                   {
                                       s+=20;
                                       if(chess[i+5][j]==1)
                                       {
                                           s+=2;
                                           if(chess[i+6][j]==2)
                                               s+=30;
                                       }
                                       else if(chess[i+5][j]==2)
                                           s+=2;
                                   }
                               }
                           }
                       }
                       if(chess[i-1][j-1]==1)
                       {
                           s+=2;
                           if(chess[i-2][j-2]==1)
                           {
                               s+=2;
                               if(chess[i-3][j-3]==1)
                               {
                                   s+=2;
                                   if(chess[i-4][j-4]==1)
                                   {
                                       s+=20;
                                       if(chess[i-5][j-5]==1)
                                       {
                                           s+=2;
                                           if(chess[i-6][j-6]==2)
                                               s+=30;
                                       }
                                       else if(chess[i-5][j-5]==2)
                                           s+=2;
                                   }
                               }
                           }
                       }
                       if(chess[i-1][j+1]==1)
                       {
                           s+=2;
                           if(chess[i-2][j+2]==1)
                           {
                               s+=2;
                               if(chess[i-3][j+3]==1)
                               {
                                   s+=2;
                                   if(chess[i-4][j+4]==1)
                                   {
                                       s+=20;
                                       if(chess[i-5][j+5]==1)
                                       {
                                           s+=2;
                                           if(chess[i-6][j+6]==2)
                                               s+=30;
                                       }
                                       else if(chess[i-5][j+5]==2)
                                           s+=2;
                                   }
                               }
                           }
                       }
                       if(chess[i+1][j+1]==1)
                       {
                           s+=2;
                           if(chess[i+2][j+2]==1)
                           {
                               s+=2;
                               if(chess[i+3][j+3]==1)
                               {
                                   s+=2;
                                   if(chess[i+4][j+4]==1)
                                   {
                                       s+=20;
                                       if(chess[i+5][j+5]==1)
                                       {
                                           s+=2;
                                           if(chess[i+6][j+6]==2)
                                               s+=30;
                                       }
                                       else if(chess[i+5][j+5]==2)
                                           s+=2;
                                   }
                               }
                           }
                       }
                       if(chess[i+1][j-1]==1)
                       {
                           s+=2;
                           if(chess[i+2][j-2]==1)
                           {
                               s+=2;
                               if(chess[i+3][j-3]==1)
                               {
                                   s+=2;
                                   if(chess[i+4][j-4]==1)
                                   {
                                       s+=20;
                                       if(chess[i+5][j-5]==1)
                                       {
                                           s+=2;
                                           if(chess[i+6][j-6]==2)
                                               s+=30;
                                       }
                                       else if(chess[i+5][j-5]==2)
                                           s+=2;
                                   }
                               }
                           }
                       }
                       if(chess[i][j+1]==1)
                       {
                           s+=2;
                           if(chess[i][j+2]==1)
                           {
                               s+=2;
                               if(chess[i][j+3]==1)
                               {
                                   s+=2;
                                   if(chess[i][j+4]==1)
                                   {
                                       s+=20;
                                       if(chess[i][j+5]==1)
                                       {
                                           s+=2;
                                           if(chess[i][j+6]==2)
                                               s+=30;
                                       }
                                       else if(chess[i][j+5]==2)
                                           s+=2;
                                   }
                               }
                           }
                       }
                       if(chess[i][j-1]==1)
                       {
                           s+=2;
                           if(chess[i][j-2]==1)
                           {
                               s+=2;
                               if(chess[i][j-3]==1)
                               {
                                   s+=2;
                                   if(chess[i][j-4]==1)
                                   {
                                       s+=20;
                                       if(chess[i][j-5]==1)
                                       {
                                           s+=2;
                                           if(chess[i][j-6]==2)
                                               s+=30;
                                       }
                                       else if(chess[i][j-5]==2)
                                           s+=2;
                                   }
                               }
                           }
                       }

                       if(chess[i-1][j]==2)
                       {
                           s+=3;
                           if(chess[i-2][j]==2)
                           {
                               s+=5;
                               if(chess[i-3][j]==2)
                               {
                                   s+=6;
                                   if(chess[i-4][j]==2)
                                   {
                                       s+=10;
                                       if(chess[i-5][j]==2)
                                           s+=10;
                                   }
                               }
                           }
                       }
                       if(chess[i+1][j]==2)
                       {
                           s+=3;
                           if(chess[i+2][j]==2)
                           {
                               s+=5;
                               if(chess[i+3][j]==2)
                               {
                                   s+=6;
                                   if(chess[i+4][j]==2)
                                   {
                                       s+=10;
                                       if(chess[i+5][j]==2)
                                           s+=10;
                                   }
                               }
                           }
                       }
                       if(chess[i-1][j-1]==2)
                       {
                           s+=3;
                           if(chess[i+2][j+2]==2)
                           {
                               s+=5;
                               if(chess[i+3][j+3]==2)
                               {
                                   s+=6;
                                   if(chess[i+4][j+4]==2)
                                   {
                                       s+=10;
                                       if(chess[i+5][j+5]==2)
                                           s+=10;
                                   }
                               }
                           }
                       }
                       if(chess[i-1][j+1]==2)
                       {
                           s+=3;
                           if(chess[i-2][j+2]==2)
                           {
                               s+=5;
                               if(chess[i-3][j+3]==2)
                               {
                                   s+=6;
                                   if(chess[i-4][j+4]==2)
                                   {
                                       s+=10;
                                       if(chess[i-5][j+5]==2)
                                           s+=10;
                                   }
                               }
                           }
                       }
                       if(chess[i+1][j+1]==2)
                       {
                           s+=3;
                           if(chess[i+2][j+2]==2)
                           {
                               s+=5;
                               if(chess[i+3][j+3]==2)
                               {
                                   s+=6;
                                   if(chess[i+4][j+4]==2)
                                   {
                                       s+=10;
                                       if(chess[i+5][j+5]==2)
                                           s+=10;
                                   }
                               }
                           }
                       }
                       if(chess[i+1][j-1]==2)
                       {
                           s+=3;
                           if(chess[i+2][j-2]==2)
                           {
                               s+=5;
                               if(chess[i+3][j-3]==2)
                               {
                                   s+=6;
                                   if(chess[i+4][j-4]==2)
                                   {
                                       s+=10;
                                       if(chess[i+5][j-5]==2)
                                           s+=10;
                                   }
                               }
                           }
                       }
                       if(chess[i][j+1]==2)
                       {
                           s+=3;
                           if(chess[i][j+2]==2)
                           {
                               s+=5;
                               if(chess[i][j+3]==2)
                               {
                                   s+=6;
                                   if(chess[i][j+4]==2)
                                   {
                                       s+=10;
                                       if(chess[i][j+5]==2)
                                           s+=10;
                                   }
                               }
                           }
                       }
                       if(chess[i][j-1]==2)
                       {
                           s+=3;
                           if(chess[i][j-2]==2)
                           {
                               s+=5;
                               if(chess[i][j-3]==2)
                               {
                                   s+=6;
                                   if(chess[i][j-4]==2)
                                   {
                                       s+=10;
                                       if(chess[i][j-5]==2)
                                           s+=10;
                                   }
                               }
                           }
                       }
                       if(s>=max)
                       {
                           max_i=i;
                           max_j=j;
                           max=s;
                       }
                   }
               }
           }

           chess[max_i][max_j]=2;
           flag=!flag;

           my_time->start(500);

           int sum=1;
           for(int i=1;i<=5;i++)
           {
               if(chess[max_i+i][max_j]==2)
                   sum+=1;
               else
                   break;
           }
           for(int i=1;i<=5;i++)
           {
               if(chess[max_i-i][max_j]==2)
                   sum+=1;
               else
                   break;
           }
           if(sum==6)      //白棋赢
           {
               QMessageBox over;
               over.setText("游戏结束！白棋获胜！");
               over.setStandardButtons(QMessageBox::Yes);
               int ret=over.exec();
               switch(ret)
               {
               case QMessageBox::Yes:
                   Restart();
                   break;
               default:
                   break;
               }
           }


           //纵向判别
           sum=1;
           for(int i=1;i<=5;i++)
           {
               if(chess[max_i][max_j+i]==2)
                   sum+=1;
               else
                   break;
           }
           for(int i=1;i<=5;i++)
           {
               if(chess[max_i][max_j-i]==2)
                   sum+=1;
               else
                   break;
           }
           if(sum==6)      //白棋赢
           {
               QMessageBox over;
               over.setText("游戏结束！白棋获胜！");
               over.setStandardButtons(QMessageBox::Yes);
               int ret=over.exec();
               switch(ret)
               {
               case QMessageBox::Yes:
                   Restart();
                   break;
               default:
                   break;
               }
           }

           //左上->右下判别
           sum=1;
           for(int i=1;i<=5;i++)
           {
               if(chess[max_i+i][max_j+i]==2)
                   sum+=1;
               else
                   break;
           }
           for(int i=1;i<=5;i++)
           {
               if(chess[max_i-i][max_j-i]==2)
                   sum+=1;
               else
                   break;
           }
           if(sum==6)      //白棋赢
           {
               QMessageBox over;
               over.setText("游戏结束！白棋获胜！");
               over.setStandardButtons(QMessageBox::Yes);
               int ret=over.exec();
               switch(ret)
               {
               case QMessageBox::Yes:
                   Restart();
                   break;
               default:
                   break;
               }
           }

           //左下->右上判别
           sum=1;
           for(int i=1;i<=5;i++)
           {
               if(chess[max_i+i][max_j-i]==2)
                   sum+=1;
               else
                   break;
           }
           for(int i=1;i<=5;i++)
           {
               if(chess[max_i-i][max_j+i]==2)
                   sum+=1;
               else
                   break;
           }
           if(sum==6)      //白棋赢
           {
               QMessageBox over;
               over.setText("游戏结束！白棋获胜！");
               over.setStandardButtons(QMessageBox::Yes);
               int ret=over.exec();
               switch(ret)
               {
               case QMessageBox::Yes:
                   Restart();
                   break;
               default:
                   break;
               }
           }

        }
    }

}

void man_machine::handleTimeout()
{
    update();
}

void man_machine::mousePressEvent(QMouseEvent *e)
{
    //黑棋落子
    if(!flag)
    {
        //获取鼠标点击的位置
        int x= e->x();
        int y= e->y();
        //获取棋子下落的位置
        if(x>=startx-10&&x<=startx+20*cellwidth+10&&y>=starty-10&&y<=starty+20*cellheigt+10)
        {
            chessx=(x-startx+20)/50;
            chessy=(y-starty+20)/50;        //20个像素点的偏差
            if(chess[chessx][chessy]==0)
            {
                flag=!flag;
                right=true;
                chess[chessx][chessy]=1;
                update();
            }
        }
        int sum=1;
        //横向判别
        for(int i=1;i<=5;i++)
        {
            if(chess[chessx+i][chessy]==1)
                sum+=1;
            else
                break;
        }
        for(int i=1;i<=5;i++)
        {
            if(chess[chessx-i][chessy]==1)
                sum+=1;
            else
                break;
        }
        if(sum==6)      //黑棋赢
        {
            QMessageBox over;
            over.setText("游戏结束！黑棋获胜！");
            over.setStandardButtons(QMessageBox::Yes);
            int ret=over.exec();
            switch(ret)
            {
            case QMessageBox::Yes:
                Restart();
                update();
                break;
            default:
                break;
            }
        }

        //纵向判别
        sum=1;
        for(int i=1;i<=5;i++)
        {
            if(chess[chessx][chessy+i]==1)
                sum+=1;
            else
                break;
        }
        for(int i=1;i<=5;i++)
        {
            if(chess[chessx][chessy-i]==1)
                sum+=1;
            else
                break;
        }
        if(sum==6)      //黑棋赢
        {
            QMessageBox over;
            over.setText("游戏结束！黑棋获胜！");
            over.setStandardButtons(QMessageBox::Yes);
            int ret=over.exec();
            switch(ret)
            {
            case QMessageBox::Yes:
                Restart();
                update();
                break;
            default:
                break;
            }
        }


        //左上->右下判别
        sum=1;
        for(int i=1;i<=5;i++)
        {
            if(chess[chessx+i][chessy+i]==1)
                sum+=1;
            else
                break;
        }
        for(int i=1;i<=5;i++)
        {
            if(chess[chessx-i][chessy-i]==1)
                sum+=1;
            else
                break;
        }
        if(sum==6)      //黑棋赢
        {
            QMessageBox over;
            over.setText("游戏结束！黑棋获胜！");
            over.setStandardButtons(QMessageBox::Yes);
            int ret=over.exec();
            switch(ret)
            {
            case QMessageBox::Yes:
                Restart();
                update();
                break;
            default:
                break;
            }
        }

        //左下->右上判别
        sum=1;
        for(int i=1;i<=5;i++)
        {
            if(chess[chessx+i][chessy-i]==1)
                sum+=1;
            else
                break;
        }
        for(int i=1;i<=5;i++)
        {
            if(chess[chessx-i][chessy+i]==1)
                sum+=1;
            else
                break;
        }
        if(sum==6)      //黑棋赢
        {
            QMessageBox over;
            over.setText("游戏结束！黑棋获胜！");
            over.setStandardButtons(QMessageBox::Yes);
            int ret=over.exec();
            switch(ret)
            {
            case QMessageBox::Yes:
                Restart();
                update();
                break;
            default:
                break;
            }
        }
    }

}




//重新开始
void man_machine::Restart()
{
    if(right)           //只有开始下棋之后才可以按
    {
        QMessageBox Again;
        Again.setInformativeText("是否重新开始?");
        Again.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        int ret=Again.exec();
        switch(ret)
        {
        case QMessageBox::Yes:
        {
            chessx=-1;
            chessy=-1;
            flag=false;
            right=false;
            for(int i=0;i<=20;i++)
            {
                for(int j=0;j<=20;j++)
                {
                    chess[i][j]=0;
                }
            }
            update();
            break;
        }
        case QMessageBox::No:
        {
            return;
            break;
        }
            default:
            break;
        }
    }

}


void man_machine::Goback()
{
    emit goback();
}



