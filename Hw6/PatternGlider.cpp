//
// Created by Brady Bodily on 11/5/19.
//

#include "PatternGlider.hpp"

PatternGlider::PatternGlider() :
    X(5), Y(5)
{
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
        {
            cells[i][j] = false;
        }
    }
    cells[1][2] = true;
    cells[2][3] = true;
    cells[3][1] = true;
    cells[3][2] = true;
    cells[3][3] = true;
}