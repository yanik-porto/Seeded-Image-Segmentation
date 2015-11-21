#ifndef ENGINE_H
#define ENGINE_H
#define EIGEN_YES_I_KNOW_SPARSE_MODULE_IS_NOT_STABLE_YET

#include <QPixmap>
#include <iostream>
#include "utilities.h"

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/eigen.hpp"
#include "opencv/cv.h"

#include <Eigen/Dense>
#include <Eigen/Core>
#include <Eigen/Sparse>

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
    void implement_D();
    void implement_Is();



private:
    QString picturePath;
    MatrixXi I;
    QPixmap pixmap_b;
    MatrixXi b;
    SparseMatrix<double> Wij;
    SparseMatrix<double> D;
    SparseMatrix<double> Is;


    //Size size_image;
};

#endif // ENGINE_H
