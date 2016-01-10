#include "utilities.h"
#include <QtDebug>

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------



VectorXd Matrix2Vector(MatrixXd M)
{
    int row = M.rows();
    int col = M.cols();
    VectorXd V(row * col);

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            V[i*col + j] = M(i, j);
        }
    }

    return V;
}

MatrixXd Vector2Matrix(VectorXd V, int row, int col)
{


    MatrixXd M(row, col);

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            M(i,j) = V(i*col+j);
        }
    }

    return M;
}

float maxInfNormInNeighood(MatrixXi M, int indexRow, int indexCol)
{
    int rowPj, colPj;
    int index=indexRow*M.cols()+indexCol;
    float maxInfNorm(0), infNorm(0);

    for(int i = 0; i < 9; i++)
    {
        rowPj = indexRow + i / 3 - 1;
        colPj = indexCol + i % 3 - 1;

        if((rowPj < 0) || (rowPj >= M.rows()) || (colPj < 0) || (colPj >= M.cols()) || (rowPj == indexRow && colPj == indexCol))
        {}
        else
        {
            infNorm = float(abs(M(indexRow, indexCol) - M(rowPj, colPj)));                //m.lpNorm<Infinity>()

            if(infNorm > maxInfNorm)
                maxInfNorm = infNorm;

            //qDebug()<<"maxinfNorm :"<<maxInfNorm;
        }

    }

    return maxInfNorm;
}
