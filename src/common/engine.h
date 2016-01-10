#ifndef ENGINE_H
#define ENGINE_H
#define EIGEN_YES_I_KNOW_SPARSE_MODULE_IS_NOT_STABLE_YET

/**
 * The Engine class receives the image input in the gui and the drawn pixmap
 * and apply mathematics in order to output the segmented image
 */


#include <QPixmap>
#include <iostream>
#include "utilities.h"
#include <time.h>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/eigen.hpp>
#include <opencv/cv.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

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
    Engine(const QString &filename);
    ~Engine();

    /**
     * Main function where all functions are called
     */
    Mat &segment_image(const QString &fileNameSeeds, float beta);

    /**
     * Mutators
     */
    void set_picturePath(const QString &filename);







private:
    /**
     * Split the different layers of the image
     * and store them in three eigen matrices
     */
    void splitRGBlayers();

    /**
     * Read pixmap of the seeds and convert it to a row vector
     */
    void pixmapSeedstoVector(const QString &fileNameSeeds);

    /**
     * Set up the graph weights and store them in a Sparse matrix
     * and deliver also a diagonal Sparse Matrix with the sum of the weigths in each row
     */
    void setUpGraphWeightAndSum(float beta);

    /**
     * Implement the diagonal sparse matrix with ones, if the pixel belongs to the Background
     *  or the Foreground, and zeros otherwise.
     */
    void checkIfInSeedsOrNot();

    /**
     * Implement the matrix corresponding to sum of the weights minus the weights
     */
    void diffBetweenSumAndWeights();

    /**
     * Solve the Energy functional by minimising using Cholesky factorization algorithm
     */
    void solveEnergyFunction();

    /**
     * keep only the foreground thanks to a given threshold and the solution of the equation
     */
    void keepOnlyForeground();


    /**
     * Path of the image to segment
     */
    QString picturePath;

    /**
     * Sizes of the image
     */
    int mat_sz;
    int img_r;
    int img_c;

    /**
     * Three layers of the color image
     */
    MatrixXd Ib;
    MatrixXd Ig;
    MatrixXd Ir;

    /**
     * All elements which help to convert seeds pixmap to vector
     */
    QPixmap pixmap_b;
    MatrixXd bMatrix;
    VectorXd b;

    /**
     * Sparse matrix storing the weights
     */
    SparseMatrix<double> Wij;

    /**
     * All sparse matrices minimizing the Energy functional
     */
    SparseMatrix<double> D;
    SparseMatrix<double> Is;
    SparseMatrix<double> L;

    /**
     * Sparse matrix representing the linear system
     */
    SparseMatrix<double> A;

    /**
     * Vector storing the solution of the minimization
     */
    VectorXd X;

    /**
     * Solution vector converted into matrix
     */
    MatrixXd xMatrix;

    /**
     * OpenCV matrix of the solution
     */
    Mat seg_image;

    /**
     * OpenCV matrix embedding the original image
     * on which we remove the backgroud later on
     */
    Mat Icv;

};

#endif // ENGINE_H
