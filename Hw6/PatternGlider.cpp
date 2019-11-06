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

    cells[3][1];
    cells[3][2];
    cells[3][3];
    cells[2][3];
    cells[1][2];
}