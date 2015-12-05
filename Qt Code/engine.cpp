#include "engine.h"

Engine::Engine()
{
}

Engine::~Engine()
{

}

void Engine::set_Pixmap_b(const QPixmap &pixmap)
{
    pixmap_b=pixmap;
}

void Engine::set_picturePath(const QString filename)
{
    picturePath=filename;
}

void Engine::implement_I()
{
    Mat matImage = imread(picturePath.toStdString());
    grayI = Mat(matImage.size(), CV_8U);
    cv::cvtColor(matImage,grayI,CV_BGR2GRAY);
    grayI.convertTo(grayI,CV_32F,1/255.0);         //Change to CV_32FC3 for color image

    cv2eigen(grayI,I);
    //cout<<I<<endl;
    cout<<"Size of I: "<<I.rows()<<I.cols()<<endl;
    cout<<"I:OK"<<endl;
}

void Engine::implement_b()
{
    Mat matDrawing = imread("extPix.png");

    //Grayscale matrix
    Mat bcv(matDrawing.size(), CV_8U);

    //Convert BGR to Gray
    cvtColor( matDrawing, bcv, CV_BGR2GRAY );

    //size_image = bcv.size();
    cv2eigen(bcv,bMatrix);

    int row = bMatrix.rows();
    int col = bMatrix.cols();
    b = VectorXd(row * col);

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            b[i*col + j] = bMatrix(i, j);
        }
    }

    //cout<<"b = "<<b<<endl;
    cout<<"b:OK"<<endl;

}

void Engine::implement_Wij()
{
    const int row = I.rows();
    const int col = I.cols();
    cout<<"rows = "<<row<<endl;
    cout<<"cols = "<<col<<endl;

    const int mat_sz = row * col;
    
    Wij = SparseMatrix<double>(mat_sz, mat_sz);
    const int sp_rsv_row = 9;
    Wij.reserve(VectorXi::Constant(mat_sz, sp_rsv_row));

    //const int mat_sz = Wij.rows();
    D = SparseMatrix<double>(mat_sz, mat_sz);
    D.reserve(VectorXi::Constant(mat_sz, 1));
    double summ(0), wij(0);



    int rowPi,colPi,rowPj,colPj,indexJ;
    float beta(1),sigma, smallCst(10^(-6));                      //Change later for float and find a solution for the square in the equation

    for(int i = 0; i < row*col; i++)
    {
        summ=0;
        rowPi=i/col;
        colPi=i%col;

        //sigma = maxInfNormInNeighood(I, rowPi, colPi);        //Still some pbm in this function
        sigma = 1;

        for(int j = 0; j<9; j++)
        {


            rowPj = rowPi + j / 3 - 1;
            colPj= colPi + j % 3 - 1;

            indexJ = (rowPj * col) + colPj;

            if(rowPj<0 || rowPj>=row || colPj<0 || colPj>=col || (rowPj==rowPi && colPj==colPi))
            {}

            else
            {
                wij = exp((-beta*(I(rowPi,colPi)-I(rowPj,colPj))*(I(rowPi,colPi)-I(rowPj,colPj)))/(sigma)) ; //change for Infinity norm if RGB image
                Wij.insert(i,indexJ) = wij;
                summ+=wij;
            }                                                                     //m.lpNorm<Infinity>()

        }

        D.insert(i,i) = summ;

    }
    
    cout<<"Wij & D : OK"<<endl;

}

void Engine::implement_Is()
{
    const int mat_sz = bMatrix.rows()*bMatrix.cols();
    Is=SparseMatrix<double>(mat_sz,mat_sz);
    Is.reserve(VectorXi::Constant(mat_sz,1));

    for(int i=0; i < bMatrix.rows(); i++)
    {
        for(int j=0; j < bMatrix.cols(); j++)
        {
            if(bMatrix(i,j) != 0)
            {
                Is.insert((i*bMatrix.cols())+j,(i*bMatrix.cols())+j)=1;
            }

        }
    }
    
    cout<<"Is:OK"<<endl;

}

void Engine::implement_L()
{
    const int mat_sz = Wij.rows();
    L=SparseMatrix<double>(Wij.rows(), Wij.cols());
    L.reserve(VectorXi::Constant(mat_sz, 9));
    L=D-Wij;
    
    cout<<"L:OK"<<endl;
}

void Engine::implement_X()
{
    clock_t t;
    t=clock();
    typedef Eigen::SparseMatrix<double> SparseMatrixType;
    const int mat_sz = Is.rows();
    A = SparseMatrix<double>(mat_sz, mat_sz);
    A.reserve(VectorXi::Constant(mat_sz, 9));

    A = (Is + L * L);
    SimplicialLDLT<SparseMatrixType> sparseSolver(A);
    X=sparseSolver.solve(b);
    //cout<<X<<endl;
    /*if(sparseSolver.info() != Eigen::Success)
      {
        throw std::runtime_error("Decomposition failed!");
      }*/

    /*Eigen::BiCGSTAB<SparseMatrixType >  BCGST;
    BCGST.compute(A);
    X = BCGST.solve(b);*/

    /*SparseLU<SparseMatrixType> solver;
    solver.analyzePattern(A);
    solver.factorize(A);
    X = solver.solve(b);*/
    xMatrix = MatrixXd(I.rows(), I.cols());

    for(int i = 0; i < I.rows(); i++)
    {
        for(int j = 0; j < I.cols(); j++)
        {
            xMatrix(i,j)=X(i*I.cols()+j);
        }
    }

    cout<<"Time : "<<t<<endl;
    cout<<"Clock per sec : "<<(float)t/CLOCKS_PER_SEC<<endl;
    cout<<"X : OK!"<<endl;
    cout<<"Size of X: "<<X.rows()<<endl;
    //cout<<X<<endl;
}

void Engine::convert_X_to_image()
{

    seg_image = Mat(xMatrix.rows(), xMatrix.cols(), CV_8U);
    //Mat seg_image1(xMatrix.rows(), xMatrix.cols(), CV_8U);

    eigen2cv(xMatrix,seg_image);


    seg_image.convertTo(seg_image,CV_8U);


}

Mat &Engine::get_seg_image()
{

    Mat mask = seg_image > 50;
    grayI.convertTo(grayI, CV_8U, 255);
    grayI.setTo(0,mask);

    return grayI;
}


