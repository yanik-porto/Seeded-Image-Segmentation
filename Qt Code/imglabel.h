#ifndef IMGLABEL_H
#define IMGLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPoint>
#include <iostream>

using namespace std;


class imgLabel : public QLabel
{
    Q_OBJECT
public:
    explicit imgLabel(QWidget *parent = 0);
    imgLabel(const QString&,QWidget *parent=0);
    ~imgLabel();

    void setPhoto(const QString &);
    QPixmap getDrawing()const;

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

signals:

public slots:

private:
    QPoint p1;
    QPoint p2;
    QPixmap *photo;
    QPixmap *drawing;
    bool mousePressed;

};

#endif // IMGLABEL_H
