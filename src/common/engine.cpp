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

Mat &Engine::get_seg_image(const QString &filename)
{
    splitRGBlayers();
    pixmapSeedstoVector(filename);
    setUpGraphWeightAndSum();
    checkIfInSeedsOrNot();
    implement_L();
    solveEnergyFunction();
    keepOnlyForeground();

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

void Engine::pixmapSeedstoVector(const QString &filename)
{
    /**
     * Read the drawing of the seeds, convert it to gray image and to
     * row*column vector. Values of the seeds are now 76 and 25 (values of blue and red in gray level)
     */

    Mat matDrawing = imread(filename.toStdString());

    //Grayscale matrix
    Mat bcv(matDrawing.size(), CV_8U);

    //Convert BGR to Gray
    cvtColor( matDrawing, bcv, CV_BGR2GRAY );

    //size_image = bcv.size();
    cv2eigen(bcv,bMatrix);

    //Convert matrix of seeds into vectors
    b=Matrix2Vector(bMatrix);

}

void Engine::setUpGraphWeightAndSum()
{
    /**
     * Read the image into OpenCV matrix, split each layer and
     *
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
    float beta(0.0001), sigma;

    for(int i = 0; i < mat_sz; i++)
    {
        summ = 0;
        rowPi = i/img_c;
        colPi = i%img_c;

        //sigma = maxInfNormInNeighood(I, rowPi, colPi);        //Still some pbm in this function
        sigma = 0.1;

        for(int j = 0; j<9; j++)
        {
            rowPj = rowPi + j / 3 - 1;
            colPj = colPi + j % 3 - 1;

            indexJ = (rowPj * img_c) + colPj;

            if(rowPj<0 || rowPj>=img_r || colPj<0 || colPj>=img_c || (rowPj==rowPi && colPj==colPi))
            {}

            else
            {
                VecDiff(0) = Ib(rowPi,colPi)-Ib(rowPj,colPj);
                VecDiff(1) = Ig(rowPi,colPi)-Ig(rowPj,colPj);
                VecDiff(2) = Ir(rowPi,colPi)-Ir(rowPj,colPj);
                diff = VecDiff.lpNorm<Infinity>();
                wij = exp((-beta*diff*diff)/(sigma)) ;
                Wij.insert(i,indexJ) = wij;
                summ += wij;
            }
        }

        D.insert(i,i) = summ;

    }
}

void Engine::checkIfInSeedsOrNot()
{
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

void Engine::implement_L()
{

    L = SparseMatrix<double>(mat_sz, mat_sz);
    L.reserve(VectorXi::Constant(mat_sz, 9));
    L = D-Wij;

}

void Engine::solveEnergyFunction()
{
    clock_t t;
    t=clock();
    typedef Eigen::SparseMatrix<double> SparseMatrixType;
    A = SparseMatrix<double>(mat_sz, mat_sz);
    A.reserve(VectorXi::Constant(mat_sz, 9));

    A = (Is + L * L);
    SimplicialLDLT<SparseMatrixType> sparseSolver(A);
    X = sparseSolver.solve(b);

    xMatrix = Vector2Matrix(X, img_r, img_c);
    t=clock()-t;
    cout<<"Duration : "<<(float)t/(CLOCKS_PER_SEC*60)<<" min"<<endl;

}

void Engine::keepOnlyForeground()
{

    seg_image = Mat(xMatrix.rows(), xMatrix.cols(), CV_8U);

    eigen2cv(xMatrix, seg_image);

    seg_image.convertTo(seg_image,CV_8U);

    Mat mask = seg_image > 50;

    Icv.setTo(0,mask);
}



