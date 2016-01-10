#include "imglabel.h"

//-----------------------------------------------------------------------------
// Constructor and destructor
//-----------------------------------------------------------------------------

imgLabel::imgLabel(QWidget *parent) :
    QLabel(parent),
    leftMousePressed(false),
    drawEnabled(false),
    FrontDraw(true)
{
    SetSizePencil(5);
    SetSize(0);
}

imgLabel::imgLabel(const QString &filename, QWidget *parent):
    QLabel(parent),
    leftMousePressed(false),
    drawEnabled(false),
    FrontDraw(true)
{
    SetSizePencil(5);
    SetSize(0);
    setPhoto(filename);
}

imgLabel::~imgLabel()
{
    if(photo!=NULL)
        delete photo;
    if(drawing!=NULL)
        delete drawing;
}

//-----------------------------------------------------------------------------
// Accessors
//-----------------------------------------------------------------------------
QPixmap imgLabel::getDrawing()const
{
    return *drawing;
}

void imgLabel::setDrawEnable(const bool &yn)
{
    drawEnabled=yn;
}

const bool &imgLabel::isDrawEnabled() const
{
    return drawEnabled;
}

const bool &imgLabel::GetFrontDraw() const // Verifie
{
    return FrontDraw;
}

const int &imgLabel::GetSize() const
{
    return SizeImage;
}

//-----------------------------------------------------------------------------
// Mutators
//-----------------------------------------------------------------------------

void imgLabel::setPhoto(const QString &filename)
{
    /**
     * Set the pixmap of the label with the image from filename
     */
    photo=new QPixmap(filename);
    this->setPixmap(*photo);
    SetSize(photo->height());
    ImageInter  = new QPixmap (photo->copy());

    /**
     * Fill the pixmap of the drawing with black pixels
     */
    drawing=new QPixmap(photo->size());
    drawing->fill(Qt::black);
}

void imgLabel::SetFrontDraw(const bool &Boolean) // Verifie
{
    FrontDraw = Boolean;
}

void imgLabel::SetSizePencil(const int &Size)
{
    SizePencil= Size;
}

void imgLabel::SetSize(const int &Size)
{
    SizeImage = Size;
}

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------
void imgLabel::CtrlZ()
{
    /**
     * Store the previous pixmap in the new one
     */
    photo  = new QPixmap(ImageInter->copy());
    drawing  = new QPixmap(DrawInter->copy());
    this->setPixmap(*ImageInter);
}

void imgLabel::SwapDrawEnable()
{
    /**
     * Say if it is drawnabled
     */
    if (drawEnabled == true){ drawEnabled = false;}
    else{drawEnabled = true;}
}

//-----------------------------------------------------------------------------
// Private functions
//-----------------------------------------------------------------------------
void imgLabel::mousePressEvent(QMouseEvent *event)
{
    /**
     * When mouse pressed store current pixmap in the previous one and
     * get the cursor position
     */
    ImageInter  = new QPixmap (photo->copy());
    DrawInter  = new QPixmap (drawing->copy());

    if(event->button()==Qt::LeftButton)
        leftMousePressed=true;

    p1=event->pos();
    p1.setY( p1.y()- GetSize() );
    p2 = event->pos();
    p2.setY( p2.y()- GetSize() );
}

void imgLabel::mouseMoveEvent(QMouseEvent *event)
{
    /**
     * When mouse moved update p2 by the new position
     */
    if(drawEnabled)
    {
        p2=event->pos();
        p2.setY( p2.y()- GetSize() );
        update();
    }
}


void imgLabel::mouseReleaseEvent(QMouseEvent *event)
{
    /**
     * event for the mouse release
     */
    if(event->button()==Qt::LeftButton)
        leftMousePressed=false;
}

void imgLabel::paintEvent(QPaintEvent *event)
{
    /**
     * Paint the image and the drawing pixmap in function of the booleans
     * Draw a line between the two cursor position
     * And update the first position with the second one
     */

    QLabel::paintEvent(event);

    if(photo && drawEnabled)
    {
        QPainter painter(photo);
        QPainter hiddenPainter(drawing);

        QPen pen;

        if(leftMousePressed==true && FrontDraw==true)
        {
            pen.setBrush(Qt::blue);
            pen.setWidth(SizePencil);

            painter.setPen(pen);
            hiddenPainter.setPen(pen);

            painter.drawLine(p1,p2);
            hiddenPainter.drawLine(p1,p2);
            p1=p2;
        }

        if(leftMousePressed==true && FrontDraw==false)
        {
            pen.setBrush(Qt::red);
            pen.setWidth(SizePencil);

            painter.setPen(pen);
            hiddenPainter.setPen(pen);

            painter.drawLine(p1,p2);
            hiddenPainter.drawLine(p1,p2);
            p1=p2;
        }

        this->setPixmap(*photo);
    }

}
