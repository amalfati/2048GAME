#include "Widget.h"
#include <QMessageBox>
#include <QDebug>


Widget::Widget(QWidget *parent) :
      QWidget(parent),score(0),state(false)
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            K[i][j]=0;

    button = new QPushButton("Start play 2048 game",this);
    button->setGeometry(70,605,410,60);
    connect(button,SIGNAL(clicked()),this,SLOT(slotStart()));
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter A(this);
    A.setBrush(Qt::blue);
    A.setFont(QFont("Courier New",40,1000,false));

    QString strscore;
    A.drawText(QPoint(60,110),"score:"+QString::number(score));

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            A.setPen(Qt::transparent);
            if(K[i][j] == 0){
                A.setBrush(Qt::black);
                A.drawRect(i*100+80,j*100+200,90,90);
            }
            else if(K[i][j] == 2){
                A.setBrush(Qt::red);
                A.drawRect(i*100+80,j*100+200,90,90);
                A.setPen(Qt::white);
                A.setFont(QFont("Courier New",10,700,false));
               A.drawText(QRectF(i*100+80,j*100+200,90,90),QString::number(2),QTextOption(Qt::AlignCenter));
            }
            else if(K[i][j] == 4){
                A.setBrush(Qt::darkRed);
                A.drawRect(i*100+80,j*100+200,90,90);
                A.setPen(Qt::white);
                A.setFont(QFont("Courier New",10,700,false));
               A.drawText(QRectF(i*100+80,j*100+200,90,90),QString::number(4),QTextOption(Qt::AlignCenter));            }
            else if(K[i][j] == 8){
                A.setBrush(Qt::green);
                A.drawRect(i*100+80,j*100+200,90,90);
                A.setPen(Qt::white);
                A.setFont(QFont("Courier New",10,700,false));
               A.drawText(QRectF(i*100+80,j*100+200,90,90),QString::number(8),QTextOption(Qt::AlignCenter));            }
            else if(K[i][j] == 16){
                A.setBrush(Qt::darkGreen);
                A.drawRect(i*100+80,j*100+200,90,90);
                A.setPen(Qt::white);
                A.setFont(QFont("Courier New",10,700,false));
               A.drawText(QRectF(i*100+80,j*100+200,90,90),QString::number(16),QTextOption(Qt::AlignCenter));            }
            else if(K[i][j] == 32){
                A.setBrush(Qt::yellow);
                A.drawRect(i*100+80,j*100+200,90,90);
                A.setPen(Qt::white);
                A.setFont(QFont("Courier New",10,700,false));
               A.drawText(QRectF(i*100+80,j*100+200,90,90),QString::number(32),QTextOption(Qt::AlignCenter));            }
            else if(K[i][j] == 64){
                A.setBrush(Qt::darkYellow);
                A.drawRect(i*100+80,j*100+200,90,90);
                A.setPen(Qt::white);
                A.setFont(QFont("Courier New",10,700,false));
               A.drawText(QRectF(i*100+80,j*100+200,90,90),QString::number(64),QTextOption(Qt::AlignCenter));            }
            else if(K[i][j] == 128){
                A.setBrush(Qt::cyan);
                A.drawRect(i*100+80,j*100+200,90,90);
                A.setPen(Qt::white);
                A.setFont(QFont("Courier New",10,700,false));
               A.drawText(QRectF(i*100+80,j*100+200,90,90),QString::number(128),QTextOption(Qt::AlignCenter));            }
            else if(K[i][j] == 256){
                A.setBrush(Qt::darkCyan);
                A.drawRect(i*100+80,j*100+200,90,90);
                A.setPen(Qt::white);
                A.setFont(QFont("Courier New",10,700,false));
               A.drawText(QRectF(i*100+80,j*100+200,90,90),QString::number(256),QTextOption(Qt::AlignCenter));            }
            else if(K[i][j] == 512){
                A.setBrush(Qt::magenta);
                A.drawRect(i*100+80,j*100+200,90,90);
                A.setPen(Qt::white);
                A.setFont(QFont("Courier New",10,700,false));
               A.drawText(QRectF(i*100+80,j*100+200,90,90),QString::number(512),QTextOption(Qt::AlignCenter));            }
            else if(K[i][j] == 1024){
                A.setBrush(Qt::darkMagenta);
                A.drawRect(i*100+80,j*100+200,90,90);
                A.setPen(Qt::white);
                A.setFont(QFont("Courier New",10,700,false));
               A.drawText(QRectF(i*100+80,j*100+200,90,90),QString::number(1024),QTextOption(Qt::AlignCenter));            }
            else if(K[i][j] == 2048){
                A.setBrush(Qt::blue);
                A.drawRect(i*100+80,j*100+200,90,90);
                A.setPen(Qt::white);
                A.setFont(QFont("Courier New",10,700,false));
               A.drawText(QRectF(i*100+80,j*100+200,90,90),QString::number(2048),QTextOption(Qt::AlignCenter));            }
            else{
                A.setBrush(Qt::darkBlue);
                A.drawRect(i*100+80,j*100+200,90,90);
                A.setPen(Qt::white);
                A.setFont(QFont("Courier New",10,700,false));
               A.drawText(QRectF(i*100+80,j*100+200,90,90),QString::number(K[i][j]),QTextOption(Qt::AlignCenter));
            }

        }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(!state)
        return;

   switch(event->key())
   {
    case Qt::Key_H:
       GoUp();
         break;
    case Qt::Key_B:
       GoDown();
         break;
    case Qt::Key_G:
       GoLeft();
         break;
    case Qt::Key_D:
      GoRight();
         break;
    default:return;
   }

   Rand();
   update();

}

