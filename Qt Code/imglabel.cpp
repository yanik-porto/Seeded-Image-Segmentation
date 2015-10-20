#include "imglabel.h"

imgLabel::imgLabel(QWidget *parent) :
    QLabel(parent),
    leftMousePressed(false),
    rightMousePressed(false),
    drawEnabled(false)
{

}

imgLabel::imgLabel(const QString &filename, QWidget *parent):
    QLabel(parent),
    leftMousePressed(false),
    rightMousePressed(false),
    drawEnabled(false)
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
    if(photo)
    {
        delete photo;
        delete drawing;
    }

    //this->setGeometry(this->x(),this->y(),0,0);
    photo=new QPixmap(filename);
    this->setGeometry(this->x(),this->y(),photo->width(),photo->height());
    this->setPixmap(*photo);
    //this->setGeometry(30,30,photo->width(),photo->height());

    drawing=new QPixmap(photo->size());
    cout<<photo->width()<<"   "<<photo->height()<<endl;
    drawing->fill(Qt::white);
    cout<<drawing->width()<<"   "<<drawing->height()<<endl;


}

QPixmap imgLabel::getDrawing()const
{
    return *drawing;
}

void imgLabel::setDrawEnable(const bool &yn)
{
    drawEnabled=yn;
}

bool imgLabel::isDrawEnabled() const
{
    return drawEnabled;
}

void imgLabel::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
        leftMousePressed=true;

    if(event->button()==Qt::RightButton)
        rightMousePressed=true;

    p1=event->pos();
    p2=event->pos();
}

void imgLabel::mouseMoveEvent(QMouseEvent *event)
{
    if(drawEnabled)
    {
        p2=event->pos();
        cout<<"x:"<<p2.x()<<"y:"<<p2.y()<<endl;
        update();
    }

}

void imgLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
        leftMousePressed=false;

    if(event->button()==Qt::RightButton)
        rightMousePressed=false;
}

void imgLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);

    if(photo && drawEnabled)
    {
        QPainter painter(photo);
        QPainter hiddenPainter(drawing);

        QPen pen;


        if(leftMousePressed==true)
        {
            pen.setBrush(Qt::blue);
            pen.setWidth(5);

            painter.setPen(pen);
            hiddenPainter.setPen(pen);

            painter.drawLine(p1,p2);
            hiddenPainter.drawLine(p1,p2);
            p1=p2;
        }

        if(rightMousePressed==true)
        {
            pen.setBrush(Qt::red);
            pen.setWidth(5);

            painter.setPen(pen);
            hiddenPainter.setPen(pen);

            painter.drawLine(p1,p2);
            hiddenPainter.drawLine(p1,p2);
            p1=p2;
        }

        this->setPixmap(*photo);
    }

}
