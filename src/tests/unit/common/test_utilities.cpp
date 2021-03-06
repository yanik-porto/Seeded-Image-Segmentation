//include my own code
#include <common/utilities.h>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <Eigen/Sparse>

using namespace Eigen;

//include the gtest library
#include <gtest/gtest.h>

//test function
TEST(convertMat, testConvesion) {

	//Initialize arbitrary matrix
	MatrixXd M(2,2);
	M(0,0) = 3;
	M(1,0) = 2.5;
	M(0,1) = 6;
	M(1,1) = 5;

	//Create Vector with the one to compare
	VectorXd V(4);
  	V << 3, 6, 2.5, 5;
	
	GTEST_ASSERT_EQ(Matrix2Vector(M), V);
}
