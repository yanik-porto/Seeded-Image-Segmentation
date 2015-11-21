#ifndef UTILITIES_H
#define UTILITIES_H

#include <Eigen/Core>

using namespace Eigen;

/**
 * The Utilities file contains some commom use functions.
 */

double maxInfNormInNeighood(MatrixXi M, int indexRow, int indexCol);

#endif // UTILITIES_H
