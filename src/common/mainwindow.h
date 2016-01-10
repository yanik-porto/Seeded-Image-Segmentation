#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <iostream>
#include <QFileDialog>
#include <QBuffer>

#include "imglabel.h"
#include "engine.h"

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv/cv.h"

using namespace cv;
using namespace std;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /**
     * Slot for the clicks on the buttons
     */
    void on_pushButton_Load_clicked();

    void on_pushButton_Extract_clicked();

    void on_pushButton_Front_Draw_clicked();

    void on_pushButton_Save_clicked();

    void on_pushButton_Back_Draw_clicked();

    void on_pushButton_CtrlZ_clicked();

    void on_pushButton_Small_Pencil_clicked();

    void on_pushButton_Medium_Pencil_clicked();

    void on_pushButton_Large_Pencil_clicked();

    void on_pushButtonOK_2_clicked();

    void on_pushButtonOK_3_clicked();

    void on_pushButtonOK_5_clicked();

private:

    /**
     * Hide all the group boxes except the one indicated in parameter
     */
    void HideGroupBox(int);

    /**
     * Get the elements from the ui
     */
    Ui::MainWindow *ui;

    /**
     * Instance of the Engine class
     */
    Engine matrixEngine;

    /**
     * instance of the class imgLabel
     */
    imgLabel *label_image;

    /**
     * OpenCV matrix storing the segmented image
     */
    Mat final_image;

    /**
     * value of beta got from the GUI
     */
    float beta;
};

#endif // MAINWINDOW_H
