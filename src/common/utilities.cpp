#include "utilities.h"
#include <QtDebug>

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------

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
