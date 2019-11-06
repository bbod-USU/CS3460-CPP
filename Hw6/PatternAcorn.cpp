//
// Created by Brady Bodily on 11/5/19.
//

#include "PatternAcorn.hpp"

PatternAcorn::PatternAcorn() :
    X(9), Y(5)
{
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
        {
            cells[i][j] = false;
        }
    }

    cells[3][2] = true;
    cells[3][5] = true;
    cells[3][6] = true;
    cells[3][7] = true;

    cells[1][2] = true;
    cells[2][4] = true;
    cells[3][1] = true;
}