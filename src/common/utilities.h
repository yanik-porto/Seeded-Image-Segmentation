#ifndef UTILITIES_H
#define UTILITIES_H

#include "Eigen/Dense"
#include "Eigen/Core"
#include "Eigen/Sparse"

using namespace Eigen;

/**
 * The Utilities file contains some commom use functions.
 */

//Convert a matrix into vector of rsize row*col
VectorXd Matrix2Vector(MatrixXd M);

//Convert a Vector into matrix of size row*col given in parameters
MatrixXd Vector2Matrix(VectorXd V, int row, int col);

//Give the maximum infinity norm in the Neighborhood for given pixel coordinates in the matrix M
float maxInfNormInNeighood(MatrixXi M, int indexRow, int indexCol);

#endif // UTILITIES_H
