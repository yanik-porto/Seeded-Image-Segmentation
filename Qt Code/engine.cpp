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
    Mat grayI(matImage.size(), CV_8U);
    cv::cvtColor(matImage,grayI,CV_BGR2GRAY);

    cv2eigen(grayI,I);
    //cout<<"I = "<<I<<endl;
}

void Engine::implement_b()
{
    Mat matDrawing = imread("extPix.png");

    //Grayscale matrix
    Mat bcv(matDrawing.size(), CV_8U);

    //Convert BGR to Gray
    cv::cvtColor( matDrawing, bcv, CV_BGR2GRAY );

    //Binary image
    //cv::Mat binaryMat(grayscaleMat.size(), grayscaleMat.type());
    //Apply thresholding
    //cv::threshold(grayscaleMat, binaryMat, 100, 255, cv::THRESH_BINARY);

    //size_image = bcv.size();
    cv2eigen(bcv,b);
    //cout<<"b = "<<b<<endl;


}

void Engine::implement_Wij()
{
    const int row=I.rows();
    const int col=I.cols();
    cout<<"rows = "<<row<<endl;
    cout<<"cols = "<<col<<endl;

    //Wij=MatrixXd(row*col,row*col);                              //Check how to do dynamic instantiation.
    const int mat_sz = row * col;
    Wij = SparseMatrix<double>(mat_sz, mat_sz);
    const int sp_rsv_row = 9;
    Wij.reserve(VectorXi::Constant(mat_sz, sp_rsv_row));

    int rowPi,colPi,rowPj,colPj,indexJ;
    float beta(5),sigma,smallCst(10^(-6));                      //Change later for float and find a solution for the square in the equation

    for(int i = 0; i < row*col; i++)
    {
        rowPi=i/col;
        colPi=i%col;

        //sigma = maxInfNormInNeighood(I, rowPi, colPi);        //Still some pbm in this function
        sigma = 5;

        for(int j = 0; j<9; j++)
        {


            rowPj=rowPi+j/3-1;
            colPj=colPi+j%3-1;

            indexJ=(rowPj*col)+colPj;

            if(rowPj<0 || rowPj>=row || colPj<0 || colPj>=col || (rowPj==rowPi && colPj==colPi))
            {}

            else
            {
                Wij.insert(i,indexJ) = exp((-beta*double(I(rowPi,colPi)-I(rowPj,colPj))*double(I(rowPi,colPi)-I(rowPj,colPj)))/(sigma+smallCst)) ; //change for Infinity norm if RGB image
            }                                                                     //m.lpNorm<Infinity>()

        }           //Change j for indexJ

    }
}

void Engine::implement_D()
{
    const int mat_sz = Wij.rows();
    D = SparseMatrix<double>(mat_sz, mat_sz);
    D.reserve(VectorXi::Constant(mat_sz, 1));

    for(int i = 0; i < D.rows(); i++)
    {
        //D.insert(i,1) = sum(Wij.r)
    }

}

void Engine::implement_Is()
{
    const int mat_sz = b.rows()*b.cols();
    Is=SparseMatrix<double>(mat_sz,mat_sz);
    Is.reserve(VectorXi::Constant(mat_sz,1));

    for(int i=0; i < b.rows(); i++)
    {
        for(int j=0; j < b.cols(); j++)
        {
            if(b(i,j) != 0)
            {
                Is.insert((i*b.cols())+j,(i*b.cols())+j)=1;
            }

        }
    }

}


