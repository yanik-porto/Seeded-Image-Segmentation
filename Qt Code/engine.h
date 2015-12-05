#ifndef ENGINE_H
#define ENGINE_H
#define EIGEN_YES_I_KNOW_SPARSE_MODULE_IS_NOT_STABLE_YET

#include <QPixmap>
#include <iostream>
#include "utilities.h"
#include <time.h>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/eigen.hpp>
#include <opencv/cv.h>
#include <opencv2/imgproc/imgproc.hpp>

#include "Eigen/Dense"
#include "Eigen/Core"
#include "Eigen/Sparse"

using namespace cv;
using namespace std;
using namespace Eigen;



class Engine
{
public:
    Engine();
    ~Engine();

    void set_Pixmap_b(const QPixmap &);
    void set_picturePath(const QString filename);
    void implement_I();
    void implement_b();
    void implement_Wij();
    void implement_Is();
    void implement_L();
    void implement_X();
    void convert_X_to_image();
    Mat &get_seg_image();



private:
    QString picturePath;
    MatrixXd I;
    Mat grayI;
    QPixmap pixmap_b;
    MatrixXd bMatrix;
    VectorXd b;
    SparseMatrix<double> Wij;
    SparseMatrix<double> D;
    SparseMatrix<double> Is;
    SparseMatrix<double> L;
    VectorXd X;
    SparseMatrix<double> A;
    MatrixXd xMatrix;
    Mat seg_image;


    //Size size_image;
};

#endif // ENGINE_H
