#ifndef IMGLABEL_H
#define IMGLABEL_H

/**
 * The imgLabel class is a class derived from QLabel and is used to draw on an image
 * It outputs also the QPixmap of the only drawing for the seeds
 */

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
    /**
     * Constructors
     */
    explicit imgLabel(QWidget *parent = 0);
    imgLabel(const QString&,QWidget *parent=0);
    ~imgLabel();

    /**
     * Accessors
     */
    QPixmap getDrawing()const;
    const bool &GetFrontDraw() const;
    const int &GetSize() const;
    const bool &isDrawEnabled() const;
    const bool &GetDrawEnabled() const;

    /**
     * Mutators
     */
    void setPhoto(const QString &);
    void SetFrontDraw(const bool &);
    void setDrawEnable(const bool &);
    void SetSize(const int &);
    void SetSizePencil(const int &);

    /**
     * Swap the boolean drawEnabled
     */
    void SwapDrawEnable();

    /**
     * Delete the last stroke on the image
     */
    void CtrlZ();


private:

    /**
     * Events managing the mouse and the paint
     */
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    /**
     * The two extremities of the line drawn between two updates
     * of the cursor
     */
    QPoint p1;
    QPoint p2;

    /**
     * Pixmap storing the original image with the drawing on it
     * and pixmap with the only drawing
     */
    QPixmap *photo;
    QPixmap *drawing;

    /**
     * Previous pixmaps saved before a change
     */
    QPixmap *ImageInter;
    QPixmap *DrawInter;

    /**
     * Booleans allowing to know if the mouse is pressed, if draw can be enable
     * and if it is a seed for the foreground or the background
     */
    bool leftMousePressed;
    bool drawEnabled;
    bool FrontDraw;

    /**
     * Size of the pencil to draw on the image
     * and size of the image to center the pencil on the image
     */
    int SizePencil;
    int SizeImage;

};

#endif // IMGLABEL_H
