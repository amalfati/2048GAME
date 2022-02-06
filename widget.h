#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QPushButton>
#include <QPainter>


class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);

    void GoUp();
    void GoDown();
    void GoLeft();
    void GoRight();
    void Rand();

    QPushButton *button;
    int K[4][4];
    int score;
    bool state;

    struct Ns{
        int i;
        int j;
    };

signals:

public slots:
    void slotStart();
};

#endif // WIDGET_H
