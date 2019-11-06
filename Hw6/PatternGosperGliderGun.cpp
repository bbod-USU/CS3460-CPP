//
// Created by Brady Bodily on 11/5/19.
//

#include "PatternGosperGliderGun.hpp"

PatternGosperGliderGun::PatternGosperGliderGun() :
    X(38), Y(11)
{
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
        {
            cells[i][j] = false;
        }
    }

    //Guns
    cells[3][35] = true;
    cells[3][36] = true;
    cells[4][35] = true;
    cells[4][36] = true;

    cells[5][1] = true;
    cells[5][2] = true;
    cells[6][1] = true;
    cells[6][2] = true;

    // Queen Bee
    cells[1][25] = true;
    cells[2][23] = true;
    cells[2][25] = true;
    cells[3][21] = true;
    cells[3][22] = true;
    cells[4][21] = true;
    cells[4][22] = true;
    cells[5][21] = true;
    cells[5][22] = true;
    cells[6][23] = true;
    cells[6][25] = true;
    cells[7][25] = true;

    // Glider
    cells[3][13] = true;
    cells[3][14] = true;
    cells[4][12] = true;
    cells[4][16] = true;
    cells[5][11] = true;
    cells[5][17] = true;
    cells[6][11] = true;
    cells[6][15] = true;
    cells[6][17] = true;
    cells[6][18] = true;
    cells[7][11] = true;
    cells[7][17] = true;
    cells[8][12] = true;
    cells[8][16] = true;
    cells[9][13] = true;
    cells[9][14] = true;
}