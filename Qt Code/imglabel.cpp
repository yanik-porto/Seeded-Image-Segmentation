#include "imglabel.h"

imgLabel::imgLabel(QWidget *parent) :
    QLabel(parent),
    mousePressed(false)
{

}

imgLabel::imgLabel(const QString &filename, QWidget *parent):
    QLabel(parent),
    mousePressed(false)
{
    photo=new QPixmap(filename);
    this->setPixmap(*photo);
    drawing=new QPixmap(photo->size());
    //drawing.scaled(this->size());
    drawing->fill(Qt::white);
}

imgLabel::~imgLabel()
{
    if(photo)
        delete photo;
    if(drawing)
        delete drawing;
}

void imgLabel::setPhoto(const QString &filename)
{
    photo=new QPixmap(filename);
    this->setPixmap(*photo);
    this->setGeometry(30,30,photo->width(),photo->height());


    drawing=new QPixmap(photo->size());
    cout<<photo->width()<<"   "<<photo->height()<<endl;
    drawing->fill(Qt::white);
    cout<<drawing->width()<<"   "<<drawing->height()<<endl;

}

QPixmap imgLabel::getDrawing()const
{
    return *drawing;
}

void imgLabel::mousePressEvent(QMouseEvent *event)
{

    mousePressed=true;
    p1=event->pos();
    p2=event->pos();
}

void imgLabel::mouseMoveEvent(QMouseEvent *event)
{
    if(mousePressed==true)
    {
        p2=event->pos();
        cout<<"x:"<<p2.x()<<"y:"<<p2.y()<<endl;
        update();
    }

}

void imgLabel::mouseReleaseEvent(QMouseEvent *event)
{
    mousePressed=false;
}

void imgLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);

    if(photo)
    {
        QPainter painter(photo);
        QPainter hiddenPainter(drawing);

        QPen pen;
        pen.setBrush(Qt::blue);
        pen.setWidth(5);

        painter.setPen(pen);
        painter.setBrush(Qt::red);

        hiddenPainter.setPen(pen);
        hiddenPainter.setBrush(Qt::red);


        if(mousePressed==true)
        {
            painter.drawLine(p1,p2);
            hiddenPainter.drawLine(p1,p2);
            p1=p2;
        }

        this->setPixmap(*photo);
    }

}