void Widget::slotStart()
{

   QMessageBox::about(this,"game rules","Hello dear player - you can use this instructions to play 2048 game "
                                        ": H , B , G, D , to move up and down, know? and Good luck😍😍🤩");
    score = 0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            K[i][j]=0;
    button->setText("Replay");

    int randi = qrand() % 4;
    int randj = qrand() % 4;
    K[randi][randj] = 2;

    state = true;
    update();

}

void Widget::GoUp()
{
    for(int i=0;i<4;i++)
         for(int j=1;j<4;j++){
             if(K[i][j] == 0){
                 continue;
             }
            for(int p=0;p<j;p++){
                if(K[i][p] == 0){
                    K[i][p] = K[i][j];
                    K[i][j] = 0;
                    break;
                }
            }
         }
    for(int i=0;i<4;i++)
         for(int j=0;j<3;j++){
             if(K[i][j] == K[i][j+1]){
                 K[i][j] = K[i][j]*2;
                 K[i][j+1] = 0;
                 score += K[i][j];
                 for(int p=j+2;p<4;p++)
                     K[i][p-1] = K[i][p];
             }

         }
}

void Widget::GoDown()
{
    for(int i=0;i<4;i++)
         for(int j=2;j>=0;j--){
             if(K[i][j] == 0){
                 continue;
             }
            for(int p=3;p>j;p--){
                if(K[i][p] == 0){
                    K[i][p] = K[i][j];
                    K[i][j] = 0;
                    break;
                }
            }
         }
    for(int i=0;i<4;i++)
         for(int j=3;j>0;j--){
             if(K[i][j] == K[i][j-1]){
                 K[i][j] = K[i][j]*2;
                 K[i][j-1] = 0;
                 score += K[i][j];
                 for(int p=j-2;p>=0;p--)
                     K[i][p+1] = K[i][p];
             }

         }
}

void Widget::GoLeft()
{
    for(int j=0;j<4;j++)
         for(int i=1;i<4;i++){
             if(K[i][j] == 0){
                 continue;
             }
            for(int p=0;p<i;p++){
                if(K[p][j] == 0){
                    K[p][j] = K[i][j];
                    K[i][j] = 0;
                    break;
                }
            }
    }
    for(int j=0;j<4;j++)
         for(int i=0;i<3;i++){
             if(K[i][j] == K[i+1][j]){
                 K[i][j] = K[i][j]*2;
                 K[i+1][j] = 0;
                 score += K[i][j];
                 for(int p=i+2;p<4;p++)
                     K[p-1][j] = K[p][j];
             }

         }

}
void Widget::GoRight()
{
    for(int j=0;j<4;j++)
         for(int i=2;i>=0;i--){
             if(K[i][j] == 0){
                 continue;
             }
            for(int p=3;p>i;p--){
                if(K[p][j] == 0){
                    K[p][j] = K[i][j];
                    K[i][j] = 0;
                    break;
                }
            }
         }
    for(int j=0;j<4;j++)
         for(int i=3;i>0;i--){
             if(K[i][j] == K[i-1][j]){
                 K[i][j] = K[i][j]*2;
                 K[i-1][j] = 0;
                 score += K[i][j];
                 for(int p=i-2;p>=0;p--)
                     K[p+1][j] = K[p][j];
             }

         }

}

void Widget::Rand()
{
    int i,j;
   struct Ns n[15];
   int ni=0;
   for(i=0;i<4;i++)
       for(j=0;j<4;j++){
           if(K[i][j] == 0)
           {
               n[ni].i=i;
               n[ni].j=j;
               ++ni;
           }
       }
   if(ni == 0){
       for(i=0;i<4;i++)
           for(j=0;j<3;j++)
               if(K[i][j] == K[i][j+1])
                  return;
       for(j=0;j<4;j++)
            for(i=0;i<3;i++)
                if(K[i][j] == K[i+1][j])
                   return;
      QMessageBox::about(this,"game over","Dear! You have failed  😂😂😂 ~~ Current score:"+QString::number(score)+"       ");
      return;
   }

   int rand = qrand() % (ni);
   K[n[rand].i][n[rand].j] = 2;

}
