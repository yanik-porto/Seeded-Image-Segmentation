#include "engine.h"

//-----------------------------------------------------------------------------
// Constructors and destructors
//-----------------------------------------------------------------------------

Engine::Engine():
    mat_sz(0),
    img_r(0),
    img_c(0)
{
}

Engine::Engine(const QString &filename):
    mat_sz(0),
    img_r(0),
    img_c(0)
{
    picturePath=filename;

}

Engine::~Engine()
{

}

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

void Engine::set_picturePath(const QString &filename)
{
    picturePath = filename;
}

Mat &Engine::segment_image(const QString &fileNameSeeds, float beta)
{
    splitRGBlayers();
    pixmapSeedstoVector(fileNameSeeds);
    setUpGraphWeightAndSum(beta);
    checkIfInSeedsOrNot();
    diffBetweenSumAndWeights();
    solveEnergyFunction();
    keepOnlyForeground();
    cout<<"OK"<<endl;

    return Icv;
}

//-----------------------------------------------------------------------------
// Private functions
//-----------------------------------------------------------------------------


void Engine::splitRGBlayers()
{
    /**
     * Read the image into OpenCV matrix, split each layer and
     * convert them in Eigen Matrices.
     */
    Icv = imread(picturePath.toStdString(),CV_LOAD_IMAGE_COLOR);

    Mat bgr[3];
    split(Icv, bgr);
    cv2eigen(bgr[0], Ib);
    cv2eigen(bgr[1], Ig);
    cv2eigen(bgr[2], Ir);

    /**
     * Update the sizes of the image
     */

    img_r = Ib.rows();
    img_c = Ib.cols();
    mat_sz = img_r * img_c;
}

void Engine::pixmapSeedstoVector(const QString &fileNameSeeds)
{
    /**
     * Read the drawing of the seeds, convert it to gray image and to
     * row*column vector. Values of the seeds are now 76 and 25 (values of blue and red in gray level)
     */

    Mat matDrawing = imread(fileNameSeeds.toStdString());

    //Grayscale matrix
    Mat bcv(matDrawing.size(), CV_8U);

    //Convert BGR to Gray
    cvtColor( matDrawing, bcv, CV_BGR2GRAY );

    //size_image = bcv.size();
    cv2eigen(bcv,bMatrix);

    //Convert matrix of seeds into vectors
    b=Matrix2Vector(bMatrix);

}

void Engine::setUpGraphWeightAndSum(float beta)
{
    /**
     * Initialize the Sparse Matrices with the number of expected values in each row
     * and instantiate the variables which will help us to compute the graph weight and the sum
     * of the rows
     */
    VectorXd VecDiff(3);
    double diff;

    Wij = SparseMatrix<double>(mat_sz, mat_sz);
    const int sp_rsv_row = 9;
    Wij.reserve(VectorXi::Constant(mat_sz, sp_rsv_row));

    D = SparseMatrix<double>(mat_sz, mat_sz);
    D.reserve(VectorXi::Constant(mat_sz, 1));
    double summ(0), wij(0);

    int rowPi, colPi, rowPj, colPj, indexJ;
    float sigma;

    /**
     * Compute weights of every pixels with their neighbors and uptate the sum
     * of the row weights at every iterations
     */
    for(int i = 0; i < mat_sz; i++)
    {
        //Get row and column location of the pixel
        summ = 0;
        rowPi = i / img_c;
        colPi = i % img_c;

        sigma = 0.1;

        for(int j = 0; j<9; j++)
        {
            //Get row an column location of the neighbor
            rowPj = rowPi + j / 3 - 1;
            colPj = colPi + j % 3 - 1;

            indexJ = (rowPj * img_c) + colPj;

            //If neighbor is out of the image bounds or is corresponding to the same pixel, do nothing
            if(rowPj<0 || rowPj>=img_r || colPj<0 || colPj>=img_c || (rowPj==rowPi && colPj==colPi))
            {}

            else
            {
                //Compute difference of the values of each layer between the two pixels
                VecDiff(0) = Ib(rowPi,colPi)-Ib(rowPj,colPj);
                VecDiff(1) = Ig(rowPi,colPi)-Ig(rowPj,colPj);
                VecDiff(2) = Ir(rowPi,colPi)-Ir(rowPj,colPj);
                //Calculate infinity norm of the differences
                diff = VecDiff.lpNorm<Infinity>();
                //Compute the weight
                wij = exp((-beta*diff*diff)/(sigma)) ;
                Wij.insert(i,indexJ) = wij;
                //Update the sum
                summ += wij;
            }
        }
        //Insert the sum in the diagonal matrix
        D.insert(i,i) = summ;
    }
}

void Engine::checkIfInSeedsOrNot()
{
    /**
     * Check if the a pixel is in the seeds or not
     * if yes, insert 1 in the diagonal sparse matrix
     * else, do nothing
     */
    Is = SparseMatrix<double>(mat_sz,mat_sz);
    Is.reserve(VectorXi::Constant(mat_sz,1));

    for(int i=0; i < img_r; i++)
    {
        for(int j=0; j < img_c; j++)
        {
            if(bMatrix(i,j) != 0)
            {
                Is.insert((i*img_c)+j,(i*img_c)+j)=1;
            }
        }
    }

}

void Engine::diffBetweenSumAndWeights()
{
    /**
     * Compute difference between the row sum of the weights
     * and the weights
     */
    L = SparseMatrix<double>(mat_sz, mat_sz);
    L.reserve(VectorXi::Constant(mat_sz, 9));
    L = D-Wij;
}

void Engine::solveEnergyFunction()
{
    /**
     * Rewrite the energy function in matrices and minimize this one
     * using Cholesky factorization
     */

    //Instantiate a sparse matrix to store the energy function
    typedef Eigen::SparseMatrix<double> SparseMatrixType;
    A = SparseMatrix<double>(mat_sz, mat_sz);
    A.reserve(VectorXi::Constant(mat_sz, 9));
    A = (Is + L * L);

    //Instantiate a clock in order to know how many time the solver takes
    clock_t t;
    t=clock();

    //Solve the system using cholesky factorization from the Eigen library
    SimplicialLDLT<SparseMatrixType> sparseSolver(A);
    X = sparseSolver.solve(b);

    //Convert the solution vector to matrix
    xMatrix = Vector2Matrix(X, img_r, img_c);

    //Get the duration of the solver in minutes
    t=clock()-t;
    cout<<"Duration : "<<(float)t/(CLOCKS_PER_SEC*60)<<" min"<<endl;

}

void Engine::keepOnlyForeground()
{
    /**
     * Convert the solution matrix in OpenCV matrix and
     * create a mask of pixels which are greater than the mean of the values of the seeds.
     * Apply this mask to the Original image
     */
    //Convert Eigen Matrix solution to opencv matrix
    seg_image = Mat(img_r, img_c, CV_8U);
    eigen2cv(xMatrix, seg_image);

    //Create the mask with a threshold
    Mat mask = seg_image > (76+25)/2;

    //Apply the mask on the original image
    Icv.setTo(0,mask);
}



