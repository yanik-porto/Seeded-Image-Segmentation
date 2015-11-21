#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void on_pushButton_load_clicked();

    void on_pushButton_extract_clicked();

    void on_pushButton_draw_clicked();

private:
    Ui::MainWindow *ui;
    Engine matrixEngine;
};

#endif // MAINWINDOW_H
